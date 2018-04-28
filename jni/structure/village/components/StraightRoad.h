#pragma once

#include "../VillagePiece.h"
class BoundingBox;
class Random;

class StraightRoad : public VillagePiece {
public:
	StraightRoad();
	StraightRoad(StartPiece*, int, Random&, const BoundingBox&, int);
	
	virtual ~StraightRoad();
	virtual void addChildren(StructurePiece*, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>> &,Random &);
	virtual int getType() const;
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
};
