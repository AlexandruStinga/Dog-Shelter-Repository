//
// Created by Alex on 5/9/2021.
//

#ifndef A45_ALEXANDRU_STINGA_UI_ADMINGUI_H_
#define A45_ALEXANDRU_STINGA_UI_ADMINGUI_H_
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QTableWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QShortcut>
#include "../service/service.h"
#include "../domain/exceptions.h"
#include "../domain/validator.h"
#include "../service/CommandController.h"

class AdminGUI : public QWidget
{
	Q_OBJECT

 public:
	explicit AdminGUI(CommandManager& c,Service& s,QWidget *parent = 0);
	void initAdminGUI();
	void populateList();
	int getSelectedIndex();
	void listItemChanged();
	void Signals();
	void addDog();
	void removeDog();
	void clearFields();
	void updateDog();
	void undo();
	void redo();



	Service& s;
	CommandManager& commandManager;

	QPushButton* addDogButton;
	QPushButton* removeDogButton;
	QPushButton* updateDogButton;
	QPushButton* clearFieldsButton;
	QPushButton* undoButton;
	QPushButton* redoButton;
	QShortcut* undoShortcut;
	QShortcut* redoShortcut;


	QTableWidget* table;
	QListWidget* dogList;
	QLineEdit* id;
	QLineEdit* name;
	QLineEdit* breed;
	QLineEdit* age;
	QTextEdit* photograph;

 signals:
	void dogsUpdatedSignal();
};

#endif //A45_ALEXANDRU_STINGA_UI_ADMINGUI_H_
