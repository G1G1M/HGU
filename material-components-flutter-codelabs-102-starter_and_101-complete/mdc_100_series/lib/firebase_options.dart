import 'package:firebase_core/firebase_core.dart' show FirebaseOptions;
import 'package:flutter/foundation.dart'
    show defaultTargetPlatform, kIsWeb, TargetPlatform;

class DefaultFirebaseOptions {
  static FirebaseOptions get currentPlatform {
    if (kIsWeb) {
      return web;
    }
    switch (defaultTargetPlatform) {
      case TargetPlatform.android:
        return android;
      case TargetPlatform.iOS:
        return ios;
      case TargetPlatform.macOS:
        return macos;
      case TargetPlatform.windows:
        return windows;
      case TargetPlatform.linux:
        throw UnsupportedError(
          'DefaultFirebaseOptions have not been configured for linux - '
          'you can reconfigure this by running the FlutterFire CLI again.',
        );
      default:
        throw UnsupportedError(
          'DefaultFirebaseOptions are not supported for this platform.',
        );
    }
  }

  static const FirebaseOptions web = FirebaseOptions(
    apiKey: 'AIzaSyBXPFha48NuBiVSk707FhNUpEtBTHWeO0Y',
    appId: '1:120144823802:web:abad3bdaba5b8d0bff9043',
    messagingSenderId: '120144823802',
    projectId: 'final-69223',
    authDomain: 'final-69223.firebaseapp.com',
    storageBucket: 'final-69223.firebasestorage.app',
  );

  static const FirebaseOptions android = FirebaseOptions(
    apiKey: 'AIzaSyBliQJXwCBFAANfyA4VjM833CPdcKNrYAg',
    appId: '1:120144823802:android:cf0a20e4678ec0a5ff9043',
    messagingSenderId: '120144823802',
    projectId: 'final-69223',
    storageBucket: 'final-69223.firebasestorage.app',
  );

  static const FirebaseOptions ios = FirebaseOptions(
    apiKey: 'AIzaSyDd9eUP43Tdh3hUq7GUe-vVEPwov_URndw',
    appId: '1:120144823802:ios:dcd832c2179416d6ff9043',
    messagingSenderId: '120144823802',
    projectId: 'final-69223',
    storageBucket: 'final-69223.firebasestorage.app',
    iosClientId:
        '120144823802-gu0ps64g4kjb9tve7p4kqgni0vs9uald.apps.googleusercontent.com',
    iosBundleId: 'com.jiwonkim.flutterfinalapp',
  );

  static const FirebaseOptions macos = FirebaseOptions(
    apiKey: 'AIzaSyDd9eUP43Tdh3hUq7GUe-vVEPwov_URndw',
    appId: '1:120144823802:ios:8466a45b1b3f4d13ff9043',
    messagingSenderId: '120144823802',
    projectId: 'final-69223',
    storageBucket: 'final-69223.firebasestorage.app',
    iosClientId:
        '120144823802-a9oi60ktksje9h9ji7cl8p7j1t78udiv.apps.googleusercontent.com',
    iosBundleId: 'com.example.mdc100Series',
  );

  static const FirebaseOptions windows = FirebaseOptions(
    apiKey: 'AIzaSyBXPFha48NuBiVSk707FhNUpEtBTHWeO0Y',
    appId: '1:120144823802:web:0add0a6ab50645e0ff9043',
    messagingSenderId: '120144823802',
    projectId: 'final-69223',
    authDomain: 'final-69223.firebaseapp.com',
    storageBucket: 'final-69223.firebasestorage.app',
  );
}
