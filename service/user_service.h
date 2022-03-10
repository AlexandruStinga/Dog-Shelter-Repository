//
// Created by Alex on 3/25/2021.
//

#ifndef A45_ALEXANDRU_STINGA_SERVICE_USER_SERVICE_H_
#define A45_ALEXANDRU_STINGA_SERVICE_USER_SERVICE_H_
#include "../repository/fileAdoptionRepo.h"
#include "../repository/filerepo.h"
class user_service
{
 public:
	Repository& r;
	AdoptionRepo& ar;

	explicit user_service(Repository& repo, AdoptionRepo& repo_adoption);
	user_service& operator=( const user_service& rhs );


	/*
	 * Adds an adoption
	 * input:
	 * 		- d: an element of type dog
	 */
	void addAdoption(Dogs d);

	/*
	 * Filters the dogs in the repo based on the age and breed
	 * input:
	 * 		- age
	 * 		- breed
	 * output:
	 * 		- returns a dynamic vector containing all filtered elements
	 */
	vector<Dogs> BreedAgeAdoption(int age, string breed);
};

#endif //A45_ALEXANDRU_STINGA_SERVICE_USER_SERVICE_H_
