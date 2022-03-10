//
// Created by Alex on 4/7/2021.
//
#include <iostream>
#include <fstream>
#include "fileAdoptionRepo.h"
#include <windows.h>
fileAdoptionRepo::fileAdoptionRepo(const string& fn)
{
	this->filename = fn;
	read_from_file();
}

void fileAdoptionRepo::addAdoption(Dogs d)
{
	AdoptionRepo::addAdoption(d);
	write_to_file();
}
void fileAdoptionRepo::removeAdoption()
{
	this->adoptions.pop_back();
	write_to_file();
}

void fileAdoptionRepo::write_to_file()
{
	ofstream fout(this->filename);
	for(auto &i : this->adoptions)
	{
		fout<<i;
	}
}
void fileAdoptionRepo::read_from_file()
{
	ifstream f(this->filename);

	Dogs s;
	while (f >> s)
	{
		this->adoptions.push_back(s);
	}

	f.close();
}
void fileAdoptionRepo::open_file()
{};