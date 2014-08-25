/* 
 * File:   callback_attacher.h
 * Author: dalmir
 *
 * Created on August 25, 2014, 5:34 PM
 */

#ifndef CALLBACK_ATTACHER_H
#define	CALLBACK_ATTACHER_H

#ifdef	__cplusplus
extern "C" {
#endif

void wkhtmltopdf_attach_callbacks(JNIEnv *env, jobject obj, wkhtmltopdf_converter** c);

#ifdef	__cplusplus
}
#endif

#endif	/* CALLBACK_ATTACHER_H */

