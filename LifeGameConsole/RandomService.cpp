#include "RandomService.h"



RandomService::RandomService(Map* map, Configuration* configuration) : map(map), configuration(configuration)
{
}


RandomService::~RandomService()
{
}

void RandomService::execute()
{
	int numberCellsToRand = this->configuration->getNumberCellRand();
	int numberCells = 0;
	srand(time(NULL));

	while (numberCells <= numberCellsToRand)
	for (int i=0;i<this->map->getNumberColumns() && numberCells <= numberCellsToRand;i++)
		for (int j = 0; j < this->map->getNumberLines() && numberCells <= numberCellsToRand; j++)
		{
			if (map->getStatusCell(Position(i + 1, j + 1)) == configuration->isRandAliveCell())
				continue;
			if (rand() % 2)
			{
				map->setStatusCell(Position(i + 1, j + 1), configuration->isRandAliveCell());
				numberCells++;
			}
		}
}
