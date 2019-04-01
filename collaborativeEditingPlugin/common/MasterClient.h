#ifndef MASTERCLIENT_H
#define MASTERCLIENT_H
#include "Client.h"
#include <memory>
#include "SyncQueue.h"

namespace collaborativeEditing {
namespace common {
class Server;
class COLLABORATIVE_EDITING_EXPORT MasterClient : public Client
{
    Q_OBJECT
public:
    explicit MasterClient(Server *server, QObject *parent = nullptr);
public slots:
    void onResponseRecieved(const HttpRequest *request, const qhttp::client::QHttpResponse *response) override;
private:
    void canStartInitialSync();
    void startInitialSync();
    void finishInitialSync();
private:
    Server *mServer;
    std::unique_ptr<SyncQueue> mSyncQueue;
};

} //namespace common
} //namespace collaborativeEditing
#endif // MASTERCLIENT_H
