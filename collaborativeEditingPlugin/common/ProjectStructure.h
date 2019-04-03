#ifndef PROJECTSTRUCTURE_H
#define PROJECTSTRUCTURE_H
#include "collaborativeEditing_global.h"
#include "QObject"
#include <QJsonDocument>

class COLLABORATIVE_EDITING_EXPORT ProjectStructure : public QObject
{
    Q_OBJECT
public:
    explicit ProjectStructure(QObject *parent = nullptr);
    QJsonDocument toJson() const;
signals:
    void projectStuctureChanged();
};

#endif // PROJECTSTRUCTURE_H
