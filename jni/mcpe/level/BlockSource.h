#pragma once

#include "block/Block.h"
#include "BlockPos.h"
#include "../material/Material.h"
#include "../../CommonTypes.h"
class BlockEntity;
class Level;

class BlockSource {
public:
	Level* getLevel() const;
	Block* getBlock(const BlockPos&);
	FullBlock getBlockID(const BlockPos&);
	DataID getData(const BlockPos&);
	Material& getMaterial(int, int, int);
	Material& getMaterial(const BlockPos&);
	bool setBlockAndData(const BlockPos&, FullBlock, int);
	bool setBlock(const BlockPos&, BlockID, int);
	bool setExtraData(const BlockPos&, unsigned short);
	void removeBlock(const BlockPos&);
	BlockEntity* getBlockEntity(const BlockPos&);
};
