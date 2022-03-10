//
// Created by Alex on 4/7/2021.
//

#include "AdoptionRepo.h"
void AdoptionRepo::addAdoption(Dogs d)
{
	this->adoptions.push_back(d);
}
AdoptionRepo& AdoptionRepo::operator=(const AdoptionRepo& rhs)
{
	this->adoptions = rhs.adoptions;
	return *this;
}
AdoptionRepo::~AdoptionRepo()
= default;
