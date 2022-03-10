//
// Created by Alex on 3/19/2021.
//

#include "ui.h"
#include "../domain/validator.h"
//#include <windows.h>
//#include <shellapi.h>
using namespace std;
ui::ui(Service& serv, user_service& user_serv) : s(serv), us(user_serv)
{
	this->s = serv;
	this->us = user_serv;
}
void ui::mainUI()
{
	while (true)
	{
		cout << endl;
		cout << "1.Administrator mode" << endl;
		cout << "2.User mode" << endl;
		cout << "0.Exit" << endl;
		int option;
		cout << "Option: ";
		cin >> option;
		if (option == 1)
		{
			adminUI();
		}
		else if (option == 2)
		{
			userUI();
		}
		else break;
	}
}
void ui::printDogs()
{
	cout << endl;
	printf("%-25s%-20s%-35s%-10s%-20s\n", "ID", "Name", "Breed", "Age", "Photograph");
	for(auto & i : this->s.r.storage)
	{
		printf("%-25d%-20s%-35s%-10d%-20s\n",
				i.get_id(),
				i.get_name().c_str(),
				i.get_breed().c_str(),
				i.get_age(), i.get_photograph().c_str());
	}
}

void ui::removeUI()
{
	int id;
	cout << "\n" << "ID: ";
	cin >> id;
	if (!cin.good())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "ID should be a number\n";
	}
	else
	{
		try
		{
			this->s.removeElementService(id);
		}
		catch (const std::exception& e)
		{
			cout << "ID doesn't exist\n";
		}
	}
}

void ui::addUI()
{
	//cout << endl;
	std::string breed;
	std::string name;
	std::string photograph;
	int age;
	int id;
	cin.get();

	cout << "ID: ";
	cin >> id;
	if (!cin.good())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "ID should be a number\n";
	}
	else
	{
		cin.get();

		cout << "Breed: ";
		cin>>breed;
		cin.get();

		cout << "Name: ";
		cin>>name;
		cin.get();

		cout << "Photograph: ";
		cin>>photograph;
		cin.get();

		cout << "Age: ";
		cin >> age;
		if (!cin.good() || age < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Age should be a number\n";
		}
		else
		{
			try
			{
				this->s.addElementService(id, breed, name, photograph, age);
			}
			catch (const std::exception& e)
			{
				cout << "ID already exists\n";
			}
			catch(const ValidationException& e)
			{
				cout<<e.getMessage();
			}
			cout << endl;
		}
	}
}

void ui::updateUI()
{
	std::string breed;
	std::string name;
	std::string photograph;
	std::string age;
	int id;
	cout << "Leave blank if you don't want to change it\n";
	cin.get();

	cout << "ID: ";
	cin >> id;

	if (!cin.good())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "ID should be a number\n";
	}
	else
	{
		cin.get();

		cout << "New breed: ";
		std::getline(std::cin, breed);

		cout << "New name: ";
		std::getline(std::cin, name);

		cout << "New photograph: ";
		std::getline(std::cin, photograph);


		cout << "New age: ";
		std::getline(std::cin, age);

		try
		{
			if (age.empty() || stoi(age, nullptr, 10) != 0)
				this->s.updateElement(id, breed, name, photograph, age);
			else cout << "Invalid age\n";
		}
		catch(exception& e)
		{
			cout<<e.what()<<endl;
		}

	}
}

void ui::adminUI()
{
	cout << endl;
	cout << "1.Add a dog" << endl;
	cout << "2.Remove a dog" << endl;
	cout << "3.Update a dog" << endl;
	cout << "4.Print all dogs" << endl;
	cout << "0.Exit" << endl;
	while (true)
	{
		int option;
		cout << "Option: ";
		cin >> option;
		if (option == 1)
		{
			addUI();
		}
		else if (option == 2)
		{
			removeUI();
		}
		else if (option == 3)
		{
			updateUI();
		}
		else if (option == 4)
		{
			printDogs();
			cout << endl;
		}
		else break;
	}
}

