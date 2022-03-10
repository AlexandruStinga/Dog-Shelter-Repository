//
// Created by Alex on 4/7/2021.
//

#ifndef A45_ALEXANDRU_STINGA_REPOSITORY_FILEREPO_H_
#define A45_ALEXANDRU_STINGA_REPOSITORY_FILEREPO_H_
#include "repo.h"
class fileRepo : public Repository
{
 public:
	string filename;
	explicit fileRepo(const string& filename);
	void addElementRepo(Dogs d) override;
	void removeElem(int pos) override;
	int positionDog(int id) override;
	void updateElem(int pos, std::string breed, std::string name, std::string photograph, std::string age) override;
	void read_from_file();
	void write_to_file();
};

#endif //A45_ALEXANDRU_STINGA_REPOSITORY_FILEREPO_H_
