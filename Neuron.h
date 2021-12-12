#ifndef __NEURON_H
#define __NEURON_H

#include <vector>
#include <string>

class CAxon;
class CNeuron;

typedef enum neuronDebugReason{
        DBG_STIMULATE=1,
        DBG_RUN=2,

        DBG_UNKNOWN=1024
};

typedef void neuronDebugCallback(neuronDebugReason reason, void* pData, CNeuron *pNeuron);

typedef struct {
        unsigned int mask;
        neuronDebugCallback *fn;
        void *pData;
}DebugHandler_t;


__declspec(dllexport) class CNeuron{
	public:
		CNeuron();

	virtual void stimulate(float stimulus);
	virtual void run();

	float excitement;
	unsigned int stimCount;
	unsigned int tier;
	std::vector<CAxon*> axon;
};

#endif
