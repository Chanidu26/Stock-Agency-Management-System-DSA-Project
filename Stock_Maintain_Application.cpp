#include <cstddef>
#include <iostream>
#include "Header.h"

using namespace std;
void printMenu() {
	cout << "\t\t\t\tMenu Table\t\t\t\t\n" << endl;
	cout << "1 - Insert Customer	2 - Print Customer	3 - Delete Customer 	 4 - Edit Customer" << endl;
	cout << "--------------------  ---------------------    --------------------   -------------------------" << endl;
	cout << "5 - Insert Supplier	6 - Print Supplier	7 - Delete Supplier 	 8 - Edit Supplier" << endl;
	cout << "--------------------  ---------------------    --------------------   -------------------------" << endl;
	cout << "9 - Insert Item         10 - Print Item         11 - Delete Item        12 - Edit Item" << endl;
	cout << "--------------------  ---------------------    ------------------------------------------------" << endl;
	cout << "13 - Receiving         14 - sale                15 - Clear the screen" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
}
void receiving(Items_List& i1) {
	int barcode;
	int quantity;
	int totPrice;
	cout << "Barcode : ";
	cin >> barcode;
	cout << "Quantity : ";
	cin >> quantity;
	cout << "Total price of item : ";
	cin >> totPrice;
	cout << endl;
	i1.searchItem(barcode, quantity, totPrice);
}
void sale(Transactions_List& t1, Items_List& i1) {

}
void selectMenu(Transactions_List& t1, Transactions_List& t2, Items_List& i1) {
	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
		t1.insertCustomer(); break;
	case 2:
		t1.printCustomer(); break;
	case 3:
		int a;
		cout << "Which customer do you want to delete" << endl;
		cin >> a;
		t1.deleteCustomer(a-1); break;
	case 4:
		int b;
		cout << "Which customer do you want to edit" << endl;
		cin >> b;
		t1.editCustomer(b-1); break;
	case 5:
		t2.insertCustomer(); break;
	case 6:
		t2.printCustomer(); break;
	case 7:
		int c;
		cout << "Which supplier do you want to delete" << endl;
		cin >> c;
		t2.deleteCustomer(c-1); break;
	case 8:
		int d;
		cout << "Which supplier do you want to edit" << endl;
		cin >> d;
		t2.editCustomer(d-1); break;
	case 9:
		i1.insertItem(); break;
	case 10:
		i1.printItem_list(); break;
	case 11:
		int e;
		cout << "Which item do you want to delete" << endl;
		cin >> e;
		i1.deleteItem(e-1); break;
	case 12:
		int f;
		cout << "Which item do you want to edit" << endl;
		cin >> f;
		i1.editItem(f-1); break;
	case 13:
		receiving(i1); break;
	case 14:
		sale(t1, i1); break;
	case 15:
		system("cls"); 
		printMenu(); break;
	default:
		cout << "\nInvalid choice. Try again!\n";
		
	}

	cout << "Choose another option from above list" << endl;
	selectMenu(t1, t2, i1);
}

int main() {
	Transactions_List t1;	// This is for the customer object
	Transactions_List t2;	// This is for the supplier object
	Items_List i1;


	printMenu();
	cout << "Give the number from Menu table" << endl;
	selectMenu(t1, t2, i1);
	
}
