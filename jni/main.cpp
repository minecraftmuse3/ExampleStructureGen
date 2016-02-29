#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "mcpe/CommonTypes.h"
#include "mcpe/block/Block.h"
#include "mcpe/structure/village/components/SimpleHouse.h"

#define LOG_TAG "ExampleVillageGen"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

void (*_SimpleHouse$postProcess)(SimpleHouse* self, BlockSource*, Random&, BoundingBox const&);
void SimpleHouse$postProcess(SimpleHouse* self, BlockSource* region, Random& rand, BoundingBox const& bounds) {
	/*
	  StructurePiece::generateBlock(region, boundingbox, minX, minY, minZ, maxX, maxY, maxZ, block1, block2, replacesExisting);
	  StructurePiece::placeBlock(region, minX, minY, minZ, block, bounds);
	*/
	
	//We generate a basic wall
	self->generateBox(region, bounds, 0, 0, 0, 4, 4, 0, {Block::mBrick->blockId, 0}, {Block::mBrick->blockId}, false);
	self->generateBox(region, bounds, 1, 1, 0, 3, 3, 0, {Block::mWoodPlanks->blockId, 0}, {Block::mWoodPlanks->blockId}, false);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	
	void* handle = dlopen("libminecraftpe.so", RTLD_LAZY);
	void* SimpleHouse$postProcess_ = dlsym(handle, "_ZN11SimpleHouse11postProcessEP11BlockSourceR6RandomRK11BoundingBox");
    MSHookFunction(SimpleHouse$postProcess_, (void*) &SimpleHouse$postProcess, (void**) &_SimpleHouse$postProcess);

	return JNI_VERSION_1_2;
}
