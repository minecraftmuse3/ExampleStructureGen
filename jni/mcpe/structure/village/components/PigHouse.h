#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class PigHouse : public VillagePiece {
public:
	PigHouse();
	PigHouse(StartPiece*, int, Random&, BoundingBox const&, int);

	virtual ~SmallHut();
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
	virtual void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	virtual void postProcess(BlockSource*, Random&, BoundingBox const&);
};
