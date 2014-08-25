#include <stdio.h>
#include <wkhtmltox/pdf.h>
#include "callback_attacher.h"

#define DEBUG

#ifdef DEBUG
void progress_changed(wkhtmltopdf_converter* c, int p) {
    printf("%3d%%\r", p);
    fflush(stdout);
}

void phase_changed(wkhtmltopdf_converter * c) {
    int phase = wkhtmltopdf_current_phase(c);
    printf("%s\n", wkhtmltopdf_phase_description(c, phase));
}

void error(wkhtmltopdf_converter * c, const char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
}

void warning(wkhtmltopdf_converter * c, const char* msg) {
    fprintf(stderr, "Warning: %s\n", msg);
}
#endif

void wkhtmltopdf_attach_callbacks(JNIEnv *env, jobject obj, wkhtmltopdf_converter** c) {
#ifdef DEBUG
    wkhtmltopdf_set_progress_changed_callback(*c, progress_changed);
    wkhtmltopdf_set_phase_changed_callback(*c, phase_changed);
    wkhtmltopdf_set_error_callback(*c, error);
    wkhtmltopdf_set_warning_callback(*c, warning);
#endif
}
