#include "All_Library.h"
#include "All_Define.h"
using namespace std;
class Account
{
    private:
    string _name;
    string _Personal_No;
    string _IDcode;
    string _Password;
    int _Money=0;




    public:

    string GetName()
    {
        return _name;
    }
    void SetName(string name)
    {
        _name=name;
    }


    string GetPersonal_No()
    {
        return _Personal_No;
    }
    void SetPersonal_No(string Personal_No)
    {
        _Personal_No=Personal_No;
    }


    string GetIDcode()
    {
        return _IDcode;
    }
    void SetIDcode(string IDcode)
    {
        _IDcode=IDcode;
    }

    int GetMoney()
    {
        return _Money;
    }
    void ImportMoney(int Money)
    {
        _Money+=Money;
    }
    void WithdrawMoney(int Money)
    {
        _Money-+Money;
    }
};
