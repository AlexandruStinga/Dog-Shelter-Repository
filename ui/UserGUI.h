//
// Created by Alex on 5/10/2021.
//

#ifndef A45_ALEXANDRU_STINGA_UI_USERGUI_H_
#define A45_ALEXANDRU_STINGA_UI_USERGUI_H_
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QTableWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include "../service/user_service.h"
#include "../service/service.h"
#include "Table.h"
class UserGUI: public QWidget
{
	Q_OBJECT

 public:
	UserGUI(Service& s,user_service& us, QWidget *parent = 0);
	void initUserGUI();
	void populateAdoptionList();
	void Signals();
	void OpenHTMLCSVClicked();
	void AllDogsClicked();
	void FilteredClicked();
	void NextClicked();
	void PrevClicked();
	void AdoptClicked();


	QLineEdit* id;
	QLineEdit* name;
	QLineEdit* breed;
	QLineEdit* age;
	QTextEdit* photograph;

	QLineEdit* breedEditable;
	QLineEdit* ageEditable;

	QPushButton* nextButton;
	QPushButton* prevButton;
	QPushButton* adoptButton;
	QPushButton* allDogsButton;
	QPushButton* filteredDogsButton;
	QPushButton* openAdoptionListButton;

	QListWidget* adoptionList;
	DogsTable* dogsTable;
	QTableView* table;

	Service& s;
	user_service& us;

	int index;
	std::vector<Dogs> dogs;

 signals:
	void dogsUpdatedSignal();
};

#endif //A45_ALEXANDRU_STINGA_UI_USERGUI_H_
