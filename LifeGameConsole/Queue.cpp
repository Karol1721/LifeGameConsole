#include "Queue.h"



Queue::Queue()
{
	this->firstElement = nullptr;
	this->lastElement = nullptr;
}

Queue::~Queue()
{
	while (firstElement != nullptr)
	{
		Modification* temp = firstElement;
		firstElement = firstElement->nextModification;
		delete temp;
	}
}

void Queue::add(Position* position)
{
	Modification* modification = new Modification(position);
	
	if (this->lastElement != nullptr)
	{
		this->lastElement->nextModification = modification;
		this->lastElement = modification;
		this->size++;
	}
	else
	{
		this->lastElement = modification;
		this->firstElement = modification;
		this->size++;
	}
}

Position* Queue::get()
{
	if (this->firstElement == nullptr)
		return nullptr;

	Position* position = firstElement->getPosition();
	Modification* temp = firstElement;

	if (this->firstElement == this->lastElement)
		this->lastElement = nullptr;
	firstElement = firstElement->nextModification;
	size--;
	delete temp;
	return position;
}

int Queue::getSize()
{
		return this->size;
}
