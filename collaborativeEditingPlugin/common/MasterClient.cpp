#include "MasterClient.h"
#include "CanStartInitialSyncRequest.h"
#include "InitialSyncRequest.h"

namespace collaborativeEditing {
namespace common {

MasterClient::MasterClient(Server *server, QObject *parent)
    : Client(parent),
      mServer(server) {
}

bool MasterClient::canStartInitialSync() const {
    CanStartInitialSyncRequest request;
    sendRequest(&request);
}

void MasterClient::initialSync() {
    CanStartInitialSyncRequest request;
    sendRequest(&request);
}

} //namespace common
} //namespace collaborativeEditing
