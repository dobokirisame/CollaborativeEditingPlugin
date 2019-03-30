#ifndef FINISHINITIALSYNCREQUEST_H
#define FINISHINITIALSYNCREQUEST_H
#include "HttpRequest.h"
#include "collaborativeEditing_global.h"

namespace collaborativeEditing {
namespace common {
class COLLABORATIVE_EDITING_EXPORT FinishInitialSyncRequest : public HttpRequest
{
public:
    FinishInitialSyncRequest();
    bool isValid() const override;
    QJsonDocument toJson() const override;
    QByteArray toByteArray() const override;
    QString clientId() const override;
};

} //namespace common
} //namespace collaborativeEditing
#endif // FINISHINITIALSYNCREQUEST_H
