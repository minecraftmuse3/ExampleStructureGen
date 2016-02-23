#pragma once

class BlockID;
class BlockSource;
class BoundingBox;
class FullBlock;

class StructurePiece {
public:
        virtual ~StructurePiece();
        
        void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, BlockID, unsigned char, BlockID, unsigned char, bool);
        int getOrientationData(Block*, unsigned char);
        virtual void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
        void placeBlock(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
        void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, FullBlock, FullBlock, bool);
        void fillColumnDown(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
        void generateAirColumnUp(BlockSource*, int, int, int, BoundingBox const&);
        void createDoor(BlockSource*, BoundingBox const&, Random&, int, int, int, int);
        void generateAirBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int);
    
};
