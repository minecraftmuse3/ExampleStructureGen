#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "mcpe/CommonTypes.h"
#include "mcpe/block/Block.h"
#include "mcpe/structure/village/components/SimpleHouse.h"

#define LOG_TAG "Village-Generation"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

void (*_SimpleHouse$postProcess)(SimpleHouse*, BlockSource*, Random&, BoundingBox const&);
void SimpleHouse$postProcess(SimpleHouse *self, BlockSource *region, Random &random, BoundingBox const &bounds) {
	genSimpleHouse(region, random, bounds);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    MSHookFunction(SimpleHouse::postProcess, (void*) &SimpleHouse$postProcess, (void**) &_SimpleHouse$postProcess);

	return JNI_VERSION_1_2;
}
