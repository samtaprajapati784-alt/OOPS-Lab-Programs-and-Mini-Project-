/*
Name: Samta Prajapati
Roll No: CO2122
*/
#include <iostream>
using namespace std;

class complex {
    float real;
    float imag;

public:
    complex() {
        real = 0;
        imag = 0;
    }

    complex(float r, float i) {
        real = r;
        imag = i;
    }

    void display() {
        cout << real << "+" << imag << "i";
    }

    friend istream& operator>>(istream& in, complex& c) {
        cout << "Enter real part :" << endl;
        in >> c.real;
        cout << "Enter imag part:" << endl;
        in >> c.imag;
        return in;
    }

    friend ostream& operator<<(ostream& out, const complex& c) {
        out << c.real << "+" << c.imag << "i";
        return out;
    }

    complex operator+(const complex& c) const {
        complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    complex operator-(const complex& c) const {
        complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }

    complex operator*(const complex& c) const {
        complex temp;
        temp.real = (real * c.real) - (imag * c.imag);
        temp.imag = (real * c.imag) + (imag * c.real);
        return temp;
    }
};

int main() {
    complex c1, c2, c3;
    int choice;

    cout << "Enter first complex no :\n";
    cin >> c1;
    cout << "Enter second complex no :\n";
    cin >> c2;

    do {
        cout << "\n===========Complex Number Calculation==========" << endl;
        cout << "1.Addition\n" << endl;
        cout << "2.Subtraction\n" << endl;
        cout << "3.Multiplication\n" << endl;
        cout << "4.Exit\n" << endl;
        cout << "Enter your choice\n" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                c3 = c1 + c2;
                cout << "Addition is :" << c3 << endl;
                break;
            case 2:
                c3 = c1 - c2;
                cout << "Subtraction is :" << c3 << endl;
                break;
            case 3:
                c3 = c1 * c2;
                cout << "Multiplication is :" << c3 << endl;
                break;
            case 4:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
        }
    } while (choice != 4);

    return 0;
}

/*OUTPUT 
Enter first complex no :
Enter real part :
8
Enter imag part:
10
Enter second complex no :
Enter real part :
3
Enter imag part:
5

===========Complex Number Calculation==========
1.Addition

2.Subtraction

3.Multiplication

4.Exit

Enter your choice

1
Addition is :11+15i

===========Complex Number Calculation==========
1.Addition

2.Subtraction

3.Multiplication

4.Exit

Enter your choice

2
Subtraction is :5+5i

===========Complex Number Calculation==========
1.Addition

2.Subtraction

3.Multiplication

4.Exit

Enter your choice

3
Multiplication is :-26+70i

===========Complex Number Calculation==========
1.Addition

2.Subtraction

3.Multiplication

4.Exit

Enter your choice

4
Exit
*/
