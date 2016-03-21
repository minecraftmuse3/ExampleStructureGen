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
	  StructurePiece::generateBlock(region, bounds, minX, minY, minZ, maxX, maxY, maxZ, outsideBlock, insideBlock, replacesExisting);
	  StructurePiece::placeBlock(region, x, y, z, block, bounds);
	  StructurePiece::createDoor(region, bounds, rand, x, y, z);
	*/
	
	//We generate a basic wall
	self->generateBox(region, bounds, 0, 0, 0, 4, 4, 4, {Block::mBrick->blockId, 0}, {Block::mAir->blockId}, false);
	self->createDoor(region, bounds, rand, 2, 1, 0);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	
	void* handle = dlopen("libminecraftpe.so", RTLD_LAZY);
	void* SimpleHouse$postProcess_ = dlsym(handle, "_ZN11SimpleHouse11postProcessEP11BlockSourceR6RandomRK11BoundingBox");
    MSHookFunction(SimpleHouse$postProcess_, (void*) &SimpleHouse$postProcess, (void**) &_SimpleHouse$postProcess);

	return JNI_VERSION_1_2;
}
