//
// Created by Alex on 5/28/2021.
//

#include "CommandController.h"

AddCommand::AddCommand(Service& serv,int i, string b, string n, string p, int a): s(serv)
{
	this->s = serv;
	this->id = i;
	this->breed = b;
	this->name = n;
	this->photograph = p;
	this->age = a;
}

void AddCommand::execute()
{
	this->s.addElementService(this->id,this->breed,this->name,this->photograph,this->age);
}

void AddCommand::undo()
{
	this->s.removeElementService(this->id);
}

void AddCommand::redo()
{
	this->s.addElementService(this->id,this->breed,this->name,this->photograph,this->age);
}

RemoveCommand::RemoveCommand(Service& serv, int i): s(serv)
{
	this->id = i;
}
void RemoveCommand::execute()
{
	int pos = this->s.r.positionDog(this->id);
	this->breed = this->s.r.storage[pos].breed;
	this->name = this->s.r.storage[pos].name;
	this->photograph = this->s.r.storage[pos].photograph;
	this->age = this->s.r.storage[pos].age;

	this->s.removeElementService(this->id);
}
void RemoveCommand::undo()
{
	this->s.addElementService(this->id,this->breed,this->name,this->photograph,this->age);
}
void RemoveCommand::redo()
{
	this->s.removeElementService(this->id);
}


UpdateCommand::UpdateCommand(Service& serv, int i, string b, string n, string p, string a): s(serv)
{
	this->s = serv;
	this->id = i;
	this->breed = b;
	this->name = n;
	this->photograph = p;
	this->age = a;
}
void UpdateCommand::execute()
{
	int pos = this->s.r.positionDog(this->id);
	this->old_breed = this->s.r.storage[pos].breed;
	this->old_name = this->s.r.storage[pos].name;
	this->old_photograph = this->s.r.storage[pos].photograph;
	this->old_age = to_string(this->s.r.storage[pos].age);
	this->old_id = this->s.r.storage[pos].id;

	this->s.updateElement(this->id,this->breed,this->name,this->photograph,this->age);
}
void UpdateCommand::undo()
{
	this->s.updateElement(this->id,this->old_breed,this->old_name,this->old_photograph,this->old_age);
}
void UpdateCommand::redo()
{
	this->s.updateElement(this->id,this->breed,this->name,this->photograph,this->age);
}


void CommandManager::execute(std::shared_ptr<ICommand> command)
{
	redoStack = commandStack_t();
	command->execute();
	undoStack.push(command);
}
void CommandManager::undo()
{
	if(undoStack.size() <= 0)
		return;

	undoStack.top()->undo();
	redoStack.push(undoStack.top());
	undoStack.pop();
}
void CommandManager::redo()
{
	if(redoStack.size() <= 0)
		return;

	redoStack.top()->redo();
	undoStack.push(redoStack.top());
	redoStack.pop();
}
