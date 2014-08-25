/* 
 * File:   JNIJWkLib.h
 * Author: dalmir
 *
 * Created on August 25, 2014, 2:11 PM
 */
#ifndef JNIJWKLIB_H
#define	JNIJWKLIB_H

#ifdef	__cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_jwk_JWk_convert(JNIEnv *env, jobject obj, jstring jsrc, jstring jdst);

#ifdef	__cplusplus
}
#endif

#endif	/* JNIJWKLIB_H */

