#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double balance=1000;
    int choice;
    cout<<endl<<"1. Menu"<<endl;
    cout<<"2. Withdraw"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"choose: "<<endl;
    cin>>choice;
    
    switch(choice){
        case 1:{
            cout<<"balance"<<balance;
            break;
        }
        case 2:{
            double amount;
            cout<<"Amount: $";
            cin>>amount;
            if (amount>balance)
            {
                cout<<"Insufficiant Balance!!";
            }
            else{
                balance-=amount;
            }
            break;
        }
        case 3:{
            cout<<"goodbye";
            break;
            default:
            cout<<"invalid choice!!";
        }
    }
    while (choice!=3);
    return 0;
    
}
