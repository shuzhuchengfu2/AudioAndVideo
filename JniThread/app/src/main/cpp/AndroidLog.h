//
// Created by zhangyimin on 2018/10/8.
//

#ifndef JNITHREAD_ANDROIDLOG_H
#define JNITHREAD_ANDROIDLOG_H

#endif //JNITHREAD_ANDROIDLOG_H

#include "android/log.h"

#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"ywl5320",FORMAT,##__VA_ARGS__);