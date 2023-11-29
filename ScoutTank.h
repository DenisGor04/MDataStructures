#pragma once
#include "IRace.h"

class ScoutTank  : public IRace    // similar to Human.h
{

public:
	ScoutTank() : IRace(1, 0, -2){

	}

    virtual ~ScoutTank(){

	}
	
};