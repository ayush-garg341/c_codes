#include<iostream>
using namespace std;

class Account {
  protected:
  float balance;

  public:
  Account(float bal) {
    balance = bal;
  }

  virtual void Deposit(float amount) = 0;
  virtual void Withdraw(float amount) = 0;
  virtual void printBalance() = 0;
};

class Savings: public Account {
  float interest_rate = 0.8;
  
  public:
  Savings(int bal): Account(bal){}
  
  void Deposit(float amount) {
    balance += amount + (amount * interest_rate);
  }
  
  void Withdraw(float amount) {
    balance -= amount + (amount * interest_rate);
  }
  
  void printBalance() {
    cout << "Balance in your saving account: " << balance << endl;
  }
};

class Current: public Account {
  
  public:
  Current(int bal): Account(bal){}
  
  void Deposit(float amount) {
    balance += amount;
  }
  
  void Withdraw(float amount) {
    balance -= amount;
  }
  
  void printBalance() {
    cout << "Balance in your current account: " << balance << endl;
  }
};

int main() {
  // creating savings account object by calling account pointer
  Account * acc[2];
  acc[0] = new Savings(50000);   // pointing acc to savings object
  acc[0]->Deposit(1000);
  acc[0]->printBalance();
  
  acc[0]->Withdraw(3000);
  acc[0]->printBalance();
  
  cout << endl;
  
  // creating current account object by calling account pointer
  
  acc[1] = new Current(50000);     //// pointing acc to current object
  acc[1]->Deposit(1000);
  acc[1]->printBalance();
  
  acc[1]->Withdraw(3000);
  acc[1]->printBalance();  
}
