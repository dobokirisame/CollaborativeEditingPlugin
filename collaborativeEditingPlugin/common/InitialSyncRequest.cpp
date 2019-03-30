#include "InitialSyncRequest.h"
namespace collaborativeEditing {
namespace common {
InitialSyncRequest::InitialSyncRequest(Storage *storage)
    : mStorage(storage){

}

bool InitialSyncRequest::isValid() const {
    // TODO(dobokirisame) add implementation
    return false;
}

QJsonDocument InitialSyncRequest::toJson() const {
    // TODO(dobokirisame) add implementation
    return QJsonDocument();
}

QByteArray InitialSyncRequest::toByteArray() const {
    // TODO(dobokirisame) add implementation
    return QByteArray();
}

QString InitialSyncRequest::clientId() const {
    // TODO(dobokirisame) add implementation
    return QString();
}

} //namespace common
} //namespace collaborativeEditing
