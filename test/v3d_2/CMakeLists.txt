cmake_minimum_required(VERSION 3.16)

project(v3d_2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appv3d_2
    main.cpp
)

set(IMG
    ./misc/rotate.png
    ./misc/3d-cube.png
    ./misc/vectors.png
    ./misc/arrow.png
)

qt_add_qml_module(appv3d_2
    URI v3d_2
    VERSION 1.0
    QML_FILES main.qml
    RESOURCES ${IMG}
)

set_target_properties(appv3d_2 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(appv3d_2
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(appv3d_2
    PRIVATE Qt6::Quick)
