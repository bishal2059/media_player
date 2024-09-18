cmake_minimum_required(VERSION 3.29)
project(media_player)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/opt/Qt/Tools/QtDesignStudio/qt6_design_studio_reduced_version/lib/cmake/Qt6")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(media_player main.cpp)
target_link_libraries(media_player
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)

