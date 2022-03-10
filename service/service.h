//
// Created by Alex on 3/19/2021.
//

#ifndef A45_ALEXANDRU_STINGA_SERVICE_SERVICE_H_
#define A45_ALEXANDRU_STINGA_SERVICE_SERVICE_H_
#include "../repository/repo.h"
#include "../repository/filerepo.h"
class Service
{
 public:
	Repository& r;

	/*
	 * Constructor
	 */
	explicit Service(Repository& r);

	/*
	 * Default constructor
	 */
	Service();

	/*
	 * Default destructor
	 */
	~Service();

	/*
	 * Adds a new element in the repo
	 * input:
	 * 		- id: the id of the dog
	 * 		- breed: the breed of the dog
	 * 		- name: the name of the dog
	 * 		- photograph: the photo of the dog
	 * 		- age: the age of the dog
	 */
	void addElementService(int id, std::string breed, std::string name, std::string photograph, int age);

	/*
	 * Assignment operator overridden
	 */
	Service& operator=( const Service& rhs );

	/*
	 * Removes an element from the repo
	 * input:
	 * 		- id: the id of the element to remove
	 */
	void removeElementService(int id);

	/*
	 * Updates an element from the repo
	 * input:
	 * 		- id: id of the element
	 * 		- breed: the new breed
	 * 		- name: the naw name
	 * 		- photograph: the new photograph
	 * 		- age: the new age
	 */
	void updateElement(int id, std::string breed, std::string name, std::string photograph, std::string age);
};

#endif //A45_ALEXANDRU_STINGA_SERVICE_SERVICE_H_
