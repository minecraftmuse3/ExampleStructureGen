#pragma once

#include "../VillagePiece.h"
class CompoundTag;
class BlockSource;
class BoundingBox;
class Random;

class Well : public VillagePiece {
public:
	Well();
	Well(StartPiece*, int, Random&, int, int);
	Well(StartPiece*, int, Random&, BoundingBox const&, int);

	virtual ~Well();
	virtual void postProcess(BlockSource*, Random&, BoundingBox const&);
};