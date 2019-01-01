#include "CollaborativeEditingPlugin.h"


#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <projectexplorer/projectpanelfactory.h>

#include <QAction>
#include <QMainWindow>
#include <QMenu>
#include <QSettings>
#include <QProcess>
#include <QFile>
#include <QDir>

namespace collaborativeEditing {
namespace core {

bool CollaborativeEditingPlugin::initialize(const QStringList &arguments, QString *errorString) {

}

void CollaborativeEditingPlugin::extensionsInitialized() {
}

ExtensionSystem::IPlugin::ShutdownFlag CollaborativeEditingPlugin::aboutToShutdown() {
	return SynchronousShutdown;
}

}
}
