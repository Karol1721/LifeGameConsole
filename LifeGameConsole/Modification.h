#pragma once
#include "Position.h"

class Modification
{
public:
	Modification(Position* position);
	~Modification();
private:
	Position* position;
public:
	Modification* nextModification;
	Position* getPosition();
};

