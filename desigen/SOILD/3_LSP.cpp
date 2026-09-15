#include <iostream>
#include<vector>
using namespace std;

/*class Account {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};*/
class DepositOnlyAccount {
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount {
public:
    virtual void withdraw(double amount) = 0;
};
class SavingAccount : public WithdrawableAccount { //account class chenaged to 
private:
    double balance;

public:
    SavingAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};

class CurrentAccount : public WithdrawableAccount { //account changed
private:
    double balance;

public:
    CurrentAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Current Account!\n";
        }
    }
};

class FixedTermAccount : public DepositOnlyAccount {
private:
    double balance;

public:
    FixedTermAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        throw logic_error("Withdrawal not allowed in Fixed Term Account!");
    }
};
    
class BankClient {
private:
    //vector<Account*> accounts;

    vector<WithdrawableAccount*> withdrawableAccounts;
    vector<DepositOnlyAccount*> depositOnlyAccounts;

public:
   /* BankClient(vector<Account*> accounts) { 
        this->accounts = accounts; 
    }*/
     BankClient( vector<WithdrawableAccount*> withdrawableAccounts, 
        vector<DepositOnlyAccount*> depositOnlyAccounts) { 
        this->withdrawableAccounts = withdrawableAccounts; 
        this->depositOnlyAccounts = depositOnlyAccounts;
    }

    /*void processTransactions() {
        for (Account* acc : accounts) {
            acc->deposit(1000);  //All accounts allow deposits

            //Assuming all accounts support withdrawal (LSP Violation)
            try {
                acc->withdraw(500);
            } catch (const logic_error& e) {
                cout << "Exception: " << e.what() << endl;
            }
        }
    }*/
     void processTransactions() {
        for (auto acc : withdrawableAccounts) {
            acc->deposit(1000);
            acc->withdraw(500); 
        }
        for (auto acc : depositOnlyAccounts) {
            acc->deposit(5000);
        }
    }
};

int main() {
    //vector<Account*> accounts;
    vector<WithdrawableAccount*> withdrawableAccounts; //vctore of pointer //Each element inside the vector is a pointer to a WithdrawableAccount.
                                                       //The vector object itself is on the stack (or wherever it is declared).
/*withdrawableAccounts (vector object)
+--------------------------------+
| ptr | size | capacity          |
+--------------------------------+
          |
          v
    +---------+---------+---------+
    |   *     |   *     |   *     |
    +---------+---------+---------+
       |          |          |
       v          v          v
   Account1   Account2   Account3*/

    withdrawableAccounts.push_back(new SavingAccount());//Different derived objects can coexist in the same vector.
    withdrawableAccounts.push_back(new CurrentAccount());//Different derived objects can coexist in the same vector.

    vector<DepositOnlyAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());

    //BankClient* client = new BankClient(accounts);
    BankClient* client = new BankClient(withdrawableAccounts,depositOnlyAccounts);

    client->processTransactions(); //  Throws exception when withdrawing from FixedTermAccount

    return 0;
}