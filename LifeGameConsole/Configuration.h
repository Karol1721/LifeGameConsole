#pragma once
#include "Queue.h"
#include "Position.h"

class Configuration
{
public:
	Configuration();
	~Configuration();
private:
	int timeRound;
	int numberRounds;
	int numberCellRand;
	int numberCells;
	int numberAliveCell;
	bool insertAliveCell;
	bool randAliveCell;
	bool simulationStatus;
	Queue* queue;
public:
	void setTimeRound(int timeRound);
	void setNumberRounds(int numberRounds);
	void setNumberCellRand(int numberCellRand);
	void setNumberCells(int numberCells);
	void setInsertAliveCell(bool insertAliveCell);
	void setRandAliveCell(bool randAliveCell);
	void setSimulationStatus(bool simulationStatus);
	void setNumberAliveCell(int numberAliveCell);
	int getTimeRound();
	int getNumberRounds();
	int getNumberCellRand();
	int getNumberCells();
	int getNumberAliveCells();
	bool isInsertAliveCell();
	bool isRandAliveCell();
	bool isSimulationStatus();
	void addToQueue(Position* position);
	Position* getFromQueue();
	int getSizeQueue();
};

