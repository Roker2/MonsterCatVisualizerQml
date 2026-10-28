cmake_minimum_required(VERSION 3.16)

project(MonsterCatVisualizerQml VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.10)

include(FetchContent)

FetchContent_Declare(
  MonsterCatVisualizerBase
  GIT_REPOSITORY https://github.com/Roker2/MonsterCatVisualizerBase.git
  EXCLUDE_FROM_ALL)
FetchContent_MakeAvailable(MonsterCatVisualizerBase)

# Content of downloaded design from Figma to Qt or similar
if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/importedcontent/CMakeLists.txt")
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/importedcontent)
endif()

qt_add_executable(appMonsterCatVisualizerQml
    main.cpp
)

qt_add_qml_module(appMonsterCatVisualizerQml
    URI MonsterCatVisualizerQml
    QML_FILES
        Main.qml
        SOURCES particlesListModel.h particlesListModel.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appMonsterCatVisualizerQml PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appMonsterCatVisualizerQml
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMonsterCatVisualizerQml
    PRIVATE Qt6::Quick Qt6::Core MonsterCatVisualizerBase
)

install(TARGETS appMonsterCatVisualizerQml
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
