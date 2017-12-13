#include "Map.h"

Map::Map(Position& position) : numberColumns(position.getX() + 1), numberLines(position.getY() + 1)
{
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
	if (this->numberColumns != numberColumns)
		this->resizeMap(Position(numberColumns, this->numberLines));
}

void Map::setNumberLines(unsigned int numberLines)
{
	if (this->numberLines != numberLines)
		this->resizeMap(Position(this->numberColumns, numberLines));
}

int Map::getNumberColumns() const
{
	return this->numberColumns;
}

int Map::getNumberLines() const
{
	return this->numberLines;
}

void Map::resizeMap(Position& position, bool statusNewCell)
{
	if (!(position.getX() + 1 - this->numberColumns) || !(position.getY() - this->numberLines))
	{
		Cell** temp = map;
		int diffrenceNumberColumn = this->numberColumns - (position.getX() + 1);
		int diffrenceNumberLines = this->numberLines - (position.getY() + 1);

		map = new Cell*[position.getX() + 1];

		for (int i = 0; i < position.getX() + 1; i++)
			map[i] = new Cell[position.getY() + 1];

		if (statusNewCell)
			for (int i = position.getX(); i < this->numberColumns; i++)
				for (int j = position.getY(); j < this->numberLines; j++)
					map[i][j].setStatus(statusNewCell);

		for (int i = 0; i < this->numberColumns && i < position.getX() + 1; i++)
			for (int j = 0; j < this->numberLines && position.getY() + 1; j++)
				map[i][j].setCell(temp[i][j]);

		for (int i = 0; i < this->numberColumns; i++)
			delete[] temp[i];

		delete[] temp;
		this->numberColumns = position.getX() + 1;
		this->numberLines = position.getY() + 1;
	}
}

void Map::setStatusCell(Position& position, bool status) const
{
	if (position.getX() > 0 && position.getX() < this->numberColumns && position.getY() > 0 && position.getY() < this->numberLines)
		this->map[position.getX()][position.getY()].setStatus(status);
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

void Map::nextRound() const
{
	for (int i = 0; i < this->numberColumns; i++)
		for (int j = 0; j < this->numberLines; j++)
			map[i][j].nextRound();
}