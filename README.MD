# Collaborative Editing Plugin

-----
Work in progress
-----

[![Build Status](https://travis-ci.com/dobokirisame/CollaborativeEditingPlugin.svg?branch=master)](https://travis-ci.com/dobokirisame/CollaborativeEditingPlugin)


-----
Building project
-----

To build project you need to get qt creator's source files

#### Example for linux:

```bash
cd  /opt
wget http://download.qt.io/official_releases/qtcreator/4.8/4.8.0/qt-creator-opensource-src-4.8.0.tar.gz
tar -xf ./qt-creator-opensource-src-4.8.0.tar.gz
```
If you use custom compiler or need to specify build environmet update custom_environmet in 3rd-party/src folder
Template file is in that folder. Just copy it and edit with name custom_environmet.

#### Build process:

```bash
git clone git@github.com:dobokirisame/CollaborativeEditingPlugin.git
cd CollaborativeEditingPlugin
git submodule sync --recursive
git submodule update --init --recursive
git submodule update --init --recursive --remote
cd 3rd-party
./build_third_party.sh
cd ..
touch qt_deps.pri
echo "QTC_SOURCE = /opt/qt-creator-opensource-src-4.8.0" > qt_deps.pri
echo "QTC_BUILD = /opt/qt512" >> qt_deps.pri
echo "LIBS+=-L/opt/qtcreator/lib/qtcreator/ -L/opt/qtcreator/lib/qtcreator/plugins" >> qt_deps.pri
qmake collaborativeEditingPlugin.pro
make
```
