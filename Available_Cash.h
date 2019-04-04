#include "All_Library.h"
#include "All_Define.h"
#include "ACPassword.h"

void ACSetColour(int colour)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), colour );
}

bool SearchAccount(string SAccount)
{
    string acc;
    ifstream searchA ("Accounts_Password.txt",ios::in);
    while(! searchA.eof())
    {
        getline(searchA,acc);

        if(acc==SAccount)
        {

            searchA.close();
            return true;
        }
    }
    searchA.close();
    return false;
}

void LookAccount(string IDcode)
{
    string acc,idcode="";
    ifstream lookA ("Accounts.txt",ios::in);
    while(! lookA.eof())
    {
        idcode="";
        getline(lookA,acc);
        for(int i=0;i<=MaxAccounts;i++)
        {
            idcode+=acc[i];

        }

        if(idcode==IDcode)
        {
            system("cls");
            LogoOfBank("SMALL");
            cout<<"\n\n\t\t\tIDcode   Name   Money"<<endl;
            cout<<"\t\t\t"<<acc<<endl;
            lookA.close();
            LogoSetColour(95);
            cout<<"\n\t\t\tPress Any Key to Continue...                            ";
            LogoSetColour(15);
            getch();
            return;
        }
    }
    lookA.close();
}

void AvailableCash()
{
    int sizeOfIDcode;
    string MyIDcode,MyPassword,Password="",AccountLOGIN="";
    LogoOfBank("SMALL");
    ACSetColour(15);
    cout<<"\n\n\t\t\t\tAvailable_Cash";
    cout<<"\n\n\t\tWrite your IDcode : ";cin>>MyIDcode;sizeOfIDcode=MyIDcode.size();
    cout<<"\n\n\t\tWrite your password : ";MyPassword=ACPassword(1,38,15);
    if(MyPassword=="")return;
    AccountLOGIN=MyIDcode+" "+MyPassword;
    if(SearchAccount(AccountLOGIN)==true)LookAccount(MyIDcode);
    else {    MessageBox(NULL,"Wrong IDcode or password","Fast Money Look",MB_OK | MB_ICONERROR );
return;}
}
