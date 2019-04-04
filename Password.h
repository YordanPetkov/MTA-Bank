#include "All_Library.h"
#include "All_Define.h"
using namespace std;

COORD Pcoord={0,0};
void Pgotoxy(int x,int y)
 {

   Pcoord.X=x;//kolona
   Pcoord.Y=y;//red
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pcoord);
 }


string PasswordDecode(string Password)
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

string PasswordUndecode(string Password)
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

string PasswordReader(int LC,int LR)
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

string Password(bool Decode,int LC,int LR)
{
    string MyPass;
    MyPass=PasswordReader(LC,LR);
    //  return MyPass;

    if(MyPass=="")return "";

    if(Decode==1)return PasswordDecode(MyPass);
    else return PasswordUndecode(MyPass);
}

