using namespace std;
COORD coord={0,0};
void LDgotoxy(int x,int y)
 {

   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }



void LDSetColour(int colour)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), colour );
}


/***************************LOADING DATABASE DESIGN**********************/
void LoadingProcess(bool ClearScr=1)
{
    LDSetColour(7);
    if(ClearScr)system("cls");
    cout<<"\n\n\n\n\n\t\t\t\tLoading Database...";
    cout<<"\t\t\t";

    LDgotoxy(3,9);
    printf("\t\t\tษอออออออออออออออออออออออออออออออออป");
    LDgotoxy(3,10);

    printf("\t\t\tบ                                 บ");

    LDgotoxy(3,11);
    printf("\t\t\tศอออออออออออออออออออออออออออออออออผ");
    LDSetColour(153);
    for(int k=25;k<58;k++)
    {

    Sleep(40);
    LDgotoxy(k,10);
    cout<<" ";
    }
    Sleep(30);
    LDSetColour(15);
    cout<<endl;
    if(ClearScr)system("cls");
}
