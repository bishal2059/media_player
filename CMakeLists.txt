cmake_minimum_required(VERSION 3.16)
project(media_player)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "~/Qt/6.8.0/gcc_64/lib/cmake/Qt6")

# set(CMAKE_PREFIX_PATH <full/path/to/Qt/cmake/file>)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(Qt6Core_DIR "~/Qt/6.8.0/gcc_64/lib/cmake/Qt6Core")
set(Qt6_DIR "~/Qt/6.8.0/gcc_64/lib/cmake/Qt6")
set(QT_QMAKE_EXECUTABLE "~/Qt/6.8.0/gcc_64/bin/qmake")


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        MultimediaWidgets
        REQUIRED)

set(PROJECT_SOURCES
            main.cpp
            mainwindow.cpp
            mainwindow.h
            mainwindow.ui
)

add_executable(media_player ${PROJECT_SOURCES})


target_link_libraries(media_player
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Multimedia
        Qt6::MultimediaWidgets
)
