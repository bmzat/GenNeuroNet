//---------------------------------------------------------------------------

#pragma hdrstop

#include "Axon.h"
#include "Neuron.h"
//---------------------------------------------------------------------------
CAxon::CAxon()
{
	dest=nullptr;
    weight=1.0f;
}

void CAxon::stimulate(float stimulus){
		dest->stimulate(stimulus*weight);
}

#pragma package(smart_init)
