/*
Name: Samta Prajapati
Roll No: CO2122
*/
#include <iostream>
using namespace std;

template <typename T>
void sortArray(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int intArr[] = {64, 25, 12, 22, 11};
    float floatArr[] = {64.5, 25.1, 12.3, 22.8, 11.0};
    int n1 = 5;
    int n2 = 5;

    sortArray(intArr, n1);
    sortArray(floatArr, n2);

    cout << "Sorted Integer Array: [";
    for (int i = 0; i < n1; i++) {
        cout << intArr[i];
        if (i < n1 - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    cout << "Sorted Float Array: [";
    cout.setf(ios::fixed);
    cout.precision(1);
    for (int i = 0; i < n2; i++) {
        cout << floatArr[i];
        if (i < n2 - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

/*OUTPUT 
Sorted Integer Array: [11, 12, 22, 25, 64]
Sorted Float Array: [11.0, 12.3, 22.8, 25.1, 64.5]
*/
