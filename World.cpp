//---------------------------------------------------------------------------

#pragma hdrstop

#include "World.h"
#include "BMPLib.h"
//---------------------------------------------------------------------------
//#pragma package(smart_init)

CWorld::CWorld(){
 this->sizeX =0;
 this->sizeY =0;
 this->mapdata = NULL;
 this->pBMP = NULL;
 step=0;
}

CWorld::~CWorld(){

}

void CWorld::loadMap(const char*fname)
{

	if(pBMP!=NULL){
	  BMPlib::BMP *bm = (BMPlib::BMP *)pBMP;
	  pBMP=NULL;
	  delete bm;
	}

	BMPlib::BMP *bm = new BMPlib::BMP();
	if(bm->Read(fname)){
	  bm->ConvertTo(BMPlib::BMP::COLOR_MODE::RGBA);
	  sizeX = bm->GetWidth();
      sizeY = bm->GetHeight();
	  mapdata = (unsigned int*)bm->GetPixelBuffer();
	  pBMP = bm;
	}else{
		throw std::string("File not opened");
    }

}
