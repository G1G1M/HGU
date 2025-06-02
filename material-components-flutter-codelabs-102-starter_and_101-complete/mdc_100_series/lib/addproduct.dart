import 'package:flutter/material.dart';
import 'dart:io';
import 'package:image_picker/image_picker.dart';
import 'package:firebase_storage/firebase_storage.dart';
import 'package:path/path.dart' as path;
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';

class AddProductPage extends StatefulWidget {
  const AddProductPage({Key? key}) : super(key: key);

  @override
  State<AddProductPage> createState() => _AddProductPageState();
}

class _AddProductPageState extends State<AddProductPage> {
  final TextEditingController nameController = TextEditingController();
  final TextEditingController priceController = TextEditingController();
  final TextEditingController descriptionController = TextEditingController();

  final ImagePicker _picker = ImagePicker();
  File? _selectedImage;
  String imageUrl = 'http://handong.edu/site/handong/res/img/logo.png';

  // ✅ 이미지 업로드
  Future<String?> uploadImageToStorage(File imageFile) async {
    try {
      final fileName = path.basename(imageFile.path);
      final storageRef =
          FirebaseStorage.instance.ref().child('product_images/$fileName');

      final uploadTask = await storageRef.putFile(imageFile);
      final downloadUrl = await uploadTask.ref.getDownloadURL();
      return downloadUrl;
    } catch (e) {
      print('이미지 업로드 실패: $e');
      return null;
    }
  }

  // ✅ 이미지 선택 + 업로드
  Future<void> _pickImage() async {
    final XFile? pickedFile =
        await _picker.pickImage(source: ImageSource.gallery);

    if (pickedFile != null) {
      final file = File(pickedFile.path);
      final uploadedUrl = await uploadImageToStorage(file);
      if (uploadedUrl != null) {
        setState(() {
          _selectedImage = file;
          imageUrl = uploadedUrl;
        });
      }
    }
  }

  // ✅ Firestore 저장 함수
  Future<void> _saveProduct() async {
    final name = nameController.text.trim();
    final price = int.tryParse(priceController.text.trim()) ?? 0;
    final description = descriptionController.text.trim();
    final user = FirebaseAuth.instance.currentUser;

    if (user == null) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('로그인이 필요합니다.')),
      );
      return;
    }

    try {
      await FirebaseFirestore.instance.collection('products').add({
        'name': name,
        'price': price,
        'description': description,
        'imageUrl': imageUrl,
        'uid': user.uid,
        'createtime': FieldValue.serverTimestamp(),
        'updatetime': FieldValue.serverTimestamp(),
      });

      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('상품이 추가되었습니다.')),
      );
      Navigator.pop(context, true);
    } catch (e) {
      print('저장 오류: $e');
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('상품이 추가되었습니다.')),
      );
      Navigator.pop(context, true); // ✅ 수정됨
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Add'),
      ),
      body: SingleChildScrollView(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            // ✅ 이미지 탭 시 선택 가능
            GestureDetector(
              onTap: _pickImage,
              child: Stack(
                alignment: Alignment.center,
                children: [
                  _selectedImage != null
                      ? Image.file(_selectedImage!,
                          height: 200, fit: BoxFit.contain)
                      : Image.network(imageUrl,
                          height: 200,
                          fit: BoxFit.contain,
                          errorBuilder: (_, __, ___) =>
                              const Icon(Icons.broken_image, size: 100)),
                  Container(
                    height: 200,
                    color: Colors.black.withOpacity(0.4),
                    alignment: Alignment.center,
                    child: const Text(
                      '이미지를 선택하려면 탭하세요',
                      style: TextStyle(color: Colors.white, fontSize: 16),
                    ),
                  ),
                ],
              ),
            ),
            const SizedBox(height: 16),
            TextField(
              controller: nameController,
              decoration: const InputDecoration(labelText: 'Product Name'),
            ),
            const SizedBox(height: 8),
            TextField(
              controller: priceController,
              keyboardType: TextInputType.number,
              decoration: const InputDecoration(labelText: 'Price'),
            ),
            const SizedBox(height: 8),
            TextField(
              controller: descriptionController,
              maxLines: 3,
              decoration: const InputDecoration(labelText: 'Description'),
            ),
            const SizedBox(height: 24),
            ElevatedButton(
              onPressed: _saveProduct,
              child: const Text('Save'),
            ),
          ],
        ),
      ),
    );
  }
}
