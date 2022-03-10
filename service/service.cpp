//
// Created by Alex on 3/19/2021.
//

#include "service.h"
#include "../domain/exceptions.h"
#include <utility>
Service::Service(Repository& repo): r(repo)
{
	this->r = repo;
}

void Service::addElementService(int id, std::string breed, std::string name, std::string photograph, int age)
{
	if (this->r.positionDog(id) != -1)
	{
		throw InvalidPos("ID already exists");
	}
	Dogs d(id, breed, name, photograph, age);
	this->r.addElementRepo(d);
}

void Service::removeElementService(int id)
{
	int pos = this->r.positionDog(id);
	if (pos == -1)
	{
		throw InvalidPos("Invalid id");
	}
	else
	{
		this->r.removeElem(pos);
	}
}

void Service::updateElement(int id, std::string breed, std::string name, std::string photograph, std::string age)
{
	int pos = this->r.positionDog(id);
	if (pos == -1)
	{
		throw InvalidPos("Invalid id");
	}
	else
	{
		this->r.updateElem(pos, breed, name, photograph, age);
	}
}

Service& Service::operator=(const Service& rhs)
{
	this->r = rhs.r;
	return *this;
}
Service::~Service()
= default;
