#include <System.hpp>
#pragma hdrstop
#include "Neuron.h"
#include "Axon.h"

#include <TestFramework.hpp>


class TTestCNeuron : public TTestCase
{
public:
  __fastcall virtual TTestCNeuron(System::String name) : TTestCase(name) {}
  virtual void __fastcall SetUp();
  virtual void __fastcall TearDown();
  
__published:
  void __fastcall Construction1();
  void __fastcall Teststimulate1();
  void __fastcall Teststimulate2();
  void __fastcall Teststimulate3();
  void __fastcall Teststimulate4();
  void __fastcall Testrun();
  void __fastcall Testrun2();
  void __fastcall RunResetsExcitement();
};


void __fastcall TTestCNeuron::SetUp()
{
}

void __fastcall TTestCNeuron::TearDown()
{
}

void __fastcall TTestCNeuron::Construction1()
{
  CNeuron n;
  CompareFloatRelative(0.0f,n.excitement);
  CheckEquals((unsigned int)0,n.tier,"Init Wrong");
 // CheckEquals((float)0.0f,n.excitement,"Init Wrong");

}

void __fastcall TTestCNeuron::Teststimulate1()
{
  CNeuron n;
  n.stimulate(2.0f);
  CheckEquals((System::Extended)2.0f,n.excitement);
}

void __fastcall TTestCNeuron::Teststimulate2()
{
  CNeuron n;
  n.stimulate(2.0f);
  CheckEquals((unsigned int)1,n.stimCount);
}

void __fastcall TTestCNeuron::Teststimulate3()
{
  float sum=0.0f;
  CNeuron n;

  for(int i=0;i<100;i++){
	sum+=0.1f;
	n.stimulate(0.1f);
  }
  CheckEquals((System::Extended)sum,n.excitement);
}

void __fastcall TTestCNeuron::Teststimulate4()
{

  CNeuron n;

  for(int i=0;i<100;i++){
	n.stimulate(0.1f);
  }
  CheckEquals((unsigned int)100,n.stimCount);
}

void __fastcall TTestCNeuron::Testrun()
{
  float stimulus = 5334.0f;
  CNeuron s;
  CNeuron d;
  CAxon a;
  a.dest = &d;
  s.stimulate(stimulus);
  s.axon.push_back(&a);
  s.run();
  CheckEquals((System::Extended) stimulus,d.excitement);
}

void __fastcall TTestCNeuron::Testrun2()
{
  float stimulus = 5334.0f;
  CNeuron s;
  CNeuron d;
  CAxon a1,a2;
  a1.dest = &d;
  a2.dest = &d;
  s.stimulate(stimulus);
  s.axon.push_back(&a1);
  s.axon.push_back(&a2);
  s.run();
  CheckEquals((System::Extended) (stimulus*2.0f),d.excitement);
}

void __fastcall TTestCNeuron::RunResetsExcitement()
{
  float stimulus = 5334.0f;
  CNeuron s;
  CNeuron d;
  CAxon a1,a2;
  a1.dest = &d;
  a2.dest = &d;
  s.stimulate(stimulus);
  s.axon.push_back(&a1);
  s.axon.push_back(&a2);
  s.run();
  CheckEquals((System::Extended) (0.0f),s.excitement);
  CheckEquals((System::Extended) (stimulus*2.0f),d.excitement);
  d.run();
  CheckEquals((System::Extended) (0.0f),d.excitement);
}



static void registerTests()
{
  Testframework::RegisterTest(TTestCNeuron::Suite());
}
#pragma startup registerTests 33
