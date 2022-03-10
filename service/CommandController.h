//
// Created by Alex on 5/28/2021.
//

#ifndef A45_ALEXANDRU_STINGA_SERVICE_COMMANDCONTROLLER_H_
#define A45_ALEXANDRU_STINGA_SERVICE_COMMANDCONTROLLER_H_
#include "service.h"
#include <stack>
#include <memory>

class ICommand
{
 public:
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual void redo() = 0;
};

class AddCommand: public ICommand
{
 public:
	int id;
	string breed;
	string name;
	string photograph;
	int age;
	Service& s;

	AddCommand(Service& serv,int i, string b, string n, string p, int a);
	void execute();
	void undo();
	void redo();
};

class RemoveCommand: public ICommand
{
 public:
	int id;
	string breed;
	string name;
	string photograph;
	int age;
	Service& s;
	RemoveCommand(Service& serv,int i);

	void execute();
	void undo();
	void redo();
};

class UpdateCommand: public ICommand
{
 public:
	int id;
	string breed;
	string name;
	string photograph;
	string age;


	int old_id;
	string old_breed;
	string old_name;
	string old_photograph;
	string old_age;
	Service& s;
	UpdateCommand(Service& serv,int i, string b, string n, string p, string a);
	void execute();
	void undo();
	void redo();
};

typedef std::stack<std::shared_ptr<ICommand> > commandStack_t;


class CommandManager
{
 public:
	commandStack_t undoStack;
	commandStack_t redoStack;

	void execute(std::shared_ptr<ICommand> command);
	void undo();
	void redo();

};

#endif //A45_ALEXANDRU_STINGA_SERVICE_COMMANDCONTROLLER_H_
