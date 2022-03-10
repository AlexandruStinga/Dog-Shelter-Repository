//
// Created by Alex on 3/19/2021.
//

#ifndef A45_ALEXANDRU_STINGA_UI_UI_H_
#define A45_ALEXANDRU_STINGA_UI_UI_H_
#include "../service/service.h"
#include "../service/user_service.h"
class ui
{
 public:
	Service& s;
	user_service& us;
	explicit ui(Service& s, user_service& user_serv);
	~ui();
	void adminUI();
	void mainUI();
	void printDogs();
	ui& operator=( const ui& rhs );
	void removeUI();
	void addUI();
	void updateUI();
	void userUI();
	void adoptUI();
	void printAdoptions();
	void adoptUI_breed_age();
	void openFile();
};

#endif //A45_ALEXANDRU_STINGA_UI_UI_H_
