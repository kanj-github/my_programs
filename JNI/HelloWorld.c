#include <jni.h>
#include <stdio.h>
#include "HelloWorld.h"
JNIEXPORT jstring JNICALL
Java_HelloWorld_print(JNIEnv *env, jobject obj, jstring abc)
{
char buf[128];
const jbyte *str;
str = (*env)->GetStringUTFChars(env,abc,NULL);
if(str==NULL)
{
return NULL;
}
//printf("Hello World!\n");
printf("%s",str);
(*env)->ReleaseStringUTFChars(env,abc,str);
//scanf("%s",buf);
gets(buf);
return(*env)->NewStringUTF(env,buf);
}