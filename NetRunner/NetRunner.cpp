//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#include <boost/format.hpp>
#pragma hdrstop

#include "NetRunner.h"
#include "../Neuron.h"
#include "../Axon.h"
#include "../NeuralNet.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

typedef struct {
         TStringGrid* pGrid;
         unsigned int row;
}DbgTag_t;

float gridDebug(unsigned int reason, void* pData, CNeuron *pNeuron)
{
    DbgTag_t *tag=(DbgTag_t*)pData;

    if(pData == nullptr)return 0.0f;

    if(reason&NDBG_REASON::DBG_INPUT){ // Read Input from grid cell
        return 0.0f;
    }else{                             // Write output to grid cell

    }

    return 0.0f;
}

float memoDebug(unsigned int reason, void* pData, CNeuron *pNeuron)
{
    TMemo *memo = (TMemo*)pData;
    std::string str;

    if(reason&NDBG_REASON::DBG_INPUT){
        return 0.0f;
    }
    //str << std::string("DBG(") << reason << std::string(")") << pNeuron->name << std::string(" = ") << pNeuron->excitement;
    boost::format fmt = boost::format("DBG( %1% ) %2% :> %3%") % reason % pNeuron->name % pNeuron->excitement;
    memo->Lines->Add(fmt.str().c_str());

    return 0.0f;
}

TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

