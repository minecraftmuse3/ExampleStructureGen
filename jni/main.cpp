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

void (*_SimpleHouse$postProcess)(SimpleHouse*, BlockSource*, Random&, const BoundingBox&);
void SimpleHouse$postProcess(SimpleHouse *self, BlockSource *region, Random &random, const BoundingBox &bounds) {
	self->genSimpleHouse(region, random, bounds);
}

void (*_MineshaftCorridor$postProcess)(MineshaftCorridor*, BlockSource*, Random&, const BoundingBox&);
void MineshaftCorridor$postProcess(MineshaftCorridor *self, BlockSource *region, Random &random, const BoundingBox &bounds) {
	 self->genMineshaftCorridor(region, random, bounds);
}

void(*_DesertPyramidPiece$postProcess)(DesertPyramidPiece*, BlockSource*, Random&, const BoundingBox&);
void MineshaftCorridor$postProcess(DesertPyramidPiece *self, BlockSource *region, Random &random, const BoundingBox &bounds) {
	self->genPyramid(region, random, bounds);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &SimpleHouse::postProcess, (void*) &SimpleHouse$postProcess, (void**) &_SimpleHouse$postProcess);
	MSHookFunction((void*) &MineshaftCorridor::postProcess, (void*) &MineshaftCorridor$postProcess, (void**) &_MineshaftCorridor$postProcess);
	MSHookFunction((void*) &DesertPyramidPiece::postProcess, (void*) &DesertPyramidPiece$postProcess, (void**) &_DesertPyramidPiece$postProcess);

	return JNI_VERSION_1_2;
}
