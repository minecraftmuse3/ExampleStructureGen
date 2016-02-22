#pragma once

#include "mcpe/structure/village/VillagePiece.h"

class SimpleHouse : public VillagePiece {
public:

   SimpleHouse();
   SimpleHouse(StartPiece*, int, Random&, BoundingBox const&, int);
   SimpleHouse(StartPiece*, int, Random&, BoundingBox const&, int);
   
   virtual ~SimpleHouse();
   
   virtual void addAdditionalSaveData(CompoundTag&);
   virtual void readAdditionalSaveData(CompoundTag&);
   virtual void postProcessMobsAt(BlockSource*, Random&, BoundingBox const&);
   virtual void postProcess(BlockSource*, Random&, BoundingBox const&);
   
};
