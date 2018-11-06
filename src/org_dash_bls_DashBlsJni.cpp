#include "org_dash_bls_DashBlsJni.h"
#include <iostream>
#include "bls.hpp"

JNIEXPORT jlong JNICALL Java_org_dash_bls_DashBlsJni_publicKeyFingerprint
  (JNIEnv* env, jobject thisObject, jintArray jseed) {
    
    jsize seed_len = env->GetArrayLength(jseed);
    jint* jseedbody = env->GetIntArrayElements(jseed, 0);
    
    uint8_t seed[seed_len];
    for (int i=0; i<seed_len; i++) {
        seed[i] = jseedbody[i];
    }
    
    bls::PrivateKey sk = bls::PrivateKey::FromSeed(seed, sizeof(seed));
    
    bls::PublicKey pk = sk.GetPublicKey();
    std::cout << "Fingerprint (native/java):\t" << pk.GetFingerprint() << std::endl;
    
    env->ReleaseIntArrayElements(jseed, jseedbody, 0);
    
    return pk.GetFingerprint();
}

JNIEXPORT void JNICALL Java_org_dash_bls_DashBlsJni_nativeSignMessage
  (JNIEnv* env, jobject thisObject) {

    uint8_t seed[] = {0, 50, 6, 244, 24, 199, 1, 25, 52, 88, 192,
                      19, 18, 12, 89, 6, 220, 18, 102, 58, 209,
                      82, 12, 62, 89, 110, 182, 9, 44, 20, 254, 22};
    
    bls::PrivateKey sk = bls::PrivateKey::FromSeed(seed, sizeof(seed));
    std::vector<uint8_t> skbytes = sk.Serialize();
    std::cout << "native priv:\t{";
    for(int i=0; i<skbytes.size(); i++) {
        std::cout << (int)skbytes[i] << ", ";
    }
    std::cout << "}" << std::endl;
    
    uint8_t msg[] = {100, 2, 254, 88, 90, 45, 23};
    
    std::cout << "native msg: \t{";
    for(int i=0; i<sizeof(msg); i++) {
        std::cout << (int)msg[i] << ", ";
    }
    std::cout << "}" << std::endl;
    
    bls::Signature sig = sk.Sign(msg, sizeof(msg));
    std::vector<uint8_t> v = sig.Serialize();
    std::cout << "native sign:\t{";
    for(int i=0; i<v.size(); i++) {
        std::cout << (int)v[i] << ", ";
    }
    std::cout << "}" << std::endl;
}

JNIEXPORT jbyteArray JNICALL Java_org_dash_bls_DashBlsJni_generatePrivateKey
  (JNIEnv* env, jobject thisObject, jintArray jseed) {
    
    jsize seed_len = env->GetArrayLength(jseed);
    jint* jseedbody = env->GetIntArrayElements(jseed, 0);
    
    uint8_t seed[seed_len];
    for (int i=0; i<seed_len; i++) {
        seed[i] = jseedbody[i];
    }
    
    bls::PrivateKey sk = bls::PrivateKey::FromSeed(seed, sizeof(seed));
    std::vector<uint8_t> v = sk.Serialize();
    
    jbyteArray array = env->NewByteArray(v.size());
    env->SetByteArrayRegion(array, 0, v.size(), reinterpret_cast<const jbyte*>(v.data()));
    //void* temp = env->GetPrimitiveArrayCritical(array, 0);
    //memcpy(temp, v.data(), v.size());
    
    //env->ReleasePrimitiveArrayCritical(array, temp, 0);
    
    return array;
}

JNIEXPORT jbyteArray JNICALL Java_org_dash_bls_DashBlsJni_generatePublicKey
  (JNIEnv* env, jobject thisObject, jbyteArray jprivateKey) {
    
    jsize len = env->GetArrayLength(jprivateKey);
    jbyte* jprivateKeyBody = env->GetByteArrayElements(jprivateKey, 0);
    
    uint8_t privateKeyBody[len];
    for (int i=0; i<len; i++) {
        privateKeyBody[i] = jprivateKeyBody[i];
    }
    
    bls::PrivateKey sk = bls::PrivateKey::FromBytes(privateKeyBody, 0);
    bls::PublicKey pk = sk.GetPublicKey();
    std::vector<uint8_t> v = pk.Serialize();
    
    jbyteArray array = env->NewByteArray(v.size());
    env->SetByteArrayRegion(array, 0, v.size(), reinterpret_cast<const jbyte*>(v.data()));
    //void* temp = env->GetPrimitiveArrayCritical(array, 0);
    //memcpy(temp, v.data(), v.size());
    
    //env->ReleaseByteArrayCritical(array, v, 0);
    
    return array;
}

JNIEXPORT jbyteArray JNICALL Java_org_dash_bls_DashBlsJni_signMessage
  (JNIEnv* env, jobject thisObject, jbyteArray jprivateKey, jintArray jMsg) {
    
    jsize len = env->GetArrayLength(jprivateKey);
    jbyte* jprivateKeyBody = env->GetByteArrayElements(jprivateKey, 0);
    
    uint8_t privateKeyBody[len];
    for (int i=0; i<len; i++) {
        privateKeyBody[i] = jprivateKeyBody[i];
    }
    
    bls::PrivateKey sk = bls::PrivateKey::FromBytes(privateKeyBody, 0);
    std::vector<uint8_t> skbytes = sk.Serialize();
    std::cout << "java priv:  \t{";
    for(int i=0; i<skbytes.size(); i++) {
        std::cout << (int)skbytes[i] << ", ";
    }
    std::cout << "}" << std::endl;
    
    jsize msg_len = env->GetArrayLength(jMsg);
    jint* jmsgBody = env->GetIntArrayElements(jMsg, 0);
    
    uint8_t msg[msg_len];
    std::cout << "java msg:   \t{";
    for (int i=0; i<msg_len; i++) {
        msg[i] = jmsgBody[i];
        std::cout << (int)msg[i] << ", ";
    }
    std::cout << "}" << std::endl;
    
    bls::Signature sign = sk.Sign(msg, msg_len);
    std::vector<uint8_t> v = sign.Serialize();
    
    jbyteArray array = env->NewByteArray(v.size());
    env->SetByteArrayRegion(array, 0, v.size(), reinterpret_cast<const jbyte*>(v.data()));
    //void* temp = env->GetPrimitiveArrayCritical(array, 0);
    //memcpy(temp, v.data(), v.size());
    
    //env->ReleaseByteArrayCritical(array, v, 0);
    
    return array;
}