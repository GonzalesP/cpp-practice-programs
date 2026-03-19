// this project simulates a console-based banking system
// a Bank consists of a map of Accounts
// an Account saves a bank customer's account #, first + last name, and balance
// this info is saved into a file named Bank.txt for data persistence

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class InsufficientBalance : std::exception {};
class AccountNotFound : std::exception {};
class NegativeDeposit : std::exception {};
class NegativeWithdrawal : std::exception {};

class Bank;
class Account {
private:
    long accountNumber;
    std::string firstName;
    std::string lastName;
    float balance;
    static long NextAccountNumber;
public:
    Account(long, std::string, std::string, float);
    Account() : Account(0, "", "", 0) {}
    long getAccountNumber();
    std::string getFirstName();
    std::string getLastName();
    float getBalance();

    static long getNextAccountNumber();
    static void setNextAccountNumber(long accountNumber);

    friend std::ostream& operator<<(std::ostream& os, Account& acc);
    friend std::ofstream& operator<<(std::ofstream& ofs, Account& acc);
    friend std::ifstream& operator>>(std::ifstream& ifs, Account& acc);

    friend Bank;
};
long Account::NextAccountNumber = 0;

class Bank {
private:
    // std::map<long, Account> accounts;
public:
    std::map<long, Account> accounts;
    Bank();
    void openAccount(std::string, std::string, float);
    void balanceInquiry(long);
    void deposit(long, float);
    void withdrawal(long, float);
    void closeAccount(long);
    void showAllAccounts();
    ~Bank();
};



void printMenu() {
    std::cout << "Select an option below:" << std::endl;
    std::cout << "\t1) Open a New Account" << std::endl;
    std::cout << "\t2) Balance Inquiry" << std::endl;
    std::cout << "\t3) Deposit" << std::endl;
    std::cout << "\t4) Withdrawal" << std::endl;
    std::cout << "\t5) Close an Account" << std::endl;
    std::cout << "\t6) Show All Accounts" << std::endl;
    std::cout << "\t7) Quit" << std::endl << std::endl;
}

int main() {
    std::cout << std::endl << "Welcome to the CPP Bank"
              << std::endl << std::endl;

    Bank b;

    int choice = 0;

    std::string fName;
    std::string lName;
    float bal;
    long accNumber;

    while (choice != 7) {
        printMenu();
        std::cout << "Enter an option: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter first name: ";
                std::cin >> fName;
                std::cout << "Enter last name: ";
                std::cin >> lName;
                std::cout << "Enter initial balance: ";
                std::cin >> bal;
                try {
                    b.openAccount(fName, lName, bal);
                }
                catch (InsufficientBalance e) {
                    std::cout << "Error: Minimum balance is 500. ";
                    std::cout << "Account not created." << std::endl;
                }
                break;
            case 2:
                std::cout << "Enter account number: ";
                std::cin >> accNumber;
                try {
                    b.balanceInquiry(accNumber);
                }
                catch (AccountNotFound e) {
                    std::cout << "Error: Account #" << accNumber
                              << " not found." << std::endl;
                }
                break;
            case 3:
                std::cout << "Enter account number: ";
                std::cin >> accNumber;
                std::cout << "Enter amount to deposit: ";
                std::cin >> bal;
                try {
                    b.deposit(accNumber, bal);
                }
                catch (AccountNotFound e) {
                    std::cout << "Error: Account #" << accNumber
                              << " not found." << std::endl;
                }
                catch (NegativeDeposit e) {
                    std::cout << "Error: Cannot deposit negative amount."
                              << std::endl;
                }
                break;
            case 4:
                std::cout << "Enter account number: ";
                std::cin >> accNumber;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> bal;
                try {
                    b.withdrawal(accNumber, bal);
                }
                catch (AccountNotFound e) {
                    std::cout << "Error: Account #" << accNumber
                              << " not found." << std::endl;
                }
                catch (NegativeWithdrawal e) {
                    std::cout << "Error: Cannot withdrawal negative amount."
                              << std::endl;
                }
                catch (InsufficientBalance e) {
                    std::cout << "Error: Insufficient balance. "
                              << "Minimum balance is 500." << std::endl;
                }
                break;
            case 5:
                std::cout << "Enter account number: ";
                std::cin >> accNumber;
                try {
                    b.closeAccount(accNumber);
                }
                catch (AccountNotFound e) {
                    std::cout << "Error: Account #" << accNumber
                              << " not found." << std::endl;
                }
                break;
            case 6:
                b.showAllAccounts();
                break;
            case 7:
                std::cout << "Closing bank..." << std::endl;
                break;
            default:
                std::cout << "Error: invalid menu option" << std::endl;
                break;
        }
        std::cout << std::endl;
    }

    std::cout << "Thank you for visiting the CPP Bank!"
              << std::endl << std::endl;

    return 0;
}


