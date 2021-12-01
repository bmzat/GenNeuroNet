//---------------------------------------------------------------------------

#ifndef IRandomH
#define IRandomH

#include "../InputNeuron.h"

__declspec(dllexport) class IRandom : public CInputNeuron{
	public:
		 static CInputNeuron *create(void *pData);
		 virtual void stimulate(CIndividual *pInd,CWorld *pWorld);

};

//---------------------------------------------------------------------------
#endif
