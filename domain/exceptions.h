//
// Created by Alex on 4/13/2021.
//

#ifndef A45_ALEXANDRU_STINGA_DOMAIN_EXCEPTIONS_H_
#define A45_ALEXANDRU_STINGA_DOMAIN_EXCEPTIONS_H_
#include <exception>
#include <iostream>
#include <utility>
using namespace std;
class InvalidPos : public std::exception
{
 private:
	string message;

 public:
	explicit InvalidPos(string  s) : message{std::move( s )} {}

	const char* what() const throw() override {
		return this->message.c_str();
	}
};

#endif //A45_ALEXANDRU_STINGA_DOMAIN_EXCEPTIONS_H_
