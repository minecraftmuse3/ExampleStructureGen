#pragma once

#include "../MineshaftPiece.h"

class MineshaftStairs : public MineshaftPiece
{
public:
	MineshaftStairs(MineshaftData&);
	MineshaftStairs(MineshaftData&, int, Random&, const BoundingBox&, int);

	virtual ~MineshaftStairs();
	virtual void addChildren(StructurePiece*, std::vector<std::unique_ptr<StructurePiece,std::default_delete<StructurePiece>>,std::allocator<std::unique_ptr<StructurePiece,std::default_delete<StructurePiece>>>>&,Random&);
	virtual int getType() const;
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
};
