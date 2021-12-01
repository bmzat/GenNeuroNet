#include <System.hpp>
#pragma hdrstop

#include <TestFramework.hpp>

#include "World.h"


class TTest_WorldBitmapMapLoader : public TTestCase
{
public:
  __fastcall virtual TTest_WorldBitmapMapLoader(System::String name) : TTestCase(name) {}
  virtual void __fastcall SetUp();
  virtual void __fastcall TearDown();
private:
	CWorld *world;
__published:
  void __fastcall TestloadMap();
  void __fastcall TestloadMap2();
  void __fastcall TestloadMap3();
  void __fastcall TestloadMap4();
  void __fastcall TestloadedData();
  void __fastcall TestColors();
  void __fastcall TestCorners();
};


void __fastcall TTest_WorldBitmapMapLoader::SetUp()
{
   world = new CWorld();
}

void __fastcall TTest_WorldBitmapMapLoader::TearDown()
{
	if(world!=NULL)delete world;
}

void __fastcall TTest_WorldBitmapMapLoader::TestloadMap()
{

  try{
	world->loadMap("testdata/test1.bmp");
  }catch(std::string str){
	Fail(str.c_str());
  }
}

void __fastcall TTest_WorldBitmapMapLoader::TestloadMap2()
{
  try{
	world->loadMap("testdata/test1.bmp");
  }catch(std::string str){
	Fail(str.c_str());
  }
  CheckNotEquals((unsigned int)0,world->sizeX,"no sizeX");
  CheckNotEquals((unsigned int)0,world->sizeY,"no sizeY");
  CheckNotEquals(NULL,world->mapdata,"no allocated data");
}

void __fastcall TTest_WorldBitmapMapLoader::TestloadMap3()
{
  try{
	world->loadMap("testdata/test1.bmp");
  }catch(std::string str){
	Fail(str.c_str());
  }
  CheckEquals((unsigned int)300,world->sizeX,"no sizeX");
  CheckEquals((unsigned int)300,world->sizeY,"no sizeY");
}

void __fastcall TTest_WorldBitmapMapLoader::TestloadMap4()
{
  try{
	world->loadMap("testdata/test2.bmp");
  }catch(std::string str){
	Fail(str.c_str());
  }
  CheckEquals((unsigned int)1000,world->sizeX,"no sizeX");
  CheckEquals((unsigned int)1000,world->sizeY,"no sizeY");
}

void __fastcall TTest_WorldBitmapMapLoader::TestloadedData()
{
  try{
	world->loadMap("testdata/test1.bmp");
  }catch(std::string str){
	Fail(str.c_str());
  }
  CheckEquals((unsigned int)0xFF000000,world->mapdata[0],"PX0,0 not Black");
  CheckNotEquals((unsigned int)0,world->mapdata[1],"PX1,0 black");
  CheckNotEquals((unsigned int)0,world->mapdata[world->sizeX],"PX0,1 black");
}

  void __fastcall TTest_WorldBitmapMapLoader::TestColors()
  {
	try{
		world->loadMap("testdata/test_corners.bmp");
	}catch(std::string str){
		Fail(str.c_str());
	}

	CheckEquals((unsigned int)0xFF000000,world->mapdata[0],"PX0,0 not Black");
	CheckEquals((unsigned int)0xFF0000FF,world->mapdata[1],"PX1,0 not Red");
	CheckEquals((unsigned int)0xFF00FF00,world->mapdata[2],"PX2,0 not Gree");
	CheckEquals((unsigned int)0xFFFF0000,world->mapdata[3],"PX3,0 not Blue");
  }

  void __fastcall TTest_WorldBitmapMapLoader::TestCorners()
  {
	try{
		world->loadMap("testdata/test_corners.bmp");
	}catch(std::string str){
		Fail(str.c_str());
	}

	CheckEquals((unsigned int)0xFF000000,world->mapdata[0],"PX0,0 not Black");
	CheckEquals((unsigned int)0xFF00FF00,world->mapdata[world->sizeX-1],"PX1,0 notGreen");
	CheckEquals((unsigned int)0xFFFF0000,world->mapdata[world->sizeX*(world->sizeY-1)],"PX2,0 not Gree");
	CheckEquals((unsigned int)0xFF0000FF,world->mapdata[world->sizeX*(world->sizeY-1)+world->sizeX-1],"PX3,0 not Blue");
  }


static void registerTests()
{
  Testframework::RegisterTest(TTest_WorldBitmapMapLoader::Suite());
}
#pragma startup registerTests 33
