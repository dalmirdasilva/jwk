/* 
 * File:   JNIJWkLib.h
 * Author: dalmir
 *
 * Created on August 25, 2014, 6:01 PM
 */

#ifndef JNIJWKLIB_H
#define	JNIJWKLIB_H

#ifdef	__cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_jwk_JWk_convertImp(JNIEnv *env, jobject obj, jstring jsrc, jstring jdst, jobject optionsMap, jobject optionsKeys);

#ifdef	__cplusplus
}
#endif

#endif	/* JNIJWKLIB_H */

