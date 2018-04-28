#pragma once

#include "../VillagePiece.h"
class BoundingBox;
class Random;

class SimpleHouse : public VillagePiece {
public:
	SimpleHouse();
	SimpleHouse(StartPiece*, int, Random&, const BoundingBox&, int);

	virtual ~SimpleHouse();
	virtual int getType() const;
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
	virtual int getVillagerProfession(int);
};
