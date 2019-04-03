#ifndef STORAGE_H
#define STORAGE_H

#include "collaborativeEditing_global.h"
#include <QStringList>
#include "ClientChanges.h"
#include "ProjectStructure.h"

namespace collaborativeEditing {
namespace common {
class COLLABORATIVE_EDITING_EXPORT Storage
{
public:
    explicit Storage(QString &&projectName);
    virtual ~Storage() = default;
    QStringList openedProjects() const;
    void applyClientChanges(const ClientChanges &changes);
    QString sourceText(const QString &filePath) const;
    void updateText(const QString &filePath);
    QString currentProject() const;
    ProjectStructure *projectStructure();
private:
    QString mProjectName;
    ProjectStructure mProjectStructure;
};
} //namespace common
} //namespace collaborativeEditing

#endif // STORAGE_H
