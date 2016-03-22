#pragma once

class BlockID;
class BlockSource;
class BoundingBox;
class FullBlock;
class Random;

class StructurePiece {
public:
	virtual ~StructurePiece();

	void placeBlock(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
	void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, FullBlock, FullBlock, bool);
	void fillColumnDown(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
	//void createChest(BlockSource*, BoundingBox const&, Random&, int, int, int, int, std::vector<WeightedTreasureItem, std::allocator<WeightedTreasureItem>> const&, int);
	void createDoor(BlockSource*, BoundingBox const&, Random&, int, int, int, int);
	void getBlock(BlockSource*, int, int, int, BoundingBox const&);
	bool isAir(BlockSource*, int, int, int, BoundingBox const&);
};