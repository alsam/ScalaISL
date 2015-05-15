#include <jni.h>
#include "isl/ctx.h"
#include "isl/val.h"
#include "isl_ISL.h"

/*
 * Class:     isl_ISL
 * Method:    createContext
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_createContext
(JNIEnv *env, jobject obj) {
    isl_ctx *ctx = isl_ctx_alloc();
    return (long)ctx;
}

/*
 * Class:     isl_ISL
 * Method:    releaseContext
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_isl_ISL_releaseContext
  (JNIEnv *env, jobject obj, jlong lp) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_ctx_free(ctx);
}

/*
 * Class:     isl_ISL
 * Method:    valZero
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valZero
(JNIEnv *env, jobject obj, jlong lp) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_val *val = isl_val_zero(ctx);
    return (long)val;
}

/*
 * Class:     isl_ISL
 * Method:    valOne
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valOne
(JNIEnv *env, jobject obj, jlong lp) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_val *val = isl_val_one(ctx);
    return (long)val;
}

/*
 * Class:     isl_ISL
 * Method:    valNegOne
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valNegOne
(JNIEnv *env, jobject obj, jlong lp) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_val *val = isl_val_negone(ctx);
    return (long)val;
}

/*
 * Class:     isl_ISL
 * Method:    valNan
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valNan
(JNIEnv *env, jobject obj, jlong lp) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_val *val = isl_val_nan(ctx);
    return (long)val;
}

/*
 * Class:     isl_ISL
 * Method:    valInfty
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valInfty
(JNIEnv *env, jobject obj, jlong lp) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_val *val = isl_val_infty(ctx);
    return (long)val;
}

/*
 * Class:     isl_ISL
 * Method:    valNegInfty
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valNegInfty
(JNIEnv *env, jobject obj, jlong lp) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_val *val = isl_val_neginfty(ctx);
    return (long)val;
}

/*
 * Class:     isl_ISL
 * Method:    valIsZero
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_isl_ISL_valIsZero
(JNIEnv *env, jobject obj, jlong lp) {
    isl_val *val = (isl_val*)lp;
    jboolean result = (jboolean)isl_val_is_zero(val);
    return result;
}

/*
 * Class:     isl_ISL
 * Method:    valIsOne
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_isl_ISL_valIsOne
(JNIEnv *env, jobject obj, jlong lp) {
    isl_val *val = (isl_val*)lp;
    jboolean result = (jboolean)isl_val_is_one(val);
    return result;
}

/*
 * Class:     isl_ISL
 * Method:    valLT
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_isl_ISL_valLT
  (JNIEnv *env, jobject obj, jlong lp1, jlong lp2) {
    isl_val *val1 = (isl_val*)lp1;
    isl_val *val2 = (isl_val*)lp2;
    jboolean result = (jboolean)isl_val_lt(val1, val2);
    return result;
}

/*
 * Class:     isl_ISL
 * Method:    valLE
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_isl_ISL_valLE
  (JNIEnv *env, jobject obj, jlong lp1, jlong lp2) {
    isl_val *val1 = (isl_val*)lp1;
    isl_val *val2 = (isl_val*)lp2;
    jboolean result = (jboolean)isl_val_le(val1, val2);
    return result;
}

/*
 * Class:     isl_ISL
 * Method:    valGT
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_isl_ISL_valGT
  (JNIEnv *env, jobject obj, jlong lp1, jlong lp2) {
    isl_val *val1 = (isl_val*)lp1;
    isl_val *val2 = (isl_val*)lp2;
    jboolean result = (jboolean)isl_val_gt(val1, val2);
    return result;
}

/*
 * Class:     isl_ISL
 * Method:    valGE
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_isl_ISL_valGE
  (JNIEnv *env, jobject obj, jlong lp1, jlong lp2) {
    isl_val *val1 = (isl_val*)lp1;
    isl_val *val2 = (isl_val*)lp2;
    jboolean result = (jboolean)isl_val_ge(val1, val2);
    return result;
}

/*
 * Class:     isl_ISL
 * Method:    valEQ
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_isl_ISL_valEQ
  (JNIEnv *env, jobject obj, jlong lp1, jlong lp2) {
    isl_val *val1 = (isl_val*)lp1;
    isl_val *val2 = (isl_val*)lp2;
    jboolean result = (jboolean)isl_val_eq(val1, val2);
    return result;
}

/*
 * Class:     isl_ISL
 * Method:    valNE
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_isl_ISL_valNE
  (JNIEnv *env, jobject obj, jlong lp1, jlong lp2) {
    isl_val *val1 = (isl_val*)lp1;
    isl_val *val2 = (isl_val*)lp2;
    jboolean result = (jboolean)isl_val_ne(val1, val2);
    return result;
}

