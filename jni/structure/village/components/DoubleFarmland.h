#pragma once

#include "../VillagePiece.h"
class BoundingBox;
class Random;

class DoubleFarmland : public VillagePiece {
public:
	DoubleFarmland();
	DoubleFarmland(StartPiece*, int, Random&, const BoundingBox&, int);
	
	virtual ~DoubleFarmland();
	virtual int getType() const;
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
};
