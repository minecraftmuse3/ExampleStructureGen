#pragma once

#include "../StructurePiece.h"

class DesertPyramidPiece : public StructurePiece
{
public:
	DesertPyramidPiece(int, int);

	virtual ~DesertPyramidPiece();
	virtual int getType() const;
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
};
