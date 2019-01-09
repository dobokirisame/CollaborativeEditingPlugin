#ifndef OUTPUTPANE_H
#define OUTPUTPANE_H

#include <QObject>
#include <coreplugin/ioutputpane.h>
#include <QPlainTextEdit>
#include <memory>
#include "collaborativeEditing_global.h"

namespace Core {
class IEditor;
} //namespace Core
class QTextEdit;
namespace collaborativeEditing {
namespace gui {
class COLLABORATIVE_EDITING_EXPORT OutputPane : public Core::IOutputPane
{
    Q_OBJECT
public:
    explicit OutputPane(QObject *parent = nullptr);
    QWidget *outputWidget(QWidget *parent) override;
    QList<QWidget *> toolBarWidgets() const override;
    QString displayName() const override;
    int priorityInStatusBar() const override;
    void clearContents() override;
    void visibilityChanged(bool visible) override;
    void setFocus() override;
    bool hasFocus() const override;
    bool canFocus() const override;
    bool canNavigate() const override;
    bool canNext() const override;
    bool canPrevious() const override;
    void goToNext() override;
    void goToPrev() override;
    
public slots:
    void updatePane();
private slots:
    void onCurrentEditorChanged(Core::IEditor *editor);
    void onEditorAboutToClose(Core::IEditor *editor);
    void onLocalTextChanged();
private:
    void disconnectDocument();
    void updateEditorConnections();
private:
    std::unique_ptr<QPlainTextEdit> mOutput;
    Core::IEditor *mCurrentEditor;
    QByteArray mData;
};
} //namespace gui
} //namespace collaborativeEditing

#endif // OUTPUTPANE_H
