#pragma once

#include "../VillagePiece.h"
class BoundingBox;
class Random;

class Farmland : public VillagePiece {
public:
	Farmland();
	Farmland(StartPiece*, int, Random&, const BoundingBox&, int);

	virtual ~Farmland();
	virtual int getType() const;
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
};
