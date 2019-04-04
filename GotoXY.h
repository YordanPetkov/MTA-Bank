#include "All_Library.h"
using namespace std;


COORD coord={0,0};
void gotoxy(int x,int y)
 {

   coord.X=x;//kolona
   coord.Y=y;//red
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
