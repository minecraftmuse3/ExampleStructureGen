#pragma once

#include "../MineshaftPiece.h"

class MineshaftRoom : public MineshaftPiece
{
public:
	MineshaftData& data;

	MineshaftRoom(MineshaftData&);
	MineshaftRoom(MineshaftData&, int, Random&, int, int);

	virtual ~MineshaftRoom();
	virtual void moveBoundingBox(int, int, int);
	virtual int getType() const;
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
};
