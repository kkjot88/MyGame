//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *Background;
        TImage *Ball;
        TTimer *BallRender;
        TImage *PaddleLP;
        TImage *PaddleRP;
        TTimer *UpLP;
        TTimer *DownLP;
        TTimer *UpRP;
        TTimer *DownRP;
        TLabel *TopPosLP;
        TLabel *TopPosRP;
        TLabel *LeftPosBall;
        void __fastcall BallRenderTimer(TObject *Sender);
        void __fastcall DownRPTimer(TObject *Sender);
        void __fastcall UpLPTimer(TObject *Sender);
        void __fastcall DownLPTimer(TObject *Sender);
        void __fastcall UpRPTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
