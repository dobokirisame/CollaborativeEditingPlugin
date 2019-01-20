#include "Client.h"
#include <LCS/diff_match_patch.h>
#include <iostream>
#include <string>

namespace collaborativeEditing {
namespace common {
Client::Client(QObject *parent)
    :QObject(parent){
}

void Client::sendChanged() {

}

void Client::sendCursiorPosition() {

}

void Client::onClientChangesReceived(const ClientChanges &changes) {

}

void Client::onClientCursorPositionReceived(const ClientCursorPostion &pos) {

}

void Client::applyClientChanges(const ClientChanges &changes) {
    if(!changes.isValid() || !canApplyClientChanges(changes)) {
        return;
    }
    diff_match_patch<std::string> tmp;
    std::list<diff_match_patch<std::string>::Patch> patches;
    try {
        patches = tmp.patch_fromText(changes.patchesText());
    } catch (...) {
        std::cerr << "Invalid patch string";
    }
    auto result = tmp.patch_apply(patches, mCurrentFileText.toStdString());
}

bool Client::canApplyClientChanges(const ClientChanges &changes) const {
    return changes.clientId() != clientId();
}

ClientChanges Client::generateClientChanges() const {
    return ClientChanges();
}

QString Client::clientId() const {
    return mClientId;
}

QString Client::currentFileText() const {
    return mCurrentFileText;
}

void Client::setCurrentFileText(const QString &currentFileText) {
    mCurrentFileText = currentFileText;
}
} //namespace common
} //namespace collaborativeEditing
