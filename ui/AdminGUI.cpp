//
// Created by Alex on 5/9/2021.
//

#include "AdminGUI.h"
AdminGUI::AdminGUI(CommandManager& c, Service &serv,QWidget* parent): s(serv),commandManager(c),QWidget(parent)
{
	this->s = serv;
	this->commandManager = c;
	this->initAdminGUI();
	this->populateList();
	this->Signals();
	this->setWindowTitle("Adopt a dog - Admin mode");

}
void AdminGUI::initAdminGUI()
{
	QHBoxLayout* layout = new QHBoxLayout{ this };

	//this->adjustSize();

	//left side - table
	//	QWidget* tableWidget = new QWidget();
	//	QVBoxLayout* tableLayout = new QVBoxLayout(tableWidget);
	//	this->table = new QTableWidget();
	//	this->table->setSelectionMode(QAbstractItemView::SingleSelection);
	//	QStringList a;
	//	a.push_back("ID");
	//	a.push_back("NAME");

	//	a.push_back("BREED");
	//	a.push_back("AGE");
	//	a.push_back("PHOTOGRAPH");
	//
	//	this->table->setColumnCount(5);
	//	this->table->setHorizontalHeaderLabels(a);
	//	tableLayout->addWidget(this->table);
	//	layout->addWidget(tableWidget);

	this->dogList = new QListWidget();
	this->dogList->setSelectionMode(QAbstractItemView::SingleSelection);
	layout->addWidget(this->dogList);
	//right side - info + buttons

	QWidget* rightSide = new QWidget();
	QVBoxLayout* vLayout = new QVBoxLayout(rightSide);

	//info
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


	vLayout->addWidget(dogInfoWidget);
	// buttons
	QWidget* buttonsWidget = new QWidget();
	QHBoxLayout* hLayout = new QHBoxLayout( buttonsWidget );
	this->addDogButton = new QPushButton("Add dog");
	this->removeDogButton = new QPushButton("Remove dog");
	this->updateDogButton = new QPushButton("Update dog");
	this->clearFieldsButton = new QPushButton("Clear fields");
	this->undoButton = new QPushButton("Undo");
	this->redoButton = new QPushButton("Redo");
	hLayout->addWidget(this->addDogButton);
	hLayout->addWidget(this->removeDogButton);
	hLayout->addWidget(this->updateDogButton);
	hLayout->addWidget(this->clearFieldsButton);
	hLayout->addWidget(this->undoButton);
	hLayout->addWidget(this->redoButton);
	vLayout->addWidget(buttonsWidget);

	layout->addWidget(rightSide);

	//Shortcuts
	this->undoShortcut = new QShortcut(QKeySequence("Ctrl+Z"),this);
	this->redoShortcut = new QShortcut(QKeySequence("Ctrl+Y"),this);

	this->resize(1064,500);
}

void AdminGUI::populateList()
{
	if(this->dogList->count() > 0)
		this->dogList->clear();

	for(auto i : this->s.r.storage)
	{
		QString dog = QString::fromStdString("ID: " + to_string(i.id) + " - Name: " + i.name + " - Breed: " + i.breed + " - Age: " + to_string(i.age) + " - Photograph: " + i.photograph);
		QFont f ("Verdana",9);
		QListWidgetItem* item = new QListWidgetItem(dog);
		item->setFont(f);
		this->dogList->addItem(item);
	}

	if(this->s.r.storage.size() > 0)
	{
		this->dogList->setCurrentRow(0);
	}

}

