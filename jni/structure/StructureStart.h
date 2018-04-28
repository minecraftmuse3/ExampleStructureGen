#pragma once

class BoundingBox;
class BlockSource;
class Random;
class Level;

class StructureStart {
public:
	virtual ~StructureStart();
	virtual void postProcess(BlockSource*, Random&, const BoundingBox&);
	virtual void postProcessMobsAt(BlockSource*, Random&, const BoundingBox&);
	virtual bool isValid() const;
};
