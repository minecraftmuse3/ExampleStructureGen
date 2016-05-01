#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BoundingBox;
class Random;

class StraightRoad : public VillagePiece {
public:
	StraightRoad();
	StraightRoad(StartPiece*, int, Random&, const BoundingBox&, int);
	
	virtual ~StraightRoad();
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
};
