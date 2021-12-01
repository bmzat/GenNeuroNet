//---------------------------------------------------------------------------

#ifndef AxonH
#define AxonH
//---------------------------------------------------------------------------


class CNeuron;

__declspec(dllexport) class CAxon{
  public:
	CAxon();

	void stimulate(float stimulus);

	float weight;
	CNeuron* dest;
};


#endif
