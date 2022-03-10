//
// Created by Alex on 3/19/2021.
//

#ifndef A45_ALEXANDRU_STINGA_REPOSITORY_REPO_H_
#define A45_ALEXANDRU_STINGA_REPOSITORY_REPO_H_

#include "domain.h"
#include <vector>
using namespace std;
class Repository
{
 public:
	vector<Dogs> storage;
	/*
	 * Default constructor
	 */
	Repository();

	/*
	 * Default destructor
	 */
	virtual ~Repository();

	 /*
	 * Given an element of type "Dogs", it adds it to the repo
	 * input:
	 * 		- d: element of type dog
	 */
	 virtual void addElementRepo(Dogs d);

	/*
	 * Assignment operator overridden
	 */
	Repository& operator=(const Repository& rhs);

	 /*
	 * Adds 10 elements to the repo
	 */
	 virtual void addTenElems();

	 /*
	 * Given the position, the function removes the element from that position from the repo
	 * input:
	 * 		- pos: position of the element to be removed
	 */
	 virtual void removeElem(int pos);

	 /*
	 * Given the ID of an element of type dog, the function returns its position in the dynamic vector
	 * input:
	 * 		- id: the id of a dog
	 * 	output:
	 * 		- returns the position of the dog
	 */
	 virtual int positionDog(int id);

	 /*
	 * Updates the element on the given position
	 * input:
	 * 		- pos: position of the element
	 * 		- breed: the new breed
	 * 		- name: the naw name
	 * 		- photograph: the new photograph
	 * 		- age: the new age
	 */
	 virtual void updateElem(int pos, std::string breed, std::string name, std::string photograph, std::string age);

	/*
	 * Adds a dog to the adoption list
	 * input:
	 * 		- d: element of type dog
	 */
//	void addAdoption(Dogs d);
};

#endif //A45_ALEXANDRU_STINGA_REPOSITORY_REPO_H_
