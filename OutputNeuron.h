//---------------------------------------------------------------------------

#ifndef OutputNeuronH
#define OutputNeuronH

#include "Neuron.h"

class CIndividual;
class CWorld;
class COutputNeuron;

__declspec(dllexport) class COutputNeuron : public CNeuron
{
public:
	virtual void run(CIndividual *pInd,CWorld *pWorld);

	static COutputNeuron* create(void *pParam);
};
//---------------------------------------------------------------------------
#endif
