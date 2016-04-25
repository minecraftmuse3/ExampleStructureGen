#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "mcpe/CommonTypes.h"
#include "mcpe/level/block/Block.h"
#include "mcpe/level/structure/village/components/SimpleHouse.h"
#include "mcpe/level/structure/mineshaft/components/MineshaftCorridor.h"
#include "mcpe/level/structure/pyramid/DesertPyramidPiece.h"

#define LOG_TAG "Structure-Generation"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

void (*_SimpleHouse$postProcess)(SimpleHouse*, BlockSource*, Random&, BoundingBox const&);
void SimpleHouse$postProcess(SimpleHouse *self, BlockSource *region, Random &random, BoundingBox const &bounds) {
	self->genSimpleHouse(region, random, bounds);
}

void (*_MineshaftCorridor$postProcess)(MineshaftCorridor*, BlockSource*, Random&, BoundingBox const&);
void MineshaftCorridor$postProcess(MineshaftCorridor *self, BlockSource *region, Random &random, BoundingBox const &bounds) {
	 self->genMineshaftCorridor(region, random, bounds);
}

void(*_DesertPyramidPiece$postProcess)(DesertPyramidPiece*, BlockSource*, Random&, BoundingBox const&);
void MineshaftCorridor$postProcess(DesertPyramidPiece *self, BlockSource *region, Random &random, BoundingBox const &bounds) {
	self->genPyramid(region, random, bounds);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    void* handle = dlopen("libminecraftpe.so", RTLD_LAZY); 
    void* SimpleHouse$postProcess_ = dlsym(handle, "_ZN11SimpleHouse11postProcessEP11BlockSourceR6RandomRK11BoundingBox");
    void* MineshaftCorridor$postProcess_ = dlsym(handle, "_ZN17MineshaftCorridor11postProcessEP11BlockSourceR6RandomRK11BoundingBox");
	void* DesertPyramidPiece$postProcess_ = dlsym(handle, "_ZN18DesertPyramidPiece11postProcessEP11BlockSourceR6RandomRK11BoundingBox");

    MSHookFunction(SimpleHouse$postProcess_, (void*) &SimpleHouse$postProcess, (void**) &_SimpleHouse$postProcess);
    MSHookFunction(MineshaftCorridor$postProcess_, (void*) &MineshaftCorridor$postProcess, (void**) &_MineshaftCorridor$postProcess);
	MSHookFunction(MineshaftCorridor$postProcess_, (void*)&MineshaftCorridor$postProcess, (void**)&_MineshaftCorridor$postProcess);
	MSHookFunction(DesertPyramidPiece$postProcess_, (void*)&DesertPyramidPiece$postProcess, (void**)&_DesertPyramidPiece$postProcess);

	return JNI_VERSION_1_2;
}
