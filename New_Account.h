#include "All_Library.h"
#include "All_Define.h"
#include "Account.h"
#include "NextIDcode.h"
#include "Password.h"
using namespace std;
void ASetColour(int colour)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), colour );
}

void SaveAccount(Account MyAccount)
{
    ofstream save ("Accounts.txt",ios::app);
    if(save.is_open())
    {
        save<<endl;
        save<<MyAccount.GetIDcode()<<" "<<MyAccount.GetName()<<" "<<MyAccount.GetMoney();
    }
    save.close();
}


void SavePassword(Account MyAccount , string APassword)
{
    ofstream save ("Accounts_Data.txt",ios::app);
    if(save.is_open())
    {
        save<<endl;
        save<<MyAccount.GetIDcode()<<" "<<MyAccount.GetName()<<" "<<MyAccount.GetPersonal_No();
    }
    save.close();

    ofstream saveP ("Accounts_Password.txt",ios::app);
    if(saveP.is_open())
    {
        saveP<<endl;
        saveP<<MyAccount.GetIDcode()<<" "<<APassword;
    }
    saveP.close();


}


void NewAccount()
{

    Account MyNewAccount;
    string name,nameDEBUG,PNo,pass,IDcode;
    LogoOfBank("SMALL");
    ASetColour(15);
    cout<<"\n\n\t\t\t\tNew Account";

    cout<<"\n\tWrite your name (one word -> Yordan_Petkov): ";cin>>name;MyNewAccount.SetName(name);

    PNOCIN :
    cout<<"\n\t\tWrite your Personal_No : ";cin>>PNo;

    ///DEBUG Personal_No
    if(PNo.size()!=10)
    {
         MessageBox(NULL,"Personal_No must be 10 chars","Fast Money Look",MB_OK | MB_ICONINFORMATION );


         goto PNOCIN;
    }

    for(int i=0;i<10;i++)
    {
        if(PNo[i]<'0' || PNo[i]>'9')
        {
            MessageBox(NULL,"Personal_No must be only numbers!","Fast Money Look",MB_OK | MB_ICONERROR );
            goto PNOCIN;
        }
    }

    MyNewAccount.SetPersonal_No(PNo);


    LoadingProcess();
    LogoOfBank("SMALL");
    ASetColour(15);
    cout<<"\n\n\t\t\t\tNew Account";
    cout<<"\n\n\t\tYour Name is : "<<MyNewAccount.GetName();
    cout<<"\n\n\t\tYour Personal_No is : "<<MyNewAccount.GetPersonal_No();
    cout<<"\n\n\t\tYour IDcode is : ";
    IDcode=NextIDcode();cout<<IDcode;
    MyNewAccount.SetIDcode(IDcode);

    cout<<"\n\n\t\tWrite your password : ";pass=Password(1,38,17);
    if(pass=="")return;
    SaveAccount(MyNewAccount);
    SavePassword(MyNewAccount,pass);
    MessageBox(NULL,"Your account is ready","Fast Money Look",MB_OK | MB_ICONINFORMATION );
}
