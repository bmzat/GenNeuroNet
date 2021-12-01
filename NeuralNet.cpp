//---------------------------------------------------------------------------


#include <vector>
#include <boost/geometry.hpp>
#pragma hdrstop

#include "Gene.h"
#include "NeuralNet.h"
#include "InputNeuron.h"
#include "Neuron.h"
#include "Axon.h"
#include "OutputNeuron.h"
#include "Individual.h"

std::vector<InputEntry_t*> CNeuralNet::inputRegister=std::vector<InputEntry_t*>();
std::vector<OutputEntry_t*> CNeuralNet::outputRegister=std::vector<OutputEntry_t*>();

//---------------------------------------------------------------------------

CNeuralNet::CNeuralNet(CIndividual *pInd){
	mIndividual = pInd;
}

CNeuralNet::~CNeuralNet()
{
	for (std::vector<CInputNeuron*>::iterator it = inputs.begin() ; it != inputs.end(); ++it ){
		delete *it;
	}
	for (std::vector<COutputNeuron*>::iterator it = outputs.begin() ; it != outputs.end(); ++it ){
		delete *it;
	}
	for (std::vector<CNeuron*>::iterator it = neurons.begin() ; it != neurons.end(); ++it ){
		delete *it;
	}
	inputs.clear();
	outputs.clear();
	neurons.clear();
}

void CNeuralNet::createInputs()
{
  for (std::vector<InputEntry_t*>::iterator it = inputRegister.begin() ; it != inputRegister.end(); ++it ){
	InputEntry_t *pe = *it;
	inputs.push_back(pe->creator(pe->pData));
  }
}

void CNeuralNet::createOutputs()
{
 for (std::vector<OutputEntry_t*>::iterator it = outputRegister.begin() ; it != outputRegister.end(); ++it ){
	OutputEntry_t *pe = *it;
	outputs.push_back(pe->creator(pe->pData));
 }

}

unsigned int CNeuralNet::fromGenome(Gene_t *buf, size_t length)
{
	unsigned int cnt = length/sizeof(Gene_t);
	unsigned int result=0;
	if(buf==nullptr)return 0;

	createInputs();
	createOutputs();

	CNeuron *src=nullptr;
	CNeuron *dst=nullptr;

	for(unsigned int n=0;n<cnt;n++){
		if(buf[n].vFlags&GeneCodeFlags::CODE_AXON){
			if(buf[n].vFlags&GeneCodeFlags::CODE_INPUT){
				  if(buf[n].from<inputs.size()){
					src = inputs[buf[n].from];
				  }
			}else{
				  if(buf[n].from<neurons.size()){
					src = neurons[buf[n].from];
				  }
			}

			if(buf[n].vFlags&GeneCodeFlags::CODE_OUTPUT){
				  if(buf[n].from<outputs.size()){
					dst = outputs[buf[n].from];
				  }
			}else{
				  if(buf[n].from<neurons.size()){
					dst = neurons[buf[n].from];
				  }
			}

			if((src!=nullptr)&&(dst!=nullptr)){
				CAxon *ax = new CAxon;
				ax->weight = buf[n].value;
				src->axon.push_back(ax);
				ax->dest = dst;
				result++;
			}
		}
	}

	return result;
}



/*
	static
*/
void CNeuralNet::regInput(const char *name,inputCreator *pCreator,void* pData)
{
	InputEntry_t *ie = new InputEntry_t{name,pCreator,pData};
	inputRegister.push_back(ie);

}


/*
	static
*/
void CNeuralNet::clearInputs()
{
 for (std::vector<InputEntry_t*>::iterator it = inputRegister.begin() ; it != inputRegister.end(); ++it ){
	delete *it;
 }
 inputRegister.clear();
}

unsigned int CNeuralNet::countInputs()
{
	return inputRegister.size();
}


void CNeuralNet::regOutput(const char *name,outputCreator *pCreator,void* pData)
{
	OutputEntry_t *ie = new OutputEntry_t{name,pCreator,pData};
	outputRegister.push_back(ie);

}


/*
	static
*/
void CNeuralNet::clearOutputs()
{
 for (std::vector<OutputEntry_t*>::iterator it = outputRegister.begin() ; it != outputRegister.end(); ++it ){
	delete *it;
 }
 outputRegister.clear();
}

unsigned int CNeuralNet::countOutputs()
{
	return outputRegister.size();
}


#pragma package(smart_init)
