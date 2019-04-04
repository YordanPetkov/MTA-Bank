#include "All_Library.h"
#include "All_Define.h"

#include "New_Account.h"
#include "Available_Cash.h"

#include "Table_Data.h"
bool Page(char Option)
{
    system("cls");
    if(Option=='A'){NewAccount();}
    if(Option=='B'){AvailableCash();}
    if(Option=='G'){TableData("Accounts.txt");}
    if(Option=='H'){TableData("Credits.txt");}
    if(Option=='I'){TableData("Deposits.txt");}

    if(MessageBox(NULL,"Do you want to open system one more time ? ","Fast Money Look",MB_YESNO | MB_ICONQUESTION ) == YES)return true;
    else return false;

}
