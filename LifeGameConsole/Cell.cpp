#include "Cell.h"

Cell::Cell(bool status) : status(status), nextStatus(false)
{
}

Cell::~Cell()
{
}

void Cell::setStatus(bool status)
{
	this->status = status;
}

void Cell::setNextStatus(bool nextStatus)
{
	this->nextStatus = nextStatus;
}

bool Cell::getStatus() const
{
	return this->status;
}

void Cell::nextRound()
{
	this->status = this->nextStatus;
	this->nextStatus = false;
}

void Cell::setCell(Cell& cell)
{
	this->status = cell.status;
	this->nextStatus = cell.nextStatus;
}