#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include "ClientChanges.h"
#include "ClientCursorPostion.h"
#include <memory>
#include "Storage.h"

namespace collaborativeEditing {
namespace common {
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    void sendChanged(const std::string &patch);
    void sendCursiorPosition();
    QString clientId() const;
public slots:
    void onClientChangesReceived(const ClientChanges &changes);
    void onClientCursorPositionReceived(const ClientCursorPostion &pos);
signals:
    void clientChangesApplied();
    void clinetCursorPositionChanged(const ClientCursorPostion &pos);
private slots:
    void onLocalTextChanges(const QString &text);
private:
    bool canApplyClientChanges(const ClientChanges &changes) const;
    ClientChanges generateClientChanges(const std::string &patch) const;
private:
    QString mCurrentFilePath;
    QString mClientId;
    std::unique_ptr<Storage> mStorage;
};
} //namespace common
} //namespace collaborativeEditing


#endif // CLIENT_H
