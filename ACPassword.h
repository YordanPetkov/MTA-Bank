#include "All_Library.h"
#include "All_Define.h"
using namespace std;

COORD ACPcoord={0,0};
void ACPgotoxy(int x,int y)
 {

   ACPcoord.X=x;//kolona
   ACPcoord.Y=y;//red
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),ACPcoord);
 }


string ACPasswordDecode(string Password)
{
    int n=Password.size();
    string NewPassword;
    char PrSym;
    for(int i=0;i<n;i++)
    {
        PrSym=Password[i]+i+1;
        if(PrSym>125)PrSym=PrSym-125+33;
        NewPassword+=PrSym;
    }
    return NewPassword;
}

string ACPasswordUndecode(string Password)
{
    int n=Password.size();
    string NewPassword="";
    char PrSym;
    for(int i=0;i<n;i++)
    {
        PrSym+=Password[i]-i-1;
        if(PrSym<34)PrSym+=33;
        NewPassword+=PrSym;
    }
    return NewPassword;
}

string ACPasswordReader(int LC,int LR)
{
    string myPassword="";
    int counterOfChars=0;

    StartPassRead:
        Pgotoxy(LC,LR);
        char C=getch();
        int k=C;
        if(k==BACKSPACE_CODE || k==ENTER_CODE || k==ESCAPE_CODE)
        {
            if(k==BACKSPACE_CODE && counterOfChars>=1)
            {
                myPassword.erase(counterOfChars-1,1);
                Pgotoxy(LC-1,LR);
                cout<<" ";
                Pgotoxy(LC-1,LR);
                LC--;
                counterOfChars--;
                goto StartPassRead;
            }
            if(k==ENTER_CODE)
            {
                goto FinishPassRead;
            }
            if(k==ESCAPE_CODE)
            {
                return "";
            }
        }
        else//17 38
        {
             myPassword=myPassword+C;
             Pgotoxy(LC,LR);
             cout<<"*";
             counterOfChars++;
             LC++;
             goto StartPassRead;
        }
        FinishPassRead :

    if(counterOfChars < 6)
    {
        int MessageBoxChoose;

        MessageBoxChoose=MessageBox(NULL,"Minimun 6 digits needed.","Fast Money Look",MB_RETRYCANCEL | MB_ICONSTOP );
        if(MessageBoxChoose==CANCEL)return "";
        if(MessageBoxChoose==RETRY){goto StartPassRead;myPassword="";counterOfChars=0;LR++;LC++;}
    }
    return myPassword;
}

string ACPassword(bool Decode,int LC,int LR)
{
    string MyPass;
    MyPass=ACPasswordReader(LC,LR);
    //  return MyPass;

    if(MyPass=="")return "";

    if(Decode==1)return ACPasswordDecode(MyPass);
    else return ACPasswordUndecode(MyPass);
}


