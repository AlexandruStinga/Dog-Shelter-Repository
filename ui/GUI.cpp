//
// Created by Alex on 5/9/2021.
//

#include "GUI.h"
#include <iostream>
#include <QtWidgets/QApplication>
GUI::GUI(CommandManager& c,Service& serv, user_service& user_serv, QWidget* parent): s(serv), us(user_serv),commandManager(c),QWidget(parent)
{
	this->commandManager = c;
	this->initGUI();
	this->Signals();
	this->s = serv;
	this->us = user_serv;
}

void GUI::initGUI()
{
	QHBoxLayout* layout = new QHBoxLayout( this );
	QWidget* buttonsWidget = new QWidget(this);
	QHBoxLayout* hLayout = new QHBoxLayout( buttonsWidget );
	QFont f( "Verdana", 15 );
	this->adminModeButton = new QPushButton("Admin mode");
	this->userModeButton = new QPushButton("User mode");
	this->adminModeButton->setFont(f);
	this->userModeButton->setFont(f);
	hLayout->addWidget(this->adminModeButton);
	hLayout->addWidget(this->userModeButton);
	layout->addWidget(buttonsWidget);

}
void GUI::Signals()
{
	QObject::connect(this->adminModeButton,&QPushButton::clicked, this, &GUI::AdminButtonClicked);
	QObject::connect(this,SIGNAL(AdminClick()),this,SLOT(AdminMode()));

	QObject::connect(this->userModeButton, &QPushButton::clicked, this, &GUI::UserButtonClicked);
	QObject::connect(this,SIGNAL(UserClick()),this,SLOT(UserMode()));
}

void GUI::AdminButtonClicked()
{
	emit AdminClick();
}
void GUI::AdminMode()
{
	AdminGUI *w = new AdminGUI(commandManager,this->s);
	w->show();
}

void GUI::UserMode()
{
	UserGUI *w = new UserGUI(this->s, this->us);
	w->show();
}
void GUI::UserButtonClicked()
{
	emit UserClick();
}
