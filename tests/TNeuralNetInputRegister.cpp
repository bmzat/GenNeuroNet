#include <System.hpp>
#pragma hdrstop

#include <TestFramework.hpp>
#include "../NeuralNet.h"
#include "../inputs/IRandom.h"

class TNeuralNetInputRegister : public TTestCase
{
public:
  __fastcall virtual TNeuralNetInputRegister(System::String name) : TTestCase(name) {}
  virtual void __fastcall SetUp();
  virtual void __fastcall TearDown();

__published:
  void __fastcall TestcreateInputs();
  void __fastcall TestregInput();
};


void __fastcall TNeuralNetInputRegister::SetUp()
{
}

void __fastcall TNeuralNetInputRegister::TearDown()
{
}

void __fastcall TNeuralNetInputRegister::TestcreateInputs()
{
   CNeuralNet net(nullptr);

  CNeuralNet::clearInputs();
  CNeuralNet::regInput("Random1",&IRandom::create,nullptr);
  CNeuralNet::regInput("Random2",&IRandom::create,nullptr);
  CNeuralNet::regInput("Random3",&IRandom::create,nullptr);
  CheckNotEquals((unsigned int)0,CNeuralNet::countInputs());
  CheckEquals((unsigned int)3,CNeuralNet::countInputs(),"Not 3 inputs prescribed");


  net.createInputs();
 CheckEquals((unsigned int)3,net.inputs.size(),"No Inputneurons created ");

}
    
void __fastcall TNeuralNetInputRegister::TestregInput()
{
  CNeuralNet::clearInputs();
  CNeuralNet::regInput("Random",&IRandom::create,nullptr);
  CheckNotEquals((unsigned int)0,CNeuralNet::countInputs());

  // static void regInput(const char *name, inputCreator *pCreator, void *pData)
}



static void registerTests()
{
  Testframework::RegisterTest(TNeuralNetInputRegister::Suite());
}
#pragma startup registerTests 33
