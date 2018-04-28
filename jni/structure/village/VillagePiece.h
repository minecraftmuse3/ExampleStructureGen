#pragma once

#include "../StructurePiece.h"
#include "../StartPiece.h"
class CompoundTag;
class PieceWeight;
class Block;

class VillagePiece : public StructurePiece
{
public:
	void** vtable; // 0

	VillagePiece();
	VillagePiece(StartPiece*, int);

	virtual ~VillagePiece();
	// pure virtual function
	virtual void placeBlock(BlockSource*, const Block&, int, int, int, const BoundingBox&);
	virtual void fillColumnDown(BlockSource*, const Block&, int, int, int, const BoundingBox&);
	virtual void createDoor(BlockSource*, const BoundingBox&, Random&, int, int, int, int);
	virtual int getVillagerProfession(int);
};
