#include <System.hpp>
#pragma hdrstop

#include "../inputs/IRandom.h"
#include "../OutputNeuron.h"
#include "../NeuralNet.h"

#include <TestFramework.hpp>

char chromosome0[] = {0x07,0x00,0x00,0x00,0x00,0x00,0x80,0x3F};
char chromosome1[] = {0x07,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0x07,0x00,0x01,0x00,0x00,0x00,0x80,0x3F,0x07,0x00,0x02,0x00,0x00,0x00,0x80,0x3F};
char chromosome2[] = {0x07,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0x07,0x01,0x00,0x00,0x00,0x00,0x80,0x3F,0x07,0x02,0x00,0x00,0x00,0x00,0x80,0x3F};
char chromosome3[] = {0x07,0x00,0x00,0x00,0xA4,0x70,0x9D,0x3F,0x07,0x01,0x00,0x00,0xA4,0x70,0x9D,0x3F,0x07,0x02,0x00,0x00,0xA4,0x70,0x9D,0x3F,0x03,0x02,0x01,0x00,0xA4,0x70,0x9D,0x3F,0x03,0x00,0x01,0x00,0xA4,0x70,0x9D,0x3F,0x05,0x01,0x00,0x00,0xA4,0x70,0x9D,0x3F,0x05,0x01,0x02,0x00,0xA4,0x70,0x9D,0x3F,0x05,0x01,0x01,0x00,0x21,0xB0,0xAA,0x40,0x0D,0x20,0x40,0xFF,0x00,0x00,0x00,0x00};
char chromosome4[] = {0x03,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0x05,0x00,0x00,0x00,0x00,0x00,0x80,0x3F};

class TNeuralNetSynthesis : public TTestCase
{
public:
  __fastcall virtual TNeuralNetSynthesis(System::String name) : TTestCase(name) {}
  virtual void __fastcall SetUp();
  virtual void __fastcall TearDown();

__published:
	void __fastcall PreReqCheck();

	void __fastcall CheckChromosome0();
	void __fastcall CheckChromosome1();
	void __fastcall CheckChromosome2();
	void __fastcall CheckChromosome3();
	void __fastcall CheckChromosome4();
};


void __fastcall TNeuralNetSynthesis::SetUp()
{
	FailsOnNoChecksExecuted=true;

  CNeuralNet::clearInputs();
  CNeuralNet::regInput("Random1",&IRandom::create,nullptr);
  CNeuralNet::regInput("Random2",&IRandom::create,nullptr);
  CNeuralNet::regInput("Random3",&IRandom::create,nullptr);

  CNeuralNet::clearOutputs();
  CNeuralNet::regOutput("Null 1",&COutputNeuron::create,nullptr);
  CNeuralNet::regOutput("Null 2",&COutputNeuron::create,nullptr);
  CNeuralNet::regOutput("Null 3",&COutputNeuron::create,nullptr);
  CNeuralNet::regOutput("Null 4",&COutputNeuron::create,nullptr);
}

void __fastcall TNeuralNetSynthesis::TearDown()
{
   CNeuralNet::clearInputs();
   CNeuralNet::clearOutputs();

}

void TNeuralNetSynthesis::PreReqCheck()
{
	CheckEquals((unsigned int)3,CNeuralNet::countInputs());
	CheckEquals((unsigned int)4,CNeuralNet::countOutputs());

}

void __fastcall TNeuralNetSynthesis::CheckChromosome0()
{
	CNeuralNet net(nullptr);
	net.createInputs();
	net.createOutputs();

	CheckEquals((unsigned int)3,net.inputs.size());
	CheckEquals((unsigned int)4,net.outputs.size());

	net.fromGenome((Gene_t*)chromosome0,sizeof(chromosome0));

	CheckEquals((unsigned int)1,net.inputs[0]->axon.size());

	net.inputs[0]->excitement = 5334.0f;
	net.inputs[0]->run();
	CheckEquals((System::Extended)5334.0f,net.outputs[0]->excitement);

}


void __fastcall TNeuralNetSynthesis::CheckChromosome1()
{
	CNeuralNet net(nullptr);
	net.createInputs();
	net.createOutputs();

	CheckEquals((unsigned int)3,net.inputs.size());
	CheckEquals((unsigned int)4,net.outputs.size());

	net.fromGenome((Gene_t*)chromosome1,sizeof(chromosome1));
	CheckEquals((unsigned int)3,net.inputs[0]->axon.size());
}

void __fastcall TNeuralNetSynthesis::CheckChromosome2()
{
	CNeuralNet net(nullptr);
	net.createInputs();
	net.createOutputs();

	CheckEquals((unsigned int)3,net.inputs.size());
	CheckEquals((unsigned int)4,net.outputs.size());

	net.fromGenome((Gene_t*)chromosome2,sizeof(chromosome2));

	CheckEquals((unsigned int)1,net.inputs[0]->axon.size());

}

void __fastcall TNeuralNetSynthesis::CheckChromosome3()
{

}

void __fastcall TNeuralNetSynthesis::CheckChromosome4()
{

}

static void registerTests()
{
  Testframework::RegisterTest(TNeuralNetSynthesis::Suite());
}
#pragma startup registerTests 33
