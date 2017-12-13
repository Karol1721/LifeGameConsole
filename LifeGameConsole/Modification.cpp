#include "Modification.h"



Modification::Modification(Position* position) : position(position)
{
}


Modification::~Modification()
{
}

Position* Modification::getPosition() 
{
	return this->position;
}
