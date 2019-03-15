#include "Server.h"
#include <QHttp/qhttpserver.hpp>
#include <iostream>
#include <QHttp/qhttpserverrequest.hpp>
#include <QHttp/qhttpserverresponse.hpp>

namespace collaborativeEditing {
namespace common {

Server::Server(QObject *parent)
    : QObject(parent) {
    mServerBackend = new qhttp::server::QHttpServer(this);
    initializeBackend();
}
void Server::initializeBackend() {
    auto backendRequestHandler = [=](qhttp::server::QHttpRequest* request, qhttp::server::QHttpResponse* response) {
//        request->
        response->setStatusCode(qhttp::ESTATUS_OK);
        response->end("Hello World!\n");
    };
    mServerBackend->listen( QHostAddress::Any, 8080, backendRequestHandler);
    if ( !mServerBackend->isListening()) {
        std::cerr << "Failed to listen with server";
    }
}
} //namespace common
} //namespace collaborativeEditing
