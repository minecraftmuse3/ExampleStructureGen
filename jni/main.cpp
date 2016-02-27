#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <mcpe.h>
#include <Substrate.h>

#include "mcpe/CommonTypes.h"
#include "mcpe/block/Block.h"
#include "mcpe/structure/village/components/SimpleHouse.h"

#define LOG_TAG "examplevillagegen"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

void (*_SimpleHouse$postProcess)(SimpleHouse* self, BlockSource*, Random&, BoundingBox const&);
void SimpleHouse$postProcess(SimpleHouse* self*, BlockSource* region, Random& rand, BoundingBox const& bounds) {
	self->placeBlock(region, {Block::mCobbleStone->blockId, 0}, 0, 1, 0, bounds);
	self->generateBox(region, bounds, 0, 0, 0, 5, 5, 5, {Block::mStone->blockId, 0}, {Block::mStone->blockId, 0}, true);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	
	void* handle = dlopen("libminecraftpe.so", RTLD_LAZY);
	void* SimpleHouse$postProcess_ = dlsym(handle, "_ZN11SimpleHouse11postProcessEP11BlockSourceR6RandomRK11BoundingBox")
        MSHookFunction(SimpleHouse$postProcess_, (void*) &SimpleHouse$postProcess, (void**) &_SimpleHouse$postProcess););
	return JNI_VERSION_1_2;
}
