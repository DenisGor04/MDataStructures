#pragma once

#include "IRace.h"
#include <memory>

class ITank   // similar to IShip.h

// This class defines features of the tanks including gun damage and health tracking

{
public:

    ITank(std::shared_ptr<IRace> race) : m_hull(0), main_gun(0), ammo_count(0), m_race(race){

    }

	virtual int GetHullPoints() = 0;

	virtual int GetDamageHit() = 0;

	virtual int GetAmmoCounter() = 0;

    virtual ~ITank(){

	}

	virtual int GetHitPoints() = 0;

	virtual void TakeDamage(int hit) = 0;

	virtual int GetAmmoCount() = 0;

	virtual int GetHealth() = 0;

protected:

	// This data is protected to prevent pubic acess and having the ability to modify
	int m_hull;
	int main_gun;
	int ammo_count;                // ammo counter
	std::shared_ptr<IRace> m_race; // pointer pointing to race

};