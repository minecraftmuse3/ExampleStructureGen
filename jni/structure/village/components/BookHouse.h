#pragma once

#include "../VillagePiece.h"
class BlockSource;
class Random;

class BookHouse : public VillagePiece {
public:
	BookHouse();
	BookHouse(StartPiece*, int, Random&, const BoundingBox&, int);

	virtual ~BookHouse();
	virtual int getType() const;
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
	virtual int getVillagerProfession(int);
};
