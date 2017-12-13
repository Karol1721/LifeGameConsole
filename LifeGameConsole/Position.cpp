#include "Position.h"

Position::Position(int x, int y) :x(x-1), y(y-1)
{
}

Position::~Position()
{
}

void Position::setX(int x)
{
	this->x = x - 1;
}

void Position::setY(int y)
{
	this->y = y - 1;
}

int Position::getX() const
{
	return this->x;
}

int Position::getY() const
{
	return this->y;
}

void Position::addX(int x)
{
	this->x += x;
}

void Position::addY(int y)
{
	this->y += y;
}

void Position::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}