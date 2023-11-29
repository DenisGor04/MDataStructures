#pragma once
#include <memory>
#include <iostream>

#include "ITank.h"
#include "IRace.h"

using namespace std;


// First type of tank: MBT (Main Battle Tank)
// Abilities/Strenghts: Stronger Armor, Munitions has more damage

class FutureTank : public ITank
{
public:
	// constructor intializes each tanks health (armor strength), ammunition carried, and damage that can be inflicted as integer. These are each at full when first created.
	FutureTank(std::shared_ptr<IRace> race) : ITank(race)   // main attributes: health and manuverability
	{
        main_gun = 28;    // Damage that can be inflicted 
        m_hull = 200;     // overall health
		ammo_count = 10;

	}

	~FutureTank(){}

	virtual int GetHullPoints() override
	{
		int retVal = m_hull + m_race->GetHullPointMods();

		return retVal;
	}

	virtual int GetDamageHit() override
	{ 
		int retVal = main_gun + m_race->Get_dmgPerHit();

		return retVal; 
	}

	virtual int GetAmmoCounter() override
	{ 
		int retVal = ammo_count + m_race->Get_ammo_count();

		return retVal; 
	}

	// tanks attack enemy tank and inflict damage.  Amount of damage determined by main_gun damage rating above.
	int GetHitPoints(){

		int Points = 0;

		if(ammo_count == 0){
			cout << "Tank is out of ammo!" << endl;
			return -1;
		}
		else{
			
			ammo_count--;
			return main_gun;
		}
	}

	// imports tha amount of damage inflicted by enemy tank as an integer and deducts it from the m_hull (armor health tracker)
	void TakeDamage(int hit){

		m_hull = m_hull - hit;

		if(m_hull <= 0){

			cout << "Tank has been destroyed" << endl;

		}

	}

	int GetAmmoCount(){

		return ammo_count;

	}

	int GetHealth(){
		
		return m_hull;
	}

    FutureTank() = delete;

};