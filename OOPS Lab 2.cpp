/*
Name: Samta Prajapati
Roll no: C02122
Div: B
*/
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
public:
    double balance;
    int account_no;
    string account_holder_name, account_type;
    static int totalaccounts;

    BankAccount() {
        totalaccounts++;
    }

    static void display_total_count() {
        cout << "\nTotal Bank Account created: " << totalaccounts;
    }

    inline void calculateInterest(double rate = 5.0) {
        double interest = (balance * rate * 1) / 100;
        balance += interest;
        cout << "\nInterest: " << interest;
        cout << "\nUpdated Balance: " << balance;
    }

    void create_account();
    void display_account();

    void comparebalance(BankAccount &obj) {
        cout << "\n----Bank Comparison----";
        if (this->balance > obj.balance) {
            cout << "\nBalance of " << this->account_holder_name << " is Greater";
        } else {
            cout << "\nBalance of " << obj.account_holder_name << " is Greater";
        }
    }
};

int BankAccount::totalaccounts = 0;

void BankAccount::create_account() {
    cout << "\nEnter account number: ";
    cin >> account_no;
    cout << "\nEnter account holder name: ";
    cin >> account_holder_name;
    cout << "\nEnter account type: ";
    cin >> account_type;
    cout << "\nEnter the balance: ";
    cin >> balance;
    cout << "\n-----------------------";
}

void BankAccount::display_account() {
    cout << "\n-----Account Details-----";
    cout << "\nAccount number: " << account_no;
    cout << "\nAccount holder name: " << account_holder_name;
    cout << "\nAccount type: " << account_type;
    cout << "\nBalance: " << balance;
    cout << "\n-----------------------";
}

int main() {
    BankAccount b1;
    BankAccount b2;

    b1.create_account();
    b2.create_account();

    b1.display_account();
    b2.display_account();

    BankAccount::display_total_count();

    cout << "\nFor account no: " << b1.account_no;
    b1.calculateInterest();

    cout << "\nFor account no: " << b2.account_no;
    b2.calculateInterest();

    b1.comparebalance(b2);

    return 0;
}

/*OUTPUT 
Enter account number: 101
Enter account holder name: Samta
Enter account type: Savings
Enter the balance: 50000
Enter account number: 102
Enter account holder name: Meera
Enter account type: Savings
Enter the balance: 25000

-----Account Details-----
Account number: 101
Account holder name: Samta
Account type: Savings
Balance: 50000

-----Account Details-----
Account number: 102
Account holder name: Meera
Account type: Savings
Balance: 25000

Total Bank Account created: 2
For account no: 101
Interest: 2500
Updated Balance: 52500
For account no: 102
Interest: 1250
Updated Balance: 26250

----Bank Comparison----
Balance of Samta is Greater
*/
