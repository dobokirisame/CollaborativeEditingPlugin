#ifndef CLIENTFILEREQUEST_H
#define CLIENTFILEREQUEST_H
#include "HttpRequest.h"
#include "collaborativeEditing_global.h"
namespace collaborativeEditing {
namespace common {
class COLLABORATIVE_EDITING_EXPORT ClientFileRequest : public HttpRequest
{
public:
    ClientFileRequest();
    bool isValid() const override;
    QJsonDocument toJson() const override;
    QByteArray toByteArray() const override;
    QString clientId() const override;
};

} //namespace common
} //namespace collaborativeEditing
#endif // CLIENTFILEREQUEST_H
