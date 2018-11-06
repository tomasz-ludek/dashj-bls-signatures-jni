#include "org_dash_bls_DashBlsJni.h"
#include <iostream>
#include "bls.hpp"

JNIEXPORT jlong JNICALL Java_org_dash_bls_DashBlsJni_publicKeyFingerprint
(JNIEnv* env, jobject thisObject, jintArray jseed) {

    jsize seed_len = env->GetArrayLength(jseed);
    jint* jseedbody = env->GetIntArrayElements(jseed, 0);

    uint8_t seed[seed_len];
    for (int i = 0; i < seed_len; i++) {
        seed[i] = jseedbody[i];
    }

    bls::PrivateKey sk = bls::PrivateKey::FromSeed(seed, sizeof (seed));

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

    bls::PrivateKey sk = bls::PrivateKey::FromSeed(seed, sizeof (seed));
    std::vector<uint8_t> skbytes = sk.Serialize();
    std::cout << "native priv:\t{";
    for (int i = 0; i < skbytes.size(); i++) {
        std::cout << (int) skbytes[i] << ", ";
    }
    std::cout << "}" << std::endl;

    uint8_t msg[] = {100, 2, 254, 88, 90, 45, 23};

    std::cout << "native msg: \t{";
    for (int i = 0; i<sizeof (msg); i++) {
        std::cout << (int) msg[i] << ", ";
    }
    std::cout << "}" << std::endl;

    bls::Signature sig = sk.Sign(msg, sizeof (msg));
    std::vector<uint8_t> v = sig.Serialize();
    std::cout << "native sign:\t{";
    for (int i = 0; i < v.size(); i++) {
        std::cout << (int) v[i] << ", ";
    }
    std::cout << "}" << std::endl;
}

JNIEXPORT jbyteArray JNICALL Java_org_dash_bls_DashBlsJni_generatePrivateKey
(JNIEnv* env, jobject thisObject, jintArray jseed) {

    jsize seed_len = env->GetArrayLength(jseed);
    jint* jseedbody = env->GetIntArrayElements(jseed, 0);

    uint8_t seed[seed_len];
    for (int i = 0; i < seed_len; i++) {
        seed[i] = jseedbody[i];
    }

    bls::PrivateKey sk = bls::PrivateKey::FromSeed(seed, sizeof (seed));

    uint8_t skBytes[bls::PrivateKey::PRIVATE_KEY_SIZE];
    sk.Serialize(skBytes);

    jbyteArray resSkBytes = env->NewByteArray(sizeof (skBytes));
    env->SetByteArrayRegion(resSkBytes, 0, sizeof (skBytes), (jbyte*) skBytes);

    env->ReleasePrimitiveArrayCritical(resSkBytes, skBytes, 0);

    return resSkBytes;
}

JNIEXPORT jbyteArray JNICALL Java_org_dash_bls_DashBlsJni_generatePublicKey
(JNIEnv* env, jobject thisObject, jbyteArray jprivateKey) {

    jsize len = env->GetArrayLength(jprivateKey);
    jbyte* jprivateKeyBody = env->GetByteArrayElements(jprivateKey, 0);

    uint8_t privateKeyBody[len];
    for (int i = 0; i < len; i++) {
        privateKeyBody[i] = jprivateKeyBody[i];
    }

    bls::PrivateKey sk = bls::PrivateKey::FromBytes(privateKeyBody, 0);
    bls::PublicKey pk = sk.GetPublicKey();

    uint8_t pkBytes[bls::PublicKey::PUBLIC_KEY_SIZE];
    pk.Serialize(pkBytes);

    jbyteArray resPkBytes = env->NewByteArray(sizeof (pkBytes));
    env->SetByteArrayRegion(resPkBytes, 0, sizeof (pkBytes), (jbyte*) pkBytes);

    env->ReleasePrimitiveArrayCritical(resPkBytes, pkBytes, 0);

    return resPkBytes;
}

JNIEXPORT jbyteArray JNICALL Java_org_dash_bls_DashBlsJni_signMessage
(JNIEnv* env, jobject thisObject, jbyteArray jPrivateKey, jintArray jMsg) {

    jsize skLength = env->GetArrayLength(jPrivateKey);
    jbyte* jskBody = env->GetByteArrayElements(jPrivateKey, 0);

    uint8_t skBytesBody[skLength];
    for (int i = 0; i < skLength; i++) {
        skBytesBody[i] = jskBody[i];
    }

    bls::PrivateKey sk = bls::PrivateKey::FromBytes(skBytesBody, 0);

    uint8_t skBytes[bls::PrivateKey::PRIVATE_KEY_SIZE];
    sk.Serialize(skBytes);
    std::cout << "java priv:  \t{";
    for (int i = 0; i < sizeof (skBytes); i++) {
        std::cout << (int) skBytes[i] << ", ";
    }
    std::cout << "}" << std::endl;

    jsize msgLen = env->GetArrayLength(jMsg);
    jint* jmsgBody = env->GetIntArrayElements(jMsg, 0);

    uint8_t msgBytes[msgLen];
    std::cout << "java msg:   \t{";
    for (int i = 0; i < msgLen; i++) {
        msgBytes[i] = jmsgBody[i];
        std::cout << (int) msgBytes[i] << ", ";
    }
    std::cout << "}" << std::endl;

    bls::Signature sig = sk.Sign(msgBytes, msgLen);

    uint8_t sigBytes[bls::Signature::SIGNATURE_SIZE];
    sig.Serialize(sigBytes);

    jbyteArray resSigBytes = env->NewByteArray(sizeof (sigBytes));
    env->SetByteArrayRegion(resSigBytes, 0, sizeof (sigBytes), (jbyte*) sigBytes);

    env->ReleasePrimitiveArrayCritical(resSigBytes, sigBytes, 0);

    return resSigBytes;
}
