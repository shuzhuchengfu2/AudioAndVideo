package com.ywl5320.jnithread;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    ThreadDemo threadDemo;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        threadDemo = new ThreadDemo();
    }

    public void normalThread(View view){
        threadDemo.normalThread();
    }


    public void mutexThread(View view) {
        threadDemo.mutexThread();
    }
}
