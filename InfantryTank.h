#pragma once
#include "IRace.h"

class InfantryTank  : public IRace
{

public:
	InfantryTank() :  IRace(-1, 0, 2){

	}

    virtual ~InfantryTank(){

	}

};