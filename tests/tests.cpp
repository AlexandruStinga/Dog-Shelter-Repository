//
// Created by Alex on 3/20/2021.
//
#include <iostream>
#include <cstring>
#include "../domain/domain.h"
#include "../repository/repo.h"
#include "../service/service.h"
#include "../service/user_service.h"
#include "../repository/AdoptionRepo.h"
#include "../repository/HTMLAdoptionRepo.h"
#include "../repository/CSVAdoptionRepo.h"
#include "../domain/validator.h"
#include <cassert>
#include <fstream>
#include <sstream>
using namespace std;
void tests_domain()
{
	Dogs d(1,"asd","asd","asd",10);
	assert(d.get_breed() == "asd");
	assert(d.get_photograph() == "asd");
	assert(d.get_age() == 10);
	assert(d.get_name() == "asd");

	d.set_age(5);
	d.set_photograph("a");
	d.set_breed("a");
	d.set_name("a");

	assert(d.get_breed() == "a");
	assert(d.get_photograph() == "a");
	assert(d.get_age() == 5);
	assert(d.get_name() == "a");

	Dogs d2;
	stringstream out;
	out<<d;
	if(out.str() == "1,a,a,5,a")
		assert(true);
}

void tests_repo()
{
	Repository r;
	string name, breed, photo;


	///Test add;
	name="Affen";
	breed="Affenpinscher";
	photo="https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/30174107/Affenpinscher-copy.jpg";
	Dogs d1(1, breed, name, photo, 1);

	r.addElementRepo(d1);
	assert(r.storage[0].get_id() == 1);

	///Test position
	int pos = r.positionDog(1);
	assert(pos == 0);

	int pos_ = r.positionDog(5);
	assert(pos_ == -1);


	///Test remove
	r.removeElem(pos);
	assert(r.storage.size() == 0);

	///Test update
	r.addElementRepo(d1);

	name="a";
	breed="b";
	photo="c";
	string age;
	age="99";

	r.updateElem(pos,breed,name,photo,age);
	assert(r.storage[0].get_age() == 99);
}

void tests_service()
{
	Repository r;
	r.addTenElems();
	Service s(r);

	string name, breed, photo;

	name="Affen";
	breed="Affenpinscher";
	photo="https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/30174107/Affenpinscher-copy.jpg";
	Dogs d1(1, breed, name, photo, 1);

	///Test add

	try
	{
		s.addElementService(1,breed,name,photo,99);
	}
	catch(exception& e)
	{
		stringstream out;
		out<<e.what();
	};

	s.addElementService(99,breed,name,photo,99);
	assert(s.r.storage[s.r.storage.size() - 1].get_id() == 99);

	///Test remove

	try
	{
		s.removeElementService(100);
	}
	catch(exception& e){};
	assert(s.r.storage.size() == 11);
	s.removeElementService(99);
	assert(s.r.storage.size() == 10);

	///Test update
	s.addElementService(99,breed,name,photo,99);
	string age;
	age="99";
	try
	{
		s.updateElement(100,breed,name,photo,age);
	}
	catch(exception& e){};

	name="a";
	breed="b";
	photo="c";
	age="48";
	s.updateElement(99,breed,name,photo,age);
	assert(s.r.storage[s.r.storage.size() - 1].get_age() == 48);

}

void tests_user_service()
{
	Repository r;
	fileAdoptionRepo ar("../tests/test_adoption.txt");
	r.addTenElems();
	user_service us(r,ar);

	string name, breed, photo;

	name="Affen";
	breed="Affenpinscher";
	photo="https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/30174107/Affenpinscher-copy.jpg";
	Dogs d1(1, breed, name, photo, 1);

	us.addAdoption(d1);
	assert(us.ar.adoptions.size() == 1);

	breed="Husky";
	vector<Dogs> dv= us.BreedAgeAdoption(10,breed);
	assert(dv.size() == 1);

	breed="";
	vector<Dogs> dv2 = us.BreedAgeAdoption(100,breed);
	assert(dv2.size() == 9);
	ar.removeAdoption();

}

void test_validator()
{
	Dogs d(-3,"a","a","a",-5);
	try
	{
		validator::validate(d);
	}
	catch(ValidationException& e)
	{
		stringstream out;
		out<<e.getMessage();
	}
}

void test_file_repo()
{
	fileRepo r("../tests/test.txt");
	Dogs d(99,"a","a","a",10);
	r.addElementRepo(d);

	assert(r.storage.size() == 1);
	int pos=r.positionDog(99);
	r.updateElem(pos,"asd","asd","asd","5");
	assert(r.storage[pos].get_id() == 99);

	r.removeElem(pos);
	assert(r.storage.size() == 0);
}

void test_file_adoption_repo()
{
	fileAdoptionRepo r("../tests/test_adoption.txt");
	Dogs d(99,"a","a","a",10);
	r.addAdoption(d);
	assert(r.adoptions.size() == 1);
	r.removeAdoption();
	r.open_file();
}

void test_html_repo()
{
	HTMLAdoptionRepo r("../tests/test_adoption.txt");
	int size = r.adoptions.size();
	Dogs d(99,"a","a","a",10);
	r.addAdoption(d);
	assert(r.adoptions.size() == size + 1);
	r.removeAdoption();
	assert(r.adoptions.size() == size);
}

void test_csv_repo()
{
	CSVAdoptionRepo r("../tests/test_adoption.txt");
	int size = r.adoptions.size();
	Dogs d(99,"a","a","a",10);
	r.addAdoption(d);
	assert(r.adoptions.size() == size + 1);
	r.removeAdoption();
	assert(r.adoptions.size() == size);
}

void all_tests()
{
	tests_domain();
	tests_repo();
	//test_adoption_repo();
	tests_service();
	tests_user_service();
	test_validator();
	test_file_repo();
	test_file_adoption_repo();
	test_html_repo();
	test_csv_repo();
}