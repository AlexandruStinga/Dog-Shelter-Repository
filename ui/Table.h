//
// Created by Alex on 5/23/2021.
//
#include <QAbstractTableModel>
#include "../service/service.h"
#include "../domain/exceptions.h"
#include "../domain/validator.h"
#include "../service/user_service.h"
#ifndef A45_ALEXANDRU_STINGA_UI_TABLE_H_
#define A45_ALEXANDRU_STINGA_UI_TABLE_H_

class DogsTable : public QAbstractTableModel
{
 public:
	user_service& s;
	explicit DogsTable(user_service& serv, QObject* parent = NULL);

	int rowCount(const QModelIndex& parent) const override;
	int columnCount(const QModelIndex& parent) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
//	bool setData(const QModelIndex& index, const QVariant & value, int role = Qt::EditRole) override;
//	Qt::ItemFlags flags(const QModelIndex & index) const override;
};

#endif //A45_ALEXANDRU_STINGA_UI_TABLE_H_
