#ifndef PROJECTSTRUCTURE_H
#define PROJECTSTRUCTURE_H
#include "collaborativeEditing_global.h"
#include <QJsonDocument>

class COLLABORATIVE_EDITING_EXPORT ProjectStructure
{
public:
    ProjectStructure();
    QJsonDocument toJson() const;
};

#endif // PROJECTSTRUCTURE_H
