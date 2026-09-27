cmake_minimum_required(VERSION 3.21)

project(ChessTraining VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(chess
    src/main.cpp
    src/chess_types.h
    src/board.h
    src/board.cpp
    src/board_view.cpp
    src/board_view.h
)

target_link_libraries(chess PRIVATE Qt6::Widgets)