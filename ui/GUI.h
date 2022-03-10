//
// Created by Alex on 5/9/2021.
//

#ifndef A45_ALEXANDRU_STINGA_UI_GUI_H_
#define A45_ALEXANDRU_STINGA_UI_GUI_H_
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include "AdminGUI.h"
#include "UserGUI.h"
#include "../service/service.h"
#include "../service/user_service.h"
class GUI: public QWidget
{
	Q_OBJECT

 public:
	GUI(CommandManager& c, Service& s, user_service& us,QWidget *parent = 0);
	void initGUI();

	Service& s;
	user_service& us;
	CommandManager& commandManager;

	QPushButton* adminModeButton;
	QPushButton* userModeButton;
	void Signals();
	void AdminButtonClicked();
	void UserButtonClicked();


 signals:
	void AdminClick();
	void UserClick();

 public slots:
	void AdminMode();
 	void UserMode();
};

#endif //A45_ALEXANDRU_STINGA_UI_GUI_H_
