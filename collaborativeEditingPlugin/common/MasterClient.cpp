#include "MasterClient.h"
#include "CanStartInitialSyncRequest.h"
#include "InitialSyncRequest.h"
#include "FinishInitialSyncRequest.h"
#include <QHttp/qhttpclientresponse.hpp>
#include "Server.h"
#include <iostream>

namespace collaborativeEditing {
namespace common {

MasterClient::MasterClient(Server *server, QObject *parent)
    : Client(parent),
      mServer(server),
      mSyncQueue(std::make_unique<SyncQueue>(storage())) {
}

void MasterClient::onResponseRecieved(const HttpRequest *request, const qhttp::client::QHttpResponse *response) {
    auto canStartSyncSent = dynamic_cast<const CanStartInitialSyncRequest*>(request) != nullptr;
    if(canStartSyncSent && response->isSuccessful()) {
        startInitialSync();
        return;
    }
    auto initialSyncRequest = dynamic_cast<const InitialSyncRequest *>(request);
    if(initialSyncRequest != nullptr && response->isSuccessful()) {
        sendInitialSyncPackage();
        return;
    }
    auto syncRequest = dynamic_cast<const SyncRequest *>(request);
    if(syncRequest != nullptr && response->isSuccessful()) {
        sendInitialSyncPackage();
        return;
    }
}

void MasterClient::canStartInitialSync() {
    CanStartInitialSyncRequest request;
    sendRequest(&request);
}

void MasterClient::startInitialSync() {
    InitialSyncRequest request(storage());
    sendRequest(&request);
}

void MasterClient::finishInitialSync() {
    FinishInitialSyncRequest request;
    sendRequest(&request);
}

void MasterClient::sendInitialSyncPackage() {
    if(mSyncQueue == nullptr) {
        std::cerr << "Sync queue was not defined";
        return;
    }
    if(!mSyncQueue->hasSyncRequest()) {
        std::cout << "Sync queue is empty";
        return;
    }
    auto request = mSyncQueue->takeNextSyncRequest();
    sendRequest(&request);
}

} //namespace common
} //namespace collaborativeEditing
