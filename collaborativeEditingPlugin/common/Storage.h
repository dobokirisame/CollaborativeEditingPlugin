#ifndef STORAGE_H
#define STORAGE_H

#include "collaborativeEditing_global.h"
#include <QStringList>
#include "ClientChanges.h"

namespace collaborativeEditing {
namespace common {
class COLLABORATIVE_EDITING_EXPORT Storage
{
public:
    Storage() = default;
    virtual ~Storage() = default;
    QStringList openedProjects() const;
    void applyClientChanges(const ClientChanges &changes);
    QString sourceText(const QString &filePath) const;
    void updateText(const QString &filePath);
};
} //namespace common
} //namespace collaborativeEditing

#endif // STORAGE_H
