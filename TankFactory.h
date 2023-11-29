#pragma once
#include <memory>
#include <map>

#include "ITank.h"

using namespace std;

//fwd declaration
class IRace;

class TankFactory
{
public:

	// enumerations are useful when we are just trying to create something, in this case a tank.
	enum enumOfTypeTank { MBTType, LBTType, FutureType, AlienType };
	enum raceOfTypeTank { AttackType, DefenseType, ScoutType, InfantryType };

	shared_ptr<ITank> CreateTank(enumOfTypeTank enumOfTypeTankType, raceOfTypeTank race);

	static 	TankFactory & GetTankFactory();

  	TankFactory(const TankFactory &) = delete;
  	TankFactory & operator = (const TankFactory &) = delete;

private:
	map<raceOfTypeTank,shared_ptr<IRace>> m_raceMap;

	TankFactory();
    ~TankFactory();

};