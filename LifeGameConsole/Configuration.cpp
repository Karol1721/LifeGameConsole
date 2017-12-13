#include "Configuration.h"

Configuration::Configuration()
{
	this->timeRound = 0;
	this->numberRounds = 0;
	this->numberCellRand = 0;
	this->numberCells = 0;
	this->insertAliveCell = false;
	this->randAliveCell = true;
	this->simulationStatus = false;
	this->queue = new Queue();
}

Configuration::~Configuration()
{
	delete this->queue;
}

void Configuration::setTimeRound(int timeRound)
{
	this->timeRound = timeRound;
}

void Configuration::setNumberRounds(int numberRounds)
{
	this->numberRounds = numberRounds;
}

void Configuration::setNumberCellRand(int numberCellRand)
{
	this->numberCellRand = numberCellRand;
}

void Configuration::setNumberCells(int numberCells)
{
	this->numberCells = numberCells;
}

void Configuration::setInsertAliveCell(bool insertAliveCell)
{
	this->insertAliveCell = insertAliveCell;
}

void Configuration::setRandAliveCell(bool randAliveCell)
{
	this->randAliveCell = randAliveCell;
}

void Configuration::setSimulationStatus(bool simulationStatus)
{
	this->simulationStatus = simulationStatus;
}

void Configuration::setNumberAliveCell(int numberAliveCell)
{
	this->numberAliveCell = numberAliveCell;
}

int Configuration::getTimeRound()
{
	return this->timeRound;
}

int Configuration::getNumberRounds()
{
	return this->numberRounds;
}

int Configuration::getNumberCellRand()
{
	return this->numberCellRand;
}

int Configuration::getNumberCells()
{
	return this->numberCells;
}

int Configuration::getNumberAliveCells()
{
	return this->numberAliveCell;
}

bool Configuration::isInsertAliveCell()
{
	return this->insertAliveCell;
}

bool Configuration::isRandAliveCell()
{
	return this->randAliveCell;
}

bool Configuration::isSimulationStatus()
{
	return this->simulationStatus;
}

void Configuration::addToQueue(Position* position)
{
	this->queue->add(position);
}

Position* Configuration::getFromQueue()
{
	return this->queue->get();
}

int Configuration::getSizeQueue()
{
	return this->queue->getSize();
}