#include "All_Library.h"
#include "All_Define.h"

using namespace std;

string ReadingIDcode()
{
    string _LastIDcode;
    ifstream ReadIDCode ("LastIDcode.txt",ios::in);
    while(! ReadIDCode.eof())
    {
        ReadIDCode>>_LastIDcode;
    }
    ReadIDCode.close();
    return _LastIDcode;
}

string NextIDcode()
{
    string LastIDcode=ReadingIDcode(),NewIDcode="";
    int n=LastIDcode.size(),IntLastIDcode=0;
    char helpCH;
    //cout<<"\nN : "<<n<<endl;
    //cout<<"LASTidCode : "<<LastIDcode<<endl;
    for(int i=n-1;i>=0;i--)
    {
         int k=1;
        for(int j=1;j<=(n-1-i);j++)
            k=k*10;
        IntLastIDcode+=(LastIDcode[i]-ZERO_CODE)*k;
        //cout<<"i :" <<i <<endl;
        //cout<<"(LastIDcode[i]-ZERO_CODE)*10^(i)\n";
        //cout<<"LASTidCode [i]: "<<LastIDcode[i]<<endl;
        //cout<<"ZERO_CODE : "<<ZERO_CODE<<endl;

        //cout<<"10^(n-i) : "<<k<<endl;
        //cout<<"LastIDcode[i]-ZERO_CODE : "<<LastIDcode[i]-ZERO_CODE<<endl;
        //cout<<"(n-i) : "<<n-i<<endl;
        //cout<<"INTlastIDcode : "<<IntLastIDcode<<endl;
    }
    IntLastIDcode+=1;
    while(IntLastIDcode!=0)
    {
        helpCH=((IntLastIDcode)%10)+ZERO_CODE;
        //cout<<"HELPCH : "<<helpCH<<endl;
        NewIDcode=helpCH+NewIDcode;
        IntLastIDcode/=10;
    }

    ofstream WriteIDcode ("LastIDcode.txt",ios::out);
    if(WriteIDcode.is_open())
    {
        WriteIDcode<<NewIDcode;


    }
    WriteIDcode.close();
    int m=NewIDcode.size();
        for(int i=m;i<=MaxAccounts;i++)
    {
        NewIDcode="0"+NewIDcode;
    }



    return NewIDcode;
}
