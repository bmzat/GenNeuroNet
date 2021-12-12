//---------------------------------------------------------------------------

#pragma hdrstop

#include "InputNeuron.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

CInputNeuron::~CInputNeuron()
{


}

void CInputNeuron::stimulate(CIndividual *pInd,CWorld *pWorld)
{
#ifdef _DEBUG
      debug(NDBG_REASON::DBG_INPUT);
#else
        throw "CInputNeuron::stimulate() not implemented, need to override in derived class";
#endif
}
