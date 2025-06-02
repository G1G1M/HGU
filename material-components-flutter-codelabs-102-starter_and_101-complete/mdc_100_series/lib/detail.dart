import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_storage/firebase_storage.dart';
import 'package:provider/provider.dart';

import 'model/product.dart';
import 'editproduct.dart';
import 'wishlist_provider.dart';

class DetailPage extends StatefulWidget {
  final String productId;
  const DetailPage({required this.productId, Key? key}) : super(key: key);

  @override
  State<DetailPage> createState() => _DetailPageState();
}

class _DetailPageState extends State<DetailPage> {
  late Future<Product> _futureProduct;
  final currentUser = FirebaseAuth.instance.currentUser;

  @override
  void initState() {
    super.initState();
    _futureProduct = _loadProduct();
  }

  Future<Product> _loadProduct() async {
    final snapshot = await FirebaseFirestore.instance
        .collection('products')
        .doc(widget.productId)
        .get();

    if (!snapshot.exists) {
      throw Exception('상품이 존재하지 않습니다.');
    }

    return Product.fromMap(
        snapshot.id, snapshot.data() as Map<String, dynamic>);
  }

  void _refreshProduct() {
    setState(() {
      _futureProduct = _loadProduct();
    });
  }

  Future<void> _toggleLike(Product product) async {
    final uid = currentUser?.uid;
    if (uid == null) return;

    final docRef =
        FirebaseFirestore.instance.collection('products').doc(product.id);

    final isLiked = product.likedBy.contains(uid);

    if (isLiked) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('이미 좋아요를 누른 상품입니다.')),
      );
      return;
    }

    await docRef.update({
      'likeCount': FieldValue.increment(1),
      'likedBy': FieldValue.arrayUnion([uid]),
    });

    _refreshProduct();
  }

  @override
  Widget build(BuildContext context) {
    final formatter = NumberFormat.simpleCurrency(locale: 'ko_KR', name: 'KRW');

    return FutureBuilder<Product>(
      future: _futureProduct,
      builder: (context, snapshot) {
        if (snapshot.connectionState == ConnectionState.waiting) {
          return const Scaffold(
              body: Center(child: CircularProgressIndicator()));
        }

        if (!snapshot.hasData || snapshot.hasError) {
          return const Scaffold(
              body: Center(child: Text('상품 정보를 불러올 수 없습니다.')));
        }

        final product = snapshot.data!;
        final isOwner = currentUser?.uid == product.uid;
        final isLiked = product.likedBy.contains(currentUser?.uid);

        final wishlistProvider = Provider.of<WishlistProvider>(context);
        final isInWishlist = wishlistProvider.contains(product.id);

        return Scaffold(
          appBar: AppBar(
            centerTitle: true,
            title: const Text('Detail'),
            actions: [
              if (isOwner) ...[
                IconButton(
                  icon: const Icon(Icons.create),
                  onPressed: () async {
                    final result = await Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (_) => EditProductPage(product: product),
                      ),
                    );
                    if (result == true) {
                      Navigator.pop(context, true);
                    }
                  },
                ),
                IconButton(
                  icon: const Icon(Icons.delete),
                  onPressed: () async {
                    final confirm = await showDialog<bool>(
                      context: context,
                      builder: (_) => AlertDialog(
                        title: const Text('삭제'),
                        content: const Text('정말 삭제하시겠습니까?'),
                        actions: [
                          TextButton(
                            onPressed: () => Navigator.pop(context, false),
                            child: const Text('취소'),
                          ),
                          TextButton(
                            onPressed: () => Navigator.pop(context, true),
                            child: const Text('삭제'),
                          ),
                        ],
                      ),
                    );
                    if (confirm == true) {
                      if (!product.imageUrl.contains('handong.edu')) {
                        try {
                          final ref = FirebaseStorage.instance
                              .refFromURL(product.imageUrl);
                          await ref.delete();
                        } catch (e) {
                          print('Storage 이미지 삭제 오류: $e');
                        }
                      }

                      await FirebaseFirestore.instance
                          .collection('products')
                          .doc(product.id)
                          .delete();

                      Navigator.pop(context, true);
                    }
                  },
                ),
              ],
            ],
          ),
          floatingActionButton: FloatingActionButton(
            onPressed: () {
              if (isInWishlist) {
                wishlistProvider.remove(product);
              } else {
                wishlistProvider.add(product);
              }
              setState(() {});
            },
            child: Icon(
              isInWishlist ? Icons.check : Icons.shopping_cart,
            ),
          ),
          body: ListView(
            padding: const EdgeInsets.all(16.0),
            children: [
              Image.network(
                product.imageUrl,
                height: 250,
                fit: BoxFit.contain,
                errorBuilder: (_, __, ___) => const Icon(Icons.broken_image),
              ),
              const SizedBox(height: 16),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  Expanded(
                    child: Text(
                      product.name,
                      style: Theme.of(context).textTheme.headlineSmall,
                      overflow: TextOverflow.ellipsis,
                    ),
                  ),
                  IconButton(
                    icon: Icon(
                      isLiked ? Icons.favorite : Icons.favorite_border,
                      color: Colors.red,
                    ),
                    onPressed: () => _toggleLike(product),
                  ),
                ],
              ),
              const SizedBox(height: 8),
              Text(formatter.format(product.price),
                  style: Theme.of(context).textTheme.titleMedium),
              const SizedBox(height: 16),
              Text(product.description),
              const Divider(height: 32),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  Text('creator : ${product.uid}',
                      style: const TextStyle(color: Colors.grey)),
                  Text('❤️ ${product.likeCount}'),
                ],
              ),
              const SizedBox(height: 4),
              Text(
                  '${DateFormat('yyyy-MM-dd HH:mm').format(product.createtime)} Created'),
              Text(
                  '${DateFormat('yyyy-MM-dd HH:mm').format(product.updatetime)} Modified'),
            ],
          ),
        );
      },
    );
  }
}
