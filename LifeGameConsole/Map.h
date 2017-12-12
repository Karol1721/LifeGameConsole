#pragma once
#include "Cell.h"
#include "Position.h"

class Map
{
public:
	Map(Position& position);
	Map(int numberColumns, int numberLines);
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
	void addColumns(unsigned int numberNewColumns, bool statusNewCell = false);
	void addLines(unsigned int numberNewLines, bool statusNewCell = false);
	void removeColumns(unsigned int numberRemoveColumns);
	void removeLines(unsigned int numberRemoveLines);
	void setStatusCell(Position& position, bool status) const;
	void setStatusCell(unsigned int x, unsigned int y, bool status) const;
	bool getStatusCell(unsigned int x, unsigned int y) const;
	bool getStatusCell(Position& position) const;
	void setNextStatusCell(Position& position, bool nextStatus) const;
	void setNextStatusCell(unsigned int x, unsigned int y, bool nextStatus) const;
	void nextRound() const;
};

