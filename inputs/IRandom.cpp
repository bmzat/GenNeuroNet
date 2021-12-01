//---------------------------------------------------------------------------

#include <stdlib>
#pragma hdrstop



#include "IRandom.h"
//---------------------------------------------------------------------------

CInputNeuron *IRandom::create(void *pData)
{
	return new IRandom;
}

void IRandom::stimulate(CIndividual *pInd,CWorld *pWorld)
{
	int r = rand();
	this->excitement = (r!=0)?float(RAND_MAX)/float(r):0.0f;
}

#pragma package(smart_init)
