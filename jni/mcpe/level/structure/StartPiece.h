#pragma once

#include <vector>
#include <allocators>

#include "StructurePiece.h"
class BiomeSource;
class CompoundTag;
class Random;
class PieceWeight;

class StartPiece {
public:
	StartPiece(BiomeSource*, int, Random&, int, int, std::vector<PieceWeight, std::allocator<PieceWeight>>&, int);

	virtual ~StartPiece();
	void getPieceWeights(void);
	void getBiomeSource(void);
};