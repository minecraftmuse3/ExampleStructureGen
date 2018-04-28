#pragma once

#include "../StructureStart.h"
class BiomeSource;
class ChunkPos;

class MineshaftStart : public StructureStart
{
public:
	MineshaftStart(BiomeSource&, Random&, const ChunkPos&);

	virtual ~MineshaftStart();
	virtual int getType() const;

	void _moveToSurface(short);
};
