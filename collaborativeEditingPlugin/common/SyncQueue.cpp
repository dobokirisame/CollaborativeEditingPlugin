#include "SyncQueue.h"
#include "Storage.h"

namespace collaborativeEditing {
namespace common {

SyncQueue::SyncQueue(Storage *storage)
    : mStorage(storage){
}

bool SyncQueue::hasSyncRequest() const {

}

SyncRequest SyncQueue::nextSyncRequest() const {

}


} //namespace common
} //namespace collaborativeEditing
