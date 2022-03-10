//
// Created by Alex on 3/19/2021.
//

#include "repo.h"
#include "../domain/validator.h"
#include "../domain/exceptions.h"
#include <cstring>
#include <utility>
Repository::Repository()
= default;
void Repository::addElementRepo(Dogs d)
{
	validator::validate(d);
	this->storage.push_back(d);
}

void Repository::addTenElems()
{
	Dogs d1(1, "Affenpinscher", "Affen", "https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/30174107/Affenpinscher-copy.jpg", 1);
	Dogs d2(2, "Husky", "Lara", "https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/26155623/Siberian-Husky-standing-outdoors-in-the-winter.jpg", 3);
	Dogs d3(3,"Staffordshire Terrier","Lucky","https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/07172037/AmStaff.06.jpg",2);
	Dogs d4(4,"Rottweiler","Scout","https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/12224942/Rottweiler-On-White-10.jpg",1);
	Dogs d5(5,"Kuvasz","Rex","https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/05132204/Kuvasz-standing-outdoors.jpg",3);
	Dogs d6(6,"Otterhound","Peanut","https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/12230108/Otterhound-On-White-03.jpg",2);
	Dogs d7(7,"Estrela Mountain Dog","Roscoe","https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/13173254/Beau.jpg",5);
	Dogs d8(8,"Saluki","Kobe","https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/14185322/AKC-121716-139.jpg",1);
	Dogs d9(9,"Samoyed","Max","https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/20122208/Samoyed-standing-in-the-forest.jpg",7);
	Dogs d10(10,"Lapponian Herder","Chase","https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/12231210/Lapponian-Herder-On-White-01.jpg",3);

	this->storage.push_back(d1);
	this->storage.push_back(d2);
	this->storage.push_back(d3);
	this->storage.push_back(d4);
	this->storage.push_back(d5);
	this->storage.push_back(d6);
	this->storage.push_back(d7);
	this->storage.push_back(d8);
	this->storage.push_back(d9);
	this->storage.push_back(d10);

}

int Repository::positionDog(int id)
{
	for (int i = 0; i < this->storage.size(); i++)
	{
		if (this->storage[i].get_id() == id)
			return i;
	}
	return -1;
}

void Repository::removeElem(int pos)
{
	this->storage.erase(this->storage.begin()+pos);
}

void Repository::updateElem(int pos, std::string breed, std::string name, std::string photograph, std::string age)
{
	if(!breed.empty())
		this->storage[pos].set_breed(breed);

	if(!name.empty())
		this->storage[pos].set_name(name);

	if(!photograph.empty())
		this->storage[pos].set_photograph(photograph);

	if(!age.empty())
	{
		int a = stoi(age);
		this->storage[pos].set_age(a);
	}

}

Repository& Repository::operator=(const Repository& rhs)
{
	this->storage = rhs.storage;
	return *this;
}
Repository::~Repository()
= default;
