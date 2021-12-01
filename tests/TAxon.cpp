#include <System.hpp>
#pragma hdrstop

#include <TestFramework.hpp>

#include "Axon.h"
#include "Neuron.h"


class TTestCAxon : public TTestCase
{
public:
  __fastcall virtual TTestCAxon(System::String name) : TTestCase(name) {}
  virtual void __fastcall SetUp();
  virtual void __fastcall TearDown();

__published:
	void __fastcall Construction();
	void __fastcall Proportionalisation();
	void __fastcall Stimuluation();
};


void __fastcall TTestCAxon::SetUp()
{
}

void __fastcall TTestCAxon::TearDown()
{
}



void __fastcall TTestCAxon::Construction()
{
  CAxon a;
  CheckEquals((System::Extended)1.0f,(System::Extended)a.weight,"Init Problem");
  CheckEquals((void*)nullptr,(void*)a.dest,"Pointer Problem");
}

void __fastcall TTestCAxon::Proportionalisation()
{
  CAxon a;
  CNeuron n;
  a.weight = 0.5f;
  a.dest = &n;
  a.stimulate(0.25f);
  CompareFloatRelative(0.125f,n.excitement);

}


void __fastcall TTestCAxon::Stimuluation()
{
  CAxon a;
  CNeuron n;
  a.weight = 0.5f;
  a.dest = &n;
  a.stimulate(0.25f);
  CompareFloatRelative(0.125f,n.excitement);
}

static void registerTests()
{
  Testframework::RegisterTest(TTestCAxon::Suite());
}
#pragma startup registerTests 33
