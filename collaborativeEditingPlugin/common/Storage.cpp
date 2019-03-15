#include "Storage.h"
#include <projectexplorer/projectexplorer.h>
#include <projectexplorer/project.h>
#include <coreplugin/documentmanager.h>
#include <coreplugin/editormanager/editormanager.h>
#include <coreplugin/editormanager/ieditor.h>
#include <LCS/diff_match_patch.h>
#include <iostream>

namespace collaborativeEditing {
namespace common {

QStringList Storage::openedProjects() const {
    return {};
}

void Storage::applyClientChanges(const ClientChanges &changes) {
    if(!changes.isValid()) {
        return;
    }
    diff_match_patch<std::string> tmp;
    std::list<diff_match_patch<std::string>::Patch> patches;
    try {
        patches = tmp.patch_fromText(changes.patchesText());
    } catch (...) {
        std::cerr << "Invalid patch string";
    }
    auto currentFileText = sourceText(changes.filePath());
    auto result = tmp.patch_apply(patches, currentFileText.toStdString());
    updateText(changes.filePath());
}

QString Storage::sourceText(const QString &filePath) const {
    // TODO(dobokirisame) add implementation
}

void Storage::updateText(const QString &filePath) {
    // TODO(dobokirisame) add implementation
}

} //namespace common
} //namespace collaborativeEditing
