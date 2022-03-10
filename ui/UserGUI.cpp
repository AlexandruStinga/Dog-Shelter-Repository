//
// Created by Alex on 5/10/2021.
//

#include "UserGUI.h"
UserGUI::UserGUI(Service& serv, user_service& user_serv, QWidget* parent): s(serv), us(user_serv), QWidget(parent)
{
	this->s = serv;
	this->us = user_serv;
	this->initUserGUI();
//	this->populateAdoptionList();
	this->Signals();
	this->index = -1;
	this->setWindowTitle("Adopt a dog - User mode");
}

void UserGUI::initUserGUI()
{
	QHBoxLayout* layout = new QHBoxLayout(this);

	///left side, labels linked to labels?

	QWidget* leftSide = new QWidget();
	QVBoxLayout* leftVBox = new QVBoxLayout(leftSide);

	QWidget* dogInfoWidget = new QWidget();
	QFormLayout* formLayout = new QFormLayout(dogInfoWidget);

	QFont f("Verdana",15);
	this->id = new QLineEdit();
	this->name = new QLineEdit();
	this->age = new QLineEdit();
	this->breed = new QLineEdit();
	this->photograph = new QTextEdit();

	QLabel* idLabel = new QLabel("&ID:");
	idLabel->setBuddy(this->id);

	QLabel* nameLabel = new QLabel("&Name:");
	nameLabel->setBuddy(this->name);

	QLabel* ageLabel = new QLabel("&Age:");
	ageLabel->setBuddy(this->age);

	QLabel* breedLabel = new QLabel("&Breed:");
	breedLabel->setBuddy(this->breed);

	QLabel* photographLabel = new QLabel("&Photograph:");
	photographLabel->setBuddy(this->photograph);

	this->id->setFont(f);
	this->name->setFont(f);
	this->age->setFont(f);
	this->breed->setFont(f);
	this->photograph->setFont(f);

	this->id->setReadOnly(true);
	this->name->setReadOnly(true);
	this->age->setReadOnly(true);
	this->breed->setReadOnly(true);
	this->photograph->setReadOnly(true);

	idLabel->setFont(f);
	nameLabel->setFont(f);
	ageLabel->setFont(f);
	breedLabel->setFont(f);
	photographLabel->setFont(f);

	formLayout->addRow(idLabel,this->id);
	formLayout->addRow(nameLabel,this->name);
	formLayout->addRow(ageLabel,this->age);
	formLayout->addRow(breedLabel,this->breed);
	formLayout->addRow(photographLabel,this->photograph);

	leftVBox->addWidget(dogInfoWidget);

	//buttons

	QWidget* NextPrevButtons = new QWidget();
	QHBoxLayout* NextPrevLayout = new QHBoxLayout(NextPrevButtons);

	this->nextButton = new QPushButton("Next");
	this->prevButton = new QPushButton("Previous");
	this->adoptButton = new QPushButton("Adopt");
	NextPrevLayout->addWidget(this->prevButton);
	NextPrevLayout->addWidget(this->nextButton);
	NextPrevLayout->addWidget(this->adoptButton);
	leftVBox->addWidget(NextPrevButtons);

	layout->addWidget(leftSide);

	//middle

	QWidget* midSide = new QWidget();
	QVBoxLayout* midVBox = new QVBoxLayout(midSide);

	//Forms

	QWidget* breedAgeInfo = new QWidget();
	QFormLayout* formLayout1 = new QFormLayout(breedAgeInfo);

	this->breedEditable = new QLineEdit();
	this->ageEditable = new QLineEdit();

	QLabel* breedEditableLabel = new QLabel("Set breed: ");
	breedEditableLabel->setBuddy(this->breedEditable);

	QLabel* ageEditableLabel = new QLabel("Set age: ");
	ageEditableLabel->setBuddy(this->ageEditable);

	this->breedEditable->setFont(f);
	this->ageEditable->setFont(f);

	breedEditableLabel->setFont(f);
	ageEditableLabel->setFont(f);

	formLayout1->addRow(breedEditableLabel,this->breedEditable);
	formLayout1->addRow(ageEditableLabel,this->ageEditable);

	midVBox->addWidget(breedAgeInfo);



	//buttons
	//QWidget* midButtons = new QWidget();
	//QVBoxLayout* midButtonsLayout = new QVBoxLayout(midButtons);

	this->filteredDogsButton = new QPushButton("Apply filters");
	this->allDogsButton = new QPushButton("All dogs");
	this->openAdoptionListButton = new QPushButton("Open CSV/HTML file");

	midVBox->addWidget(this->filteredDogsButton);
	midVBox->addWidget(this->allDogsButton);
	midVBox->addWidget(this->openAdoptionListButton);

	//midVBox->addWidget(midButtons);

	layout->addWidget(midSide);

	/// left side - list
//	this->adoptionList = new QListWidget();
//	this->adoptionList->setSelectionMode(QAbstractItemView::SingleSelection);
//	layout->addWidget(this->adoptionList);
	this->dogsTable = new DogsTable(this->us);
	this->table = new QTableView{};
	this->table->setModel(this->dogsTable);
	this->table->resizeColumnsToContents();
	layout->addWidget(this->table);

}
void UserGUI::populateAdoptionList()
{
	if(this->adoptionList->count() > 0)
		this->adoptionList->clear();

	for(auto i: this->us.ar.adoptions)
	{
		QString dog = QString::fromStdString("ID: " + to_string(i.id) + " - Name: " + i.name + " - Breed: " + i.breed + " - Age: " + to_string(i.age) + " - Photograph: " + i.photograph);
		QFont f ("Verdana",9);
		QListWidgetItem* item = new QListWidgetItem(dog);
		item->setFont(f);
		this->adoptionList->addItem(item);
	}

	if(this->us.ar.adoptions.size() > 0)
	{
		this->adoptionList->setCurrentRow(0);
	}
}

