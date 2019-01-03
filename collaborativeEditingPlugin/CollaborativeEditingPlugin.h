#pragma once

#include <memory>
#include "collaborativeEditing_global.h"
#include <extensionsystem/iplugin.h>

namespace collaborativeEditing {
namespace gui {
class OutputPane;
} //namespace gui
namespace core {

class COLLABORATIVE_EDITING_EXPORT CollaborativeEditingPlugin : public ExtensionSystem::IPlugin
{
	Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "CollaborativeEditing.json")

public:
    CollaborativeEditingPlugin() = default;
    bool initialize(const QStringList &arguments, QString *errorString) override;
    void extensionsInitialized() override;
    ShutdownFlag aboutToShutdown() override;
private:
    gui::OutputPane *mOutputPane;
};

} // namespace core
} // namespace collaborativeEditing
