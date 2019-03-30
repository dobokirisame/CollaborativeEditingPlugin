#include "ClientFileRequest.h"
namespace collaborativeEditing {
namespace common {
ClientFileRequest::ClientFileRequest() {

}

bool ClientFileRequest::isValid() const {
    // TODO(dobokirisame) add implementation
    return false;
}

QJsonDocument ClientFileRequest::toJson() const {
    // TODO(dobokirisame) add implementation
    return QJsonDocument();
}

QByteArray ClientFileRequest::toByteArray() const {
    // TODO(dobokirisame) add implementation
    return QByteArray();
}

QString ClientFileRequest::clientId() const {
    // TODO(dobokirisame) add implementation
    return QString();
}
} //namespace common
} //namespace collaborativeEditing
