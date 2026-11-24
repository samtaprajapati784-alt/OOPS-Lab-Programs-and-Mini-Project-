/*
Name: Samta Prajapati
Roll no: CO2122
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Item {
public:
    int itemCode;
    string name;
    float cost;
    int quantity;

    void input() {
        cout << "Enter Item Code: ";
        cin >> itemCode;
        cin.ignore();
        cout << "Enter Item Name: ";
        getline(cin, name);
        cout << "Enter Cost: ";
        cin >> cost;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void display() const {
        cout << itemCode << "\t" << name << "\t"
             << cost << "\t" << quantity << endl;
    }
};

void displayItems(const vector<Item>& items) {
    cout << "\nCode\tName\tCost\tQuantity\n";
    for (const auto& item : items) {
        item.display();
    }
}

int main() {
    vector<Item> items;
    int choice;

    do {
        cout << "\n--- Item Record Management ---\n";
        cout << "1. Add Item\n";
        cout << "2. Display Items\n";
        cout << "3. Sort by Item Code\n";
        cout << "4. Sort by Cost\n";
        cout << "5. Sort by Quantity\n";
        cout << "6. Search by Item Code\n";
        cout << "7. Search by Item Name\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Item item;
                item.input();
                items.push_back(item);
                cout << "Item added successfully!\n";
                break;
            }
            case 2:
                displayItems(items);
                break;
            case 3:
                sort(items.begin(), items.end(),
                     [](const Item& a, const Item& b) {
                         return a.itemCode < b.itemCode;
                     });
                cout << "Items sorted by Item Code.\n";
                displayItems(items);
                break;
            case 4:
                sort(items.begin(), items.end(),
                     [](const Item& a, const Item& b) {
                         return a.cost < b.cost;
                     });
                cout << "Items sorted by Cost.\n";
                displayItems(items);
                break;
            case 5:
                sort(items.begin(), items.end(),
                     [](const Item& a, const Item& b) {
                         return a.quantity < b.quantity;
                     });
                cout << "Items sorted by Quantity.\n";
                displayItems(items);
                break;
            case 6: {
                int code;
                cout << "Enter Item Code to search: ";
                cin >> code;
                auto it = find_if(items.begin(), items.end(),
                                  [code](const Item& a) {
                                      return a.itemCode == code;
                                  });
                if (it != items.end()) {
                    cout << "Item Found:\n";
                    cout << "Code\tName\tCost\tQuantity\n";
                    it->display();
                } else {
                    cout << "Item not found!\n";
                }
                break;
            }
            case 7: {
                string searchName;
                cout << "Enter Item Name to search: ";
                cin.ignore();
                getline(cin, searchName);
                auto it = find_if(items.begin(), items.end(),
                                  [&searchName](const Item& a) {
                                      return a.name == searchName;
                                  });
                if (it != items.end()) {
                    cout << "Item Found:\n";
                    cout << "Code\tName\tCost\tQuantity\n";
                    it->display();
                } else {
                    cout << "Item not found!\n";
                }
                break;
            }
            case 8:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);

    return 0;
}

/*OUTPUT 
--- Item Record Management ---
1. Add Item
2. Display Items
3. Sort by Item Code
4. Sort by Cost
5. Sort by Quantity
6. Search by Item Code
7. Search by Item Name
8. Exit
Enter your choice: 1
Enter Item Code: 101
Enter Item Name: Pen
Enter Cost: 10
Enter Quantity: 20
Item added successfully!

--- Item Record Management ---
1. Add Item
2. Display Items
3. Sort by Item Code
4. Sort by Cost
5. Sort by Quantity
6. Search by Item Code
7. Search by Item Name
8. Exit
Enter your choice: 1
Enter Item Code: 102
Enter Item Name: Book
Enter Cost: 50
Enter Quantity: 10
Item added successfully!

--- Item Record Management ---
1. Add Item
2. Display Items
3. Sort by Item Code
4. Sort by Cost
5. Sort by Quantity
6. Search by Item Code
7. Search by Item Name
8. Exit
Enter your choice: 1
Enter Item Code: 103
Enter Item Name: Pencil
Enter Cost: 5
Enter Quantity: 30
Item added successfully!

--- Item Record Management ---
1. Add Item
2. Display Items
3. Sort by Item Code
4. Sort by Cost
5. Sort by Quantity
6. Search by Item Code
7. Search by Item Name
8. Exit
Enter your choice: 2

Code	Name	Cost	Quantity
101	Pen	10	20
102	Book	50	10
103	Pencil	5	30

--- Item Record Management ---
1. Add Item
2. Display Items
3. Sort by Item Code
4. Sort by Cost
5. Sort by Quantity
6. Search by Item Code
7. Search by Item Name
8. Exit
Enter your choice: 4
Items sorted by Cost.

Code	Name	Cost	Quantity
103	Pencil	5	30
101	Pen	10	20
102	Book	50	10

--- Item Record Management ---
1. Add Item
2. Display Items
3. Sort by Item Code
4. Sort by Cost
5. Sort by Quantity
6. Search by Item Code
7. Search by Item Name
8. Exit
Enter your choice: 6
Enter Item Code to search: 102
Item Found:
Code	Name	Cost	Quantity
102	Book	50	10

--- Item Record Management ---
1. Add Item
2. Display Items
3. Sort by Item Code
4. Sort by Cost
5. Sort by Quantity
6. Search by Item Code
7. Search by Item Name
8. Exit
Enter your choice: 8
Exiting program...
*/
