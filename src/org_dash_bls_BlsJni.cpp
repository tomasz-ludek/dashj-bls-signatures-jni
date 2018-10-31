#include "org_dash_bls_BlsJni.h"

JNIEXPORT void JNICALL Java_org_dash_bls_DashBlsJni_callBls
  (JNIEnv* env, jobject thisObject) {
    std::cout << "callBls" << std::endl;
    uint8_t seed[] = {0, 50, 6, 244, 24, 199, 1, 25, 52, 88, 192,
                      19, 18, 12, 89, 6, 220, 18, 102, 58, 209,
                      82, 12, 62, 89, 110, 182, 9, 44, 20, 254, 22};

    bls::PrivateKey sk = bls::PrivateKey::FromSeed(seed, sizeof(seed));
    bls::PublicKey pk = sk.GetPublicKey();
	std::cout << "Fingerprint: " << pk.GetFingerprint() << std::endl;
  }

JNIEXPORT jlong JNICALL Java_org_dash_bls_DashBlsJni_sumIntegers
  (JNIEnv* env, jobject thisObject, jint first, jint second) {
    std::cout << "C++: The numbers received are : " << first << " and " << second << std::endl;
    return (long)first + (long)second;
}

JNIEXPORT jstring JNICALL Java_org_dash_bls_DashBlsJni_sayHelloToMe
  (JNIEnv* env, jobject thisObject, jstring name, jboolean isFemale) {
    const char* nameCharPointer = env->GetStringUTFChars(name, NULL);
    
    std::string title;
    if(isFemale) {
        title = "Ms. ";
    } else {
        title = "Mr. ";
    }
    
    std::string fullName = title + nameCharPointer;
    return env->NewStringUTF(fullName.c_str());
}
