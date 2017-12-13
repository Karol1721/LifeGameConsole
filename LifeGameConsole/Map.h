#pragma once
#include "Cell.h"
#include "Position.h"

class Map
{
public:
	Map(Position& position);
	~Map();
private:
	int numberColumns;
	int numberLines;
	Cell** map;
public:
	void setNumberColumns(unsigned int numberColumns);
	void setNumberLines(unsigned int numberLines);
	int getNumberColumns() const;
	int getNumberLines() const;
	void resizeMap(Position& position, bool statusNewCell = false);
	void setStatusCell(Position& position, bool status) const;
	bool getStatusCell(Position& position) const;
	void setNextStatusCell(Position& position, bool nextStatus) const;
	void nextRound() const;
};

