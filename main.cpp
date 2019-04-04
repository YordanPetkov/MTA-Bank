#include "All_Library.h"
#include "All_Define.h"

#include "BankAccount.h"
#include "LogoFML.h"
#include "OptionsForChoose.h"
#include "Loading_Database.h"
#include "PageWithOptions.h"

//#include "SetColour.h"
//#include "GotoXY.h"

using namespace std;

int main()
{
    FMLsystem:
    LogoOfBank("BIG");
    LoadingProcess();
    if(Page(ChooseOption()))goto FMLsystem;
    else LogoOfBank("BIG");


    return 0;
}
