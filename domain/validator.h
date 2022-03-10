//
// Created by Alex on 4/13/2021.
//

#ifndef A45_ALEXANDRU_STINGA_DOMAIN_VALIDATOR_H_
#define A45_ALEXANDRU_STINGA_DOMAIN_VALIDATOR_H_
#include <iostream>
#include "domain.h"
class ValidationException {
 private:
	std::string message;

 public:
	explicit ValidationException(std::string _message);

	std::string getMessage() const;
};
class validator
{
 public:
	static void validate(const Dogs &d);
};

#endif //A45_ALEXANDRU_STINGA_DOMAIN_VALIDATOR_H_
