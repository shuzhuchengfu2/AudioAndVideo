#include <jni.h>
#include <string>
#include "pthread.h"
#include "AndroidLog.h"
#include "queue"
#include "unistd.h"


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

pthread_t produc;
pthread_t cust;
pthread_mutex_t mutex;
pthread_cond_t cond;
std::queue<int> queue;
bool exit = false;

void *producCallback(void *data) {
    // 生产
    while (exit) {
        pthread_mutex_lock(&mutex);
        queue.push(1);
        LOGI("[生产者] 生产了一个产品，通知消费者，产品数量为%d", queue.size());
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(5);
    }
}

void *custCallback(void *data) {
    // 消费
    while (exit) {
        pthread_mutex_lock(&mutex);
        if (queue.size() > 0) {
            queue.pop();
            LOGI("[消费者] 消费了一个产品，产品数量为%d", queue.size());
        } else {
            LOGI("[消费者] 当前没有产品可以消费了,等待中...");
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
        usleep(1000 * 500);
    }

}

extern "C"
JNIEXPORT void JNICALL
Java_com_ywl5320_jnithread_ThreadDemo_mutexThread(JNIEnv *env, jobject instance) {
    exit = !exit;

    for (int i = 0; i < 10; i++) {
        queue.push(i);
    }

    // 初始化
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    pthread_create(&produc, NULL, producCallback, NULL);
    pthread_create(&cust, NULL, custCallback, NULL);

    if(!exit){
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    }
}