//#include "All_Library.h"
//#include "All_Define.h"

using namespace std;
void OFCgotoxy(int x,int y)
 {
COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
void OFCSetColour(int colour)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), colour );
}

enum OptionNo
{
    New_Account,
    Available_Cash,
    Withdraw_Money,
    Import_Money,
    Make_Credit,
    Make_Deposit,
    All_Accounts,
    All_Credits,
    All_Deposits,
    Closing_Account,
    Exit
};
char ChooseOption()
{
    system("cls");
    LogoOfBank("SMALL");
    OFCSetColour(8);
    OFCgotoxy(20,8);
    cout<<"ษอออออออออออออออออออออออออออออออออป";
    OFCgotoxy(30,9);
    cout<<"A New_Account";
    OFCgotoxy(30,10);
    cout<<"B Available_Cash";
    OFCgotoxy(30,11);
    cout<<"C Withdraw_Money";
    OFCgotoxy(30,12);
    cout<<"D Import_Money";
    OFCgotoxy(30,13);
    cout<<"E Make_Credit";
    OFCgotoxy(30,14);
    cout<<"F Make_Deposit";
    OFCgotoxy(30,15);
    cout<<"G All_Accounts";
    OFCgotoxy(30,16);
    cout<<"H All_Credits";
    OFCgotoxy(30,17);
    cout<<"I All_Deposits";
    OFCgotoxy(30,18);
    cout<<"J Closing_Account";
    OFCgotoxy(30,19);
    cout<<"ESC BANK_EXIT";
    OFCgotoxy(20,9+Options);
    cout<<"ศอออออออออออออออออออออออออออออออออผ";

    OFCSetColour(15);
    OFCgotoxy(20,10+Options);
    cout<<"ษอออออออออออออออออออออออออออออออออป";
    OFCgotoxy(20,13+Options);
    cout<<"ศอออออออออออออออออออออออออออออออออผ";
    OFCgotoxy(30,11+Options);

    Human_Choose:
    char Choose;
    char Choose_No=' ';
    Choose=getch();

    if(Choose=='A' || Choose=='a'){cout<<"\tNew_Account\n";Choose_No='A';}
    if(Choose=='B' || Choose=='b'){cout<<"\tAvailable_Cash\n";Choose_No='B';}
    if(Choose=='C' || Choose=='c'){cout<<"\tWithdraw_Money\n";Choose_No='C';}
    if(Choose=='D' || Choose=='d'){cout<<"\tImport_Money\n";Choose_No='D';}
    if(Choose=='E' || Choose=='e'){cout<<"\tMake_Credit\n";Choose_No='E';}
    if(Choose=='F' || Choose=='f'){cout<<"\tMake_Deposit\n";Choose_No='F';}
    if(Choose=='G' || Choose=='g'){cout<<"\tAll_Accounts\n";Choose_No='G';}
    if(Choose=='H' || Choose=='h'){cout<<"\tAll_Credits\n";Choose_No='H';}
    if(Choose=='I' || Choose=='i'){cout<<"\tAll_Deposits\n";Choose_No='I';}
    if(Choose=='J' || Choose=='j'){cout<<"\tClosing_Account\n";Choose_No='J';}
    if(Choose==ESCAPE_CODE){cout<<"\tBANK_EXIT\n";Choose_No=ESCAPE_CODE;}
    OFCgotoxy(30,12+Options);
    if(Choose_No>='A' && Choose_No<='A'+Options || Choose_No==ESCAPE_CODE)
    {
        return Choose_No;
    }
    goto Human_Choose;
}
