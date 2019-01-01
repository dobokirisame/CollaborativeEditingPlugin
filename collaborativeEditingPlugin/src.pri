PROJECT_ROOT = $$PWD/..

CONFIG(debug, debug|release) {
        DIR_OUTPUT = $$PROJECT_ROOT/build/debug
        DEFINES += COMPILER_EXPLORER_DEBUG
}
CONFIG(release, debug|release) {
        DIR_OUTPUT = $$PROJECT_ROOT/build/release
}
DESTDIR = $$DIR_OUTPUT
OBJECTS_DIR = $$DESTDIR/.obj/$$PROJECTFILENAME
MOC_DIR = $$DESTDIR/.moc/$$PROJECTFILENAME
UI_DIR = $$DESTDIR/.ui/$$PROJECTFILENAME
RCC_DIR = $$DESTDIR/.res/$$PROJECTFILENAME

unix: CONFIG += c++14
mingw: QMAKE_CXXFLAGS += -std=gnu++14
