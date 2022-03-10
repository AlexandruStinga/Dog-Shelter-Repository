//
// Created by Alex on 5/23/2021.
//

#include <QFont>
#include <QBrush>
#include "Table.h"
DogsTable::DogsTable(user_service& serv, QObject* parent): s(serv), QAbstractTableModel(parent)
{
	this->s = serv;
}
int DogsTable::rowCount(const QModelIndex& parent) const
{
	int n = this->s.ar.adoptions.size();
	return n;
}
int DogsTable::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant DogsTable::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();

	if(row == this->s.ar.adoptions.size())
	{
		return QVariant();
	}

	Dogs d = this->s.ar.adoptions[row];

	if(role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch(column)
		{
		case 0:
			return QString::fromStdString(to_string(d.id));
		case 1:
			return QString::fromStdString(d.name);
		case 2:
			return QString::fromStdString(d.breed);
		case 3:
			return QString::fromStdString(to_string(d.age));
		case 4:
			return QString::fromStdString(d.photograph);
		default:
			break;
		}
	}

	if(role == Qt::FontRole)
	{
		QFont font("Times",15,10,true);
		font.setItalic(false);
		return font;
	}

	if(role == Qt::BackgroundRole)
	{
		if(row % 2 == 1)
			return QBrush(QColor(0,250,155));
	}

	return QVariant();
}
QVariant DogsTable::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(role == Qt::DisplayRole)
	{
		if(orientation == Qt::Horizontal)
		{
			switch(section)
			{
			case 0:
				return QString("ID");
			case 1:
				return QString("Name");
			case 2:
				return QString("Breed");
			case 3:
				return QString("Age");
			case 4:
				return QString("Photograph");
			default:
				break;
			}
		}
	}

	if(role == Qt::FontRole)
	{
		QFont font("Times",15,10,true);
		font.setBold(true);
		font.setItalic(false);
		return font;
	}
	return QVariant();
}
//bool DogsTable::setData(const QModelIndex& index, const QVariant& value, int role)
//{
//	if(!index.isValid() || role != Qt::EditRole)
//		return false;
//
//	int dogIndex = index.row();
//
//	if(dogIndex == this->s.ar.adoptions.size())
//	{
//		this->beginInsertRows(QModelIndex{},dogIndex,dogIndex);
//
//		switch(index.column())
//		{
//		case 0:
//			this->s.r.addElementRepo(Dogs(value.toString().toInt(),"","","",999));
//		case 1:
//			this->s.r.addElementRepo(Dogs(999,"",value.toString().toStdString(),"",999));
//		case 2:
//			this->s.r.addElementRepo(Dogs(999,value.toString().toStdString(),"","",999));
//		case 3:
//			this->s.r.addElementRepo(Dogs(999,"","","",value.toString().toInt()));
//		case 4:
//			this->s.r.addElementRepo(Dogs(999,"","",value.toString().toStdString(),999));
//		}
//
//		this->endInsertRows();
//		return true;
//
//	}
//
//	Dogs& currDog = this->s.r.storage[dogIndex];
//	switch(index.column())
//	{
//	case 0:
//		currDog.id = value.toString().toInt();
//	case 1:
//		currDog.name = value.toString().toStdString();
//	case 2:
//		currDog.breed = value.toString().toStdString();
//	case 3:
//		currDog.age = value.toString().toInt();
//	case 4:
//		currDog.photograph = value.toString().toStdString();
//	}
//	this->s.r.updateElem(dogIndex,currDog.breed,currDog.name,currDog.photograph,to_string(currDog.age));
//
//	emit dataChanged(index,index);
//
//	return true;
//}
//Qt::ItemFlags DogsTable::flags(const QModelIndex& index) const
//{
//	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
//}

