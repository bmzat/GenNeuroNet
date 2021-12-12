#ifndef __NEURON_H
#define __NEURON_H

#include <vector>
#include <string>

class CAxon;
class CNeuron;

typedef enum {
        DBG_STIMULATE=1,
        DBG_RUN=2,
        DBG_INPUT=4,

        DBG_UNKNOWN=1024
}NDBG_REASON;

typedef float neuronDebugCallback(unsigned int reason, void* pData, CNeuron *pNeuron);

typedef struct {
        unsigned int mask;
        neuronDebugCallback *fn;
        void *pData;
}NeuronDebugHandler_t;


__declspec(dllexport) class CNeuron{
	public:
		CNeuron();

	virtual void stimulate(float stimulus);
	virtual void run();

        void debug(unsigned int reason);

	float excitement;
	unsigned int stimCount;
	unsigned int tier;
	std::vector<CAxon*> axon;
        std::vector<NeuronDebugHandler_t*> dbg;
        std::string name;
};

#endif
