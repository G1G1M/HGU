import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'model/product.dart';

class WishlistProvider with ChangeNotifier {
  final Map<String, List<Product>> _userWishlists = {}; // uid -> wishlist

  String get _uid => FirebaseAuth.instance.currentUser?.uid ?? '';

  List<Product> get items => _userWishlists[_uid] ?? [];

  bool isInWishlist(Product product) {
    return items.any((item) => item.id == product.id);
  }

  void add(Product product) {
    final list = _userWishlists[_uid] ?? [];
    if (!list.any((item) => item.id == product.id)) {
      list.add(product);
      _userWishlists[_uid] = list;
      notifyListeners();
    }
  }

  void remove(Product product) {
    final list = _userWishlists[_uid];
    if (list != null) {
      list.removeWhere((item) => item.id == product.id);
      notifyListeners();
    }
  }

  void toggle(Product product) {
    isInWishlist(product) ? remove(product) : add(product);
  }

  bool contains(String productId) {
    return items.any((p) => p.id == productId);
  }
}
