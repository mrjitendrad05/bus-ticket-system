#include <iostream>
#include <fstream>
//#include <string>
using namespace std;

struct Customer {
    int id;
    string name;
    int age;
    string phone;
};

struct Policy {
    int id;
    int customerId;
    string type;
    float coverage;
    float premium;
};

void addCustomer() {
    Customer c;
    ofstream file("data/customers.txt", ios::app);
    cout << "\nEnter customer ID: ";
    cin >> c.id;
    cin.ignore();
    cout << "Enter customer name: ";
    getline(cin, c.name);
    cout << "Enter age: ";
    cin >> c.age;
    cout << "Enter phone number: ";
    cin >> c.phone;

    if (c.name == "" || c.age < 18 || c.age > 100) {
        cout << "Invalid customer details.\n";
        return;
    }

    file << c.id << "|" << c.name << "|" << c.age << "|" << c.phone << endl;
    file.close();
    cout << "Customer saved successfully.\n";
}

void showCustomers() {
    ifstream file("data/customers.txt");
    string line;
    cout << "\n--- Customer List ---\n";
    while (getline(file, line))
        cout << line << endl;
    file.close();
}

void addPolicy() {
    Policy p;
    ofstream file("data/policies.txt", ios::app);
    cout << "\nEnter policy ID: ";
    cin >> p.id;
    cout << "Enter customer ID: ";
    cin >> p.customerId;

    cout << "\n1. Life\n2. Health\n3. Vehicle\n4. Property\nChoose type: ";
    int choice;
    cin >> choice;

    if (choice == 1) p.type = "Life";
    else if (choice == 2) p.type = "Health";
    else if (choice == 3) p.type = "Vehicle";
    else if (choice == 4) p.type = "Property";
    else {
        cout << "Invalid insurance type.\n";
        return;
    }

    cout << "Enter coverage amount: ";
    cin >> p.coverage;
    if (p.coverage <= 0) {
        cout << "Coverage must be greater than zero.\n";
        return;
    }

    if (p.type == "Life") p.premium = p.coverage * 0.02;
    else if (p.type == "Health") p.premium = p.coverage * 0.03;
    else if (p.type == "Vehicle") p.premium = p.coverage * 0.04;
    else p.premium = p.coverage * 0.01;

    file << p.id << "|" << p.customerId << "|" << p.type << "|"
         << p.coverage << "|" << p.premium << endl;
    file.close();

    cout << "\nPolicy saved successfully.\n";
    cout << "Policy ID: " << p.id << endl;
    cout << "Insurance Type: " << p.type << endl;
    cout << "Premium: " << p.premium << endl;
}

void showPolicies() {
    ifstream file("data/policies.txt");
    string line;
    cout << "\n--- Policy List ---\n";
    while (getline(file, line))
        cout << line << endl;
    file.close();
}

void searchCustomer() {
    ifstream file("data/customers.txt");
    int searchId, id, age;
    string name, phone;
    char separator;

    cout << "\nEnter customer ID to search: ";
    cin >> searchId;

    while (file >> id >> separator) {
        getline(file, name, '|');
        file >> age >> separator;
        getline(file, phone);

        if (id == searchId) {
            cout << "\nCustomer found!\n";
            cout << "ID: " << id << "\nName: " << name
                 << "\nAge: " << age << "\nPhone: " << phone << endl;
            file.close();
            return;
        }
    }
    cout << "Customer not found.\n";
    file.close();
}

int main() {
    int choice;
    do {
        cout << "\n====================================\n";
        cout << "   INSURANCE MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Add Customer\n";
        cout << "2. Show Customers\n";
        cout << "3. Search Customer\n";
        cout << "4. Add Insurance Policy\n";
        cout << "5. Show Policies\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) addCustomer();
        else if (choice == 2) showCustomers();
        else if (choice == 3) searchCustomer();
        else if (choice == 4) addPolicy();
        else if (choice == 5) showPolicies();
        else if (choice == 0) cout << "Thank you for using the system.\n";
        else cout << "Invalid choice. Try again.\n";
    } while (choice != 0);

    return 0;
}
