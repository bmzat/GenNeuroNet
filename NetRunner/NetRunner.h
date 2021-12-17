//---------------------------------------------------------------------------

#ifndef NetRunnerH
#define NetRunnerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TStringGrid *InputGrid;
	TStringGrid *NeuronGrid;
	TStringGrid *OutputGrid;
	TEdit *HexCodeEdit;
	TStatusBar *StatusBar1;
	TMemo *Memo1;
	TButton *SyntheseButton;
	TTrackBar *NumInputs;
	TTrackBar *NumNeurons;
	TTrackBar *NumOutputs;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:	// Benutzer-Deklarationen
public:		// Benutzer-Deklarationen
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
