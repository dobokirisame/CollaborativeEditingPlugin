#ifndef CANSTARTINITIALSYNCREQUEST_H
#define CANSTARTINITIALSYNCREQUEST_H
#include "HttpRequest.h"
#include "collaborativeEditing_global.h"

class COLLABORATIVE_EDITING_EXPORT CanStartInitialSyncRequest : public HttpRequest
{
public:
    CanStartInitialSyncRequest();
    bool isValid() const override;
    QJsonDocument toJson() const override;
    QByteArray toByteArray() const override;
    QString clientId() const override;
};

#endif // CANSTARTINITIALSYNCREQUEST_H
