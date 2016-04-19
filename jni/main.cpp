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
	/*
	  StructurePiece::generateBlock(region, bounds, minX, minY, minZ, maxX, maxY, maxZ, outsideBlocks, insideBlocks, onlyReplaceExisting);
	  StructurePiece::placeBlock(region, x, y, z, block, bounds);
	  StructurePiece::createDoor(region, bounds, random, x, y, z, 0);
	*/
	
	//We generate a basic cube
	self->generateBox(region, bounds, 0, 0, 0, 4, 4, 4, {Block::mBrick->blockId, 0}, {Block::mAir->blockId, 0}, false);
	self->createDoor(region, bounds, random, 2, 1, 0, 0);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	
	void* handle = dlopen("libminecraftpe.so", RTLD_LAZY);
	void* SimpleHouse$postProcess_ = dlsym(handle, "_ZN11SimpleHouse11postProcessEP11BlockSourceR6RandomRK11BoundingBox");

    MSHookFunction(SimpleHouse$postProcess_, (void*) &SimpleHouse$postProcess, (void**) &_SimpleHouse$postProcess);

	return JNI_VERSION_1_2;
}
