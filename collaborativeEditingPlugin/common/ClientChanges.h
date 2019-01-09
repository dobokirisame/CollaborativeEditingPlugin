#ifndef CLIENTCHANGES_H
#define CLIENTCHANGES_H
#include <string>
#include <QString>
#include "collaborativeEditing_global.h"

namespace collaborativeEditing {
namespace common {
class COLLABORATIVE_EDITING_EXPORT ClientChanges
{
public:
    ClientChanges() = default;
    ClientChanges(const QString &projectName, const QString &filePath, std::string &pathesText);
    explicit ClientChanges(const QByteArray &data);
    void setProjectName(const QString &projectName);
    void setFilePath(const QString &value);
    void setPatchesText(const std::string &patchesText);
    QByteArray toByteArray() const;
    QString &projectName() const;
    QString &filePath() const;
    std::string patchesText() const;
    bool isValid() const;
private:
    void parserData(const QByteArray &data);
private:
    QString mProjectName;
    QString mFilePath;
    std::string mPatchesText;
};
} //namespace common
} //namespace collaborativeEditing

#endif // CLIENTCHANGES_H
