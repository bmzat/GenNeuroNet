//---------------------------------------------------------------------------

#ifndef InputNeuronH
#define InputNeuronH

#include "Neuron.h"

class CIndividual;
class CWorld;
class CInputNeuron;

__declspec(dllexport) class CInputNeuron : public CNeuron
{
public:
    virtual ~CInputNeuron();
	virtual void stimulate(CIndividual *pInd,CWorld *pWorld)=0;

	static CInputNeuron* create(void *pParam);
};

//---------------------------------------------------------------------------
#endif
