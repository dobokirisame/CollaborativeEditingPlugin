#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
namespace collaborativeEditing {
namespace common {
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
};
} //namespace common
} //namespace collaborativeEditing


#endif // CLIENT_H
