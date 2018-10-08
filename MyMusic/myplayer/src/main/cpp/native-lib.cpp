#include <jni.h>
#include <string>
#include "android/log.h"

extern "C" {
#include <libavformat/avformat.h>
}


#define LOGI(FORMAT, ...)__android_log_print(ANDROID_LOG_INFO,"ywl5320",FORMAT,##__VA_ARGS__);

extern "C"
JNIEXPORT void JNICALL
Java_com_ywl5320_myplayer_Demo_sestFfmpeg(JNIEnv *env, jobject instance) {
    av_register_all();
    AVCodec *c_temp = av_codec_next(NULL);
    while (c_temp != NULL) {
        switch (c_temp->type) {
            case AVMEDIA_TYPE_VIDEO:
                LOGI("[Video]:%s", c_temp->name)
                break;
            case AVMEDIA_TYPE_AUDIO:
                LOGI("[Audio]:%s", c_temp->name)
                break;
            default:
                LOGI("[Other]:%s", c_temp->name)
                break;
        }
        c_temp = c_temp->next;
    }
}