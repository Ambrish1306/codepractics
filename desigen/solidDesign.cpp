/*+-------------------+
|   IAccount        |<----------------+
|-------------------|                 |
| +deposit()        |                 |
| +withdraw()       |                 |
| +getBalance()     |                 |
+-------------------+                 |
          ^                           |
          |                           |
+-------------------+       +----------------------+
| BankAccount       |-----> | IAccountRepository   |
+-------------------+       +----------------------+
                                     ^
                                     |
                         +--------------------------+
                         | FileAccountRepository    |
                         +--------------------------+

BankAccount ---> INotificationService
                      ^
          +-----------+------------+
          |                        |
+------------------+   +------------------+
| EmailNotifier    |   | SMSNotifier      |
+------------------+   +------------------+
*/
/*key take away
1. interface doesnt define any const*/
#include <iostream>
#include <string>
#include <memory>
///////////////////////////Interfaces//////////////////////////
// Account abstraction
class IAccount {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual double getBalance() const = 0;
    virtual ~IAccount() = default;
};

// Notification abstraction
class INotificationService {
public:
    virtual void notify(const std::string& message) = 0;
    virtual ~INotificationService() = default;
};

// Persistence abstraction
class IAccountRepository {
public:
    virtual void save(double balance) = 0;
    virtual ~IAccountRepository() = default;
};

//////////////////////////////Concrete Implementations////////////////////////////////////////////
// Email notification
class EmailNotifier : public INotificationService {
public:
    void notify(const std::string& message) override {
        std::cout << "[Email] " << message << std::endl;
    }
};

// SMS notification
class SMSNotifier : public INotificationService {
public:
    void notify(const std::string& message) override {
        std::cout << "[SMS] " << message << std::endl;
    }
};

// File persistence
class FileAccountRepository : public IAccountRepository {
public:
    void save(double balance) override {
        std::cout << "Saving balance to file: " << balance << std::endl;
    }
};

//////////////BankAccount (Core Business Logic)///////////////////
class BankAccount : public IAccount {
private:
    double balance;
    std::shared_ptr<IAccountRepository> repository;//aggregation of account repository
    std::shared_ptr<INotificationService> notifier;//aggregation of notification service

public:
    BankAccount(double initialBalance,
                std::shared_ptr<IAccountRepository> repo,
                std::shared_ptr<INotificationService> notify)
        : balance(initialBalance), repository(repo), notifier(notify) {}

    void deposit(double amount) override {
        balance += amount;
        repository->save(balance);
        notifier->notify("Amount deposited: " + std::to_string(amount));
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            notifier->notify("Withdrawal failed: Insufficient balance");
            return;
        }
        balance -= amount;
        repository->save(balance);
        notifier->notify("Amount withdrawn: " + std::to_string(amount));
    }

    double getBalance() const override {
        return balance;
    }
};

//////////usage //////////////////
int main() {
    auto repository = std::make_shared<FileAccountRepository>();
    auto notifier = std::make_shared<EmailNotifier>();
    // Try SMSNotifier without changing BankAccount
    // auto notifier = std::make_shared<SMSNotifier>();

    BankAccount account(1000.0, repository, notifier);

    account.deposit(500);
    account.withdraw(300);
    account.withdraw(1500);

    std::cout << "Final Balance: " << account.getBalance() << std::endl;
    return 0;
}

