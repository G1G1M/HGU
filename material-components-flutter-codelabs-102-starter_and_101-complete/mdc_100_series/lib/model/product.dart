import 'package:cloud_firestore/cloud_firestore.dart';

class Product {
  final String id;
  final String name;
  final double price;
  final String imageUrl;
  final String description;
  final String uid;
  final DateTime createtime;
  final DateTime updatetime;
  final int likeCount;
  final List<String> likedBy;

  Product({
    required this.id,
    required this.name,
    required this.price,
    required this.imageUrl,
    required this.description,
    required this.uid,
    required this.createtime,
    required this.updatetime,
    required this.likeCount,
    required this.likedBy,
  });

  factory Product.fromMap(String id, Map<String, dynamic> data) {
    return Product(
      id: id,
      name: data['name'] ?? '',
      price: (data['price'] ?? 0).toDouble(),
      imageUrl: data['imageUrl'] ?? '',
      description: data['description'] ?? '',
      uid: data['uid'] ?? '',
      createtime:
          (data['createtime'] as Timestamp?)?.toDate() ?? DateTime.now(),
      updatetime:
          (data['updatetime'] as Timestamp?)?.toDate() ?? DateTime.now(),
      likeCount: data['likeCount'] ?? 0,
      likedBy: List<String>.from(data['likedBy'] ?? []),
    );
  }
}
