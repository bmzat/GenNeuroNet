#ifndef __NEURON_H
#define __NEURON_H

#include <vector>

class CAxon;

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
