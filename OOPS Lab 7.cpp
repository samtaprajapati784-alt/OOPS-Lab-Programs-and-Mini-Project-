/*
Name: Samta Prajapati
Roll No: CO2122
*/
#include <iostream>
#include <string>
using namespace std;

class Exception {
public:
    string message;
    Exception(string msg) {
        message = msg;
    }
};

int main() {
    int age, vehicle;
    double income;
    string city;

    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Income: ";
    cin >> income;
    cout << "Enter City: ";
    cin >> city;
    cout << "Do you have a 4-wheeler? (4 for Yes, 0 for No): ";
    cin >> vehicle;

    try {
        if (age < 18 || age > 55) {
            throw Exception("Age must be between 18 and 55");
        }
        if (income < 50000 || income > 100000) {
            throw Exception("Income must be between 50000 and 100000");
        }
        if (city != "Pune" && city != "Mumbai" &&
            city != "Bangalore" && city != "Chennai") {
            throw Exception("City must be Pune, Mumbai, Bangalore or Chennai");
        }
        if (vehicle != 4) {
            throw Exception("You must have a 4-wheeler vehicle");
        }
        cout << "All conditions are satisfied!" << endl;
    } catch (Exception &e) {
        cout << "Exception is: " << e.message << endl;
    }

    return 0;
}

/*OUTPUT 
Enter Age: 25
Enter Income: 60000
Enter City: Pune
Do you have a 4-wheeler? (4 for Yes, 0 for No): 4
All conditions are satisfied!

Enter Age: 16
Enter Income: 60000
Enter City: Pune
Do you have a 4-wheeler? (4 for Yes, 0 for No): 4
Exception is: Age must be between 18 and 55
*/
