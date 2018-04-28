#pragma once

#include "../MineshaftPiece.h"

class MineshaftCorridor : public MineshaftPiece
{
public:
	MineshaftCorridor(MineshaftData&);
	MineshaftCorridor(MineshaftData&, int, Random&, const BoundingBox&, int);

	virtual ~MineshaftCorridor();
	virtual void addChildren(StructurePiece*, std::vector<std::unique_ptr<StructurePiece,std::default_delete<StructurePiece>>,std::allocator<std::unique_ptr<StructurePiece,std::default_delete<StructurePiece>>>>&,Random&);
	virtual int getType() const;
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);

	void _placeCobWeb(BlockSource*, const BoundingBox&, Random&, float, int, int, int);
	void _placeSupport(BlockSource*, const BoundingBox&, int, int, int, int, int, Random&);
};
