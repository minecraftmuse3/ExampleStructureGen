#pragma once

#include "../StructureStart.h"
class BiomeSource;

class VillageStart : public StructureStart
{
public:
	VillageStart(BiomeSource*, Random&, int, int, int);

	virtual ~VillageStart();
	virtual bool isValid() const;
	virtual int getType() const;
};
