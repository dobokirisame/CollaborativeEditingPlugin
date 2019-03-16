PROJECT_ROOT = $$PWD/..

CONFIG(debug, debug|release) {
        DIR_OUTPUT = $$PROJECT_ROOT/build/debug
        DEFINES += COLLABORATIVE_EDITING_DEBUG
}
CONFIG(release, debug|release) {
        DIR_OUTPUT = $$PROJECT_ROOT/build/release
}
DESTDIR = $$DIR_OUTPUT
OBJECTS_DIR = $$DESTDIR/.obj/$$PROJECTFILENAME
MOC_DIR = $$DESTDIR/.moc/$$PROJECTFILENAME
UI_DIR = $$DESTDIR/.ui/$$PROJECTFILENAME
RCC_DIR = $$DESTDIR/.res/$$PROJECTFILENAME

INCLUDEPATH += $$PROJECT_ROOT/3rd-party/out/include
LIBS += -L$$PROJECT_ROOT/3rd-party/out/lib
LIBS += -L$$PROJECT_ROOT/3rd-party/out/bin
LIBS += -lqhttp
DEFINES += QHTTP_HAS_CLIENT

unix: CONFIG += c++14
mingw: QMAKE_CXXFLAGS += -std=gnu++14
