#ifndef SYNCQUEUE_H
#define SYNCQUEUE_H
#include "collaborativeEditing_global.h"
#include "SyncRequest.h"

namespace collaborativeEditing {
namespace common {
class Storage;
class COLLABORATIVE_EDITING_EXPORT SyncQueue final
{
public:
    explicit SyncQueue(Storage *storage);
    SyncQueue() = default;
    bool hasSyncRequest() const;
    SyncRequest nextSyncRequest() const;
private:
    Storage *mStorage;
};
} //namespace common
} //namespace collaborativeEditing
#endif // SYNCQUEUE_H
