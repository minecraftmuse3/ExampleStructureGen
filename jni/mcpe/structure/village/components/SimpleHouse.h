#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class SimpleHouse : public VillagePiece {
public:
	SimpleHouse();
	SimpleHouse(StartPiece*, int, Random&, BoundingBox const&, int);

	virtual ~SimpleHouse();
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
	virtual void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	virtual void postProcess(BlockSource*, Random&, BoundingBox const&);
};