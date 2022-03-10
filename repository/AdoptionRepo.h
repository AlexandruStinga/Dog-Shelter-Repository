//
// Created by Alex on 4/7/2021.
//

#ifndef A45_ALEXANDRU_STINGA_REPOSITORY_ADOPTIONREPO_H_
#define A45_ALEXANDRU_STINGA_REPOSITORY_ADOPTIONREPO_H_
#include "domain.h"
#include <vector>
#include "repo.h"
class AdoptionRepo
{
 public:
	vector<Dogs> adoptions;

	 /*
	 * Adds a dog to the adoption list
	 * input:
	 * 		- d: element of type dog
	 */
	 virtual void addAdoption(Dogs d);

	 virtual ~AdoptionRepo();

	 AdoptionRepo& operator=(const AdoptionRepo& rhs);

	 virtual void open_file() = 0;

};

#endif //A45_ALEXANDRU_STINGA_REPOSITORY_ADOPTIONREPO_H_
