# definition of used Qt modules
set(Qt_Modules
 Core
 Gui
 Widgets
)

# add Qt modules
message("-- Either Qt5_DIR or CMAKE_PREFIX_PATH must be set")
message("-- Qt5_DIR must be e.g. \"Z:/qt5127/5.12.7/msvc2017/lib/cmake/Qt5\"")
message("-- Qt5_DIR is \"" ${Qt5_DIR} "\"")
message("-- (Qt5) CMAKE_PREFIX_PATH must be e.g. \"Z:/qt5127/5.12.7/msvc2017\"")
message("-- (Qt5) CMAKE_PREFIX_PATH is \"" ${CMAKE_PREFIX_PATH} "\"")

find_package(Qt5 COMPONENTS ${Qt_Modules} REQUIRED)

##### QML Import Path #####
if("${QML_LIBS_IMPORT_PATH}" STREQUAL "")
    set(QML_LIBS_IMPORT_PATH "${DEPLOY_DIR}/qml") # default path QML Modules
endif()
list(APPEND QML_DIRS "${QML_LIBS_IMPORT_PATH}")
set(QML_IMPORT_PATH "${QML_DIRS}" CACHE STRING "QML custom import path" FORCE)

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
