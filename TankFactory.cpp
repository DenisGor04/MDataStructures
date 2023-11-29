#include "TankFactory.h"
#include "MBT.h"
#include "LBT.h"
#include "FutureTank.h"
#include "AlienTank.h"
#include "DefenseTank.h"
#include "AttackTank.h"
#include "InfantryTank.h"
#include "ScoutTank.h"


using namespace std;

TankFactory &TankFactory::GetTankFactory()
{
	static TankFactory s;
	return s;
}


shared_ptr<ITank> TankFactory::CreateTank(enumOfTypeTank enumOfTypeTankType, raceOfTypeTank race)
{
	shared_ptr<ITank> retVal = nullptr;
	if (enumOfTypeTankType == MBTType)
	{
		retVal = make_shared<MBT>(m_raceMap[race]);
	}
    else if (enumOfTypeTankType == LBTType)
    {
        retVal = make_shared<LBT>(m_raceMap[race]); 
    }
	else if (enumOfTypeTankType == FutureType)
    {
        retVal = make_shared<FutureTank>(m_raceMap[race]); 
    }
	else if (enumOfTypeTankType == AlienType)
    {
        retVal = make_shared<AlienTank>(m_raceMap[race]); 
    }

	return retVal;
}

TankFactory::TankFactory()   // WHAT DOES THIS DO??
{
		
	shared_ptr<IRace> t1 = make_shared<AttackTank>();
	shared_ptr<IRace> t2 = make_shared<DefenseTank>();
	shared_ptr<IRace> t3 = make_shared<ScoutTank>();
	shared_ptr<IRace> t4 = make_shared<InfantryTank>();

	m_raceMap.insert(pair(AttackType, t1));    // depending on what these are for, this section may need modifications
	m_raceMap[DefenseType]= t2;
	m_raceMap[ScoutType]= t3;
	m_raceMap[InfantryType]= t4;
	//m_raceMap.insert(std::pair(ZergType, t1));
	//m_raceMap[HumanType]= t2;
}

// destructor
TankFactory::~TankFactory() 
{

}