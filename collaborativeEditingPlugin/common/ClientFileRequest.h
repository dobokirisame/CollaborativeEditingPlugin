#ifndef CLIENTFILEREQUEST_H
#define CLIENTFILEREQUEST_H
#include "HttpRequest.h"

class ClientFileRequest : public HttpRequest
{
public:
    ClientFileRequest();
    bool isValid() const override;
    QJsonDocument toJson() const override;
    QByteArray toByteArray() const override;
    QString clientId() const override;
};

#endif // CLIENTFILEREQUEST_H
