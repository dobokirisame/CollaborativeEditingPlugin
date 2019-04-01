#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <vector>
#include <memory>
#include "collaborativeEditing_global.h"
#include "Storage.h"

namespace qhttp {
namespace server {
class QHttpServer;
class QHttpConnection;
} //namespace server
} //namespace qhttp
namespace collaborativeEditing {
namespace common {
class Client;
class COLLABORATIVE_EDITING_EXPORT Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server() override;
signals:
    void initialSyncFinished();
private:
    void initializeBackend();
    void onDataReceived(const QByteArray &data);
    void sendChangesToClients(const QByteArray &data);
private slots:
    void onNewConnection(qhttp::server::QHttpConnection* connection);
    void onSyncStarted();
    void onSyncFinished();
private:
    std::vector<Client *> mClients;
    std::unique_ptr<Storage> mStorage;
    qhttp::server::QHttpServer *mServerBackend;
    std::vector<qhttp::server::QHttpConnection *> mConnections;
};
} //namespace common
} //namespace collaborativeEditing
#endif // SERVER_H
