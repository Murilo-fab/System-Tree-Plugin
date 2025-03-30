## Plugin - System Tree Visualizer - JSON


CUBEGUI_CONFIG = /home/murilo/cube/bin/cubegui/bin/cubegui-config
CUBELIB_CONFIG = /home/murilo/cube/bin/cubelib/bin/cubelib-config

INCLUDEPATH    += $$system($$CUBEGUI_CONFIG --include) $$system($$CUBELIB_CONFIG --include)
LIBS           += $$system($$CUBEGUI_CONFIG --ldflags) $$system($$CUBEGUI_CONFIG --libs) \
                  $$system($$CUBELIB_CONFIG --ldflags) $$system($$CUBELIB_CONFIG --libs)

TEMPLATE        = lib
CONFIG         += plugin
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS         = SystemTree.h
SOURCES         = SystemTree.cpp
TARGET          = $$qtLibraryTarget(SystemTree)