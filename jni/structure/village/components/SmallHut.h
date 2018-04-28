#pragma once

#include "../VillagePiece.h"
class BoundingBox;
class Random;

class SmallHut : public VillagePiece {
public:
	SmallHut();
	SmallHut(StartPiece*, int, Random&, const BoundingBox&, int);

	virtual ~SmallHut();
	virtual int getType() const;
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
};