// BANK METHODS
Bank::Bank() {
    long lastAccountNumber = 0;

    std::ifstream ifs("Bank.txt");
    while (!ifs.eof()) {
        Account acc;
        ifs >> acc;
        if (acc.getFirstName() != "") {
            accounts.insert(std::pair<long, Account>
                (acc.getAccountNumber(), acc));
            lastAccountNumber = (acc.getAccountNumber() > lastAccountNumber ?
                                 acc.getAccountNumber() : lastAccountNumber);
        }
    }
    ifs.close();

    Account::setNextAccountNumber(lastAccountNumber);
}

Bank::~Bank() {
    std::ofstream ofs("Bank.txt", std::ios::trunc);

    std::map<long, Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); it++)
        ofs << it->second;

    ofs.close();
}

void Bank::openAccount(std::string fName, std::string lName, float b) {
    // InsufficientBalance
    if (b < 500)
        throw InsufficientBalance();
    
    // Create Account
    Account::NextAccountNumber++;
    Account acc(Account::NextAccountNumber, fName, lName, b);

    // Add Account to Bank (accounts)
    accounts.insert(std::pair<long, Account>(acc.accountNumber, acc));

    // Print Receipt
    std::cout << std::endl;
    std::cout << "Account #" << acc.accountNumber << " created."
              << std::endl;
    std::cout << acc;
}

void Bank::balanceInquiry(long accNum) {
    std::map<long, Account>::iterator it;
    it = accounts.find(accNum);

    // AccountNotFound
    if (it == accounts.end())
        throw AccountNotFound();

    // Print Account
    std::cout << std::endl;
    std::cout << "Account #" << accNum << " Details:" << std::endl;
    std::cout << it->second;
}

void Bank::deposit(long accNum, float b) {
    std::map<long, Account>::iterator it;
    it = accounts.find(accNum);

    // AccountNotFound
    if (it == accounts.end())
        throw AccountNotFound();
    
    // NegativeDeposit
    if (b < 0)
        throw NegativeDeposit();
    
    // Deposit Balance into Account
    it->second.balance += b;

    // Print Receipt
    std::cout << std::endl;
    std::cout << "Deposited " << b << std::endl;
    std::cout << it->second;
}

void Bank::withdrawal(long accNum, float b) {
    std::map<long, Account>::iterator it;
    it = accounts.find(accNum);

    // AccountNotFound
    if (it == accounts.end())
        throw AccountNotFound();
    
    // NegativeWithdrawal
    if (b < 0)
        throw NegativeDeposit();
    
    // InsufficientBalance
    if (it->second.getBalance() - b < 500)
        throw InsufficientBalance();
    
    // Withdraw Balance from Account
    it->second.balance -= b;

    // Print Receipt
    std::cout << std::endl;
    std::cout << "Withdrew " << b << std::endl;
    std::cout << it->second;
}

void Bank::closeAccount(long accNum) {
    std::map<long, Account>::iterator it;
    it = accounts.find(accNum);

    // AccountNotFound
    if (it == accounts.end())
        throw AccountNotFound();

    // Print Receipt
    accounts.erase(accNum);
    std::cout << std::endl;
    std::cout << "Deleted Account #" << accNum << std::endl;
}

void Bank::showAllAccounts() {
    std::cout << std::endl;

    // print all accounts
    std::map<long, Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); it++) {
        std::cout << "Account #" << it->second.accountNumber << std::endl;
        std::cout << it->second << std::endl;
    }
}


// ACCOUNT METHODS
Account::Account(long accNum, std::string fName, std::string lName, float b) {
    accountNumber = accNum;
    firstName = fName;
    lastName = lName;
    balance = b;
}

long Account::getAccountNumber() {
    return accountNumber;
}

std::string Account::getFirstName() {
    return firstName;
}

std::string Account::getLastName() {
    return lastName;
}

float Account::getBalance() {
    return balance;
}

long Account::getNextAccountNumber() {
    return NextAccountNumber;
}

void Account::setNextAccountNumber(long accountNumber) {
    NextAccountNumber = accountNumber;
}

std::ostream& operator<<(std::ostream& os, Account& acc) {
    os << "First Name: " << acc.firstName << std::endl;
    os << "Last Name: " << acc.lastName << std::endl;
    os << "Account Number: " << acc.accountNumber << std::endl;
    os << "Balance: " << acc.balance << std::endl;
    return os;
}

std::ofstream& operator<<(std::ofstream& ofs, Account& acc) {
    ofs << acc.accountNumber << std::endl;
    ofs << acc.firstName << std::endl;
    ofs << acc.lastName << std::endl;
    ofs << acc.balance << std::endl;
    return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Account& acc) {
    ifs >> acc.accountNumber >> acc.firstName >> acc.lastName >> acc.balance;
    return ifs;
}