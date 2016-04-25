#pragma once

#include "../StructurePiece.h"
class BoundingBox;
class BlockSource;
class CompoundTag;
class Random;

class DesertPyramidPiece : public StructurePiece {
public:
	Random& random;
	BlockSource* region;
	BoundingBox const& bounds;

	DesertPyramidPiece(Random&, int, int);

	~DesertPyramidPiece();
	addAdditionalSaveData(CompoundTag&);
	readAdditionalSaveData(CompoundTag&);
	postProcess(BlockSource*, Random&, BoundingBox const&);

	//Custom functions
	void genMineshaftCorridor(BlockSource*, Random&, BoundingBox const&);
};