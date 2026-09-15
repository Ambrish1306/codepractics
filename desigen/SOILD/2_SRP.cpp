#include <iostream>
#include <vector>

using namespace std;

// Product class representing any item of any ECommerce.
class Product {
public:
    string name;
    double price;
 
    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

// Violating SRP: ShoppingCart is handling multiple responsibilities
class ShoppingCart {
    private: 
    vector<shared_ptr<Product>> products; 

public:
    void addProduct(shared_ptr<Product> p) { 
        products.push_back(p);
    }

    const vector<shared_ptr<Product>>& getProducts() { 
        return products;
    } 

    // 1. Calculates total price in cart.
    double calculateTotal() {
        double total = 0;
        for (auto p : products) {
            total += p->price;
        }
        return total;
    }

    // 2. Violating SRP - Prints invoice (Should be in a separate class)
    /*void printInvoice() {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : products) {
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << calculateTotal() << endl;
    }*/

    // 3. Violating SRP - Saves to DB (Should be in a separate class)
    /*void saveToDatabase() {
        cout << "Saving shopping cart to database..." << endl;
    }*/
};
class IShoppingCartStorage {
    public: 
        virtual void saveToDatabase() = 0;
        virtual ~IShoppingCartStorage () = default;
};
class FileDB : public IShoppingCartStorage {
      shared_ptr<ShoppingCart> cart;
    public: 
      FileDB(shared_ptr<ShoppingCart> cart):cart(cart){};
      void saveToDatabase() override {
            cout << "saving on file DB";
      }
};
class MangoDB : public IShoppingCartStorage {
    public: 
      void saveToDatabase() override{
            cout << "saving on file MangoDB";
      }
};
class ShoppingCartPrint{
       shared_ptr<ShoppingCart> cart;
       public :
         ShoppingCartPrint(shared_ptr<ShoppingCart> cart):cart(cart){};

    void printInvoice() {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : cart->getProducts()) {
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << cart->calculateTotal() << endl;
    } 
};


int main() {
    shared_ptr<ShoppingCart> cart = make_shared<ShoppingCart>();

    ///this is very imp shared_ptr<Product> p=make_shared<Product>("Laptop", 50000)
    cart->addProduct(make_shared<Product>("Laptop", 50000));///this is very imp shared_ptr<Product> p=make_shared<Product>("Laptop", 50000)
    cart->addProduct(make_shared<Product>("Mouse", 2000));
     
    shared_ptr<IShoppingCartStorage > db = make_shared<FileDB>(cart); 
    db->saveToDatabase();
    shared_ptr<ShoppingCartPrint> print = make_shared<ShoppingCartPrint>(cart);
    print->printInvoice(); 
    return 0;
}