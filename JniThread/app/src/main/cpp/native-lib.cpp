#include <jni.h>
#include <string>
#include "pthread.h"
#include "AndroidLog.h"


pthread_t thread;

void *normalCallback(void *data) {
    LOGI("create normal thread from C++")
    pthread_exit(&thread);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ywl5320_jnithread_ThreadDemo_normalThread(JNIEnv *env, jobject instance) {
    // 创建一个普通线程
    pthread_create(&thread, NULL, normalCallback, NULL);
}