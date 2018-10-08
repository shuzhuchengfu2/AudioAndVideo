package com.ywl5320.jnithread;

/**
 * project:JniThread
 * author:xiongdejin
 * date:2018/10/8
 * time:15:41
 */
public class ThreadDemo {
    static {
        System.loadLibrary("native-lib");
    }

    public native void normalThread();
}
