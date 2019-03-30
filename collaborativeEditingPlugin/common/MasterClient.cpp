#include "MasterClient.h"
#include "CanStartInitialSyncRequest.h"
#include "InitialSyncRequest.h"
#include <QHttp/qhttpclientresponse.hpp>

namespace collaborativeEditing {
namespace common {

MasterClient::MasterClient(Server *server, QObject *parent)
    : Client(parent),
      mServer(server) {
}

void MasterClient::onResponseRecieved(const HttpRequest *request, const qhttp::client::QHttpResponse *response) const {
    auto canStartSyncSent = dynamic_cast<const CanStartInitialSyncRequest*>(request) != nullptr;
    if(canStartSyncSent && response->isSuccessful()) {
        startInitialSync();
    }
}

bool MasterClient::canStartInitialSync() const {
    CanStartInitialSyncRequest request;
    sendRequest(&request);
}

void MasterClient::startInitialSync() const {
    CanStartInitialSyncRequest request;
    sendRequest(&request);
}

} //namespace common
} //namespace collaborativeEditing
