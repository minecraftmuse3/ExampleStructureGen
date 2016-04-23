#include "mcpe/level/structure/village/components/SimpleHouse.h"

#include "mcpe/level/block/Block.h"

void SimpleHouse::genSimpleHouse(BlockSource *region, Random &random, BoundingBox const &bounds) {
     int avgY = -8;

	//We generate just a cube with a door
	generateBox(region, bounds, 0, avgY+0, 0, 4, avgY+3, 4, {Block::mBrick->blockId, 0}, {Block::mBrick->blockId, 0}, false);
     generateAirBox(region, bounds, 1, avgY+1, 1, 3, avgY+2, 3);
	createDoor(region, bounds, random, 2, avgY+1, 0, 0);
}
