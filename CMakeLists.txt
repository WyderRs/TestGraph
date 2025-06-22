cmake_minimum_required(VERSION 3.16)

project(TestGraph LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Quick Widgets)
message("Qt version: Qt" ${QT_VERSION_MAJOR})


add_executable(TestGraph
  main.cpp
)
qt_add_qml_module(TestGraph
    URI path
    VERSION 1.0
    QML_FILES main.qml
    SOURCES wControl.h wControl.cpp
)


target_link_libraries(TestGraph
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Widgets
)

set_target_properties(TestGraph PROPERTIES
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS TestGraph
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
