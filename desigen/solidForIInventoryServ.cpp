/*+----------------------+
|   IInventoryService  |
|----------------------|
| +addItem()           |
| +removeItem()        |
| +updateStock()       |
+----------------------+
           ^
           |
+----------------------+
| InventoryService     |
+----------------------+
   |            |
   |            +--------------------+
   |                                 |
   v                                 v
+-------------------+       +----------------------+
| IInventoryRepo    |       | INotificationService |
+-------------------+       +----------------------+
        ^                               ^
        |                               |
+---------------------+      +---------------------+
| FileInventoryRepo   |      | EmailNotifier       |
+---------------------+      +---------------------+
                               SMSNotifier
*/

//////////Interfaces (Pure Abstractions)//////////////
#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
using namespace std;
// Inventory operations
class IInventoryService {
public:
    virtual void addItem(const string& item, int qty) = 0;
    virtual void removeItem(const string& item) = 0;
    virtual void updateStock(const string& item, int qty) = 0;
    virtual ~IInventoryService() = default;
};

// Persistence abstraction
class IInventoryRepository {
public:
    virtual void save(const string& item, int qty) = 0;
    virtual int load(const string& item) = 0;
    virtual void remove(const string& item) = 0;
    virtual ~IInventoryRepository() = default;
};

// Notification abstraction
class INotificationService {
public:
    virtual void notify(const string& message) = 0;
    virtual ~INotificationService() = default;
};

///////////////////Concrete Implementations/////////////////////
class FileInventoryRepository : public IInventoryRepository {
private:
    unordered_map<string, int> storage;

public:
    void save(const string& item, int qty) override {
        storage[item] = qty;
         cout << "[FileRepo] Saved " << item << ": " << qty << endl;
    }

    int load(const string& item) override {
        return storage[item];
    }

    void remove(const string& item) override {
        storage.erase(item);
         cout << "[FileRepo] Removed " << item << endl;
    }
};
class EmailNotifier : public INotificationService {
public:
    void notify(const string& message) override {
          cout << "[Email] " << message << endl;
    }
};

class SMSNotifier : public INotificationService {
public:
    void notify(const  string& message) override {
          cout << "[SMS] " << message <<  endl;
    }
};
/// BUSINESS logic 
class InventoryService : public IInventoryService {
private:
     shared_ptr<IInventoryRepository> mRepository;//aggregation of account repository
     shared_ptr<INotificationService> mNotifier;//aggregation of notification service
    const int LOW_STOCK_THRESHOLD = 5;

public:
    InventoryService( shared_ptr<IInventoryRepository> repo,
                      shared_ptr<INotificationService> notify)
        : mRepository(repo), mNotifier(notify) {}

    void addItem(const  string& item, int qty) override {
        mRepository->save(item, qty);
        mNotifier->notify("Item added: " + item);
    }

    void removeItem(const  string& item) override {
        mRepository->remove(item);
        mNotifier->notify("Item removed: " + item);
    }

    void updateStock(const  string& item, int qty) override {
        mRepository->save(item, qty);

        if (qty < LOW_STOCK_THRESHOLD) {
            mNotifier->notify("Low stock alert for " + item);
        }
    }
};
//✔ SRP✔ DIP✔ Testable✔ Clean

///CLIENT 
int main() {
    auto repository =  make_shared<FileInventoryRepository>();
    auto notifier =  make_shared<EmailNotifier>();
    // switch to SMSNotifier without touching InventoryService

    InventoryService inventory(repository, notifier);

    inventory.addItem("Laptop", 10);
    inventory.updateStock("Laptop", 3);
    inventory.removeItem("Laptop");

    return 0;
}
