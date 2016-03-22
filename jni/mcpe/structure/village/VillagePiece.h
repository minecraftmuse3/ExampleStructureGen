#pragma once

#include "../StartPiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class FullBlock;

class VillagePiece : public StructurePiece {
public:
	VillagePiece();
	VillagePiece(StartPiece*, int);

	virtual ~VillagePiece();
	virtual int getVillagerProfession(int);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
	virtual void spawnVillagers(BlockSource*, BoundingBox const&, int, int, int, int);
	virtual void biomeBlock(FullBlock);
	void placeBlock(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
	void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, FullBlock, FullBlock, bool);
	void fillColumnDown(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
	virtual void getAverageGroundHeight(BlockSource*, BoundingBox const&);
	virtual bool isOkBox(BoundingBox const&);
};
