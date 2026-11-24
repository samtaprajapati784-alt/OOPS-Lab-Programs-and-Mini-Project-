/*
Title: Vehicle Rental System using Abstract Class and Dynamic Memory Allocation
Name: Samta Prajapati
Roll No: CO2122
*/
#include <iostream>
#include <string>
using namespace std;

class vehicle {
public:
    string veh_no, type_of_veh;
    int no_of_days;
    float total_kms;

    virtual void input() = 0;
    virtual float calculateRate() = 0;
    virtual ~vehicle() {}
};

class car : public vehicle {
public:
    void input() override {
        cout << "Enter car number: ";
        cin >> veh_no;
        cout << "Enter type of vehicle: ";
        cin >> type_of_veh;
        cout << "Enter no of days: ";
        cin >> no_of_days;
        cout << "Enter total kms: ";
        cin >> total_kms;
    }

    float calculateRate() override {
        float perday = 1000;
        float perkm = 25;
        return (no_of_days * perday) + (total_kms * perkm);
    }
};

class bus : public vehicle {
public:
    void input() override {
        cout << "Enter bus number: ";
        cin >> veh_no;
        cout << "Enter type of vehicle: ";
        cin >> type_of_veh;
        cout << "Enter no of days: ";
        cin >> no_of_days;
        cout << "Enter total kms: ";
        cin >> total_kms;
    }

    float calculateRate() override {
        float perday = 1500;
        float perkm = 35;
        return (no_of_days * perday) + (total_kms * perkm);
    }
};

class bike : public vehicle {
public:
    void input() override {
        cout << "Enter bike number: ";
        cin >> veh_no;
        cout << "Enter type of vehicle: ";
        cin >> type_of_veh;
        cout << "Enter no of days: ";
        cin >> no_of_days;
        cout << "Enter total kms: ";
        cin >> total_kms;
    }

    float calculateRate() override {
        float perday = 500;
        float perkm = 5;
        return (no_of_days * perday) + (total_kms * perkm);
    }
};

int main() {
    int choice;
    vehicle* v = nullptr;

    do {
        cout << "\n--- Vehicle Rental System ---\n";
        cout << "1. Car\n";
        cout << "2. Bus\n";
        cout << "3. Bike\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                v = new car();
                cout << "\n--- Car Details ---\n";
                v->input();
                cout << "Car Rent = Rs. " << v->calculateRate() << endl;
                delete v;
                v = nullptr;
                break;
            case 2:
                v = new bus();
                cout << "\n--- Bus Details ---\n";
                v->input();
                cout << "Bus Rent = Rs. " << v->calculateRate() << endl;
                delete v;
                v = nullptr;
                break;
            case 3:
                v = new bike();
                cout << "\n--- Bike Details ---\n";
                v->input();
                cout << "Bike Rent = Rs. " << v->calculateRate() << endl;
                delete v;
                v = nullptr;
                break;
            case 4:
                cout << "\nExiting program..." << endl;
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

/*OUTPUT 
--- Vehicle Rental System ---
1. Car
2. Bus
3. Bike
4. Exit
Enter your choice: 1

--- Car Details ---
Enter car number: 123
Enter type of vehicle: car
Enter no of days: 3
Enter total kms: 100
Car Rent = Rs. 5500

--- Vehicle Rental System ---
1. Car
2. Bus
3. Bike
4. Exit
Enter your choice: 3

--- Bike Details ---
Enter bike number: 789
Enter type of vehicle: bike
Enter no of days: 4
Enter total kms: 80
Bike Rent = Rs. 2400

--- Vehicle Rental System ---
1. Car
2. Bus
3. Bike
4. Exit
Enter your choice: 4

Exiting program...
*/
