//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

        int x = -8;
        int y = -8;
        int ScoreLP = 0;
        int ScoreRP = 0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BallRenderTimer(TObject *Sender)
{
        Ball->Left += x;
        Ball->Top += y;

        if ((Ball->Left) <= Background->Left) {
                x = -x;
                //ScoreRP++;
        }

        if ((Ball->Top) <= Background->Top) {
                y = -y;
        }

        if ((Ball->Left + Ball->Width) >= Background->Width) {
                x = -x;
                //ScoreLP++;
        }

        if ((Ball->Top + Ball->Height) >= Background->Height) {
                y = -y;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpLPTimer(TObject *Sender)
{
        if (PaddleLP->Top == 0) UpLP->Enabled = false;
        PaddleLP->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DownLPTimer(TObject *Sender)
{
        if ((PaddleLP->Top + PaddleLP->Height) != Background->Height)
                PaddleLP->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpRPTimer(TObject *Sender)
{
        PaddleRP->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DownRPTimer(TObject *Sender)
{
        PaddleRP->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 0x57)        UpLP->Enabled = true;
        if (Key == 0x53)        DownLP->Enabled = true;
        if (Key == VK_UP)       UpRP->Enabled = true;
        if (Key == VK_DOWN)     DownRP->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 0x57)        UpLP->Enabled = false;
        if (Key == 0x53)        DownLP->Enabled = false;
        if (Key == VK_UP)       UpRP->Enabled = false;
        if (Key == VK_DOWN)     DownRP->Enabled = false;
}
//---------------------------------------------------------------------------


