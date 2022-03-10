//
// Created by Alex on 4/7/2021.
//

#ifndef A45_ALEXANDRU_STINGA_REPOSITORY_FILEADOPTIONREPO_H_
#define A45_ALEXANDRU_STINGA_REPOSITORY_FILEADOPTIONREPO_H_
#include "AdoptionRepo.h"
class fileAdoptionRepo : public AdoptionRepo
{
 public:
	string filename;
	explicit fileAdoptionRepo(const string& fn);
	void addAdoption(Dogs d) override;
	virtual void write_to_file();
	void read_from_file();
	virtual void removeAdoption();
	virtual void open_file();
};

#endif //A45_ALEXANDRU_STINGA_REPOSITORY_FILEADOPTIONREPO_H_
