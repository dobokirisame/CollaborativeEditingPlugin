#ifndef FINISHINITIALSYNCREQUEST_H
#define FINISHINITIALSYNCREQUEST_H
#include "HttpRequest.h"
#include "collaborativeEditing_global.h"

class COLLABORATIVE_EDITING_EXPORT FinishInitialSyncRequest : public HttpRequest
{
public:
    FinishInitialSyncRequest();
    bool isValid() const override;
    QJsonDocument toJson() const override;
    QByteArray toByteArray() const override;
    QString clientId() const override;
};

#endif // FINISHINITIALSYNCREQUEST_H
