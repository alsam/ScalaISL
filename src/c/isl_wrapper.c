#include <jni.h>
#include "isl/ctx.h"
#include "isl/val.h"
#include "isl_ISL.h"

JNIEXPORT jlong JNICALL Java_isl_ISL_createContext
(JNIEnv *env, jobject obj) {
    isl_ctx *ctx = isl_ctx_alloc();
    return (long)ctx;
}

JNIEXPORT void JNICALL Java_isl_ISL_releaseContext
  (JNIEnv *env, jobject obj, jlong lp) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_ctx_free(ctx);
}

JNIEXPORT jlong JNICALL Java_isl_ISL_valZero
(JNIEnv *env, jobject obj, jlong lp) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_val *val = isl_val_zero(ctx);
    return (long)val;
}

JNIEXPORT jlong JNICALL Java_isl_ISL_valOne
(JNIEnv *env, jobject obj, jlong lp) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_val *val = isl_val_one(ctx);
    return (long)val;
}

JNIEXPORT jlong JNICALL Java_isl_ISL_valNegOne
(JNIEnv *env, jobject obj, jlong lp) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_val *val = isl_val_negone(ctx);
    return (long)val;
}

JNIEXPORT jlong JNICALL Java_isl_ISL_valNan
(JNIEnv *env, jobject obj, jlong lp) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_val *val = isl_val_nan(ctx);
    return (long)val;
}

JNIEXPORT jlong JNICALL Java_isl_ISL_valInfty
(JNIEnv *env, jobject obj, jlong lp) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_val *val = isl_val_infty(ctx);
    return (long)val;
}

JNIEXPORT jlong JNICALL Java_isl_ISL_valNegInfty
(JNIEnv *env, jobject obj, jlong lp) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_val *val = isl_val_neginfty(ctx);
    return (long)val;
}

JNIEXPORT jboolean JNICALL Java_isl_ISL_valIsZero
(JNIEnv *env, jobject obj, jlong lp) {
    isl_val *val = (isl_val*)lp;
    jboolean result = (jboolean)isl_val_is_zero(val);
    return result;
}

JNIEXPORT jboolean JNICALL Java_isl_ISL_valIsOne
(JNIEnv *env, jobject obj, jlong lp) {
    isl_val *val = (isl_val*)lp;
    jboolean result = (jboolean)isl_val_is_one(val);
    return result;
}

