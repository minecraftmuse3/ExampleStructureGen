#pragma once

#include <vector>

class BiomeSource;
class CompoundTag;
class Random;
class PieceWeight;

class StartPiece {
public:
	StartPiece(BiomeSource*, int, Random&, int, int, std::vector<PieceWeight, std::allocator<PieceWeight>>&, int);

	virtual ~StartPiece();
	virtual void addChildren(StructurePiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&);
	void getPieceWeights();
	void getBiomeSource();
};