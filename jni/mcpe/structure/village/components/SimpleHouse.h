#pragma once

#include "mcpe/structure/village/VillagePiece.h"
#include "mcpe/util/Random.h"
class CompoundTag;
class BlockSource;
class BoundingBox;

class SimpleHouse : public VillagePiece {
public:

        SimpleHouse();
        SimpleHouse(StartPiece*, int, Random&, BoundingBox const&, int);
        //SimpleHouse(StartPiece*, int, Random&, BoundingBox const&, int); Idont think we need two of this
   
        virtual ~SimpleHouse();
   
        virtual void addAdditionalSaveData(CompoundTag&);
        virtual void readAdditionalSaveData(CompoundTag&);
        virtual void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
        virtual void postProcess(BlockSource*, Random&, BoundingBox const&);
   
};
