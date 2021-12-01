//---------------------------------------------------------------------------

#ifndef NeuralNetH
#define NeuralNetH

#include <vector>
#include "Gene.h"

class CIndividual;
class CInputNeuron;
class COutputNeuron;
class CNeuron;

typedef CInputNeuron* inputCreator(void*);
typedef COutputNeuron* outputCreator(void*);

typedef struct {
	const char* Name;
	inputCreator *creator;
	void *pData;
}InputEntry_t;

typedef struct {
	const char* Name;
	outputCreator *creator;
	void *pData;
}OutputEntry_t;

__declspec(dllexport) class CNeuralNet{
	public:
		CNeuralNet(CIndividual* pInd);
		~CNeuralNet();



		void createInputs();
		void createOutputs();

		unsigned int fromGenome(Gene_t *buf, size_t length);


		static void regInput(const char *name,inputCreator *pCreator,void* pData);
		static void clearInputs();
		static unsigned int countInputs();

		static void regOutput(const char *name,outputCreator *pCreator,void* pData);
		static void clearOutputs();
		static unsigned int countOutputs();

		std::vector<CInputNeuron*> inputs;
		std::vector<CNeuron*> neurons;
		std::vector<COutputNeuron*> outputs;
	private:
		 static  std::vector<InputEntry_t*> inputRegister;
		 static  std::vector<OutputEntry_t*> outputRegister;
         CIndividual *mIndividual;
};

//---------------------------------------------------------------------------
#endif
