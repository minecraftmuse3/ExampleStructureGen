#pragma once

#include "StructurePiece.h"

class BiomeSource;
class CompoundTag;
class Random;
class PieceWeight;

class StartPiece : public StructurePiece {
public:
	StartPiece(BiomeSource*, int, Random&, int, int, std::vector<PieceWeight, std::allocator<PieceWeight>>&, int);

	virtual ~StartPiece();
	virtual void addChildren(StructurePiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&);
	virtual int getType() const;	
};