int AdminGUI::getSelectedIndex()
{
	if(this->dogList->count() == 0)
		return -1;


	QModelIndexList index = this->dogList->selectionModel()->selectedIndexes();
	if(index.size() == 0)
	{
		this->id->clear();
		this->age->clear();
		this->name->clear();
		this->breed->clear();
		this->photograph->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void AdminGUI::listItemChanged()
{
	int idx = this->getSelectedIndex();
	if(idx == -1)
		return;

	if(idx >= this->s.r.storage.size())
		return;

	Dogs d = this->s.r.storage[idx];

	this->id->setText(QString::fromStdString(to_string(d.id)));
	this->name->setText(QString::fromStdString(d.name));
	this->breed->setText(QString::fromStdString(d.breed));
	this->age->setText(QString::fromStdString(to_string(d.age)));
	this->photograph->setText(QString::fromStdString(d.photograph));

}

void AdminGUI::Signals()
{
	QObject::connect(this->dogList, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemChanged();});
	QObject::connect(this,&AdminGUI::dogsUpdatedSignal, this, &AdminGUI::populateList);
	QObject::connect(this->addDogButton,&QPushButton::clicked,this,&AdminGUI::addDog);
	QObject::connect(this->clearFieldsButton, &QPushButton::clicked, this, &AdminGUI::clearFields);
	QObject::connect(this->removeDogButton, &QPushButton::clicked, this, &AdminGUI::removeDog);
	QObject::connect(this->updateDogButton,&QPushButton::clicked,this,&AdminGUI::updateDog);
	QObject::connect(this->undoButton,&QPushButton::clicked,this,&AdminGUI::undo);
	QObject::connect(this->redoButton,&QPushButton::clicked,this,&AdminGUI::redo);
	QObject::connect(this->undoShortcut,&QShortcut::activated,this,&AdminGUI::undo);
	QObject::connect(this->redoShortcut,&QShortcut::activated,this,&AdminGUI::redo);

}

void AdminGUI::addDog()
{
	if(this->breed->text().isEmpty() || this->age->text().isEmpty() || this->name->text().isEmpty() ||
		this->id->text().isEmpty() || this->photograph->toPlainText().isEmpty())
		return;

	QString new_id = this->id->text();
	QString new_name = this->name->text();
	QString new_age = this->age->text();
	QString new_breed = this->breed->text();
	QString new_photo = this->photograph->toPlainText();

	shared_ptr<ICommand> add(new AddCommand(this->s,new_id.toInt(),new_breed.toStdString(),new_name.toStdString(),new_photo.toStdString(),new_age.toInt()));

	try
	{
//		this->s.addElementService(new_id.toInt(),new_breed.toStdString(),new_name.toStdString(),new_photo.toStdString(),new_age.toInt());
		this->commandManager.execute(add);
	}
	catch(const exception& e)
	{
		cout<<e.what();
	}
	catch(const ValidationException& e)
	{
		cout<<e.getMessage();
	}

	emit dogsUpdatedSignal();

	this->id->clear();
	this->name->clear();
	this->breed->clear();
	this->age->clear();
	this->photograph->clear();
}

void AdminGUI::clearFields()
{
	this->id->clear();
	this->name->clear();
	this->breed->clear();
	this->age->clear();
	this->photograph->clear();
}

void AdminGUI::removeDog()
{
	int idx = getSelectedIndex();
	shared_ptr<ICommand> remove(new RemoveCommand(this->s,this->s.r.storage[idx].id));
	//this->s.removeElementService(this->s.r.storage[idx].id);
	this->commandManager.execute(remove);
	emit dogsUpdatedSignal();
}
void AdminGUI::updateDog()
{
	if(this->breed->text().isEmpty() || this->age->text().isEmpty() || this->name->text().isEmpty() ||
			this->id->text().isEmpty() || this->photograph->toPlainText().isEmpty())
		return;

	QString new_name = this->name->text();
	QString new_age = this->age->text();
	QString new_breed = this->breed->text();
	QString new_photo = this->photograph->toPlainText();

	int idx = getSelectedIndex();
	int currID = this->s.r.storage[idx].id;

	shared_ptr<ICommand> update(new UpdateCommand(this->s,currID,new_breed.toStdString(),new_name.toStdString(),new_photo.toStdString(),new_age.toStdString()));

	try
	{
//		this->s.updateElement(currID,new_breed.toStdString(),new_name.toStdString(),new_photo.toStdString(),new_age.toStdString());
		this->commandManager.execute(update);
	}
	catch (exception &e)
	{
		cout<<e.what()<<endl;
	}

	emit dogsUpdatedSignal();
}
void AdminGUI::undo()
{
	this->commandManager.undo();
	emit dogsUpdatedSignal();
}

void AdminGUI::redo()
{
	this->commandManager.redo();
	emit dogsUpdatedSignal();
}
