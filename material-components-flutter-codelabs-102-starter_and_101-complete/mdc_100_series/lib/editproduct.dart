import 'package:flutter/material.dart';
import 'dart:io';
import 'package:image_picker/image_picker.dart';
import 'package:firebase_storage/firebase_storage.dart';
import 'package:path/path.dart' as path;
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:intl/intl.dart';

import 'model/product.dart';

class EditProductPage extends StatefulWidget {
  final Product product;
  const EditProductPage({required this.product, Key? key}) : super(key: key);

  @override
  State<EditProductPage> createState() => _EditProductPageState();
}

class _EditProductPageState extends State<EditProductPage> {
  late TextEditingController nameController;
  late TextEditingController priceController;
  late TextEditingController descriptionController;

  File? _newImageFile;
  final ImagePicker _picker = ImagePicker();
  late String imageUrl;

  @override
  void initState() {
    super.initState();
    final p = widget.product;
    nameController = TextEditingController(text: p.name);
    priceController = TextEditingController(text: p.price.toInt().toString());
    descriptionController = TextEditingController(text: p.description);
    imageUrl = p.imageUrl;
  }

  Future<String?> _uploadImage(File imageFile) async {
    try {
      final fileName = path.basename(imageFile.path);
      final ref = FirebaseStorage.instance.ref('product_images/$fileName');
      final uploadTask = await ref.putFile(imageFile);
      return await uploadTask.ref.getDownloadURL();
    } catch (e) {
      print('이미지 업로드 실패: $e');
      return null;
    }
  }

  Future<void> _pickNewImage() async {
    final XFile? picked = await _picker.pickImage(source: ImageSource.gallery);
    if (picked != null) {
      setState(() {
        _newImageFile = File(picked.path);
      });
    }
  }

  Future<void> _updateProduct() async {
    final name = nameController.text.trim();
    final price = int.tryParse(priceController.text.trim()) ?? 0;
    final description = descriptionController.text.trim();

    String finalImageUrl = imageUrl;
    if (_newImageFile != null) {
      final uploadedUrl = await _uploadImage(_newImageFile!);
      if (uploadedUrl != null) {
        finalImageUrl = uploadedUrl;
      }
    }

    await FirebaseFirestore.instance
        .collection('products')
        .doc(widget.product.id)
        .update({
      'name': name,
      'price': price,
      'description': description,
      'imageUrl': finalImageUrl,
      'updatetime': FieldValue.serverTimestamp(),
    });

    Navigator.pop(context, true); // 변경된 정보 알림
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Edit Product')),
      body: SingleChildScrollView(
        padding: const EdgeInsets.all(16),
        child: Column(
          children: [
            GestureDetector(
              onTap: _pickNewImage,
              child: _newImageFile != null
                  ? Image.file(_newImageFile!, height: 200, fit: BoxFit.contain)
                  : Image.network(imageUrl, height: 200, fit: BoxFit.contain),
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
              onPressed: _updateProduct,
              child: const Text('Update'),
            )
          ],
        ),
      ),
    );
  }
}
