#include "Map.h"



Map::Map(Position& position)
{
	this->numberColumns = position.getX() + 1;
	this->numberLines = position.getY() + 1;
	map = new Cell*[this->numberColumns];

	for (int i=0; i < numberColumns; i++)
		map[i] = new Cell[this->numberLines];
}

Map::Map(int numberColumns, int numberLines)
{
	this->numberColumns = numberColumns;
	this->numberLines = numberLines;

	map = new Cell*[this->numberColumns];

	for (int i=0; i < numberColumns; i++)
		map[i] = new Cell[this->numberLines];
}

Map::~Map()
{
	for (int i = 0; i < numberColumns; i++)
		delete[] map[i];

	delete[] map;
}

void Map::setNumberColumns(unsigned int numberColumns)
{
	if (this->numberColumns > numberColumns)
		this->addColumns(this->numberColumns - numberColumns);
	else if (this->numberColumns < numberColumns)
		this->removeColumns(numberColumns - this->numberColumns);
}

void Map::setNumberLines(unsigned int numberLines)
{
	if (this->numberLines > numberLines)
		this->addLines(this->numberLines - numberLines);
	else if (this->numberLines < numberLines)
		this->removeLines(numberLines - this->numberLines);
}

int Map::getNumberColumns() const
{
	return this->numberColumns;
}

int Map::getNumberLines() const
{
	return this->numberLines;
}

void Map::addColumns(unsigned int numberNewColumns, bool statusNewCell)
{
	if (!numberNewColumns)
	{
		Cell** temp = map;
		this->numberColumns += numberNewColumns;
		map = new Cell*[this->numberColumns];

		for (int i = 0; i < this->numberColumns; i++)
			map[i] = new Cell [this->numberLines];

		for (int i=0;i<this->numberColumns - numberNewColumns;i++)
			for (int j = 0; j<this->numberLines; j++)
				map[i][j].setCell(temp[i][j]);

		if (statusNewCell)
			for (int i = this->numberColumns - numberNewColumns; i < this->numberColumns; i++)
				for (int j = 0; j < this->numberLines; j++)
					map[i][j].setStatus(statusNewCell);

		for (int i = 0; i < this->numberColumns - numberNewColumns; i++)
			delete[] temp[i];

		delete[] temp;
	}
}

void Map::addLines(unsigned int numberNewLines, bool statusNewCell)
{
	if (!numberNewLines)
	{
		Cell** temp = map;
		this->numberLines += numberNewLines;
		map = new Cell*[this->numberColumns];

		for (int i = 0; i < this->numberColumns; i++)
			map[i] = new Cell[this->numberLines];

		for (int i = 0; i<this->numberColumns; i++)
			for (int j = 0; j<this->numberLines-numberNewLines; j++)
				map[i][j].setCell(temp[i][j]);

		if (statusNewCell)
			for (int i = 0; i < this->numberColumns; i++)
				for (int j = this->numberLines-numberNewLines; j < this->numberLines; j++)
					map[i][j].setStatus(statusNewCell);

		for (int i = 0; i < this->numberColumns; i++)
			delete[] temp[i];

		delete[] temp;
	}
}

void Map::removeColumns(unsigned int numberRemoveColumns)
{
	if (!numberRemoveColumns)
	{
		Cell** temp = map;
		this->numberColumns -= numberRemoveColumns;
		map = new Cell*[this->numberColumns];

		for (int i = 0; i < this->numberColumns; i++)
			map[i] = new Cell[this->numberLines];

		for (int i = 0; i<this->numberColumns; i++)
			for (int j = 0; j<this->numberLines; j++)
				map[i][j].setCell(temp[i][j]);

		for (int i = 0; i < this->numberColumns + numberRemoveColumns; i++)
			delete[] temp[i];

		delete[] temp;
	}
}

void Map::removeLines(unsigned int numberRemoveLines)
{
	if (!numberRemoveLines)
	{
		Cell** temp = map;
		this->numberLines -= numberRemoveLines;
		map = new Cell*[this->numberColumns];

		for (int i = 0; i < this->numberColumns; i++)
			map[i] = new Cell[this->numberLines];

		for (int i = 0; i<this->numberColumns; i++)
			for (int j = 0; j<this->numberLines; j++)
				map[i][j].setCell(temp[i][j]);

		for (int i = 0; i < this->numberColumns; i++)
			delete[] temp[i];

		delete[] temp;
	}
}
void Map::setStatusCell(Position& position, bool status) const
{
	if (position.getX() > 0 && position.getX() < this->numberColumns && position.getY() > 0 && position.getY() < this->numberLines)
		this->map[position.getX()][position.getY()].setStatus(status);
}

void Map::setStatusCell(unsigned int x, unsigned int y, bool status) const
{
	if (x > 0 && x < this->numberColumns && y > 0 && y < this->numberLines)
		this->map[x][y].setStatus(status);
}

bool Map::getStatusCell(unsigned int x, unsigned int y) const
{
	if (x > 0 && x < this->numberColumns && y > 0 && y < this->numberLines)
		return this->map[x][y].getStatus();
	return false;
}

bool Map::getStatusCell(Position& position) const
{
	if (position.getX() > 0 && position.getX() < this->numberColumns && position.getY() > 0 && position.getY() < this->numberLines)
		return this->map[position.getX()][position.getY()].getStatus();
	return false;
}

void Map::setNextStatusCell(Position& position, bool nextStatus) const
{
	if (position.getX() > 0 && position.getX() < this->numberColumns && position.getY() > 0 && position.getY() < this->numberLines)
		this->map[position.getX()][position.getY()].setNextStatus(nextStatus);
}

void Map::setNextStatusCell(unsigned int x, unsigned int y, bool nextStatus) const
{
	if (x > 0 && x < this->numberColumns && y > 0 && y < this->numberLines)
		this->map[x][y].setNextStatus(nextStatus);
}

void Map::nextRound() const
{
	for (int i = 0; i < this->numberColumns; i++)
		for (int j = 0; j < this->numberLines; j++)
			map[i][j].nextRound();
}