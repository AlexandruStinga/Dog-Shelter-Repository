//
// Created by Alex on 3/24/2021.
//

#ifndef A45_DOMAIN_DOMAIN_H_
#define A45_DOMAIN_DOMAIN_H_

#include <iostream>
using namespace std;

class Dogs
{
 public:
	int id{};
	std::string breed;
	std::string name;
	int age{};
	std::string photograph{};

 public:
	Dogs(int id, std::string breed, std::string name, std::string photograph, int age);
	Dogs();
	std::string get_name();
	std::string get_breed();
	std::string get_photograph();
	int get_age() const;
	int get_id() const;

	void set_name(std::string n);
	void set_breed(std::string b);
	void set_photograph(std::string p);
	void set_age(int a);


	friend std::istream &operator>>(std::istream &is, Dogs &s);

	friend std::ostream &operator<<(std::ostream &os, const Dogs &s);
};

#endif //A45_DOMAIN_DOMAIN_H_
