//
// Created by Alex on 4/18/2021.
//

#include "HTMLAdoptionRepo.h"
#include <fstream>
#include <windows.h>
HTMLAdoptionRepo::HTMLAdoptionRepo(const string& fn) : fileAdoptionRepo(fn)
{
	this->filename = fn;
}
void HTMLAdoptionRepo::addAdoption(Dogs d)
{
	fileAdoptionRepo::addAdoption(d);
	write_to_file();
}
void HTMLAdoptionRepo::removeAdoption()
{
	fileAdoptionRepo::removeAdoption();
	write_to_file();
}
void HTMLAdoptionRepo::write_to_file()
{
	fileAdoptionRepo::write_to_file();
	ofstream html;
	html.open("../adoptions.html");
	html<<"<!DOCTYPE html>"<<endl;
	html<<"<html>"<<endl;
	html<<"<head>"<<endl;
	html<<"		<title>Adoptions</title>"<<endl;
	html<<"</head>"<<endl;
	html<<"<body>"<<endl;
	html<<"<table border=\"1\">"<<endl;
	html<<"\t<tr>"<<endl;
	html<<"\t\t<td>ID</td>"<<endl;
	html<<"\t\t<td>Name</td>"<<endl;
	html<<"\t\t<td>Breed</td>"<<endl;
	html<<"\t\t<td>Age</td>"<<endl;
	html<<"\t\t<td>Photograph</td>"<<endl;
	html<<"\t</tr>"<<endl;
	html<<"\t<tr>"<<endl;
	for(auto & i : this->adoptions)
	{
		html<<"\t<tr>"<<endl;
		html<<"\t<td>"<<i.get_id()<<"</td>"<<endl;
		html<<"\t<td>"<<i.get_name()<<"</td>"<<endl;
		html<<"\t<td>"<<i.get_breed()<<"</td>"<<endl;
		html<<"\t<td>"<<i.get_age()<<"</td>"<<endl;
		html<<"\t<td><a href=\""<<i.get_photograph()<<"\">Photograph</a></td>"<<endl;
		html<<"\t</tr>"<<endl;
	}
	html<<"</table>"<<endl;
	html<<"</body>"<<endl;
	html<<"</html>";

}
void HTMLAdoptionRepo::open_file()
{
	write_to_file();
	LPCSTR file="C:/Users/Alex/Documents/GitHub/OOP/a89-Alexandru-Stinga/adoptions.html";
	ShellExecuteA(nullptr,"open",file,nullptr,nullptr,SW_SHOWNORMAL);
}
