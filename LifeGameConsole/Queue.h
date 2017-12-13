#pragma once
#include "Position.h"
#include "Modification.h"
class Queue
{
public:
	Queue();
	~Queue();
private:
	Modification* firstElement;
	Modification* lastElement;
	int size;
public:
	void add(Position* position);
	Position* get();
	int getSize();
};

