import 'package:cloud_firestore/cloud_firestore.dart';
import 'product.dart';

class ProductsRepository {
  static Future<List<Product>> loadProducts({String sort = 'asc'}) async {
    final query = FirebaseFirestore.instance
        .collection('products')
        .orderBy('price', descending: sort == 'desc'); // 가격 기준 정렬

    final snapshot = await query.get();

    return snapshot.docs
        .map((doc) => Product.fromMap(doc.id, doc.data()))
        .toList();
  }
}
