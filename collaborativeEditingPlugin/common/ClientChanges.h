#ifndef CLIENTCHANGES_H
#define CLIENTCHANGES_H
#include <string>
#include <QString>
#include "collaborativeEditing_global.h"
#include <QJsonDocument>
#include "HttpRequest.h"

namespace collaborativeEditing {
namespace common {
class COLLABORATIVE_EDITING_EXPORT ClientChanges : public HttpRequest
{
public:
    ClientChanges() = default;
    ClientChanges(const QString &projectName, const QString &filePath, const std::string &pathesText);
    static ClientChanges fromByteArray(const QByteArray &data);
    explicit ClientChanges(const QByteArray &data);
    void setProjectName(const QString &projectName);
    void setFilePath(const QString &value);
    void setPatchesText(const std::string &patchesText);
    QJsonDocument toJson() const override;
    QByteArray toByteArray() const override;
    QString projectName() const;
    QString filePath() const;
    std::string patchesText() const;
    bool isValid() const override;
    QString clientId() const override;
    void setClientId(const QString &clientId);
private:
    void parserData(const QByteArray &data);
private:
    QString mProjectName;
    QString mFilePath;
    std::string mPatchesText;
    QString mClientId;
};
} //namespace common
} //namespace collaborativeEditing

#endif // CLIENTCHANGES_H
