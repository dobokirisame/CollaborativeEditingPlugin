#ifndef INITIALSYNCREQUEST_H
#define INITIALSYNCREQUEST_H
#include "HttpRequest.h"
#include "collaborativeEditing_global.h"

namespace collaborativeEditing {
namespace common {

class Storage;
class COLLABORATIVE_EDITING_EXPORT InitialSyncRequest : public HttpRequest
{
public:
    explicit InitialSyncRequest(Storage *storage);
    bool isValid() const override;
    QJsonDocument toJson() const override;
    QByteArray toByteArray() const override;
    QString clientId() const override;
private:
    Storage *mStorage;
};

} //namespace common
} //namespace collaborativeEditing
#endif // INITIALSYNCREQUEST_H
