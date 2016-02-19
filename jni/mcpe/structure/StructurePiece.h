#pragma once

class StructurePiece {
public:

    virtual void postProcess(BlockSource*, Random&, BoundingBox const&);
    virtual void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
    virtual void placeBlock(BlockSource*, FullBlock, int, int, int, BoundingBox const&);
    virtual void generateBox(BlockSource*, BoundingBox const&, int, int, int, int, int, int, FullBlock, FullBlock):
    
};
