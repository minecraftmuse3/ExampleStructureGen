#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "structure/village/components/SmallHut.h"
#include "Block.h"

#define LOG_TAG "Structure-Generation"
#define LOG(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))

void (*_SmallHut$postProcess)(SmallHut*, BlockSource*, Random&, const BoundingBox&);
void SmallHut$postProcess(SmallHut *self, BlockSource *region, Random &random, const BoundingBox &bounds) {
	LOG("Generating SmallHut");
	// For some reson placing blocks doesn't work
	self->placeBlock(region, *Block::mTNT, 0, 10, 0, bounds);
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
	MSHookFunction((void*) &SmallHut::postProcess, (void*) &SmallHut$postProcess, (void**) &_SmallHut$postProcess);

	return JNI_VERSION_1_2;
}
