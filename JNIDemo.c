#include <jni.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 本地方法的实现
JNIEXPORT void JNICALL Java_JNIDemo_allocateMemory(JNIEnv *env, jobject obj, jint sizeInBytes) {
    // 使用 malloc 分配内存，但不释放
    void *memory = malloc(sizeInBytes);
    if (memory == NULL) {
        printf("Failed to allocate memory!\n");
        return;
    }
    memset(memory, 0, sizeInBytes);
    printf("Allocated %d bytes at address %p\n", sizeInBytes, memory);
    // 注意：此处没有 free(memory)，故意制造内存泄漏
}