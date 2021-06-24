//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

        int x = -4;
        int y = -4;
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
        BallRender->Interval = 8;
        Ball->Left += x;
        Ball->Top += y;

        
        //dodac odbicie od gory paletki i dolu zeby wygladalo poprawnie i nie wpadala w rezonans + corner shot

        //Handling left side

        if ((Ball->Left <= (PaddleLP->Left + PaddleLP->Width)) &&
           (Ball->Top == (PaddleLP->Top - (Ball->Height / 2))) && //previous >=
           ((Ball->Top + (Ball->Height / 2)) == (PaddleLP->Top + PaddleLP->Height))) //previous <=
        {
                Ball->Left = PaddleLP->Left + PaddleLP->Width;
                x = -x;
        }
        else if (Ball->Left <= Background->Left - Ball->Width)
        {
                Ball->Left = Background->Left + (Background->Width / 2) - (Ball->Width / 2);
                Ball->Top = Background->Top + (Background->Height / 2) - (Ball->Height / 2);
                x = -x;
        }

        //Handlig right side

        if (
           ((Ball->Left + Ball->Width) >= PaddleRP->Left)
           &&
           (Ball->Top == (PaddleRP->Top - (Ball->Height / 2))) && //previous >=
           ((Ball->Top + (Ball->Height / 2)) == (PaddleRP->Top + PaddleRP->Height)) //previous <=
           )
        {
                x = -x;
        }
        else if (Ball->Left >= (Background->Left + Background->Width))
        {
                Ball->Left = Background->Left + (Background->Width / 2) - (Ball->Width / 2);
                Ball->Top = Background->Top + (Background->Height / 2) - (Ball->Height / 2);
                x = -x;
                BallRender->Interval = 3000;
        }
                                                      
        //Handling top and bottom

        if ((Ball->Top) <= Background->Top) {
                y = -y;
        }

        if ((Ball->Top + Ball->Height) >= Background->Height) {
                y = -y;
        }

        LeftPosBall->Caption = Ball->Left;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpLPTimer(TObject *Sender)
{
        if (PaddleLP->Top > 5) PaddleLP->Top -= 5;
        TopPosLP->Caption = PaddleLP->Top;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DownLPTimer(TObject *Sender)
{
        if ((PaddleLP->Top + PaddleLP->Height) < (Background->Height - 5))
                PaddleLP->Top += 5;

        TopPosLP->Caption = PaddleLP->Top;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpRPTimer(TObject *Sender)
{
        if (PaddleRP->Top > 5) PaddleRP->Top -= 5;
        TopPosRP->Caption = PaddleRP->Top;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DownRPTimer(TObject *Sender)
{
        if ((PaddleRP->Top + PaddleRP->Height) < (Background->Height - 5))
                PaddleRP->Top += 5;

        TopPosRP->Caption = PaddleRP->Top;
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







