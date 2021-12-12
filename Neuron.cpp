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
        debug(NDBG_REASON::DBG_STIMULATE);
}

void CNeuron::run()
{
  debug(NDBG_REASON::DBG_RUN);
  for(std::vector<CAxon*>::iterator it=axon.begin();it!=axon.end();++it){
	(*it)->stimulate(excitement);
  }
  excitement=0.0f;
}

void CNeuron::debug(unsigned int reason)
{
#ifdef _DEBUG
   for(std::vector<NeuronDebugHandler_t*>::iterator it=dbg.begin();it!=dbg.end();++it){
       if((*it)->mask&reason){
       		(*it)->fn(reason,(*it)->pData,this);
       }
  }
#endif
}