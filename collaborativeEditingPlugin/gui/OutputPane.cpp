#include "OutputPane.h"
#include <projectexplorer/projectexplorer.h>
#include <projectexplorer/projectmanager.h>
#include <projectexplorer/projectmodels.h>
#include <coreplugin/editormanager/editormanager.h>
#include <coreplugin/editormanager/ieditor.h>
#include <QTextCodec>

namespace collaborativeEditing {
namespace gui {
OutputPane::OutputPane(QObject *parent)
    : Core::IOutputPane(parent),
    mOutput(std::make_unique<QTextEdit>()) {
    mCurrentDocument = Core::EditorManager::currentDocument();
    connect(Core::EditorManager::instance(), &Core::EditorManager::currentDocumentStateChanged,
            this, [=] {
        if(mCurrentDocument!=nullptr) {
            disconnect(mCurrentDocument, &Core::IDocument::contentsChanged,
                    this, &OutputPane::updatePane);
        }
        mCurrentDocument = Core::EditorManager::currentDocument();
        connect(mCurrentDocument, &Core::IDocument::contentsChanged,
                this, &OutputPane::updatePane);
    });
}


QWidget *OutputPane::outputWidget(QWidget *parent) {
    Q_UNUSED(parent);
    return mOutput.get();
}

QList<QWidget *> OutputPane::toolBarWidgets() const {
    return {};
}

QString OutputPane::displayName() const {
    return QString("Collaborative Editor");
}

int OutputPane::priorityInStatusBar() const {
    return 1;
}

void OutputPane::clearContents() {
    mOutput->clear();
}

void OutputPane::visibilityChanged(bool visible) {
    Q_UNUSED(visible);
}

void OutputPane::setFocus() {
    mOutput->setFocus();
}

bool OutputPane::hasFocus() const {
    return mOutput->hasFocus();
}

bool OutputPane::canFocus() const {
    return true;
}

bool OutputPane::canNavigate() const {
    return false;
}

bool OutputPane::canNext() const {
    return false;
}

bool OutputPane::canPrevious() const {
    return false;
}

void OutputPane::goToNext() {
}

void OutputPane::goToPrev() {
}

void OutputPane::updatePane() {
    if(mCurrentDocument == nullptr) {
        clearContents();
        return;
    }
    auto source = mCurrentDocument->contents();
    auto unicodeSource = QTextCodec::codecForMib(106)->toUnicode(source);
    mOutput->setText(unicodeSource);
    return;
}
} //namespace gui
} //namespace collaborativeEditing
