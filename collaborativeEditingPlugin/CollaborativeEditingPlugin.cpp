#include "CollaborativeEditingPlugin.h"
#include "gui/OutputPane.h"
#include <QAction>
#include <QMenu>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>

namespace collaborativeEditing {
namespace core {

bool CollaborativeEditingPlugin::initialize(const QStringList &arguments, QString *errorString) {
    Q_UNUSED(arguments);
    Q_UNUSED(errorString);
    mOutputPane = new gui::OutputPane(this);
    auto action = new QAction(QIcon("000"), tr("Update Collaborative Editor"), this);
    Core::Command *cmd = Core::ActionManager::registerAction(action, "Collaborative.Action",
                                                             Core::Context(Core::Constants::C_GLOBAL));
    connect(action, &QAction::triggered, mOutputPane, &gui::OutputPane::updatePane);

    Core::ActionContainer *menu = Core::ActionManager::createMenu("Collaborative.Menu");
    menu->menu()->setTitle(tr("Collaborative Editor"));
    menu->addAction(cmd);
    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);
    return true;
}

void CollaborativeEditingPlugin::extensionsInitialized() {
}

ExtensionSystem::IPlugin::ShutdownFlag CollaborativeEditingPlugin::aboutToShutdown() {
	return SynchronousShutdown;
}

} // namespace core
} // namespace collaborativeEditing
