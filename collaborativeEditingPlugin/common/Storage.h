#ifndef STORAGE_H
#define STORAGE_H

#include "collaborativeEditing_global.h"
#include <QStringList>

namespace collaborativeEditing {
namespace common {
class COLLABORATIVE_EDITING_EXPORT Storage
{
public:
    Storage() = default;
    QStringList openedProjects() const;
    virtual ~Storage() = default;
};
} //namespace common
} //namespace collaborativeEditing

#endif // STORAGE_H
