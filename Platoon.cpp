//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing C1-4
    @file PlainBox.cpp */
#include <memory>   
#include <vector>
#include <iostream>

#include "Platoon.h"

using namespace std;

// default constructor
Platoon::Platoon()
{
}

// constructor
Platoon::Platoon(const shared_ptr<ITank> theItem) : m_Leader(theItem)
{
}

// Set a team leader for the platoon
void Platoon::setTeamLeader(const shared_ptr<ITank> theItem)
{
    m_Leader = theItem;
    team_Leader = true;
}  // end setItem

// returns the pointer to the leading tank in the platoon
shared_ptr<ITank> Platoon::getLeadTank()
{
    return m_Leader;
}  // end getItem

// return the current health of the tank from the ITank class
int Platoon::getHealth(shared_ptr<ITank> the_Tank){

    return the_Tank->GetHealth();

}

// returns the current ammunition count stored in the ITank class
int Platoon::getAmmo(shared_ptr<ITank> the_Tank){

    return the_Tank->GetAmmoCount();

}

// Adds infantry tanks to the platoon
void Platoon::addSupport(const shared_ptr<ITank> theSupport)
{ 
    m_support.push_back(theSupport);
    m_count_support++;
}

// Puts the current platoon into a vector
vector<shared_ptr<ITank>> Platoon::getSupport()
{
    return m_support;
}

// This method allows one tank to attack another by importing the shared pointer of both the attacker and the target tank
void Platoon::Attack_Enemy(shared_ptr<ITank> Attacker, shared_ptr<ITank> Target)
{
    int damage = Attacker->GetHitPoints();

    if(damage == -1){

        cout << "Tank is out of ammo. You cannot attack." << endl;
        cout << endl;
    
    }
    else{

        cout << "Enemy Tank is attacked." << endl;
        Target->TakeDamage(damage);
        cout << endl;

    }

}

Platoon::~Platoon(){
}