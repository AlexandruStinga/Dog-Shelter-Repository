//
// Created by Alex on 4/7/2021.
//

#include "filerepo.h"
#include <fstream>
fileRepo::fileRepo(const string& filename)
{
	this->filename=filename;
	read_from_file();
}
void fileRepo::addElementRepo(Dogs d)
{
	Repository::addElementRepo(d);
	write_to_file();
}
void fileRepo::removeElem(int pos)
{
	Repository::removeElem(pos);
	write_to_file();
}
int fileRepo::positionDog(int id)
{
	return Repository::positionDog(id);
}
void fileRepo::updateElem(int pos, std::string breed, std::string name, std::string photograph, std::string age)
{
	Repository::updateElem(pos, breed, name, photograph, age);
	write_to_file();
}

void fileRepo::read_from_file()
{
	ifstream f(this->filename);

	Dogs s{};
	while (f >> s)
	{
		this->storage.push_back(s);
	}

	f.close();
}

void fileRepo::write_to_file()
{
	ofstream fout(this->filename);
	for(auto &i : this->storage)
	{
		fout<<i;
	}
}
