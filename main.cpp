#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <iostream>
#include <memory>

#include "Platoon.h"

#include "ITank.h"
#include "MBT.h"
#include "LBT.h"
#include "FutureTank.h"
#include "AlienTank.h"

#include "TankFactory.h"

// from IRace:
#include "DefenseTank.h"
#include "AttackTank.h"
#include "ScoutTank.h"
#include "InfantryTank.h"

using namespace std;

int main()
{
    
    Platoon Squad1;
    Platoon Squad2;

    // First make the first Platoon (team or "Adventuring party")

	
    shared_ptr<ITank> Squad1_MBT = TankFactory::GetTankFactory().CreateTank(TankFactory::MBTType, TankFactory::AttackType);    // create a tank in the factory

	shared_ptr<MBT> Mainbattletank1 = std::dynamic_pointer_cast<MBT>(Squad1_MBT);                                             // dynamic pointer cast 

    Squad1.setTeamLeader(Mainbattletank1);                                                             // set this tank to be the leader of its platoon (or team)


    shared_ptr<ITank> Squad1_LBT_Infantry = TankFactory::GetTankFactory().CreateTank(TankFactory::LBTType, TankFactory::InfantryType);

    shared_ptr<LBT> Lightbattletank1 = std::dynamic_pointer_cast<LBT>(Squad1_LBT_Infantry);

    Squad1.addSupport(Lightbattletank1);                                                                           // set this tank to be the member of its platoon (or team)

    
    shared_ptr<ITank> Squad1_LBT_Defense = TankFactory::GetTankFactory().CreateTank(TankFactory::LBTType, TankFactory::DefenseType);

    shared_ptr<LBT> Lightbattletank2 = std::dynamic_pointer_cast<LBT>(Squad1_LBT_Defense);

    Squad1.addSupport(Lightbattletank2);

   
    shared_ptr<ITank> Squad1_Future = TankFactory::GetTankFactory().CreateTank(TankFactory::FutureType, TankFactory::ScoutType);

    shared_ptr<FutureTank> Futurebattletank1 = std::dynamic_pointer_cast<FutureTank>(Squad1_Future);

    Squad1.addSupport(Futurebattletank1);


    // Now make the second Platoon (other team or "Adventuring party")

    shared_ptr<ITank> Squad2_MBT = TankFactory::GetTankFactory().CreateTank(TankFactory::MBTType, TankFactory::InfantryType);

	shared_ptr<MBT> Mainbattletank2 = std::dynamic_pointer_cast<MBT>(Squad2_MBT);

    Squad2.setTeamLeader(Mainbattletank2);


    shared_ptr<ITank> Squad2_Future = TankFactory::GetTankFactory().CreateTank(TankFactory::FutureType, TankFactory::ScoutType);

    shared_ptr<FutureTank> Lightbattletank3 = std::dynamic_pointer_cast<FutureTank>(Squad2_Future);

    Squad2.addSupport(Lightbattletank3);


    shared_ptr<ITank> Squad2_Alien = TankFactory::GetTankFactory().CreateTank(TankFactory::AlienType, TankFactory::AttackType);

    shared_ptr<AlienTank> Alienbattletank = std::dynamic_pointer_cast<AlienTank>(Squad2_Alien);

    Squad2.addSupport(Alienbattletank);


    shared_ptr<ITank> Squad2_Alien2 = TankFactory::GetTankFactory().CreateTank(TankFactory::AlienType, TankFactory::DefenseType);

    shared_ptr<AlienTank> Alienbattletank2 = std::dynamic_pointer_cast<AlienTank>(Squad2_Alien2);

    Squad2.addSupport(Alienbattletank2);
    
    //Now lets preform some attack operations:

    cout << "Squad 1 is attacking Sqaud 2:" << endl;
    cout << endl;

    shared_ptr<ITank> attacker;
    shared_ptr<ITank> target;

    attacker = Squad1_MBT;
    target = Squad2_Alien;

    Squad1.Attack_Enemy(attacker, target);

    cout << "The attacker tank has attacked the target." << endl;

}