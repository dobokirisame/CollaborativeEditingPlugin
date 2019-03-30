#ifndef CANSTARTINITIALSYNCREQUEST_H
#define CANSTARTINITIALSYNCREQUEST_H
#include "HttpRequest.h"
#include "collaborativeEditing_global.h"
namespace collaborativeEditing {
namespace common {
class COLLABORATIVE_EDITING_EXPORT CanStartInitialSyncRequest : public HttpRequest
{
public:
    CanStartInitialSyncRequest();
    bool isValid() const override;
    QJsonDocument toJson() const override;
    QByteArray toByteArray() const override;
    QString clientId() const override;
};

} //namespace common
} //namespace collaborativeEditing
#endif // CANSTARTINITIALSYNCREQUEST_H
