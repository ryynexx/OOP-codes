#include <iostream>
using namespace std;

class User //abstract class
{
    protected:
        string name;
        string email;
        double walletBalance;
    public:
        User() {}
        User(string n, string e, double bal)
            : name(n), email(e), walletBalance(bal) {}
        virtual ~User() {}

        void AddMoney(double amount) //normal functionn
        {
            walletBalance += amount;
        }

        virtual void displayProfile() = 0;//pure virtual function
};

class Buyer : public User //dervied class
{
    private:
        string* purchase_his;
        int num_p;//number of products
        int capacity;
    public:
        Buyer() : User(), num_p(0), capacity(10) 
        {
            purchase_his = new string[capacity];
        }

        Buyer(string n, string e, double bal)
        : User(n, e, bal), num_p(0), capacity(10) 
            {
                purchase_his = new string[capacity];
            }

        ~Buyer() 
        {
            delete[] purchase_his;
        }

        void buy(string prod) 
        {
            if (num_p >= capacity) 
            {
                capacity *= 2;
                string* new_purchase = new string[capacity];
                for (int i = 0; i < num_p; i++) 
                {
                    new_purchase[i] = purchase_his[i];
                }
                delete[] purchase_his;
                purchase_his = new_purchase;
            }
            purchase_his[num_p++] = prod;
        }

        void displayProfile() 
        {
            cout << "\n---------- Buyer ---------\n";
            cout << "Name : " << name << endl;
            cout << "Email : " << email << endl;
            cout << "Wallet Balance : $" << walletBalance << endl;
            cout << "Purchase History:\n";
            for (int i = 0; i < num_p; i++) {
                cout << " - " << purchase_his[i] << endl;
            }
        }
};

class Seller : public User //derived class
{
    private:
        string* sales_his;
        int num_p;
        int capacity;
    public:
        Seller() : User(), num_p(0), capacity(10) 
            {
                sales_his = new string[capacity];
            }

        Seller(string n, string e, double bal)
            : User(n, e, bal), num_p(0), capacity(10) 
            {
                sales_his = new string[capacity];
            }

        ~Seller() 
        {
            delete[] sales_his;
        }

        void sell(string prod) 
        {
            if (num_p >= capacity) 
            {
                capacity *= 2;
                string* new_sale = new string[capacity];
                for (int i = 0; i < num_p; i++) 
                {
                    new_sale[i] = sales_his[i];
                }
                delete[] sales_his;
                sales_his = new_sale;
            }
            sales_his[num_p++] = prod;
        }

        void displayProfile() 
        {
            cout << "\n---------- Seller ---------\n";
            cout << "Name : " << name << endl;
            cout << "Email : " << email << endl;
            cout << "Wallet Balance : $" << walletBalance << endl;
            cout << "Sales History:\n";
            for (int i = 0; i < num_p; i++) 
            {
                cout << " - " << sales_his[i] << endl;
            }
        }
};

class PaymentMethod //interface class
{
    public:
        virtual void pay(double amount) = 0;
        virtual ~PaymentMethod() {}
};

class CreditCardPayment : public PaymentMethod 
{
    public:
        void pay(double amount) 
        {
            cout << "Amount $" << amount << " paid using Credit Card.\n";
        }
};

int main() 
{
    User* buyer = new Buyer("Amina", "amina@gmail.com", 2000);//dma
    User* seller = new Seller("Ahmad", "ahmad@gmail.com", 3000);//dma

    buyer->AddMoney(4000);
    seller->AddMoney(6000);

    buyer->displayProfile();
    seller->displayProfile();

    Buyer b1("Amina", "amina@gmail.com", 2000);
    Seller s1("Ahmad", "ahmad@gmail.com", 3000);

    b1.buy("Hair Brush");
    s1.sell("Hair Brush");
    b1.buy("Shirt");
    s1.sell("Shirt");

    PaymentMethod* payment = new CreditCardPayment;//dma
    payment->pay(150);

    b1.displayProfile();
    s1.displayProfile();

    delete buyer;
    delete seller;
    delete payment;

return 0;
}
