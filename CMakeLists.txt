cmake_minimum_required(VERSION 3.10)

project(QtTemplate)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(GetGitRevisionDescription)
git_describe(GIT_VERSION --always --dirty)
configure_file(git_version.h.in git_version.h)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc and uic automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(Qt5 COMPONENTS Core Widgets)

set(SOURCES
    main.cpp
    mainwindow.cpp
)

set(UIFORMS
    mainwindow.ui
)
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${UIFORMS}
)
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Widgets
)
