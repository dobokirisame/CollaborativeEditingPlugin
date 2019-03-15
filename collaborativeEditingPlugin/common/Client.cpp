#include "Client.h"
#include <iostream>
#include <string>
#include <LCS/diff_match_patch.h>

namespace collaborativeEditing {
namespace common {
Client::Client(QObject *parent)
    :QObject(parent){
}

void Client::sendChanged(const std::string &patch) {
    auto changes = generateClientChanges(patch);
}

void Client::sendCursiorPosition() {

}

void Client::onClientChangesReceived(const ClientChanges &changes) {
    if(mStorage == nullptr) {
        std::cerr << "Could not find local storage";
        return;
    }
    if(!canApplyClientChanges(changes)) {
        return;
    }
    mStorage->applyClientChanges(changes);
}

void Client::onClientCursorPositionReceived(const ClientCursorPostion &pos) {

}

void Client::onLocalTextChanges(const QString &text) {
    if(mStorage == nullptr) {
        std::cerr << "Could not find local storage";
        return;
    }
    const auto sourceData = mStorage->sourceText(mCurrentFilePath);
    diff_match_patch<std::string> tmp;
    auto patches = tmp.patch_make(sourceData.toStdString(), text.toStdString());
    diff_match_patch<std::string>::patch_toText(patches);
    for(const auto &patch : patches) {
        if(!patch.isNull()) {
            sendChanged(patch.toString());
        }
    }
}

bool Client::canApplyClientChanges(const ClientChanges &changes) const {
    return changes.clientId() != clientId();
}

ClientChanges Client::generateClientChanges(const std::string &patch) const {
    if(mStorage == nullptr) {
        std::cerr << "Could not find local storage";
        return {};
    }
    ClientChanges result;
    result.setClientId(mClientId);
    result.setFilePath(mCurrentFilePath);
    result.setPatchesText(patch);
    result.setProjectName(mStorage->currentProject());
    return result;
}

QString Client::clientId() const {
    return mClientId;
}

} //namespace common
} //namespace collaborativeEditing
