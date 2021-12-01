//---------------------------------------------------------------------------

#pragma hdrstop

#include "OutputNeuron.h"
//---------------------------------------------------------------------------

void COutputNeuron::run(CIndividual *pInd,CWorld *pWorld){
			  excitement=0.0f;
}

COutputNeuron* COutputNeuron::create(void *pData)
{
    return new COutputNeuron;
}

#pragma package(smart_init)
