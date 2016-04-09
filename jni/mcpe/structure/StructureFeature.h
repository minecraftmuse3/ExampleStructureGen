#pragma once

#include "../Feature.h"

class LevelChunk;
class BiomeSource;
class BlockSource;
class Random;

class StructureFeature : public Feature {
public:
	virtual ~StructureFeature();
	
	void addFeature(LevelChunk&, BiomeSource*, Random&, int, int);
	void getStructureAt(int, int, int);
	bool isInsideFeature(int, int, int);
	bool isInsideBoundingFeature(int, int, int);
	void postProcess(BlockSource*, Random&, int, int);
	void postProcessMobsAt(BlockSource*, int, int, Random&);
};
