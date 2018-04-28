#pragma once

#include "../VillagePiece.h"
class BoundingBox;
class Random;

class SmallTemple : public VillagePiece {
public:
	SmallTemple();
	SmallTemple(StartPiece*, int, Random&, const BoundingBox&, int);

	virtual ~SmallTemple();
	virtual int getType() const;
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
	virtual int getVillagerProfession(int);
};
