#include <iostream>
#include <vector>
using namespace std;

class bankAccount
{
private:
    string name;
    int account_no;
    double balance;

public:
    bankAccount(string n, int ac, double b)
    {
        name = n;
        account_no = ac;
        balance = b;
    }

    string getName()
    {
        return name;
    }

    int getAccount_no()
    {
        return account_no;
    }

    double getBalance()
    {
        return balance;
    }
    void depositMoney(double amount)
    {
        balance = balance + amount;
    }
    void withdrawMoney(double amount)
    {
        if(balance>=amount)
        {
            balance=balance-amount;
            
        }
        else
        {
            cout<<"Insufficient balance"<<endl;
        }

    }

};

class bankManagement
{
private:
    vector<bankAccount> accounts;

public:
    void createAccount(string name, int account_no, double balance)
    {
        accounts.push_back(bankAccount(name, account_no, balance));
    }

    void showAllAccount()
    {
        cout << "\t\tAll Account:\n";
        for (int i = 0; i < accounts.size(); i++)
        {
            cout << "Name: " << accounts[i].getName()  << ", Account Number: " << accounts[i].getAccount_no() << ", Balance: " << accounts[i].getBalance()<<endl;
        }
    }

    void searchAccount(int ac)
    {
        cout<<"Account Holder Details :\n";
        for(int i=0; i<accounts.size(); i++)
        {
            if(accounts[i].getAccount_no()==ac)
            {
            cout << "Name: " << accounts[i].getName()  << ", Account Number: " << accounts[i].getAccount_no() << ", Balance: " << accounts[i].getBalance()<<endl;
            }
            
            else
            {
                cout<<"\t\tAccount Not Matched...\n";
            }
        }
    }

    bankAccount*findAccount(int account_no)
    {
        for(int i=0; i<=accounts.size();i++)
        {
            if(accounts[i].getAccount_no()==account_no)
            {
                return &accounts[i];
            }
        }

    }
};

int main()
{
    bankManagement bank;
    int choice;
    char op;

    do
    {
        system("cls");
        cout << "\t\t::Bank Management system\n\n";
        cout << "\t\t\t---Main Menu---\n";
        cout << "\t\t1.Create Account\n";
        cout << "\t\t2.Show All Account\n";
        cout << "\t\t3.Search Account\n";
        cout << "\t\t4.Deposit Money\n";
        cout << "\t\t5.Withdraw Money\n";
        cout << "\t\t6.Exit\n";
        cout << "\t\t-----------------------------------------\t";

        cout << "\n\t\tEnter Your Choice :";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            int account_no;
            double balance;

            cout << "\t\tEnter Your Name :";
            cin >> name;
            cout << "\t\tEnter Your Bank Account :";
            cin >> account_no;
            cout << "\t\tEnter Your Initial Balance :";
            cin >> balance;

            bank.createAccount(name, account_no, balance);
            cout << "\t\tAccount created successfully....";
            break;
        }

        case 2:
        {
            bank.showAllAccount();
            break;
        }

        case 3:
        {
            int account_no;
            cout<<"\nEnter Account Number: ";
            cin>>account_no;
            bank.searchAccount(account_no);
            break;
        }

        case 4:
        {
            int account_no;
            double amount;
            cout<<"\t\tEnter The Account Number To Deposit the Money :";
            cin>>account_no;
           
            bankAccount * ac=bank.findAccount(account_no);
            if(ac !=NULL)
            {
                cout<<"\t\tEnter The Money : ";
                cin>>amount;
                ac->depositMoney(amount);
                cout<<"\t\tDeposit Succsessfully...."<<endl;

            }
            else
            {
                cout<<"\t\tAccount Not Found....";
            }
            break;

        }

        case 5:
        {
            int account_no;
            double amount;
            cout<<"\t\tEnter The Account Number To Withdraw the Money :";
            cin>>account_no;
           
            bankAccount * ac=bank.findAccount(account_no);
            if(ac !=NULL)
            {
                cout<<"\t\tEnter The Money : ";
                cin>>amount;
                ac->withdrawMoney(amount);
                cout<<"\t\tWithdraw Succsessfully...."<<endl;

            }
            else
            {
                cout<<"\t\tAccount Not Found....";
            }
            break;
        }

        case 6:
        {
            exit(1);
        }
        }
        cout << "\n\n\t\tDo you want countinue or Exit [Yes/No] ??";
        cin >> op;

    } while (op == 'y');

    if (op == 'n')
    {
        cout << "\n\t\tThank U USING FOR BANK";
    }
}