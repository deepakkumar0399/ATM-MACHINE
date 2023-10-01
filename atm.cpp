#include<iostream>
#include<string.h>
#include<unordered_map>
#include<set>
using namespace std;
void check(int &balance)
{
     cout<<"\nyour account balance=RS:"<<balance;
            if(balance<5000)
            {
                cout<<"\ndeposit cash otherwise u have to be pay tax!!!";

            }

}
void withdraw(int &balance)
{
        int w;
        cout<<"\nenter amount to withdraw=RS:";cin>>w;
         if(balance>=w)
        {

            cout<<"\nWITHDRAWING CASH IN PROCESSING.";
            cout<<"\nPLEASE COLLECT YOUR CASH RS:"<<w<<"!!!";
            balance=balance-w;
            cout<<"\n\tTHANK YOU FOR BANKING WITH US";
        }
        else
        {
            cout<<"\nyou have not sufficient balance to withdraw!!!";
        }


}
void deposit(int &balance)
{
    int d;
        cout<<"\nenter amount to deposit=RS:";cin>>d;
            if(d<=25000)
                {

                      cout<<"\nplease place your cash in cash deposit machine";
                      balance=balance+d;
                       cout<<"\n\tTRANSACTION FINISHED!!!";
                       cout<<"\n\tTHANK YOU FOR BANKING WITH US";
                }

             else
                {
                    cout<<"\nonce you can deposit RS:25000 only!!!";
                   }
}
void transfer(int &balance )
{
     cout<<"\nTRANSFER FUNDS TO ANOTHER ACCOUNT!!!";
           cout<<"\nenter beneficiary account details";
           char x[100],y[15],z[10];
           int t;
           //strupr(x);
           cout<<"\nenter beneficiary account name=";cin.get();cin.get(x,100);
           cout<<"\nenter beneficiary account number=";cin.get();cin.get(y,15);
           cout<<"\nenter beneficiary mobile number=";cin.get();cin.get(z,10);
           cout<<"\nenter amount to be transfer=RS:";cin>>t;
           if(t<balance)
           {
               cout<<"\nTRANSFERING MONEY IN PROCESS RS:"<<t;
               balance=balance-t;
               cout<<"\n\tTHANK YOU FOR BANKING WITH US";

           }
           else
           {
               cout<<"\nnot sufficient balance!!";
           }

}
int main()
{
    //IT IS A PROJECT FOR SMALL BANK ATM,WE HAVE ONLY FEW NUMBER OF ACCOUNT HOLDERS.THIS NUMBER IS 5!!
   unordered_map<string,int>atm; //data of account holder name ans password
    atm["deepak"]=8836;
    atm["honey"]=9999;
    atm["prabh"]=3331;
    atm["gurleen"]=1231;
    atm["anjali"]=1098;
    unordered_map<string,int>atm1;//balance in account
    atm1["deepak"]=45000;
    atm1["honey"]=25000;
    atm1["prabh"]=3331;
    atm1["gurleen"]=12000;
    atm1["anjali"]=10980;
    cout<<"\t***WELCCOME TO ATM***\t";
    cout<<"\n\tinsert the ATM/debitcard";
    string name;
    char accNo[15],mobileNo[10],choice,enquiry;
    cout<<"\nEnter account holder name=";getline(cin,name);
    if(atm.count(name))
    {
    cout<<"\nenter account number=";cin.get();cin.get(accNo,15);
    cout<<"\nenter mobile number=";cin.get();cin.get(mobileNo,10);
    auto itr=atm1.find(name);
    int balance=(*itr).second;
    cout<<"\nenter your account balance=RS:"<<balance; //balance in a account
    int pass;
    cout<<"\nenter your pin=";cin.get();cin>>pass;//password enter by user
    auto it=atm.find(name);
    if((*it).second==pass)
    {
    do{
    cout<<"\n*************************************************";//options to do task which u want
    cout<<"\n*                                               *";
    cout<<"\n*  press C to check your account balance        *";
    cout<<"\n*  press W to withdraw cash                     *";
    cout<<"\n*  press D to deposit cash                      *";
    cout<<"\n*  press T to transfer balance to other account *";
    cout<<"\n*                                               *";
    cout<<"\n*************************************************";
    cout<<"\ninput your enquiry=";cin>>enquiry; //enter choice here

   switch(enquiry)
    {
    case 'C':
    case 'c':
            check(balance);
            break;
    case 'W':
    case 'w':
          withdraw(balance);
          check(balance);
          break;
    case 'D':
    case 'd':
            deposit(balance);
            check(balance);
            break;
    case 'T':
    case 't':
           transfer(balance);
           check(balance);
            break;
    default:
        cout<<"invalid choice";
    }
cout<<"\npress y to continue=";cin>>choice; //press y to do another task now
}while(choice=='y'||choice=='Y');
}
else if( (*it).second!=pass)
{
  cout<<"\nINVALID PIN!!";
}
}

else
{
    cout<<"\nSORRY,ACCOUNT NOT FOUND ON THIS NAME!!";
}

return 0;
}
