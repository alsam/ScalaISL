#include <jni.h>
#include "isl/ctx.h"
#include "isl/val.h"
#include "isl/flow.h"
#include "isl/constraint.h"
#include "isl/set.h"
#include "isl/map.h"
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
 * Method:    valIsNegOne
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_isl_ISL_valIsNegOne
  (JNIEnv *env, jobject obj, jlong lp) {
    isl_val *val = (isl_val*)lp;
    jboolean result = (jboolean)isl_val_is_negone(val);
    return result;
}

/*
 * Class:     isl_ISL
 * Method:    valIsNan
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_isl_ISL_valIsNan
  (JNIEnv *env, jobject obj, jlong lp) {
    isl_val *val = (isl_val*)lp;
    jboolean result = (jboolean)isl_val_is_nan(val);
    return result;
}

/*
 * Class:     isl_ISL
 * Method:    valIsInfty
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_isl_ISL_valIsInfty
  (JNIEnv *env, jobject obj, jlong lp) {
    isl_val *val = (isl_val*)lp;
    jboolean result = (jboolean)isl_val_is_infty(val);
    return result;
}

/*
 * Class:     isl_ISL
 * Method:    valIsNegInfty
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_isl_ISL_valIsNegInfty
  (JNIEnv *env, jobject obj, jlong lp) {
    isl_val *val = (isl_val*)lp;
    jboolean result = (jboolean)isl_val_is_neginfty(val);
    return result;
}

/*
 * Class:     isl_ISL
 * Method:    valLT
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_isl_ISL_valLT
  (JNIEnv *env, jobject obj, jlong lp1, jlong lp2) {
    isl_val *val1 = isl_val_copy((isl_val*)lp1);
    isl_val *val2 = isl_val_copy((isl_val*)lp2);
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
    isl_val *val1 = isl_val_copy((isl_val*)lp1);
    isl_val *val2 = isl_val_copy((isl_val*)lp2);
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
    isl_val *val1 = isl_val_copy((isl_val*)lp1);
    isl_val *val2 = isl_val_copy((isl_val*)lp2);
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
    isl_val *val1 = isl_val_copy((isl_val*)lp1);
    isl_val *val2 = isl_val_copy((isl_val*)lp2);
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
    isl_val *val1 = isl_val_copy((isl_val*)lp1);
    isl_val *val2 = isl_val_copy((isl_val*)lp2);
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
    isl_val *val1 = isl_val_copy((isl_val*)lp1);
    isl_val *val2 = isl_val_copy((isl_val*)lp2);
    jboolean result = (jboolean)isl_val_ne(val1, val2);
    return result;
}

/*
 * Class:     isl_ISL
 * Method:    valAbs
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valAbs
  (JNIEnv *env, jobject obj, jlong lp) {
    isl_val *ival = isl_val_copy((isl_val*)lp);
    isl_val *oval = isl_val_abs(ival);
    return (long)oval;
}

/*
 * Class:     isl_ISL
 * Method:    valNeg
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valNeg
  (JNIEnv *env, jobject obj, jlong lp) {
    isl_val *ival = isl_val_copy((isl_val*)lp);
    isl_val *oval = isl_val_neg(ival);
    return (long)oval;
}

/*
 * Class:     isl_ISL
 * Method:    valFloor
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valFloor
  (JNIEnv *env, jobject obj, jlong lp) {
    isl_val *ival = isl_val_copy((isl_val*)lp);
    isl_val *oval = isl_val_floor(ival);
    return (long)oval;
}

/*
 * Class:     isl_ISL
 * Method:    valCeil
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valCeil
  (JNIEnv *env, jobject obj, jlong lp) {
    isl_val *ival = isl_val_copy((isl_val*)lp);
    isl_val *oval = isl_val_ceil(ival);
    return (long)oval;
}

/*
 * Class:     isl_ISL
 * Method:    valTrunc
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valTrunc
  (JNIEnv *env, jobject obj, jlong lp) {
    isl_val *ival = isl_val_copy((isl_val*)lp);
    isl_val *oval = isl_val_trunc(ival);
    return (long)oval;
}

/*
 * Class:     isl_ISL
 * Method:    val2Exp
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_val2Exp
  (JNIEnv *env, jobject obj, jlong lp) {
    isl_val *ival = isl_val_copy((isl_val*)lp);
    isl_val *oval = isl_val_2exp(ival);
    return (long)oval;
}

/*
 * Class:     isl_ISL
 * Method:    valMin
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valMin
  (JNIEnv *env, jobject obj, jlong lp1, jlong lp2) {
    isl_val *ival1 = isl_val_copy((isl_val*)lp1);
    isl_val *ival2 = isl_val_copy((isl_val*)lp2);
    isl_val *oval  = isl_val_min(ival1, ival2);
    return (long)oval;
}

/*
 * Class:     isl_ISL
 * Method:    valMax
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valMax
  (JNIEnv *env, jobject obj, jlong lp1, jlong lp2) {
    isl_val *ival1 = isl_val_copy((isl_val*)lp1);
    isl_val *ival2 = isl_val_copy((isl_val*)lp2);
    isl_val *oval  = isl_val_max(ival1, ival2);
    return (long)oval;
}

/*
 * Class:     isl_ISL
 * Method:    valAdd
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valAdd
  (JNIEnv *env, jobject obj, jlong lp1, jlong lp2) {
    isl_val *ival1 = isl_val_copy((isl_val*)lp1);
    isl_val *ival2 = isl_val_copy((isl_val*)lp2);
    isl_val *oval  = isl_val_add(ival1, ival2);
    return (long)oval;
}

/*
 * Class:     isl_ISL
 * Method:    valSub
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valSub
  (JNIEnv *env, jobject obj, jlong lp1, jlong lp2) {
    isl_val *ival1 = isl_val_copy((isl_val*)lp1);
    isl_val *ival2 = isl_val_copy((isl_val*)lp2);
    isl_val *oval  = isl_val_sub(ival1, ival2);
    return (long)oval;
}

/*
 * Class:     isl_ISL
 * Method:    valMul
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valMul
  (JNIEnv *env, jobject obj, jlong lp1, jlong lp2) {
    isl_val *ival1 = isl_val_copy((isl_val*)lp1);
    isl_val *ival2 = isl_val_copy((isl_val*)lp2);
    isl_val *oval  = isl_val_mul(ival1, ival2);
    return (long)oval;
}

/*
 * Class:     isl_ISL
 * Method:    valDiv
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_valDiv
  (JNIEnv *env, jobject obj, jlong lp1, jlong lp2) {
    isl_val *ival1 = isl_val_copy((isl_val*)lp1);
    isl_val *ival2 = isl_val_copy((isl_val*)lp2);
    isl_val *oval  = isl_val_div(ival1, ival2);
    return (long)oval;
}

/*
 * Class:     isl_ISL
 * Method:    printVal
 * Signature: (JJ)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_isl_ISL_printVal
  (JNIEnv *env, jobject obj, jlong lp) {
    isl_val *val = (isl_val*)lp;
    isl_ctx *ctx = isl_val_get_ctx(val);
    isl_printer *printer = isl_printer_to_str(ctx);
    printer = isl_printer_print_val(printer, val);
    const char *str = isl_printer_get_str(printer);
    jstring retval = (*env)->NewStringUTF(env, str);
    isl_printer_free(printer);
    return retval;
}

/*
 * Class:     isl_ISL
 * Method:    idAlloc
 * Signature: (JLjava/lang/String;J)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_idAlloc
  (JNIEnv *env, jobject obj, jlong lp1, jstring str, jlong lp2) {
    isl_ctx *ctx = (isl_ctx*)lp1;
    const char* name = (*env)->GetStringUTFChars(env, str, 0);
    void *user = (void*)lp2;
    isl_id *id = isl_id_alloc(ctx, name, user);
    return (long)id;
}

/*
 * Class:     isl_ISL
 * Method:    idGetName
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_isl_ISL_idGetName
  (JNIEnv *env, jobject obj, jlong lp) {
    isl_id *id = (isl_id*)lp;
    const char* name = isl_id_get_name(id);
    jstring retval = (*env)->NewStringUTF(env, name);
    return retval;
}

/*
 * Class:     isl_ISL
 * Method:    idGetUser
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_idGetUser
  (JNIEnv *env, jobject obj, jlong lp);

/*
 * Class:     isl_ISL
 * Method:    spaceAlloc
 * Signature: (JIII)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_spaceAlloc
  (JNIEnv *env, jobject obj, jlong lp, jint nparam, jint n_in, jint n_out) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_space *space = isl_space_alloc(ctx, nparam, n_in, n_out);
    return (long)space;
}

/*
 * Class:     isl_ISL
 * Method:    spaceSetAlloc
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_isl_ISL_spaceSetAlloc
  (JNIEnv *env, jobject obj, jlong lp, jint nparam, jint dim) {
    isl_ctx *ctx = (isl_ctx*)lp;
    isl_space *space = isl_space_set_alloc(ctx, nparam, dim);
    return (long)space;
}

