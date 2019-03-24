#ifndef INITIALSYNCREQUEST_H
#define INITIALSYNCREQUEST_H
#include "HttpRequest.h"
#include "collaborativeEditing_global.h"

class COLLABORATIVE_EDITING_EXPORT InitialSyncRequest : public HttpRequest
{
public:
    InitialSyncRequest();
    bool isValid() const override;
    QJsonDocument toJson() const override;
    QByteArray toByteArray() const override;
    QString clientId() const override;
};
#endif // INITIALSYNCREQUEST_H
