#ifndef CLIENTPOSITION_H
#define CLIENTPOSITION_H
#include "collaborativeEditing_global.h"
#include <QJsonDocument>

class COLLABORATIVE_EDITING_EXPORT ClientPosition
{
public:
    ClientPosition();
    QJsonDocument toJson() const;
};

#endif // CLIENTPOSITION_H
