#pragma once
#include "IRace.h"

class AttackTank  : public IRace    // similar to Human.h
{

public:
	AttackTank() : IRace(1, 0, -2){

	}

    virtual ~AttackTank(){

	}
	
};