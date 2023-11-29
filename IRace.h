#pragma once

// This is an abstract class

class IRace
{
public:
	IRace(int HullPointMods, int speedMods, int dmgPerHit) :m_HullPointMods(HullPointMods), m_ammo_count(speedMods), m_dmgPerHit(dmgPerHit){
	}

	virtual int GetHullPointMods(){ 
		
		return m_HullPointMods; 
	}

	virtual int Get_dmgPerHit(){ 
		
		return m_dmgPerHit; 
	}

	virtual int Get_ammo_count(){ 
		
		return m_ammo_count; 
	}

    ~IRace(){
	}

protected:
	
	int m_HullPointMods; // Health of tank armor
	int m_dmgPerHit;   	 // damage main gun inflicts
	int m_ammo_count;    // ammo tank can hold
};