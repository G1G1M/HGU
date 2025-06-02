import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:google_sign_in/google_sign_in.dart';
import 'package:cloud_firestore/cloud_firestore.dart';

class LoginPage extends StatelessWidget {
  const LoginPage({Key? key}) : super(key: key);

  // ✅ Firestore에 사용자 정보 저장
  Future<void> addUserToFirestore(User user, {String? statusMessage}) async {
    final CollectionReference users =
        FirebaseFirestore.instance.collection('user');
    final DocumentSnapshot snapshot = await users.doc(user.uid).get();

    if (!snapshot.exists) {
      final data = {
        'uid': user.uid,
        'status_message':
            statusMessage ?? 'I promise to take the test honestly before GOD.',
      };

      if (!user.isAnonymous) {
        data['name'] = user.displayName ?? '';
        data['email'] = user.email ?? '';
      }

      await users.doc(user.uid).set(data);
    }
  }

  // ✅ Google 로그인
  Future<void> _signInWithGoogle(BuildContext context) async {
    final GoogleSignInAccount? googleUser = await GoogleSignIn().signIn();
    final GoogleSignInAuthentication googleAuth =
        await googleUser!.authentication;

    final credential = GoogleAuthProvider.credential(
      accessToken: googleAuth.accessToken,
      idToken: googleAuth.idToken,
    );

    final result = await FirebaseAuth.instance.signInWithCredential(credential);
    await addUserToFirestore(result.user!);
    Navigator.pushReplacementNamed(context, '/home');
  }

  // ✅ 익명 로그인
  Future<void> _signInAnonymously(BuildContext context) async {
    final result = await FirebaseAuth.instance.signInAnonymously();
    await addUserToFirestore(result.user!);
    Navigator.pushReplacementNamed(context, '/home');
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: SafeArea(
        child: ListView(
          padding: const EdgeInsets.symmetric(horizontal: 24.0),
          children: <Widget>[
            const SizedBox(height: 80.0),
            Column(
              children: const [
                Image(image: AssetImage('assets/diamond.png')),
                SizedBox(height: 16.0),
                Text('SHRINE', style: TextStyle(fontSize: 24)),
              ],
            ),
            const SizedBox(height: 120.0),
            ElevatedButton.icon(
              icon: const Icon(Icons.login),
              label: const Text("Sign in with Google"),
              onPressed: () => _signInWithGoogle(context),
            ),
            const SizedBox(height: 12.0),
            ElevatedButton.icon(
              icon: const Icon(Icons.person_outline),
              label: const Text("Continue as Guest"),
              onPressed: () => _signInAnonymously(context),
            ),
          ],
        ),
      ),
    );
  }
}
