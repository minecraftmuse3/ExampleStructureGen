#pragma once

class BlockID;
class BlockSource;
class BoundingBox;
class FullBlock;
class Random;
class Brightness;

class StructurePiece {
public:
	virtual ~StructurePiece();

	void _getWorldPos(int, int, int);
	void getWorldX(int, int);
	void getWorldY(int);
	void getWorldZ(int, int);
	void createTag();
	void getBrightness(int, int, int, BlockSource*);
	void getLocatorPosition();
	void getOrientationData(Block*, uchar);
	void getTorchData(uchar);
	void getBlock(BlockSource*, int, int, int, BoundingBox const&);
	bool isAir(BlockSource*, int, int, int, BoundingBox const&);
	//void createChest(BlockSource*, BoundingBox const&, Random &, int, int, int, int, std::vector<WeighedTreasureItem, std::allocator<WeighedTreasureItem>> const&, int);
	void createDoor(BlockSource*, BoundingBox const&, Random&, int, int, int, int);
	void edgesLiquid(BlockSource*, BoundingBox const&);
	void fillColumnDown(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
	void generateAirBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int);
	void generateAirColumnUp(BlockSource*, int, int, int, BoundingBox const&);
	void generateBox(BlockSource*, BoundingBox const&, BoundingBox const&, BlockID, BlockID, bool);
	void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, FullBlock, FullBlock, bool);
	void generateBox(BlockSource*, BoundingBox const&, BoundingBox const&, bool, Random&, BlockSelector*);
	//void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, BlockID, uchar, BlockID, uchar, bool);
	//void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, bool, Random&, BlockSelector*);
	void generateMaybeBox(BlockSource*, BoundingBox const&, Random&, float, int, int, int, int, int, int, BlockID, BlockID, bool, Brightness);
	void generateUpperHalfSphere(BlockSource*, BoundingBox const&, int, int, int, int, int, int, BlockID, bool);
	void isInChunk(ChunkPos const&);
	void placeBlock(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
	void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
};