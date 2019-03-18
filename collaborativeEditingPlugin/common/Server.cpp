#include "Server.h"
#include <QHttp/qhttpserver.hpp>
#include <iostream>
#include <QHttp/qhttpserverrequest.hpp>
#include <QHttp/qhttpserverresponse.hpp>
#include <QHttp/qhttpserverconnection.hpp>
#include <QHttp/qhttpfwd.hpp>

namespace collaborativeEditing {
namespace common {

Server::Server(QObject *parent)
    : QObject(parent) {
    mServerBackend = new qhttp::server::QHttpServer(this);
    initializeBackend();
}
void Server::initializeBackend() {
    auto backendRequestHandler = [=](qhttp::server::QHttpRequest* request, qhttp::server::QHttpResponse* response) {
        if(request->method() != qhttp::EHTTP_POST) {
            std::cerr << "Received strange package";
            response->setStatusCode(qhttp::ESTATUS_BAD_REQUEST);
            response->end();
            return;
        }
        connect(request, &qhttp::server::QHttpRequest::data,
                this, [=,&response](const QByteArray &data) {
            onDataReceived(data);
            response->setStatusCode(qhttp::ESTATUS_OK);
            response->end();
        } );
    };
    connect(mServerBackend, &qhttp::server::QHttpServer::newConnection,
            this, &Server::onNewConnection);
    mServerBackend->listen( QHostAddress::Any, 8080, backendRequestHandler);
    if ( !mServerBackend->isListening()) {
        std::cerr << "Failed to listen with server";
    }
}

void Server::onDataReceived(const QByteArray &data) {
    if(mStorage == nullptr) {
        std::cerr << "Could not find local storage";
        return;
    }
    auto changes = ClientChanges::fromByteArray(data);
    if(changes.areValid()) {
        mStorage->applyClientChanges(changes);
    }

}

void Server::sendChangesToClients() {
    // TODO(dobokirisame) add implementation
}

void Server::onNewConnection(qhttp::server::QHttpConnection *connection) {
    if(connection->backendType() != qhttp::ETcpSocket) {
        std::cerr << "Didn't get right socket";
        return;
    }
    mSockets.emplace_back(std::unique_ptr<QTcpSocket>(connection->tcpSocket()));

}
} //namespace common
} //namespace collaborativeEditing
