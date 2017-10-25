#include <jni.h>
#include <string>

extern "C"
{
jstring
Java_com_lonly_example_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
JNIEXPORT jstring JNICALL
Java_com_lonly_example_ndkdemo_MainActivity_getCLanguageString(
        JNIEnv* env,
        jobject /* this */) {
    std::string test = "This just a test for Android Studio NDK JNI developer!";
    return env->NewStringUTF(test.c_str());
}
}

