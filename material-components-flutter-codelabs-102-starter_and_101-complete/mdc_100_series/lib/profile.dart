import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';

class ProfilePage extends StatelessWidget {
  const ProfilePage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final user = FirebaseAuth.instance.currentUser;
    final isAnonymous = user?.isAnonymous ?? true;

    final String profileImage = isAnonymous
        ? 'http://handong.edu/site/handong/res/img/logo.png'
        : user?.photoURL ?? 'http://handong.edu/site/handong/res/img/logo.png';

    final String displayName =
        isAnonymous ? 'Anonymous' : (user?.displayName ?? 'No Name');

    final String email = isAnonymous ? 'Anonymous' : (user?.email ?? '');

    return Scaffold(
      appBar: AppBar(
        title: const Text('Profile'),
        actions: [
          IconButton(
            icon: const Icon(Icons.exit_to_app),
            onPressed: () async {
              await FirebaseAuth.instance.signOut();
              Navigator.pushReplacementNamed(context, '/login');
            },
          )
        ],
      ),
      body: Padding(
        padding: const EdgeInsets.all(24.0),
        child: Column(
          children: [
            // ✅ 프로필 이미지
            CircleAvatar(
              radius: 60,
              backgroundImage: NetworkImage(profileImage),
              backgroundColor: Colors.grey[200],
            ),
            const SizedBox(height: 24),
            // ✅ UID & Email
            Text('UID: ${user?.uid}', style: const TextStyle(fontSize: 14)),
            Text('Email: $email', style: const TextStyle(fontSize: 14)),
            const SizedBox(height: 24),
            // ✅ 사용자 이름 (서명)
            Text(
              'Jiwon Kim', // ← 원하는 이름으로 바꾸세요
              style: const TextStyle(
                fontSize: 18,
                fontWeight: FontWeight.bold,
              ),
            ),
            const SizedBox(height: 12),
            // ✅ Honor Code
            const Text(
              'I promise to take the test honestly before GOD.',
              textAlign: TextAlign.center,
              style: TextStyle(
                fontSize: 16,
                color: Colors.black87,
                fontStyle: FontStyle.italic,
              ),
            ),
          ],
        ),
      ),
    );
  }
}
