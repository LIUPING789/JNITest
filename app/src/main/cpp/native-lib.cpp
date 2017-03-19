#include <com_knight_ndktest_Hello.h>

#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT jobject JNICALL
Java_com_knight_ndktest_Hello_test(JNIEnv *env, jclass type) {
    //关于包描述符，这儿可以是 com.knight.ndktest.Student;
    // 这两种类型 都可以获得class引用

    jclass student_class = env->FindClass("com/knight/ndktest/Student");
    //获得得该类型的构造函数  函数名为 <init> 返回类型必须为 void 即 V
    jmethodID constrocMID = env->GetMethodID(student_class, "<init>", "()V");
    jfieldID nameFieldId = env->GetFieldID(student_class, "name", "Ljava/lang/String;");
    jfieldID sexFieldId = env->GetFieldID(student_class, "sex", "Ljava/lang/String;");
    jstring name = env->NewStringUTF("knight");
    jstring sex = env->NewStringUTF("24");
    jobject stu_object = env->NewObject(student_class, constrocMID);
    env->SetObjectField(stu_object, nameFieldId, name);
    env->SetObjectField(stu_object, sexFieldId, sex);

    return stu_object;
}

JNIEXPORT jstring JNICALL
Java_com_knight_ndktest_MainActivity_stringFromJNI(
        JNIEnv *env, jclass /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
#ifdef __cplusplus
}
#endif