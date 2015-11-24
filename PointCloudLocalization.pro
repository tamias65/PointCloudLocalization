TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    odomdata.cpp \
    laserdata.cpp \
    parsedata.cpp

INCLUDEPATH += /usr/local/opencv/build/include/opencv2
LIBS += `pkg-config opencv –cflags –libs`

or

INCLUDEPATH += /usr/local/opencv/build/include/opencv2
LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann

HEADERS += \
    odomdata.h \
    laserdata.h \
    parsedata.h
