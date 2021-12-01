//---------------------------------------------------------------------------

#ifndef WorldH
#define WorldH


__declspec(dllexport) class CWorld{
	public:
	   CWorld();
	   ~CWorld();


	   void loadMap(const char* fname);


		unsigned int sizeX;
		unsigned int sizeY;
		unsigned int *mapdata;
		unsigned int step;
	private:
       void *pBMP;

};
//---------------------------------------------------------------------------
#endif