void UserGUI::Signals()
{
	QObject::connect(this->openAdoptionListButton, &QPushButton::clicked, this, &UserGUI::OpenHTMLCSVClicked);
	QObject::connect(this->allDogsButton, &QPushButton::clicked, this, &UserGUI::AllDogsClicked);
	QObject::connect(this->nextButton, &QPushButton::clicked, this, &UserGUI::NextClicked);
	QObject::connect(this->prevButton, &QPushButton::clicked, this, &UserGUI::PrevClicked);
	QObject::connect(this->filteredDogsButton, &QPushButton::clicked, this, &UserGUI::FilteredClicked);
//	QObject::connect(this,&UserGUI::dogsUpdatedSignal, this, &UserGUI::populateAdoptionList);
//	QObject::connect(this,&UserGUI::dogsUpdatedSignal, this, &UserGUI::populateAdoptionList);
	QObject::connect(this->adoptButton, &QPushButton::clicked,this,&UserGUI::AdoptClicked);

}

void UserGUI::OpenHTMLCSVClicked()
{
	this->us.ar.open_file();
}

void UserGUI::AllDogsClicked()
{
	this->dogs = this->s.r.storage;
	if(this->dogs.empty())
		return;


	this->index = 0;
	Dogs d=this->dogs[index];
	this->id->setText(QString::fromStdString(to_string(d.id)));
	this->name->setText(QString::fromStdString(d.name));
	this->breed->setText(QString::fromStdString(d.breed));
	this->age->setText(QString::fromStdString(to_string(d.age)));
	this->photograph->setText(QString::fromStdString(d.photograph));
}

void UserGUI::NextClicked()
{
	if(this->index == -1)
		return;
	this->index++;
	if (this->index >= this->dogs.size())
		this->index = 0;

	Dogs d = this->dogs[index];
	this->id->setText(QString::fromStdString(to_string(d.id)));
	this->name->setText(QString::fromStdString(d.name));
	this->breed->setText(QString::fromStdString(d.breed));
	this->age->setText(QString::fromStdString(to_string(d.age)));
	this->photograph->setText(QString::fromStdString(d.photograph));
}
void UserGUI::PrevClicked()
{
	if(this->index == -1)
		return;
	this->index--;
	if(this->index <= -1)
		this->index = this->dogs.size() - 1;

	Dogs d = this->dogs[index];
	this->id->setText(QString::fromStdString(to_string(d.id)));
	this->name->setText(QString::fromStdString(d.name));
	this->breed->setText(QString::fromStdString(d.breed));
	this->age->setText(QString::fromStdString(to_string(d.age)));
	this->photograph->setText(QString::fromStdString(d.photograph));
}

void UserGUI::FilteredClicked()
{
	if(this->breedEditable->text().isEmpty() || this->ageEditable->text().isEmpty())
		return;
	QString b = this->breedEditable->text();
	QString a = this->ageEditable->text();

	this->dogs = this->us.BreedAgeAdoption(a.toInt(), b.toStdString());
	if(this->dogs.empty())
		return;

	this->index = 0;

	Dogs d=this->dogs[index];
	this->id->setText(QString::fromStdString(to_string(d.id)));
	this->name->setText(QString::fromStdString(d.name));
	this->breed->setText(QString::fromStdString(d.breed));
	this->age->setText(QString::fromStdString(to_string(d.age)));
	this->photograph->setText(QString::fromStdString(d.photograph));
}

void UserGUI::AdoptClicked()
{
	if(this->index == -1)
		return;

	this->us.addAdoption(this->dogs[this->index]);
	this->dogs.erase(this->dogs.begin() + this->index);
	NextClicked();
	if(this->dogs.empty())
	{
		this->index = -1;
		this->id->clear();
		this->name->clear();
		this->breed->clear();
		this->age->clear();
		this->photograph->clear();

	}
	this->table->reset();
	this->dogsTable = new DogsTable(this->us);
	this->table->setModel(this->dogsTable);
//	emit dogsUpdatedSignal();
}
