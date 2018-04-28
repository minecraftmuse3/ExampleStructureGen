#pragma once

#include "../StructurePiece.h"
#include "MineshaftData.h"
class PieceWeight;

class MineshaftPiece : public StructurePiece
{
public:
	virtual ~MineshaftPiece();
	virtual void createChest(BlockSource*, const BoundingBox&, Random&, int, int, int, int, const std::string&);

	bool _isSupportingBox(int, int, BlockSource*, int, int);
	void createRandomShaftPiece(MineshaftData&, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int, int);
	void generateAndAddPiece(StructurePiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>>&, Random&, int, int, int, int, int);
};
