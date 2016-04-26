#include "mcpe/level/structure/StructurePiece.h"

Material& StructurePiece::getMaterial(BlockSource *region, int x, int y, int z){
	return region->getMaterial(x, y, z);
}

void StructurePiece::placeBlock(BlockSource *region, BlockID id, int x, int y, int z) {
	region->setBlock(x, y, z, id, 3);
}

void StructurePiece::placeBlock(BlockSource *region, BlockID id, unsigned char ch, int x, int y, int z) {
	region->setBlock(x, y, z, id, ch, 3);
}

bool isEmptyBlock(BlockSource *region, int x, int y, int z) {
	if (region->isEmptyBlock(x, y, z))
		return true;
	else
		return false;
}
