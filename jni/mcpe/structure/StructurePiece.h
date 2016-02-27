#pragma once

class BlockID;
class BlockSource;
class BoundingBox;
class FullBlock;

class StructurePiece {
public:
        virtual ~StructurePiece();
        
        void placeBlock(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
        void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, FullBlock, FullBlock, bool);
    
};
