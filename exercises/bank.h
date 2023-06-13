#pragma once

class BankAccount
{
private:
   
    int id;

protected:
    
    double balance;

public:
    BankAccount();
    BankAccount(int);

   
    virtual void deposit(double);
    virtual void withdraw(double);
    
    double getBalance();
    int getId();
    
    virtual void printDetails();
};


class PaymentAccount : public BankAccount
{
private:

    double maxOverdraft;

public:
    PaymentAccount(int, double);
    void withdraw(double);
    void printDetails();
};

// Клас за спестовна сметка
class SavingsAccount : public BankAccount
{
private:
    double percentReturn;

public:
    SavingsAccount(int, double);
    void deposit(double);
    void printDetails();
};


class DepositAccount : public BankAccount
{
private:
    double percentReturn;
    double fee;

public:
    DepositAccount(int, double, double);
    void deposit(double);
    void withdraw(double);
    void printDetails();
};


class BankProfile
{
private:
    Vector<BankAccount *> accounts;

public:
    void addAccount(BankAccount *);
    void deposit(int, double);
    BankAccount * getAccount(int);
    void removeAccount(int);
    void withdraw(int, double);
    void printDetails(int);
};
