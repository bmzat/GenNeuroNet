#include "Neuron.h"

#include "Axon.h"

CNeuron::CNeuron()
{
	excitement = 0.0f;
	tier = 0;
    stimCount = 0;


}

void CNeuron::stimulate(float stimulus)
{
	excitement+=stimulus;
	++stimCount;
}

void CNeuron::run()
{
  for(std::vector<CAxon*>::iterator it=axon.begin();it!=axon.end();++it){
	(*it)->stimulate(excitement);
  }
  excitement=0.0f;
}