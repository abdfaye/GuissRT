#-------------------------------------------------
#
# Project created by QtCreator 2016-02-25T09:57:47
#
#-------------------------------------------------

QT       += qml gui quick widgets multimedia xml network xmlpatterns network

QT_XCB_GL_INTEGRATION=xcb_egl

CONFIG += qt c++11

TARGET = GuissRT
TEMPLATE = app

CONFIG -= console

#QMAKE_CXXFLAGS_RELEASE -= -O
#QMAKE_CXXFLAGS_RELEASE -= -O1
#QMAKE_CXXFLAGS_RELEASE -= -O2

#QMAKE_CXXFLAGS_RELEASE *= -O3

#CONFIG += link_pkgconfig
#PKGCONFIG += opencv

win32{
LIBS += -lopencv_core310 -lopencv_highgui310 -lopencv_imgproc310 -lopencv_video310 -lopencv_videoio310
}


#android {
##    LIBS += -L$$PWD/android-sources/libs/armeabi-v7a -lvlcjni
#    LIBS +=  -llibtiff\
#        -llibjpeg\
#        -llibjasper\
#        -llibpng\
#        -lIlmImf\
#        -ltbb\
#        -lopencv_core\
#        -lopencv_imgcodecs\
#        -lopencv_flann\
#        -lopencv_imgproc\
#        -lopencv_highgui\
#        -lopencv_features2d\
#        -lopencv_calib3d\
#        -lopencv_ml\
#        -lopencv_objdetect\
#        -lopencv_video\
#         -lopencv_videoio\
#        -lopencv_photo\
#        -lopencv_java3\
#        -lopencv_shape\
#        -lopencv_stitching\
#        -lopencv_superres\
#        -lopencv_ts\
#        -lopencv_videostab\
#        -lvlcjni \
#        -lvlc
#}


SOURCES += main.cpp \
    capture.cpp \
    converter.cpp \
    imageviewer.cpp \
    imageprovider.cpp \
    servoclient.cpp \
    libONVIF/client.cpp \
    libONVIF/devicemanagement.cpp \
    libONVIF/devicesearcher.cpp \
    libONVIF/mediamanagement.cpp \
    libONVIF/message.cpp \
    libONVIF/messageparser.cpp \
    libONVIF/ptzmanagement.cpp \
    libONVIF/service.cpp \
    libONVIF/device_management/capabilities.cpp \
    libONVIF/device_management/networkinterfaces.cpp \
    libONVIF/device_management/networkprotocols.cpp \
    libONVIF/device_management/systemdateandtime.cpp \
    libONVIF/device_management/systemfactorydefault.cpp \
    libONVIF/device_management/systemreboot.cpp \
    libONVIF/device_management/user.cpp \
    libONVIF/media_management/audioencoderconfiguration.cpp \
    libONVIF/media_management/audioencoderconfigurationoptions.cpp \
    libONVIF/media_management/audioencoderconfigurations.cpp \
    libONVIF/media_management/audiosourceconfiigurations.cpp \
    libONVIF/media_management/profile.cpp \
    libONVIF/media_management/profiles.cpp \
    libONVIF/media_management/streamuri.cpp \
    libONVIF/media_management/videoencoderconfiguration.cpp \
    libONVIF/media_management/videoencoderconfigurationoptions.cpp \
    libONVIF/media_management/videoencoderconfigurations.cpp \
    libONVIF/media_management/videosourceconfiguration.cpp \
    libONVIF/media_management/videosourceconfigurations.cpp \
    libONVIF/ptz_management/absolutemove.cpp \
    libONVIF/ptz_management/configuration.cpp \
    libONVIF/ptz_management/configurations.cpp \
    libONVIF/ptz_management/continuousmove.cpp \
    libONVIF/ptz_management/gotohomeposition.cpp \
    libONVIF/ptz_management/gotopreset.cpp \
    libONVIF/ptz_management/node.cpp \
    libONVIF/ptz_management/nodes.cpp \
    libONVIF/ptz_management/preset.cpp \
    libONVIF/ptz_management/presets.cpp \
    libONVIF/ptz_management/relativemove.cpp \
    libONVIF/ptz_management/removepreset.cpp \
    libONVIF/ptz_management/stop.cpp \
    myserver.cpp \
    ctxprovider.cpp \
    ctxsender.cpp \
    captureqt.cpp

HEADERS  += \
    capture.h \
    converter.h \
    imageviewer.h \
    imageprovider.h \
    servoclient.h \
    libONVIF/client.h \
    libONVIF/devicemanagement.h \
    libONVIF/devicesearcher.h \
    libONVIF/mediamanagement.h \
    libONVIF/message.h \
    libONVIF/messageparser.h \
    libONVIF/ptzmanagement.h \
    libONVIF/service.h \
    libONVIF/device_management/capabilities.h \
    libONVIF/device_management/networkinterfaces.h \
    libONVIF/device_management/networkprotocols.h \
    libONVIF/device_management/systemdateandtime.h \
    libONVIF/device_management/systemfactorydefault.h \
    libONVIF/device_management/systemreboot.h \
    libONVIF/device_management/user.h \
    libONVIF/media_management/audioencoderconfiguration.h \
    libONVIF/media_management/audioencoderconfigurationoptions.h \
    libONVIF/media_management/audioencoderconfigurations.h \
    libONVIF/media_management/audiosourceconfigurations.h \
    libONVIF/media_management/profile.h \
    libONVIF/media_management/profiles.h \
    libONVIF/media_management/streamuri.h \
    libONVIF/media_management/videoencoderconfiguration.h \
    libONVIF/media_management/videoencoderconfigurationoptions.h \
    libONVIF/media_management/videoencoderconfigurations.h \
    libONVIF/media_management/videosourceconfiguration.h \
    libONVIF/media_management/videosourceconfigurations.h \
    libONVIF/ptz_management/absolutemove.h \
    libONVIF/ptz_management/configuration.h \
    libONVIF/ptz_management/configurations.h \
    libONVIF/ptz_management/continuousmove.h \
    libONVIF/ptz_management/gotohomeposition.h \
    libONVIF/ptz_management/gotopreset.h \
    libONVIF/ptz_management/node.h \
    libONVIF/ptz_management/nodes.h \
    libONVIF/ptz_management/preset.h \
    libONVIF/ptz_management/presets.h \
    libONVIF/ptz_management/relativemove.h \
    libONVIF/ptz_management/removepreset.h \
    libONVIF/ptz_management/stop.h \
    myserver.h \
    ctxprovider.h \
    ctxsender.h \
    captureqt.h

OTHER_FILES += \
    main.qml

RESOURCES += \
    qml.qrc

#DISTFILES += \
#    android/AndroidManifest.xml \
#    android/gradle/wrapper/gradle-wrapper.jar \
#    android/gradlew \
#    android/res/values/libs.xml \
#    android/build.gradle \
#    android/gradle/wrapper/gradle-wrapper.properties \
#    android/gradlew.bat

#ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android




