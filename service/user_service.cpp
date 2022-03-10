//
// Created by Alex on 3/25/2021.
//

#include <cstring>
#include "user_service.h"
#include <algorithm>
user_service::user_service(Repository& repo, AdoptionRepo& repo_adoption): r(repo), ar(repo_adoption)
{
	this->r = repo;
	this->ar = repo_adoption;
}
user_service& user_service::operator=(const user_service& rhs)
{
	this->r = rhs.r;
	return *this;
}

void user_service::addAdoption(Dogs d)
{
	int pos = this->r.positionDog(d.get_id());
	this->ar.addAdoption(d);
	this->r.removeElem(pos);
	//this->r.storage.erase(this->r.storage.begin() + pos);
}

vector<Dogs> user_service::BreedAgeAdoption(int age, string breed)
{
	vector<Dogs> filtered;
	if(!breed.empty())
	{
		copy_if(this->r.storage.begin(),this->r.storage.end(),back_inserter(filtered),[&age,&breed](auto i){return i.get_age()<age && i.get_breed() == breed;});
	}
	else
	{
		copy_if(this->r.storage.begin(),this->r.storage.end(),back_inserter(filtered),[&age](auto i){return i.get_age()<age;});
	}
	return filtered;
}