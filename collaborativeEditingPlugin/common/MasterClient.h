#ifndef MASTERCLIENT_H
#define MASTERCLIENT_H
#include <Client.h>

namespace collaborativeEditing {
namespace common {
class Server;
class COLLABORATIVE_EDITING_EXPORT MasterClient : public Client
{
    Q_OBJECT
public:
    explicit MasterClient(Server *server, QObject *parent = nullptr);
private:
    bool canStartInitialSync() const;
    void initialSync();
private:
    Server *mServer;
};

} //namespace common
} //namespace collaborativeEditing
#endif // MASTERCLIENT_H
