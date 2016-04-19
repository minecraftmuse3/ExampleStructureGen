#pragma once

#include "../StartPiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class FullBlock;
class PieceWeight;

class VillagePiece : public StructurePiece {
public:
	StartPiece* start;
	Random& random;
	BLockSource* region;
	BoundingBox const& bounds;

	VillagePiece();
	VillagePiece(StartPiece*, int);

	virtual ~VillagePiece();
	virtual void addAdditionalSaveData(CompoundTag&);
	void readAdditionalSaveData(CompoundTag&);
	void spawnVillagers(BlockSource*, BoundingBox const&, int, int, int, int);
	bool biomeBlock(FullBlock);
	void fillColumnDown(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
	void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, FullBlock, FullBlock, bool);
	int getAverageGroundHeight(BlockSource*, BoundingBox const&);
	int getVillagerProfession(int);
	bool isOkBox(BoundingBox const&);
	void placeBlock(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
};
