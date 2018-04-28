#pragma once

#include <string>
#include <vector>
#include <memory>

//#include "../BlockSource.h"
class Block;
class BlockSource;
class BoundingBox;
class Random;
class LevelChunk;

class StructurePiece
{
public:
	void** vtable; // 0

	virtual ~StructurePiece();
	virtual void moveBoudingBox(int, int, int);
	virtual int getType() const = 0;
	virtual void addChildren(StructurePiece*, std::vector<std::unique_ptr<StructurePiece,std::default_delete<StructurePiece>>,std::allocator<std::unique_ptr<StructurePiece,std::default_delete<StructurePiece>>>>&,Random&);
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	// pure virtual function
	virtual void getWorldX(int, int);
	virtual void getWorldZ(int, int);
	virtual void placeBlock(BlockSource*, const Block&, int, int, int, const BoundingBox&);
	virtual void generateBox(BlockSource*, const BoundingBox& ,int, int, int, int, int, int, const Block&, const Block&, bool);
	virtual void fillColumnDown(BlockSource*, const Block&, int, int, int, const BoundingBox&);
	virtual void createChest(BlockSource*, const BoundingBox&, Random&, int, int, int, int, const std::string&);
	virtual void createDispenser(BlockSource*, const BoundingBox&, Random& ,int, int, int, int, const std::string&);
	virtual void createDoor(BlockSource*, const BoundingBox&, Random&, int, int, int, int);
	virtual void addHardcodedSpawnAreas(LevelChunk&);

	void generateAirColumnUp(BlockSource*, int, int, int, const BoundingBox&);
};
