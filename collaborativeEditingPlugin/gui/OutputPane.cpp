#include "OutputPane.h"
#include <projectexplorer/projectexplorer.h>
#include <projectexplorer/projectmanager.h>
#include <projectexplorer/projectmodels.h>
#include <coreplugin/editormanager/editormanager.h>
#include <coreplugin/editormanager/ieditor.h>
#include <QTextCodec>
#include <iostream>
#include <LCS/diff_match_patch.h>

namespace collaborativeEditing {
namespace gui {
OutputPane::OutputPane(QObject *parent)
    : Core::IOutputPane(parent),
    mOutput(std::make_unique<QPlainTextEdit>()) {
    mCurrentEditor = Core::EditorManager::currentEditor();
    connect(Core::EditorManager::instance(), &Core::EditorManager::currentEditorChanged,
            this, &OutputPane::onCurrentEditorChanged);
    connect(Core::EditorManager::instance(), &Core::EditorManager::editorAboutToClose,
            this, &OutputPane::onEditorAboutToClose);
    connect(mOutput.get(), &QPlainTextEdit::textChanged,
            this, &OutputPane::onLocalTextChanged);
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
    if(mCurrentEditor == nullptr || mCurrentEditor->document() == nullptr) {
        clearContents();
        return;
    }
    auto source = mCurrentEditor->document()->contents();
    auto unicodeSource = QTextCodec::codecForMib(106)->toUnicode(source);
    auto cursor = mOutput->textCursor();
    mOutput->setPlainText(unicodeSource);
    //    mOutput->setTextCursor()
}

void OutputPane::onCurrentEditorChanged(Core::IEditor *editor) {
    if(mCurrentEditor != nullptr) {
        disconnectDocument();
    }
    if(editor == nullptr) {
        return;
    }
    mCurrentEditor = editor;
    updateEditorConnections();
}

void OutputPane::onEditorAboutToClose(Core::IEditor *editor) {
    if(mCurrentEditor == editor) {
        disconnectDocument();
        mCurrentEditor = nullptr;
    }
}

void OutputPane::onLocalTextChanged() {
    QString diff;
    QString sourceData = QString::fromUtf8(mData);
    std::set_difference(sourceData.begin(), sourceData.end(), mOutput->toPlainText().begin(), mOutput->toPlainText().end(),
                            std::back_inserter(diff));
    puts(diff.toStdString().c_str());
}

void OutputPane::disconnectDocument() {
//    mOutput->blockSignals(true);
    if(mCurrentEditor->document() != nullptr) {
        disconnect(mCurrentEditor->document(), &Core::IDocument::contentsChanged,
                this, &OutputPane::updatePane);
    }
}

void OutputPane::updateEditorConnections() {
    mData.clear();
    if(mCurrentEditor == nullptr || mCurrentEditor->document() == nullptr) {
        return;
    }
    mData = mCurrentEditor->document()->contents();
    connect(mCurrentEditor->document(), &Core::IDocument::contentsChanged,
            this, &OutputPane::updatePane);
    updatePane();
//    mOutput->blockSignals(false);
}

} //namespace gui
} //namespace collaborativeEditing
