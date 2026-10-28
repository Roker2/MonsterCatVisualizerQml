#pragma once

#include <QAbstractListModel>
#include <QObject>

#include <particlesContainer.h>

class ParticlesListModel : public QAbstractListModel, public monsterCatVisualizer::ParticlesContainer
{
    Q_OBJECT
public:
    enum Roles
    {
        Position = Qt::UserRole + 1,
        Radius,
        Color,
        Opacity,
    };

    explicit ParticlesListModel(QObject *parent = nullptr);

    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex& parent=QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role) const;
};
