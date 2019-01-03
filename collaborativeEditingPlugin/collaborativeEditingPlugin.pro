DEFINES += COLLABORATIVE_EDITING_LIBRARY
exists(qt_deps.pri) {
    include (qt_deps.pri)
}
QTC_PLUGIN_NAME = CollaborativeEditing
isEmpty(IDE_SOURCE_TREE): IDE_SOURCE_TREE = $$QTC_SOURCE
isEmpty(IDE_BUILD_TREE): IDE_BUILD_TREE = $$QTC_BUILD

QTC_LIB_DEPENDS += \
    extensionsystem

QTC_PLUGIN_DEPENDS += \
    coreplugin \
    projectexplorer

include($$IDE_SOURCE_TREE/src/qtcreatorplugin.pri)

include (src.pri)


USE_USER_DESTDIR = YES

QT += network

DISTFILES += \
    src.pri \
    *.json

SOURCES += \
    *.cpp \
    gui\*.cpp \
    common\*.cpp

HEADERS += \
    *.h \
    gui\*.h \
    common\*.h

#FORMS += \
#    *.ui

LISB +=-L$$IDE_BUILD_TREE/bin
LISB +=-L$$IDE_BUILD_TREE/lib
