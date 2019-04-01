#include "SyncQueue.h"
#include "Storage.h"

namespace collaborativeEditing {
namespace common {

SyncQueue::SyncQueue(Storage *storage)
    : mStorage(storage){
}

bool SyncQueue::hasSyncRequest() const {
    // TODO(dobokirisame) add implementation
    return false;
}

SyncRequest SyncQueue::nextSyncRequest() const {
    // TODO(dobokirisame) add implementation
    return SyncRequest(mStorage);
}


} //namespace common
} //namespace collaborativeEditing