void ui::printAdoptions()
{
	cout << endl;
	printf("%-25s%-20s%-35s%-10s%-20s\n", "ID", "Name", "Breed", "Age", "Photograph");
	for(auto & i : this->us.ar.adoptions)
	{
		printf("%-25d%-20s%-35s%-10d%-20s\n",
				i.get_id(),
				i.get_name().c_str(),
				i.get_breed().c_str(),
				i.get_age(), i.get_photograph().c_str());
	}
}

void ui::adoptUI()
{
	int i = 0;
	cout << endl;
	cout << "1.Next dog" << endl;
	cout << "2.Adopt dog" << endl;
	cout << "3.Go back" << endl;
	cout << endl;
	while (i < this->s.r.storage.size())
	{
		cout << "ID: " << this->s.r.storage[i].get_id() << endl;
		cout << "Name: " << this->s.r.storage[i].get_name() << endl;
		cout << "Breed: " << this->s.r.storage[i].get_breed() << endl;
		cout << "Age: " << this->s.r.storage[i].get_age() << endl;
		cout << "Photograph: " << this->s.r.storage[i].get_photograph() << endl;
		//ShellExecute(0, 0, this->s.r.storage.elems[i].get_photograph(), 0, 0 , SW_SHOWNORMAL);

		int option;
		cout << "Option: ";
		cin >> option;
		cout << endl;

		if (option == 1)
		{
			i++;
		}
		else if (option == 2)
		{
			this->us.addAdoption(this->s.r.storage[i]);
		}
		else break;

		if (i == this->s.r.storage.size())
			i = 0;
	}
}

void ui::adoptUI_breed_age()
{
	int i = 0;
	string breed;
	int age;
	cout << "Age: ";
	cin >> age;
	cin.get();
	cout << "Breed: ";
	std::getline(std::cin, breed);

	vector<Dogs> filtered = this->us.BreedAgeAdoption(age,breed);

	if(filtered.empty())
	{
		cout<<"No dogs with specified breed/age\n";
		return;
	}

	cout << endl;
	cout << "1.Next dog" << endl;
	cout << "2.Adopt dog" << endl;
	cout << "3.Go back" << endl;
	cout << endl;

	while (i < filtered.size())
	{
		cout << "ID: " << filtered[i].get_id() << endl;
		cout << "Name: " << filtered[i].get_name() << endl;
		cout << "Breed: " << filtered[i].get_breed() << endl;
		cout << "Age: " << filtered[i].get_age() << endl;
		//cout << "Photograph: " << filtered[i].get_photograph() << endl;
		//ShellExecute(0, 0, filtered[i].get_photograph(), 0, 0 , SW_SHOW );

		int option;
		cout << "Option: ";
		cin >> option;
		cout << endl;

		if (option == 1)
		{
			i++;
		}
		else if (option == 2)
		{
			this->us.addAdoption(filtered[i]);
			filtered.erase(filtered.begin() + i);
		}
		else break;

		if (i == filtered.size())
			i = 0;

		if(filtered.empty())
		{
			cout<<"There are no more dogs with specified breed/age."<<endl;
			break;
		}
	}

	cout << endl;
}

void ui::openFile()
{
	this->us.ar.open_file();
	cout<<endl;
}

void ui::userUI()
{
	cout << endl;
	cout << "1.Adopt a dog" << endl;
	cout << "2.See dogs of a given breed, having an age less than a give number" << endl;
	cout << "3.See adoption list" << endl;
	cout << "4.Open CSV/HTML file" << endl;
	cout << "0.Go back" << endl;
	while (true)
	{
		int option;
		cout << "Option: ";
		cin >> option;

		if (option == 1)
		{
			adoptUI();
		}
		else if (option == 2)
		{
			adoptUI_breed_age();
		}
		else if (option == 3)
		{
			printAdoptions();
		}
		else if (option == 4)
		{
			openFile();
		}
		else break;
	}
}

ui& ui::operator=(const ui& rhs)
{
	this->s = rhs.s;
	return *this;
}
ui::~ui()
= default;