TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp


QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    ring_queue_template.h \
    ring_queue.h

