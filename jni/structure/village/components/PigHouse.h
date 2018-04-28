#pragma once

#include "../VillagePiece.h"
class BoundingBox;
class Random;

class PigHouse : public VillagePiece {
public:
	PigHouse();
	PigHouse(StartPiece*, int, Random&, const BoundingBox&, int);

	virtual ~PigHouse();
	virtual int getType() const;
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
	virtual int getVillagerProfession(int);
};
