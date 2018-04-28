#pragma once

struct Block {
	void** vtable;

	static Block* mTNT;
};
