#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Bill {
private:
    string item;
    int rate, quantity;

public:
    Bill() : item(""), rate(0), quantity(0) {}

    void setItem(string i) { item = i; }
    void setRate(int r) { rate = r; }
    void setQuant(int q) { quantity = q; }

    string getItem() { return item; }
    int getRate() { return rate; }
    int getQuant() { return quantity; }
};

void addItem(Bill b) {
    bool close = false;
    while (!close) {
        system("cls");
        int choice;
        cout << "\t1. Add Item\n\t2. Close\n\tEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            string item;
            int rate, quant;

            cout << "\tEnter Item Name: ";
            cin >> item;
            b.setItem(item);

            cout << "\tEnter Rate of Item: ";
            cin >> rate;
            b.setRate(rate);

            cout << "\tEnter Quantity of Item: ";
            cin >> quant;
            b.setQuant(quant);

            ofstream out("Bill.txt", ios::app);
            if (!out) {
                cout << "\tError: File can't open!" << endl;
            } else {
                out << b.getItem() << " " << b.getRate() << " " << b.getQuant() << endl;
                cout << "\tItem Added Successfully!" << endl;
            }
            out.close();
            Sleep(2000);
        } else if (choice == 2) {
            close = true;
            cout << "\tBack To Main Menu!" << endl;
            Sleep(2000);
        } else {
            cout << "\tInvalid Choice!" << endl;
        }
    }
}

void printBill() {
    system("cls");
    ifstream in("Bill.txt");
    if (!in) {
        cout << "\tError: File can't open!" << endl;
        return;
    }

    string line;
    int total = 0;
    cout << "\n\tItem\tRate\tQty\tAmount" << endl;
    cout << "\t----------------------------------" << endl;

    while (getline(in, line)) {
        stringstream ss(line);
        string item;
        int rate, quant;
        ss >> item >> rate >> quant;
        int amount = rate * quant;
        cout << "\t" << item << "\t" << rate << "\t" << quant << "\t" << amount << endl;
        total += amount;
    }

    cout << "\n\tTotal Bill: " << total << endl;
    cout << "\tThanks for shopping!" << endl;

    in.close();
    Sleep(5000);
}

int main() {
    Bill b;
    bool exit = false;

    while (!exit) {
        system("cls");
        int val;

        cout << "\tWelcome to the Supermarket Billing System" << endl;
        cout << "\t****************************************" << endl;
        cout << "\t1. Add Item" << endl;
        cout << "\t2. Print Bill" << endl;
        cout << "\t3. Exit" << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (val == 1) {
            addItem(b);
        } else if (val == 2) {
            printBill();
        } else if (val == 3) {
            exit = true;
            cout << "\tGoodbye!" << endl;
            Sleep(2000);
        } else {
            cout << "\tInvalid Choice!" << endl;
            Sleep(2000);
        }
    }

    return 0;
}

