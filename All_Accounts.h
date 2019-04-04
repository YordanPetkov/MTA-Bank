#include "All_Library.h"
#include "All_Define.h"



void TableData(string FileName)
{
    LogoOfBank("SMALL");
    string acc;
    ifstream lookA (name.c_str(),ios::in);
    while(! lookA.eof())
    {
        getline(lookA,acc);
        cout<<"\n\t\t\t"<<acc;
    }
    lookA.close();
}
