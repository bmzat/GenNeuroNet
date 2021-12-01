#include <System.hpp>
#pragma hdrstop

#include <TestFramework.hpp>
#include "../Gene.h"

class TTestGene_t : public TTestCase
{
public:
  __fastcall virtual TTestGene_t(System::String name) : TTestCase(name) {}
  virtual void __fastcall SetUp();
  virtual void __fastcall TearDown();
  
__published:
	void __fastcall testSize();
	void __fastcall testInt();
};


void __fastcall TTestGene_t::SetUp()
{
}

void __fastcall TTestGene_t::TearDown()
{
}

void __fastcall TTestGene_t::testSize()
{
	size_t s = sizeof(Gene_t);
	CheckEquals((unsigned int)8,s);
}

void __fastcall TTestGene_t::testInt()
{
	size_t s = sizeof(int);
	CheckEquals((unsigned int)4,s);
}

static void registerTests()
{
  Testframework::RegisterTest(TTestGene_t::Suite());
}
#pragma startup registerTests 33
