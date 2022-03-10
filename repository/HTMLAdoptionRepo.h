//
// Created by Alex on 4/18/2021.
//

#ifndef A45_ALEXANDRU_STINGA_REPOSITORY_HTMLADOPTIONREPO_H_
#define A45_ALEXANDRU_STINGA_REPOSITORY_HTMLADOPTIONREPO_H_
#include "fileAdoptionRepo.h"

class HTMLAdoptionRepo : public fileAdoptionRepo
{
 public:
	string filename;
	explicit HTMLAdoptionRepo(const string& fn);
	void addAdoption(Dogs d) override;
	void write_to_file() override;
	void removeAdoption() override;
	void open_file() override;
};

#endif //A45_ALEXANDRU_STINGA_REPOSITORY_HTMLADOPTIONREPO_H_
