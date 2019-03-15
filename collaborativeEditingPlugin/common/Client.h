#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include "ClientChanges.h"
#include "ClientCursorPostion.h"

namespace collaborativeEditing {
namespace common {
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    void sendChanged();
    void sendCursiorPosition();
    QString currentFileText() const;
    void setCurrentFileText(const QString &currentFileText);
    QString clientId() const;
public slots:
    void onClientChangesReceived(const ClientChanges &changes);
    void onClientCursorPositionReceived(const ClientCursorPostion &pos);
signals:
    void clientChangesApplied();
    void clinetCursorPositionChanged(const ClientCursorPostion &pos);
private:
    void applyClientChanges(const ClientChanges &changes);
    bool canApplyClientChanges(const ClientChanges &changes) const;
    ClientChanges generateClientChanges() const;
private:
    QString mCurrentFileText;
    QString mClientId;
};
} //namespace common
} //namespace collaborativeEditing


#endif // CLIENT_H
