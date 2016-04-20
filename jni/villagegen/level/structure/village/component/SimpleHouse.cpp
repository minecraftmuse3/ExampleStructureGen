#include "mcpe/level/structure/village/components/SimpleHouse/h"

include "mcpe/level/block/Block.h"

void SimpleHouse::_postProcess(BlockSource* region, Random& random, BoundingBox const& bounds) {
        //We generate a basic cube
	this->generateBox(region, bounds, 0, 0, 0, 4, 4, 4, {Block::mBrick->blockId, 0}, {Block::mAir->blockId, 0}, false);
	this->createDoor(region, bounds, random, 2, 1, 0, 0);
}
       
