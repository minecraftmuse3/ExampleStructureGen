#include "mcpe/level/structure/pyramid/MineshaftCorridor.h"

#include "mcpe/level/block/Block.h"

void MineshaftCorridor::genPyramid(BlockSource *region, Random &random, const BoundingBox &bounds) {
	generateBox(region, bounds, 0, 0, 0, 5, 10, 5, { Block::mWorkBench->blockId, 0 }, { Block::mWorkBench->blockId, 0 }, false);
}