#include<iostream>
using namespace std;
//working on stragyies designe pattern 
class Pyament{ 
public: 
   virtual void pay()=0; 
   virtual ~Pyament(){};
};

class CrditeCard : public Pyament{
    public :
       void pay() override{ 
            cout<<"Pyment done through Crdite Card"<<endl;

       }
};
class UpiPyment : public Pyament{
    public:
    void pay() override{ 
        cout<<"Payment done through Dedite card"<<endl;
    }
};
class DebitCarPayment : public Pyament{
    public: 
    void pay() override{
        cout<<"Paying through debit card"<<endl;
    }
};

class PaymentContext{
  Pyament *payment;
  public : 
   void setPayment(Pyament *p)
    {
        payment = p;
    }
    void makePayment() 
    {
        payment->pay();
    }
};

int main() 
{
    PaymentContext *pay; 
    UpiPyment *upi; 
    CrditeCard *cc; 
    pay->setPayment(upi);
    pay->makePayment();
    DebitCarPayment dbp; 
    pay->setPayment(&dbp);
    pay->makePayment();

}