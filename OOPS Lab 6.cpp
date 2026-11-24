/*
Name: Samta Prajapati
Roll No: CO2122
*/
#include <iostream>
#include <fstream>
using namespace std;

class Student {
    int roll;
    char name[50];
    int age;

public:
    void getdata() {
        cout << "Enter Student Roll No: ";
        cin >> roll;
        cout << "Enter Student Name: ";
        cin >> name;
        cout << "Enter Student Age: ";
        cin >> age;
    }

    void displaydata() {
        cout << "Student Roll No: " << roll << endl;
        cout << "Student Name: " << name << endl;
        cout << "Student Age: " << age << endl;
    }
};

int main() {
    Student s[3];
    fstream file;

    file.open("Student.dat", ios::out);
    cout << "Writing Student Information\n";
    for (int i = 0; i < 3; i++) {
        s[i].getdata();
        file.write((char*)&s[i], sizeof(s[i]));
    }
    file.close();

    file.open("Student.dat", ios::in);
    cout << "\nReading Student Information\n";
    for (int i = 0; i < 3; i++) {
        file.read((char*)&s[i], sizeof(s[i]));
        s[i].displaydata();
        cout << endl;
    }
    file.close();

    return 0;
}

/*OUTPUT 
Writing Student Information
Enter Student Roll No: 122
Enter Student Name: Samta
Enter Student Age: 19
Enter Student Roll No: 123
Enter Student Name: Rida
Enter Student Age: 19
Enter Student Roll No: 121
Enter Student Name: Divya
Enter Student Age: 19

Reading Student Information
Student Roll No: 122
Student Name: Samta
Student Age: 19

Student Roll No: 123
Student Name: Rida
Student Age: 19

Student Roll No: 121
Student Name: Divya
Student Age: 19
*/
