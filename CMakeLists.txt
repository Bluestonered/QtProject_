cmake_minimum_required(VERSION 3.21)
project(QtProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(QtProject main.cpp View/StartWindow.cpp View/MainWindow.cpp View/MyGraphicsView.cpp Controller/SlotController.cpp Model/SlotModel.cpp)
target_link_libraries(QtProject
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )
