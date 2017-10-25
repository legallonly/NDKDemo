package com.lonly.example.ndkdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        TextView tv1 = (TextView) findViewById(R.id.textView1);
        tv1.setText(getCLanguageString());

        TextView tv2 = (TextView) findViewById(R.id.textView2);
        tv2.setText(getMyString());

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String getCLanguageString();

    public native String getMyString();

    // 用于应用启动时，加载.so库.
    static {
        System.loadLibrary("native-lib");
    }
}
