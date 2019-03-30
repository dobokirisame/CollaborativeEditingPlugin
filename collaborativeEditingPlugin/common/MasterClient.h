#ifndef MASTERCLIENT_H
#define MASTERCLIENT_H
#include "Client.h"

namespace collaborativeEditing {
namespace common {
class Server;
class COLLABORATIVE_EDITING_EXPORT MasterClient : public Client
{
    Q_OBJECT
public:
    explicit MasterClient(Server *server, QObject *parent = nullptr);
public slots:
    void onResponseRecieved(const HttpRequest *request, const qhttp::client::QHttpResponse *response) const override;
private:
    bool canStartInitialSync() const;
    void startInitialSync() const;
private:
    Server *mServer;
};

} //namespace common
} //namespace collaborativeEditing
#endif // MASTERCLIENT_H
