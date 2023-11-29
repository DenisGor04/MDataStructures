#pragma once

#include <vector>
#include <memory>

#include "MBT.h"
#include "LBT.h"
#include "FutureTank.h"
#include "AlienTank.h"

using namespace std;

// Declaration for the class 

class ITank;

class Platoon  // similar to Fleet.h
{
private:
   // Data field
   shared_ptr<ITank> m_Leader;          // each team will have a leading tanks (Leader)
   vector<shared_ptr<ITank>> m_support; // each team has a set of support vehicles (that support the leader)
   bool team_Leader = false;            // set to true once the team leader has been made
   int m_count_support = 0;             // keeps track of number of support vehicles in platoon


   
public:
   // Default constructor
   Platoon();
   
   // Parameterized constructor.  Give the Team a leader tank
   Platoon(const shared_ptr<ITank> Leader);
   
   // Mutator method that can change the value of the data field
   void setTeamLeader(const shared_ptr<ITank> theLeader);
   
   // Accessor method to get the value of the data field
   shared_ptr<ITank> getLeadTank();

   int getHealth(shared_ptr<ITank> the_Tank);

   int getAmmo(shared_ptr<ITank> the_Tank);

   void addSupport(const shared_ptr<ITank> theSupport);  

   vector<shared_ptr<ITank>> getSupport();     

   void Attack_Enemy(shared_ptr<ITank> Attacker,shared_ptr<ITank> Target);

   ~Platoon();

};