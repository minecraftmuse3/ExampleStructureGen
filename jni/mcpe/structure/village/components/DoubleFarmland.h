#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class DoubleFarmland : public VillagePiece {
public:
	DoubleFarmland();
	DoubleFarmland(StartPiece*, int, Random&, BoundingBox const&, int);

	virtual ~DoubleFarmland();
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void readAdditionalSaveData(CompoundTag&);
	virtual void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
	virtual void postProcess(BlockSource*, Random&, BoundingBox const&);
};
