#include "Storage.h"
#include <projectexplorer/projectexplorer.h>
#include <projectexplorer/project.h>
#include <coreplugin/documentmanager.h>
#include <coreplugin/editormanager/editormanager.h>
#include <coreplugin/editormanager/ieditor.h>

namespace collaborativeEditing {
namespace common {

QStringList Storage::openedProjects() const {
    return {};
}

} //namespace common
} //namespace collaborativeEditing
