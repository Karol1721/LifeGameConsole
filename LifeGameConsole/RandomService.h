#pragma once
#include "Map.h"
#include "Configuration.h"
#include "IService.h"
#include <cstdlib>
#include <ctime>

class RandomService : public IService
{
public:
	RandomService(Map* map, Configuration* configuration);
	~RandomService();
private:
	Map* map;
	Configuration* configuration;
public:
	void execute();
};

