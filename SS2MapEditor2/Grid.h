#pragma once
#include <Draw/Draw.h>

class Grid {
private:
	Draw* draw;
public:
	Grid(Draw* _draw);

	void step();
};

