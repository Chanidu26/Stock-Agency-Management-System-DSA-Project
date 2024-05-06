#pragma once
#include <iostream>
#include <string>
#include <cstddef>



using namespace std;

class TempCustomer {
public:
	string name;
	int ctNo;
	TempCustomer* next;

	TempCustomer() { // Default  constructor
		name = "";
		ctNo = 0;

	}
	TempCustomer(string name, int ctNo) { // Overloaded constructor
		this->name = name;
		this->ctNo = ctNo;
	}
};

class Transactions_List {
private:
	TempCustomer* head;
	TempCustomer* tail;
	int size;

public:
	Transactions_List() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void insertCustomer() {
			string Name;
			int Ctno;
			cout << "Dealer's name : ";
			cin >> Name;
			cout << "Dealer's contact number : ";
			cin >> Ctno;
			TempCustomer* temp = new TempCustomer(Name, Ctno);
			if (head == NULL) {
				head = temp;
				tail = temp;
				size++;
			}
			else {
				tail->next = temp;
				tail = temp;
				size++;
			}
		
	}

	void printCustomer() {

		TempCustomer* current = head;
		if (head == NULL) {
			cout << "There is no customer to print.\n" << endl;
		}
		else {
			cout << endl;
			cout << "CUSTOM NAME" << "\t" << "CONTACT NUMBER\n" << endl;
			for (int i = 0; i < size; i++) {
				cout << current->name << "\t\t\t" << current->ctNo << endl;
				current = current->next;
			}
			cout << endl;
		}
	}
	void deleteCustomer(int pos) {
		TempCustomer* temp = head;
		if (head == NULL) {
			cout << "No customer to delete.\n" << endl;
		}
		else if (pos < 0 || pos >= size) {
			cout << "Invalid position. There is no customer at this position.\n" << endl;
		}
		else if (pos == 0) {
			head = head->next;
		}
		else {
			TempCustomer* current = head;
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}
			temp = current->next;
			current->next = temp->next;
			delete temp;
			size--;
		}
	}
	void editCustomer(int pos) {
		if (head == NULL) {
			cout << "No customer to edit." << endl;
		}
		else if (pos < 0 || pos >= size) {
			cout << "Invalid position. There is no customer at this position." << endl;
		}
		else {
			TempCustomer* current = head;
			for (int i = 0; i < pos; i++) {
				current = current->next;
			}
			string new_Name;
			cout << "Give the new customer name for " << current->name << " : ";
			cin >> new_Name;
			current->name = new_Name;
			cout << "Give the new custom contact no : ";
			cin >> current->ctNo;
		}
	}
};

class TempItem {
public:
	string name;
	int barcode;
	float costPrice;
	float sellPrice;
	int quantity;
	TempItem* next;

	TempItem() { // Default  constructor
		name = "";
		quantity = 0;
	}
	TempItem(string name, int barcode, float sellPrice ) { // Overloaded constructor
		this->name = name;
		this->barcode = barcode;
		this->sellPrice = sellPrice;
		
	}
};

class Items_List {
private:
	TempItem* head;
	TempItem* tail;
	int size;

public:
	Items_List() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void insertItem() {
		string name;
		int barcode;
		float costPrice;
		float sellPrice;
		
		cout << "Item name : ";
		cin >> name;
		cout << "Item barcode : ";
		cin >> barcode;
		cout << "Item sellPrice : ";
		cin >> sellPrice;
		
		TempItem* temp = new TempItem(name, barcode, sellPrice);
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			tail->next = temp;
			tail = temp;
			size++;
		}
	}
	void printItem_list() {
		TempItem* temp = head;
		if (head == NULL) {
			cout << "No item to print.\n" << endl;
		}
		else {
			cout << "ITEM NAME\t\t BARCODE\t\t QUANTITY\t\t COST PRICE(Rs)\t\t SELL PRICE\n" << endl;
			for (int i = 0; i < size; i++) {
				cout << temp->name << "\t\t\t" << temp->barcode << "\t\t\t" << temp->quantity << "\t\t\t" << temp->costPrice << "\t\t\t" << temp->sellPrice << endl;
				temp = temp->next;
			}
			cout << endl;
		}
	}
	void deleteItem(int pos) {
		TempItem* temp = head;
		if (head == NULL) {
			cout << "No item to delete.\n" << endl;
		}
		else if (pos < 0 || pos >= size) {
			cout << "Invalid position. There is no item at this position.\n" << endl;
		}
		else if (pos == 0) {
			head = head->next;
		}
		else {
			TempItem* current = head;
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}
			temp = current->next;
			current->next = temp->next;
			delete temp;
			size--;
		}
	}
	void editItem(int pos) {
		if (head == NULL) {
			cout << "No items to edit." << endl;
		}
		else if (pos < 0 || pos >= size) {
			cout << "Invalid position. There is no item at this position." << endl;
		}
		else {
			TempItem* current = head;
			for (int i = 0; i < pos; i++) {
				current = current->next;
			}
			string new_Name;
			cout << "Give the new item name for " << current->name << " : ";
			cin >> new_Name;
			current->name = new_Name;
			cout << "Give the new item BARCODE: ";
			cin >> current->quantity;
			cout << "Give the new item cost price: ";
			cin >> current->costPrice;
		}
	}
	void searchItem(int code, int quant, int totalPrice) { //Search the item from the barcode
		TempItem* current = head;
		for (int i = 0; i < size; i++) {
			if (current->barcode == code) {
				current->quantity = +quant;
				current->costPrice = ((current->costPrice * current->quantity) + totalPrice) / (current->quantity + quant);
				break;
			}
			else {
				current = current->next;
			}				
		}
	}
};