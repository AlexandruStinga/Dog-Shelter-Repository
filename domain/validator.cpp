//
// Created by Alex on 4/13/2021.
//

#include "validator.h"

#include <utility>
ValidationException::ValidationException(std::string _message) : message{std::move(_message)} {
}

std::string ValidationException::getMessage() const {
	return this->message;
}

void validator::validate(const Dogs &d) {
	string errors;
	if (d.get_id() <= 0)
		errors += string("ID should be a positive integer!\n");
	if (d.get_age() <= 0)
		errors += string("Age should be a positive integer!\n");

	if (!errors.empty())
		throw ValidationException(errors);
}