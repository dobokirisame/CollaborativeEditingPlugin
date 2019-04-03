#include "SyncQueue.h"
#include "Storage.h"

namespace collaborativeEditing {
namespace common {

SyncQueue::SyncQueue(Storage *storage)
    : mStorage(storage) {
    generateRequests();
}

bool SyncQueue::hasSyncRequest() const {
    return !mRequests.empty();
}

SyncRequest SyncQueue::takeNextSyncRequest() {
    auto result = mRequests.back();
    mRequests.pop_back();
    return result;
}

void SyncQueue::generateRequests() {
    mRequests.clear();
    if(mStorage == nullptr) {
        return;
    }
    // TODO(dobokirisame) add implementation
}


} //namespace common
} //namespace collaborativeEditing
