package com.ywl5320.myplayer;

/**
 * project:MyMusic
 * author:xiongdejin
 * date:2018/10/8
 * time:13:24
 */
public class Demo {
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("avcodec-57");
        System.loadLibrary("avdevice-57");
        System.loadLibrary("avfilter-6");
        System.loadLibrary("avformat-57");
        System.loadLibrary("avutil-55");
        System.loadLibrary("postproc-54");
        System.loadLibrary("swresample-2");
        System.loadLibrary("swscale-4");
    }


    public native void sestFfmpeg();
}
