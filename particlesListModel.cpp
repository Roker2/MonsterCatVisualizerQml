#include "particlesListModel.h"

#include <QPointF>
#include <QColor>

using namespace monsterCatVisualizer;

ParticlesListModel::ParticlesListModel(QObject *parent)
    : QAbstractListModel(parent)
    , ParticlesContainer()
{}

QHash<int, QByteArray> ParticlesListModel::roleNames() const
{
    static QHash<int, QByteArray> roles;
    if (roles.isEmpty()) {
        roles[Position] = "position";
        roles[Radius] = "radius";
        roles[Color] = "color";
        roles[Opacity] = "opacity";
    }
    return roles;
}

int ParticlesListModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_particles.size();
}

QVariant ParticlesListModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }
    const Particle& particle = m_particles.at(index.row());
    switch (role) {
    case Position:
        return QPointF(particle.getX(), particle.getY());
    case Radius:
        return particle.getRadius();
    case Color:
        return QColor(particle.getR(), particle.getG(), particle.getB());
    case Opacity:
        return particle.getA();
    default:
        return QVariant();
    }
}