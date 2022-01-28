#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int count=0;

struct contact
{
	string name;
	string phone;

	contact read()
	{
		cout<<"enter name:";
		cin>>name;
		cout<<"enter phone:";
		cin>>phone;
		count++;
		return *this;
	}
};

struct PhoneBook {
	contact* contacts = new contact[1];
	int length = 0;
	int size = 1;

	void add(contact c) {
		if (size < length + 1)
			enlarge();
		contacts[length++] = c;
	}

	void sortByName() {
		for (int i = 0; i < count - 1; i++)
			for (int j = 0; j < count - i - 1; j++)
				if (contacts[j].name > contacts[j + 1].name) {
					swap(contacts[j], contacts[j + 1]);
				}
	}

	void sortByPhone() {
		for (int i = 0; i < count - 1; i++)
			for (int j = 0; j < count - i - 1; j++)
				if (contacts[j].phone > contacts[j + 1].phone) {
					swap(contacts[j], contacts[j + 1]);
				}
	}

	void show() {
		cout << setw(20) << "name" << setw(20) << "phone" << "\n";
		string s(40, '-');
		cout << s << "\n";
		for (int i = 0; i < count; i++)
			cout << setw(20) << contacts[i].name << setw(20) << contacts[i].phone << "\n";
	}

	string linearSearch(string n) {
		for (int i = 0; i < count; i++)
			if (contacts[i].name == n)
				return contacts[i].phone;
		return "not found";
	}

	void enlarge() {
		size *= 2;
		contact* c = new contact[size];
		for (int i = 0; i < length; ++i)
			c[i] = contacts[i];
		delete[] contacts;
		contacts = c;
	}
};
int main() {
	PhoneBook phone_book;
	while (true) {
		system("cls");
		int num;
		cout << "1:read 2: show  3:search 4: sort by name 5: sort by phone 6:exit.\n enter a num: ";
		cin >> num;
		lbl_switch:		switch (num) {
		case 1:
			phone_book.add((*new contact()).read());
			break;
		case 2:
			phone_book.show();
			system("pause");
			break;
		case 3: {
			string name;
			cout << "enter name for search:";
			cin >> name;
			cout << "phone " << name << "is " << phone_book.linearSearch(name) << "\n";
			system("pause");
			break;
		}
		case 4:
			phone_book.sortByName();
			break;
		case 5:
			phone_book.sortByPhone();
			break;
		case 6:
			goto lbl_exit;
		default:
			cout << "enter correct option number\n";
			goto lbl_switch;
	}
	}
	lbl_exit:
	system("pause");
}
