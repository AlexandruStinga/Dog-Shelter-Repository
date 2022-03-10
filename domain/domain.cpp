//
// Created by Alex on 3/24/2021.
//

#include "domain.h"
#include <vector>
#include <utility>
#include <sstream>
Dogs::Dogs(int id, std::string breed, std::string name, std::string photograph, int age)
{
	this->id = id;
	this->name = std::move(name);
	this->breed = std::move(breed);
	this->photograph = std::move(photograph);
	this->age = age;
}
void Dogs::set_name(std::string n)
{
	this->name = std::move(n);
}
void Dogs::set_breed(std::string b)
{
	this->breed = std::move(b);
}
void Dogs::set_photograph(std::string p)
{
	this->photograph = std::move(p);
}

void Dogs::set_age(int a)
{
	this->age = a;
}

std::string Dogs::get_name()
{
	return this->name;
}
std::string Dogs::get_breed()
{
	return this->breed;
}
std::string Dogs::get_photograph()
{
	return this->photograph;
}
int Dogs::get_age() const
{
	return this->age;
}
int Dogs::get_id() const
{
	return this->id;
}

vector<string> tokenize(const string& str, char delimiter) {
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

std::istream &operator>>(std::istream &is, Dogs &d) {
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5)
		return is;
	d.id = stoi(tokens[0]);
	d.breed = tokens[1];
	d.name = tokens[2];
	d.age = stoi(tokens[3]);
	d.photograph = tokens[4];

	return is;
}

std::ostream &operator<<(std::ostream &os, const Dogs &d) {
	os << d.id << "," << d.breed << "," << d.name << "," << d.age << "," << d.photograph<< '\n';
	return os;
}

Dogs::Dogs()
= default;
