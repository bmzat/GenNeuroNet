//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.Classes.hpp>
#include <System.Math.hpp>

#include <stdlib.h>

#pragma hdrstop


#include "../Gene.h"

#include "GeneEditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  Gene_t Gene;
  HexToBin(ReverseInput->Text.c_str(),&Gene,sizeof(Gene_t));

  displayGene(&Gene);

}

void __fastcall TForm1::displayGene(Gene_t *g)
{
  Axon->Checked = g->vFlags&GeneCodeFlags::CODE_AXON;
  FromInput->Checked = g->vFlags&GeneCodeFlags::CODE_INPUT;
  ToOutput->Checked= g->vFlags&GeneCodeFlags::CODE_OUTPUT;
  IsFeature->Checked = g->vFlags&GeneCodeFlags::CODE_FEATURE;
  IsParam->Checked  = g->vFlags&GeneCodeFlags::CODE_PARAM;
  IsValue->Checked  = g->vFlags&GeneCodeFlags::CODE_VALUE;
  Reserved1->Checked = g->vFlags&GeneCodeFlags::CODE_RESERVED1;
  Reserved2-> Checked  = g->vFlags&GeneCodeFlags::CODE_RESERVED2;
  From->Text = IntToHex(g->from);
  To->Text = IntToHex(g->dest);
  Reserved->Text = IntToHex(g->reserved);
  try{
	Value->Text = (IsNan(g->value)||IsInfinite(g->value))?FloatToStr(1.0f):FloatToStr(g->value);
  }catch(...){
	Value->Text = 0;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   Gene_t g;
   UnicodeString str;

   str.SetLength(16);
   int *p=(int*)&g;
   p[0] = rand()<<16|rand();
   p[1] = rand()<<16|rand();

   displayGene(&g);
   BinToHex(&g,str.c_str(),sizeof(Gene_t));
   ReverseInput->Text = str;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
 Gene_t Gene;
 Gene_t *g=&Gene;
   UnicodeString str;
   UnicodeString pre ="0x";

   str.SetLength(16);
 g->vFlags = 0;
 g->vFlags |= (Axon->Checked)?GeneCodeFlags::CODE_AXON:0;
 g->vFlags |= (FromInput->Checked)?GeneCodeFlags::CODE_INPUT:0;
 g->vFlags |= (ToOutput->Checked)?GeneCodeFlags::CODE_OUTPUT:0;
 g->vFlags |= (IsFeature->Checked)?GeneCodeFlags::CODE_FEATURE:0;
 g->vFlags |= (IsParam->Checked)?GeneCodeFlags::CODE_PARAM:0;
 g->vFlags |= (IsValue->Checked)?GeneCodeFlags::CODE_VALUE:0;
 g->vFlags |= (Reserved1->Checked)?GeneCodeFlags::CODE_RESERVED1:0;
 g->vFlags |= (Reserved2->Checked)?GeneCodeFlags::CODE_RESERVED2:0;
 g->from = (UInt8)StrToInt(pre+From->Text);
 g->dest = (UInt8)StrToInt(pre+To->Text);
 g->reserved =(UInt8)StrToInt(pre+Reserved->Text);
 g->value = StrToFloat(Value->Text);
   BinToHex(g,str.c_str(),sizeof(Gene_t));
   ReverseInput->Text = str;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{

 Gene_t *g=new Gene_t;
   UnicodeString str;
   UnicodeString pre ="0x";

   str.SetLength(16);
 g->vFlags = 0;
 g->vFlags |= (Axon->Checked)?GeneCodeFlags::CODE_AXON:0;
 g->vFlags |= (FromInput->Checked)?GeneCodeFlags::CODE_INPUT:0;
 g->vFlags |= (ToOutput->Checked)?GeneCodeFlags::CODE_OUTPUT:0;
 g->vFlags |= (IsFeature->Checked)?GeneCodeFlags::CODE_FEATURE:0;
 g->vFlags |= (IsParam->Checked)?GeneCodeFlags::CODE_PARAM:0;
 g->vFlags |= (IsValue->Checked)?GeneCodeFlags::CODE_VALUE:0;
 g->vFlags |= (Reserved1->Checked)?GeneCodeFlags::CODE_RESERVED1:0;
 g->vFlags |= (Reserved2->Checked)?GeneCodeFlags::CODE_RESERVED2:0;
 g->from = (UInt8)StrToInt(pre+From->Text);
 g->dest = (UInt8)StrToInt(pre+To->Text);
 g->reserved =(UInt8)StrToInt(pre+Reserved->Text);
 g->value = StrToFloat(Value->Text);
   BinToHex(g,str.c_str(),sizeof(Gene_t));
   ReverseInput->Text = str;

   genome.push_back(g);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 UnicodeString str;

 Memo1->Text="";
 for(std::vector<Gene_t*>::iterator it= genome.begin();it!=genome.end();++it){
	  for(UInt8 *b=(UInt8*)*it;b<(sizeof(Gene_t)+(UInt8*)*it);b++){
		  str+="0x";
		  str+=IntToHex(*b);
		  str+=",";
	  }
 }
 Memo1->Text = str;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
 for(std::vector<Gene_t*>::iterator it= genome.begin();it!=genome.end();++it){
	delete *it;
 }
 genome.clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
 UnicodeString str;

 Memo1->Text="";
 for(std::vector<Gene_t*>::iterator it= genome.begin();it!=genome.end();++it){
	  for(UInt8 *b=(UInt8*)*it;b<(sizeof(Gene_t)+(UInt8*)*it);b++){
		  str+=IntToHex(*b);
   	  }
 }
 Memo1->Text = str;
}
//---------------------------------------------------------------------------
