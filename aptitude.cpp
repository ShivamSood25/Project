#include<iostream>
#include<ctime>
#include<vector>
#include<iomanip>
using namespace std;

struct Item {
    string name;
    int price;
    int quantity;
};

class Bill {
private:
    string name, address;
    time_t now = time(0);
    long long cn;
    int totalbill = 0, billnumber = 1;
    vector<Item> itemsOrdered;

public:
    Bill(string n, string a, long long c) {
        name = n;
        address = a;
        cn = c;
    }

    void addDish(int dishcode, int quantity) {
        Item item;
        bool validDish = true;
        switch (dishcode) {
            case 1: item = {"Pasta", 100, quantity}; break;
            case 2: item = {"Pizza", 200, quantity}; break;
            case 3: item = {"Burger", 50, quantity}; break;
            case 4: item = {"Noodles", 60, quantity}; break;
            case 5: item = {"Soup", 90, quantity}; break;
            case 6: item = {"Salad", 40, quantity}; break;
            case 7: item = {"Cold drinks", 40, quantity}; break;
            case 8: item = {"Tea", 30, quantity}; break;
            case 9: item = {"Coffee", 50, quantity}; break;
            case 10: item = {"Water", 20, quantity}; break;
            default: 
                cout << "Invalid dish code!" << endl;
                validDish = false;
        }
        if (validDish) {
            item.price *= quantity;
            itemsOrdered.push_back(item);
            totalbill += item.price;
        }
    }

    void showBill() {
        cout << "\n\n\n------------------------------------------------" << endl;
        cout << "                      BILL" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Bill number: #" << billnumber << endl;
        cout << "Current date and time: " << ctime(&now);
        cout << "Customer name: " << name << endl;
        cout << "Customer address: " << address << endl;
        cout << "Credit card number: " << cn << endl;
        cout << "------------------------------------------------" << endl;
        cout << left << setw(20) << "ITEMS" << setw(15) << "QUANTITY" << setw(10) << "PRICE" << endl;
        cout << "------------------------------------------------" << endl;

        for (auto &item : itemsOrdered) {
            cout << left << setw(20) << item.name 
                 << setw(15) << item.quantity 
                 << "Rs." << item.price << endl;
        }

        cout << "------------------------------------------------" << endl;
        cout << setw(35) << right << "Total Bill: Rs." << totalbill << endl;
        cout << "------------------------------------------------" << endl;
    }
};

int main() {
    string name, address;
    long long cn;
    cout << "\n-----------ENTER DETAILS-----------" << endl;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter credit card number: ";
    cin >> cn;
    Bill b1(name, address, cn);

    int q, c;
    char ans;

    cout << "\n\n\n";
    cout << "------------------------------------------------" << endl;
    cout << "         MENU" << endl;
    cout << "ITEMS            PRICE" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "1) Pasta          Rs.100" << endl;
    cout << "2) Pizza          Rs.200" << endl;
    cout << "3) Burger         Rs.50" << endl;
    cout << "4) Noodles        Rs.60" << endl;
    cout << "5) Soup           Rs.90" << endl;
    cout << "6) Salad          Rs.40" << endl;
    cout << "7) Cold drinks    Rs.40" << endl;
    cout << "8) Tea            Rs.30" << endl;
    cout << "9) Coffee         Rs.50" << endl;
    cout << "10) Water         Rs.20" << endl;
    cout << "------------------------------------------------\n" << endl;

    do {
        cout << "Enter Order: ";
        cin >> c;
        cout << "Enter quantity: ";
        cin >> q;
        b1.addDish(c, q); 
        cout << "Any other dish? y/n: ";
        cin >> ans;
    } while (ans != 'n');
    
    b1.showBill();
    return 0;
}
