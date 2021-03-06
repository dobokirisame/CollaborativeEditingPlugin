#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include <QJsonDocument>
#include <QByteArray>
#include <QString>

namespace collaborativeEditing {
namespace common {
class HttpRequest {
public:
    virtual ~HttpRequest() = default;
    virtual bool isValid() const = 0;
    virtual QJsonDocument toJson() const = 0;
    virtual QByteArray toByteArray() const = 0;
    virtual QString clientId() const = 0;
};
} //namespace common
} //namespace collaborativeEditing
#endif // HTTPREQUEST_H
