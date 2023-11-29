#include <gtest/gtest.h>
#include <vector>

#include "MBT.h"
#include "LBT.h"
#include "FutureTank.h"
#include "AlienTank.h"
#include "ITank.h"
#include "Platoon.h"
#include "Platoon.cpp"
#include "TankFactory.h"
#include "TankFactory.cpp"


		TEST(Platoon, SetTeamLeaderTest1)
		{
			Platoon TestSquad;
			shared_ptr<ITank> theItem;

			TestSquad.setTeamLeader(theItem);
			ASSERT_EQ(theItem, TestSquad.getLeadTank());

		}

		TEST(Platoon, SetTeamLeaderTest2)
		{
			Platoon TestSquad1;
			Platoon TestSquad2;

			shared_ptr<ITank> m_leader1;
			shared_ptr<ITank> m_leader2;

			TestSquad1.setTeamLeader(m_leader1);
			TestSquad2.setTeamLeader(m_leader2);

			ASSERT_EQ(m_leader1, TestSquad1.getLeadTank());
			ASSERT_EQ(m_leader2, TestSquad2.getLeadTank());

		}

		TEST(Platoon, AddSupportTest1)
		{
			Platoon TestSquad;

			shared_ptr<ITank> supportTank_1;
			shared_ptr<ITank> supportTank_2;
			shared_ptr<ITank> supportTank_3;
			shared_ptr<ITank> supportTank_4;

			vector<shared_ptr<ITank>> support_Team;

			support_Team.push_back(supportTank_1);
        	support_Team.push_back(supportTank_2);
        	support_Team.push_back(supportTank_3);
        	support_Team.push_back(supportTank_4);

			TestSquad.addSupport(supportTank_1);
			TestSquad.addSupport(supportTank_2);
			TestSquad.addSupport(supportTank_3);
			TestSquad.addSupport(supportTank_4);

			ASSERT_EQ(support_Team, TestSquad.getSupport());
			

		}

		TEST(Platoon, AddSupportTest2)
		{
			Platoon TestSquad1;
			Platoon TestSquad2;

			shared_ptr<ITank> TankTeam1_1;
			shared_ptr<ITank> TankTeam1_2;
			shared_ptr<ITank> TankTeam1_3;
			shared_ptr<ITank> TankTeam1_4;

			shared_ptr<ITank> TankTeam2_1;
			shared_ptr<ITank> TankTeam2_2;
			shared_ptr<ITank> TankTeam2_3;
			shared_ptr<ITank> TankTeam2_4;

			vector<shared_ptr<ITank>> support_Team1;
			vector<shared_ptr<ITank>> support_Team2;

			support_Team1.push_back(TankTeam1_1);
        	support_Team1.push_back(TankTeam1_2);
        	support_Team1.push_back(TankTeam1_3);
        	support_Team1.push_back(TankTeam1_4);

			support_Team2.push_back(TankTeam2_1);
        	support_Team2.push_back(TankTeam2_2);
        	support_Team2.push_back(TankTeam2_3);
        	support_Team2.push_back(TankTeam2_4);

			TestSquad1.addSupport(TankTeam1_1);
			TestSquad1.addSupport(TankTeam1_2);
			TestSquad1.addSupport(TankTeam1_3);
			TestSquad1.addSupport(TankTeam1_4);

			TestSquad2.addSupport(TankTeam2_1);
			TestSquad2.addSupport(TankTeam2_2);
			TestSquad2.addSupport(TankTeam2_3);
			TestSquad2.addSupport(TankTeam2_4);

			ASSERT_EQ(support_Team1, TestSquad1.getSupport());

			ASSERT_EQ(support_Team2, TestSquad2.getSupport());

		}

		TEST(Platoon, GetTankHealthTest1)
		{
			Platoon Test;

			shared_ptr<ITank> the_Tank = TankFactory::GetTankFactory().CreateTank(TankFactory::LBTType, TankFactory::InfantryType);

    		shared_ptr<LBT> LBT1 = std::dynamic_pointer_cast<LBT>(the_Tank);

			ASSERT_EQ(50,Test.getHealth(the_Tank));

		}

		TEST(Platoon, GetTankHealthTest2)
		{
			Platoon Test_Squad;

			shared_ptr<ITank> Squad2_MBT = TankFactory::GetTankFactory().CreateTank(TankFactory::MBTType, TankFactory::InfantryType);

			shared_ptr<MBT> Mainbattletank2 = std::dynamic_pointer_cast<MBT>(Squad2_MBT);

    		//Test_Squad.setTeamLeader(Mainbattletank2);


    		shared_ptr<ITank> Squad2_Future = TankFactory::GetTankFactory().CreateTank(TankFactory::FutureType, TankFactory::ScoutType);

    		shared_ptr<FutureTank> Lightbattletank2 = std::dynamic_pointer_cast<FutureTank>(Squad2_Future);

   			//Test_Squad.addSupport(Lightbattletank2);


    		shared_ptr<ITank> Squad2_Alien = TankFactory::GetTankFactory().CreateTank(TankFactory::AlienType, TankFactory::AttackType);

    		shared_ptr<AlienTank> Alienbattletank = std::dynamic_pointer_cast<AlienTank>(Squad2_Alien);

    		//Test_Squad.addSupport(Alienbattletank);


   			shared_ptr<ITank> Squad2_Alien2 = TankFactory::GetTankFactory().CreateTank(TankFactory::AlienType, TankFactory::DefenseType);

    		shared_ptr<AlienTank> Alienbattletank2 = std::dynamic_pointer_cast<AlienTank>(Squad2_Alien2);

    		//Test_Squad.addSupport(Alienbattletank2);

			ASSERT_EQ(200,Test_Squad.getHealth(Squad2_MBT));
			ASSERT_EQ(200,Test_Squad.getHealth(Squad2_Future));
			ASSERT_EQ(200,Test_Squad.getHealth(Squad2_Alien));
			ASSERT_EQ(200,Test_Squad.getHealth(Squad2_Alien2));

		}

		TEST(Platoon, getSupportTest1)
		{
			Platoon Test;

			vector<shared_ptr<ITank>> Tanks_List;

			shared_ptr<ITank> Squad1_MBT = TankFactory::GetTankFactory().CreateTank(TankFactory::MBTType, TankFactory::AttackType);

			shared_ptr<MBT> Mainbattletank1 = std::dynamic_pointer_cast<MBT>(Squad1_MBT);                                           

   			Test.setTeamLeader(Mainbattletank1);


   			shared_ptr<ITank> Squad1_LBT_Infantry = TankFactory::GetTankFactory().CreateTank(TankFactory::LBTType, TankFactory::InfantryType);

    		shared_ptr<LBT> Lightbattletank1 = std::dynamic_pointer_cast<LBT>(Squad1_LBT_Infantry);

    		Test.addSupport(Lightbattletank1);

    
    		shared_ptr<ITank> Squad1_LBT_Defense = TankFactory::GetTankFactory().CreateTank(TankFactory::LBTType, TankFactory::DefenseType);

    		shared_ptr<LBT> Lightbattletank2 = std::dynamic_pointer_cast<LBT>(Squad1_LBT_Defense);

    		Test.addSupport(Lightbattletank2);

   
    		shared_ptr<ITank> Squad1_Future = TankFactory::GetTankFactory().CreateTank(TankFactory::FutureType, TankFactory::ScoutType);

    		shared_ptr<FutureTank> Futurebattletank1 = std::dynamic_pointer_cast<FutureTank>(Squad1_Future);

    		Test.addSupport(Futurebattletank1);

			Tanks_List.push_back(Lightbattletank1);
			Tanks_List.push_back(Lightbattletank2);
			Tanks_List.push_back(Futurebattletank1);

			ASSERT_EQ(Tanks_List,Test.getSupport());

		}

		TEST(Platoon, getSupportTest2)
		{
			Platoon Test_Squad_1;
			Platoon Test_Squad_2;	

			vector<shared_ptr<ITank>> Tanks_Squad1;
			vector<shared_ptr<ITank>> Tanks_Squad2;


   			shared_ptr<ITank> Squad1_LBT_Infantry = TankFactory::GetTankFactory().CreateTank(TankFactory::LBTType, TankFactory::InfantryType);

    		shared_ptr<LBT> Lightbattletank1 = std::dynamic_pointer_cast<LBT>(Squad1_LBT_Infantry);

    		Test_Squad_1.addSupport(Lightbattletank1);                                                                           // set this tank to be the member of its platoon (or team)

    
    		shared_ptr<ITank> Squad1_LBT_Defense = TankFactory::GetTankFactory().CreateTank(TankFactory::LBTType, TankFactory::DefenseType);

    		shared_ptr<LBT> Lightbattletank2 = std::dynamic_pointer_cast<LBT>(Squad1_LBT_Defense);

    		Test_Squad_1.addSupport(Lightbattletank2);

   
    		shared_ptr<ITank> Squad1_Future = TankFactory::GetTankFactory().CreateTank(TankFactory::FutureType, TankFactory::ScoutType);

    		shared_ptr<FutureTank> Futurebattletank1 = std::dynamic_pointer_cast<FutureTank>(Squad1_Future);

    		Test_Squad_1.addSupport(Futurebattletank1);

			Tanks_Squad1.push_back(Lightbattletank1);
			Tanks_Squad1.push_back(Lightbattletank2);
			Tanks_Squad1.push_back(Futurebattletank1);



			shared_ptr<ITank> Squad2_Future = TankFactory::GetTankFactory().CreateTank(TankFactory::FutureType, TankFactory::ScoutType);

    		shared_ptr<FutureTank> Lightbattletank3 = std::dynamic_pointer_cast<FutureTank>(Squad2_Future);

    		Test_Squad_2.addSupport(Lightbattletank3);


    		shared_ptr<ITank> Squad2_Alien = TankFactory::GetTankFactory().CreateTank(TankFactory::AlienType, TankFactory::AttackType);

    		shared_ptr<AlienTank> Alienbattletank = std::dynamic_pointer_cast<AlienTank>(Squad2_Alien);

    		Test_Squad_2.addSupport(Alienbattletank);


    		shared_ptr<ITank> Squad2_Alien2 = TankFactory::GetTankFactory().CreateTank(TankFactory::AlienType, TankFactory::DefenseType);

    		shared_ptr<AlienTank> Alienbattletank2 = std::dynamic_pointer_cast<AlienTank>(Squad2_Alien2);

    		Test_Squad_2.addSupport(Alienbattletank2);

			Tanks_Squad2.push_back(Lightbattletank3);
			Tanks_Squad2.push_back(Alienbattletank);
			Tanks_Squad2.push_back(Alienbattletank2);



			ASSERT_EQ(Tanks_Squad1,Test_Squad_1.getSupport());

			ASSERT_EQ(Tanks_Squad2,Test_Squad_2.getSupport());

		}

		TEST(Platoon, GetAmmoCountTest1)
		{
			Platoon Test;

			shared_ptr<ITank> the_Tank = TankFactory::GetTankFactory().CreateTank(TankFactory::LBTType, TankFactory::InfantryType);

    		shared_ptr<LBT> LBT1 = std::dynamic_pointer_cast<LBT>(the_Tank);

			ASSERT_EQ(35,Test.getAmmo(the_Tank));
		}

		TEST(Platoon, GetAmmoCountTest2)
		{
			Platoon Test_Squad;

			shared_ptr<ITank> Squad2_MBT = TankFactory::GetTankFactory().CreateTank(TankFactory::MBTType, TankFactory::InfantryType);

			shared_ptr<MBT> Mainbattletank2 = std::dynamic_pointer_cast<MBT>(Squad2_MBT);

    		//Test_Squad.setTeamLeader(Mainbattletank2);


    		shared_ptr<ITank> Squad2_Future = TankFactory::GetTankFactory().CreateTank(TankFactory::FutureType, TankFactory::ScoutType);

    		shared_ptr<FutureTank> Lightbattletank2 = std::dynamic_pointer_cast<FutureTank>(Squad2_Future);

   			//Test_Squad.addSupport(Lightbattletank2);


    		shared_ptr<ITank> Squad2_Alien = TankFactory::GetTankFactory().CreateTank(TankFactory::AlienType, TankFactory::AttackType);

    		shared_ptr<AlienTank> Alienbattletank = std::dynamic_pointer_cast<AlienTank>(Squad2_Alien);

    		//Test_Squad.addSupport(Alienbattletank);


   			shared_ptr<ITank> Squad2_Alien2 = TankFactory::GetTankFactory().CreateTank(TankFactory::AlienType, TankFactory::DefenseType);

    		shared_ptr<AlienTank> Alienbattletank2 = std::dynamic_pointer_cast<AlienTank>(Squad2_Alien2);

    		//Test_Squad.addSupport(Alienbattletank2);

			ASSERT_EQ(10,Test_Squad.getAmmo(Squad2_MBT));
			ASSERT_EQ(10,Test_Squad.getAmmo(Squad2_Future));
			ASSERT_EQ(8,Test_Squad.getAmmo(Squad2_Alien));
			ASSERT_EQ(8,Test_Squad.getAmmo(Squad2_Alien2));
		}

		TEST(Platoon, AttackEnemyTest1)
		{
			Platoon Test;

			shared_ptr<ITank> Squad1_MBT = TankFactory::GetTankFactory().CreateTank(TankFactory::MBTType, TankFactory::AttackType);

			shared_ptr<MBT> Mainbattletank1 = std::dynamic_pointer_cast<MBT>(Squad1_MBT);                                             


    		shared_ptr<ITank> Squad2_LBT_Infantry = TankFactory::GetTankFactory().CreateTank(TankFactory::LBTType, TankFactory::InfantryType);

    		shared_ptr<LBT> Lightbattletank1 = std::dynamic_pointer_cast<LBT>(Squad2_LBT_Infantry);

    		
			shared_ptr<ITank> attacker;
    		shared_ptr<ITank> target;

    		attacker = Squad1_MBT;        
    		target = Squad2_LBT_Infantry;

    		Test.Attack_Enemy(attacker, target);

			ASSERT_EQ(9,Test.getAmmo(attacker));    // new ammo = ammo - 1
			ASSERT_EQ(25, Test.getHealth(target));  // new health = health - 25

			ASSERT_EQ(35,Test.getAmmo(target));        // checking to make sure no changes in target's ammo count
			ASSERT_EQ(200, Test.getHealth(attacker));  // checking to make sure no change in attacker's health

		}

		TEST(Platoon, AttackEnemyTest2)
		{

			Platoon Squad1;
    		//Platoon Squad2;

    		// First make the first Platoon (team or "Adventuring party")
	
    		shared_ptr<ITank> Squad1_MBT = TankFactory::GetTankFactory().CreateTank(TankFactory::MBTType, TankFactory::AttackType);    // create a tank in the factory

			shared_ptr<MBT> Mainbattletank1 = std::dynamic_pointer_cast<MBT>(Squad1_MBT);                                             // dynamic pointer cast 

    		//Squad1.setTeamLeader(Mainbattletank1);                                                             // set this tank to be the leader of its platoon (or team)


    		shared_ptr<ITank> Squad1_LBT_Infantry = TankFactory::GetTankFactory().CreateTank(TankFactory::LBTType, TankFactory::InfantryType);

    		shared_ptr<LBT> Lightbattletank1 = std::dynamic_pointer_cast<LBT>(Squad1_LBT_Infantry);

    		//Squad1.addSupport(Lightbattletank1);                                                                           // set this tank to be the member of its platoon (or team)

    
    		shared_ptr<ITank> Squad1_LBT_Defense = TankFactory::GetTankFactory().CreateTank(TankFactory::LBTType, TankFactory::DefenseType);

    		shared_ptr<LBT> Lightbattletank2 = std::dynamic_pointer_cast<LBT>(Squad1_LBT_Defense);

    		//Squad1.addSupport(Lightbattletank2);

   
    		shared_ptr<ITank> Squad1_Future = TankFactory::GetTankFactory().CreateTank(TankFactory::FutureType, TankFactory::ScoutType);

   		 	shared_ptr<FutureTank> Futurebattletank1 = std::dynamic_pointer_cast<FutureTank>(Squad1_Future);

    		//Squad1.addSupport(Futurebattletank1);


    		// Now make the second Platoon (other team or "Adventuring party")

    		shared_ptr<ITank> Squad2_MBT = TankFactory::GetTankFactory().CreateTank(TankFactory::MBTType, TankFactory::InfantryType);

			shared_ptr<MBT> Mainbattletank2 = std::dynamic_pointer_cast<MBT>(Squad2_MBT);

    		//Squad2.setTeamLeader(Mainbattletank2);


    		shared_ptr<ITank> Squad2_Future = TankFactory::GetTankFactory().CreateTank(TankFactory::FutureType, TankFactory::ScoutType);

    		shared_ptr<FutureTank> Lightbattletank3 = std::dynamic_pointer_cast<FutureTank>(Squad2_Future);

    		//Squad2.addSupport(Lightbattletank3);


    		shared_ptr<ITank> Squad2_Alien = TankFactory::GetTankFactory().CreateTank(TankFactory::AlienType, TankFactory::AttackType);

    		shared_ptr<AlienTank> Alienbattletank = std::dynamic_pointer_cast<AlienTank>(Squad2_Alien);

    		//Squad2.addSupport(Alienbattletank);


    		shared_ptr<ITank> Squad2_Alien2 = TankFactory::GetTankFactory().CreateTank(TankFactory::AlienType, TankFactory::DefenseType);

    		shared_ptr<AlienTank> Alienbattletank2 = std::dynamic_pointer_cast<AlienTank>(Squad2_Alien2);

   			//Squad2.addSupport(Alienbattletank2);


			// First attack: target one takes damage from attacking tank

			shared_ptr<ITank> attacker1;
    		shared_ptr<ITank> target1;

    		attacker1 = Squad1_MBT;   // Squad 1 tank     
    		target1 = Squad2_MBT;	 // Squad 2 tank

    		Squad1.Attack_Enemy(attacker1, target1);

			ASSERT_EQ(9,Squad1.getAmmo(attacker1));    // new ammo = ammo - 1
			ASSERT_EQ(175, Squad1.getHealth(target1));  // new health = health - 25

			ASSERT_EQ(10,Squad1.getAmmo(target1));        // checking to make sure no changes in target's ammo count
			ASSERT_EQ(200, Squad1.getHealth(attacker1));  // checking to make sure no change in attacker's health

			// Second attack: target 1 takes more damage from antoher attacking tank

			shared_ptr<ITank> attacker2 = Squad1_LBT_Defense;   // Squad 1 tank     

    		Squad1.Attack_Enemy(attacker2, target1);

			ASSERT_EQ(34,Squad1.getAmmo(attacker2));    // new ammo = ammo - 1
			ASSERT_EQ(165, Squad1.getHealth(target1));  // new health = health - 10

			ASSERT_EQ(10,Squad1.getAmmo(target1));        // checking to make sure no changes in target's ammo count
			ASSERT_EQ(50,Squad1.getHealth(attacker2));  // checking to make sure no change in attacker's health

			// Third attack: target 1 becomes attacker 3 and attacks another tank

			shared_ptr<ITank> attacker3 = target1;
			shared_ptr<ITank> target2 = Squad1_Future;

			Squad1.Attack_Enemy(attacker3, target2);

			ASSERT_EQ(9,Squad1.getAmmo(attacker3));    // new ammo = ammo - 1
			ASSERT_EQ(175, Squad1.getHealth(target2));  // new health = health - 25

			ASSERT_EQ(10,Squad1.getAmmo(target2));        // checking to make sure no changes in target's ammo count
			ASSERT_EQ(165,Squad1.getHealth(attacker3));  // checking to make sure no change in attacker's health

			// These tanks took no damage and did not attack, so there ammo count and ammor health should be the same:

			ASSERT_EQ(35,Squad1.getAmmo(Squad1_LBT_Infantry));
			ASSERT_EQ(50,Squad1.getHealth(Squad1_LBT_Infantry));

			ASSERT_EQ(10,Squad1.getAmmo(Squad2_Future));
			ASSERT_EQ(200,Squad1.getHealth(Squad2_Future));
			
			ASSERT_EQ(8,Squad1.getAmmo(Squad2_Alien));
			ASSERT_EQ(200,Squad1.getHealth(Squad2_Alien));
			
			ASSERT_EQ(8,Squad1.getAmmo(Squad2_Alien2));
			ASSERT_EQ(200,Squad1.getHealth(Squad2_Alien2));
			
		}


	int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

