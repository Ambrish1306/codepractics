#include <iostream>
#include <vector>

using namespace std;

// Product class representing any item in eCommerce.
class Product {
public:
    string mName;
    double mPrice;

    Product(string name, double price) {
        this->mName = name;
        this->mPrice = price;
    }
};

//1. ShoppingCart: Only responsible for Cart related business logic.
class ShoppingCart {
private:
    //vector<Product*> products;
     vector<shared_ptr<Product>>  mProducts;
public:
    void addProduct(shared_ptr<Product> p) { 
        mProducts.push_back(p);//***************************forgot to add on (p)*** */
    }

    const vector<shared_ptr<Product>> getProducts() { 
        return mProducts;
    } 

    //Calculates total price in cart.
    double calculateTotal() {
        double total = 0;
        for (auto p : mProducts) {
            total = total + p->mPrice;
        }
        return total;
    }
};

// 2. ShoppingCartPrinter: Only responsible for printing invoices
class ShoppingCartPrinter {
private:
    shared_ptr<ShoppingCart> mCart; 

public:
    ShoppingCartPrinter(shared_ptr<ShoppingCart> cart) { 
        this->mCart = cart; //I forgot the const completly 
    }

    void printInvoice() {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : mCart->getProducts()) {
            cout << p->mName << " - Rs " << p->mPrice << endl;
        }
        cout << "Total: Rs " << mCart->calculateTotal() << endl;
    }
};

// 3. ShoppingCartStorage: Only responsible for saving cart to DB
/*class ShoppingCartStorage {
private:
    shared_ptr<ShoppingCart> cart; 

public:
    ShoppingCartStorage(shared_ptr<ShoppingCart> cart) { 
        this->cart = cart; 
    }

    void saveToSQLDatabase() {
        cout << "Saving shopping cart to SQL DB..." << endl;
    }

    void saveToMongoDatabase() {
        cout << "Saving shopping cart to Mongo DB..." << endl;
    }

    void saveToFile() {
        cout << "Saving shopping cart to File..." << endl;
    }
};*/
class IPersistence{
  public : 
    virtual void save(shared_ptr<ShoppingCart> cart)=0;
    virtual ~IPersistence()=default ; 
};
class SQLDB: public IPersistence
{
    private: 
    shared_ptr<ShoppingCart> mCart;
    public: 
    SQLDB(shared_ptr<ShoppingCart> cart){
        this->mCart=cart;
    }
    
    void save(shared_ptr<ShoppingCart> cart) override {//object setter same like constructor
        this->mCart = cart;
        cout<<"save to sqldb"<<endl;
    }
    void save2()
    {
        cout<<"saving to usng save2 fuc";
    }
};
class ManogDB: public IPersistence
{
    void save(shared_ptr<ShoppingCart> cart) override {
        cout<<"save to MangoDB"<<endl;
    }
};
class File: public IPersistence
{
    void save(shared_ptr<ShoppingCart> cart) override {
        cout<<"save to file"<<endl;
    }
};



int main() {

    shared_ptr<ShoppingCart> cart = make_shared<ShoppingCart>();

    cart->addProduct(make_shared<Product>("Laptop", 50000));
    cart->addProduct(make_shared<Product>("Mouse", 2000));

    shared_ptr<ShoppingCartPrinter> printer = make_shared<ShoppingCartPrinter>(cart);
    printer->printInvoice();

    shared_ptr<IPersistence> sqldb   = make_shared<SQLDB>(cart);
    shared_ptr<IPersistence> manogDB = make_shared<ManogDB>();
    shared_ptr<IPersistence> file    = make_shared<File>();

    shared_ptr<SQLDB> sqldbLocal = make_shared<SQLDB>(cart);
    sqldb->save(cart);
    sqldbLocal->save2();
    file->save(cart);
    manogDB->save(cart);

    return 0;
}