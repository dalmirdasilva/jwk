#include <jni.h>
#include <stdbool.h>
#include <stdio.h>
#include <wkhtmltox/pdf.h>
#include "JNIJWkLib.h"
#include "callback_attacher.h"

bool initialized = false;

void wkhtmltopdf_setup(wkhtmltopdf_global_settings** gs, wkhtmltopdf_object_settings** os, wkhtmltopdf_converter** c) {
    if (!initialized) {
        wkhtmltopdf_init(false);
        initialized = true;
    }
    *gs = wkhtmltopdf_create_global_settings();
    *os = wkhtmltopdf_create_object_settings();
    *c = wkhtmltopdf_create_converter(*gs);
}

JNIEXPORT void JNICALL Java_jwk_JWk_convertImp(JNIEnv *env, jobject obj, jstring jsrc, jstring jdst, jobject optionsMap, jobject optionsKeys) {
    
    //(*env)->MonitorEnter(env, obj);

    printf("%p\n", &obj);

    wkhtmltopdf_global_settings* gs;
    wkhtmltopdf_object_settings* os;
    wkhtmltopdf_converter* c;

    const char* src = (*env)->GetStringUTFChars(env, jsrc, NULL);
    const char* dst = (*env)->GetStringUTFChars(env, jdst, NULL);
    
    wkhtmltopdf_setup(&gs, &os, &c);
    wkhtmltopdf_attach_callbacks(env, &obj, &c);

    wkhtmltopdf_set_global_setting(gs, "out", dst);
    wkhtmltopdf_set_object_setting(os, "page", src);
    
    wkhtmltopdf_add_object(c, os, NULL);

    if (!wkhtmltopdf_convert(c)) {
        fprintf(stderr, "Convertion failed!");
    }
    printf("httpErrorCode: %d\n", wkhtmltopdf_http_error_code(c));

    wkhtmltopdf_destroy_converter(c);


    //wkhtmltopdf_deinit();

    //(*env)->MonitorExit(env, obj);
}

