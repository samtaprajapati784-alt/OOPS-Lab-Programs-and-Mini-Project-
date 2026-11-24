/*
Title: Employee Bio-Data System using multiple inheritance & Virtual base class
Name: Samta Prajapati
Roll no.: CO2122
Division: B
*/
#include <iostream>
#include <string>
using namespace std;

class personal {
protected:
    string name;
    int age;
    string gender;
    string address;
    string qualification;

public:
    void getpersonal() {
        cout << "\nEnter your name: ";
        cin >> name;
        cout << "\nEnter your age: ";
        cin >> age;
        cout << "\nEnter your gender: ";
        cin >> gender;
        cout << "\nEnter your address: ";
        cin >> address;
        cout << "\nEnter your qualifications: ";
        cin >> qualification;
    }

    void displaypersonal() {
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nGender: " << gender;
        cout << "\nAddress: " << address;
        cout << "\nQualifications: " << qualification;
    }
};

class professional : virtual public personal {
protected:
    int experience;
    int empid;
    string organization;
    int salary;

public:
    void getprofessional() {
        cout << "\nEnter your job experience: ";
        cin >> experience;
        cout << "\nEnter your employee id: ";
        cin >> empid;
        cout << "\nEnter your organization name: ";
        cin >> organization;
        cout << "\nEnter your salary: ";
        cin >> salary;
    }

    void displayprofessional() {
        cout << "\nJob experience: " << experience;
        cout << "\nEmployee id: " << empid;
        cout << "\nOrganization: " << organization;
        cout << "\nSalary: " << salary;
    }
};

class academic : virtual public personal {
protected:
    string skill;
    string quality;

public:
    void getacademic() {
        cout << "\nEnter your skills: ";
        cin >> skill;
        cout << "\nEnter your qualities: ";
        cin >> quality;
    }

    void displayacademic() {
        cout << "\nSkill: " << skill;
        cout << "\nQuality: " << quality;
    }
};

class employeebiodata : public professional, public academic {
public:
    void getdata() {
        getpersonal();
        getprofessional();
        getacademic();
    }

    void displaydata() {
        displaypersonal();
        displayprofessional();
        displayacademic();
    }
};

int main() {
    employeebiodata obj1;
    cout << "Enter data";
    obj1.getdata();
    obj1.displaydata();
    return 0;
}

/*OUTPUT 
Enter data
Enter your name: R.R
Enter your age: 19
Enter your gender: Female
Enter your address: Pune
Enter your qualifications: B.Tech
Enter your job experience: 2
Enter your employee id: 2123
Enter your organization name: Scantech
Enter your salary: 2500000
Enter your skills: Designing
Enter your qualities: Punctuality

Name: R.R
Age: 19
Gender: Female
Address: Pune
Qualifications: B.Tech
Job experience: 2
Employee id: 2123
Organization: Scantech
Salary: 2500000
Skill: Designing
Quality: Punctuality
*/
