#ifndef PROJECTSTRUCTUREREQUEST_H
#define PROJECTSTRUCTUREREQUEST_H
#include "HttpRequest.h"
#include "collaborativeEditing_global.h"

namespace collaborativeEditing {
namespace common {
class COLLABORATIVE_EDITING_EXPORT ProjectStructureRequest : public HttpRequest
{
public:
    ProjectStructureRequest();
    bool isValid() const override;
    QJsonDocument toJson() const override;
    QByteArray toByteArray() const override;
    QString clientId() const override;
};
} //namespace common
} //namespace collaborativeEditing

#endif // PROJECTSTRUCTUREREQUEST_H
