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
private:
    void initializeBackend();
private:
    std::vector<Client *> mClients;
    std::unique_ptr<Storage> mStorage;
    qhttp::server::QHttpServer *mServerBackend;
};
} //namespace common
} //namespace collaborativeEditing
#endif // SERVER_H
