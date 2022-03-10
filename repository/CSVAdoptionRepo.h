//
// Created by Alex on 4/19/2021.
//

#ifndef A45_ALEXANDRU_STINGA_REPOSITORY_CSVADOPTIONREPO_H_
#define A45_ALEXANDRU_STINGA_REPOSITORY_CSVADOPTIONREPO_H_
#include "fileAdoptionRepo.h"
class CSVAdoptionRepo : public fileAdoptionRepo
{
 public:
	string filename;
	CSVAdoptionRepo(const string& fn);
	void addAdoption(Dogs d) override;
	void write_to_file() override;
	void removeAdoption() override;
	void open_file() override;
};

#endif //A45_ALEXANDRU_STINGA_REPOSITORY_CSVADOPTIONREPO_H_
