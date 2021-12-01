//---------------------------------------------------------------------------

#ifndef GeneEditFormH
#define GeneEditFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include <vector>

#include "../Gene.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TCheckBox *Axon;
	TCheckBox *FromInput;
	TCheckBox *ToOutput;
	TCheckBox *IsFeature;
	TCheckBox *IsParam;
	TCheckBox *IsValue;
	TEdit *From;
	TLabel *Label1;
	TEdit *To;
	TLabel *Label2;
	TCheckBox *Reserved1;
	TCheckBox *Reserved2;
	TLabel *Label3;
	TEdit *Value;
	TLabel *Label4;
	TEdit *Reserved;
	TButton *Button1;
	TButton *Button2;
	TMemo *Memo1;
	TEdit *ReverseInput;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
private:	// Benutzer-Deklarationen
    std::vector<Gene_t*> genome;
public:		// Benutzer-Deklarationen
	__fastcall TForm1(TComponent* Owner);
	void __fastcall displayGene(Gene_t *g);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
