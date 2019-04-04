#include "All_Library.h"
#include "All_Define.h"

using namespace std;

void LogoSetColour(int colour)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), colour );
}

void LogoOfBank(string Size)
{

    if(Size=="BIG")
    {
         system("cls");
         cout<<"\t\t\t\t Fast Money Look                             \n";
         LogoSetColour(11);
         cout<<"                       ******      ***     ***       *\n";
         cout<<"                      /*////      /** *   */**      /*\n";
         cout<<"                      /*          /**/ * * /**      /*\n";
         cout<<"                      /*****      /** / *  /**      /*\n";
         cout<<"                      /*///       /**  /   /**      /*\n";
         cout<<"                      /*          /**      /**      /*\n";
         cout<<"                      /*          /**      /**      /******\n";
         cout<<"                      /           //       //       //////\n";
         LogoSetColour(143);
         cout<<"\n\n\t\t        Program by: Yordan Petkov                               ";
         LogoSetColour(95);
         cout<<"\n\t\t\tPress Any Key to Continue...                            ";
         LogoSetColour(15);
         char x;
         x = getch();
         if(x==ESCAPE_CODE) return;
         system("cls");
    }

    if(Size=="SMALL")
    {
        LogoSetColour(11);
        cout<<"                             ***    **   **    *\n";
        cout<<"                            /*/   /* * */*   /*\n";
        cout<<"                            /**    /*/ * /*   /*\n";
        cout<<"                            /*     /* /  /*   /*\n";
        cout<<"                            /*     /*    /*   /****\n";
        cout<<"                            /      /     /    ////\n";
        LogoSetColour(143);
        cout<<"\t\t\t  Program by: Yordan Petkov                       ";
        LogoSetColour(15);
    }
}
