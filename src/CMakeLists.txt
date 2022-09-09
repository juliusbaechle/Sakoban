# Add Sources to the shared library (DLL/SO)
add_library(${PROJECT_LIB} SHARED ${SOURCES_COMMON})
# Copy include dir to target dir for further use

message("-- ${PROJECT}: Start publishing headers...")
file(GLOB_RECURSE HEADERS RELATIVE "${PROJECT_SOURCE_DIR}/src" "*.h")
foreach(HEADER ${HEADERS})
	get_filename_component(RELATIVE_DIR ${HEADER} DIRECTORY)
	file(COPY ${HEADER} DESTINATION ${DEPLOY_DIR}/include/${PROJECT}/${RELATIVE_DIR})
	message("Publishing " ${HEADER})
endforeach()
message("-- ${PROJECT}: ...publishing headers finished")

# Tell library where to find necessary header files to build library
#target_include_directories(${LIB} PUBLIC ${LIBRARY_INCLUDES})
target_include_directories(${PROJECT_LIB} PUBLIC ${INCLUDE_DIRS_COMMON})

# Add custom compile features
target_compile_features(${PROJECT_LIB} PUBLIC cxx_std_17)

# Link against libraries, e.g. nlohmann-json
target_link_libraries(${PROJECT_LIB} PUBLIC ${LIBS_ALL})

# Required for Qt dynamic libraries build
message("-- ${PROJECT}: WARNING - PLEASE EDIT (define BUILD_LIB_NAME_WITH_QT, libName_global.h, ) if you want to export Qt signals, refrence https://doc.qt.io/qt-5/sharedlibrary.html")
target_compile_definitions(${PROJECT_LIB} PRIVATE BUILD_LIB_NAME_WITH_QT)
