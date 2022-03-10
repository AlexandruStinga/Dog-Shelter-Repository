//
// Created by Alex on 4/19/2021.
//

#include "CSVAdoptionRepo.h"
#include <fstream>
#include <windows.h>
CSVAdoptionRepo::CSVAdoptionRepo(const string& fn) : fileAdoptionRepo(fn)
{
	this->filename=fn;
}
void CSVAdoptionRepo::addAdoption(Dogs d)
{
	fileAdoptionRepo::addAdoption(d);
	write_to_file();
}
void CSVAdoptionRepo::removeAdoption()
{
	fileAdoptionRepo::removeAdoption();
	write_to_file();
}
void CSVAdoptionRepo::open_file()
{
	write_to_file();
	LPCSTR file="C:/Users/Alex/Documents/GitHub/OOP/a89-Alexandru-Stinga/adoptions.csv";
	ShellExecuteA(nullptr,"open",file,nullptr,nullptr,SW_SHOWNORMAL);
}
void CSVAdoptionRepo::write_to_file()
{
	fileAdoptionRepo::write_to_file();
	ofstream fout("../adoptions.csv");
	for(auto &i : this->adoptions)
	{
		fout<<i;
	}
}