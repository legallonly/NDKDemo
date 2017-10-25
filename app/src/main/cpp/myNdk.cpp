//
// Created by lonly on 2017/10/25.
//
#include <jni.h>
#include <string>
#include <android/log.h>
#define  TAG    "JNITAG"
// 定义debug信息，其他级别的Log亦如此
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
extern "C"
{
JNIEXPORT jstring JNICALL
Java_com_lonly_example_ndkdemo_MainActivity_getMyString(
        JNIEnv* env,
        jobject /* this */) {
    std::string str = "This is my ndk example."; //std是命名空间,std::string可以定义一个类型为string的变量
    LOGD("str=%s", str.c_str());  //str.c_str()将C++ string转化成 c string
    return env->NewStringUTF(str.c_str());
}
}

/**
std::string指的是C++ Std命名空间下面的string类。
和这种用法一样：
using namespace std;
string str;
str = "haha";
 */
