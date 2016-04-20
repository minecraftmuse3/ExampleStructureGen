#include "mcpe/level/structure/village/components/SimpleHouse.h"

#include "mcpe/level/block/Block.h"

void SimpleHouse::genSimpleHouse(BlockSource *region, Random &random, BoundingBox const &bounds) {
	//We generate just a cube with a door
	generateBox(region, bounds, 0, 0, 0, 4, 4, 4, Block::mBrick->blockId, 0, false);
	createDoor(region, bounds, random, 2, 1, 0, 0);
}
