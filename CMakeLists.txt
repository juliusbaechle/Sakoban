cmake_minimum_required(VERSION 3.16)

##### CMake Project name & version #####
set(PROJECT Sakoban)
project(${PROJECT}_Project VERSION 0.0.0 LANGUAGES CXX C)

# Build Type check
if(CMAKE_BUILD_TYPE MATCHES Debug)
  message("-- Debug build")
elseif(CMAKE_BUILD_TYPE MATCHES Release)
  message("-- Release build")
else()
  message("-- Some other build type")
endif()

##### Global CMake variables are set here #####
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)

##### Options #####
option(ENABLE_WARNINGS "Enable to add warnings to a target." OFF)
option(ENABLE_TESTING "Enable a Unit Testing build." OFF)
option(ENABLE_COVERAGE "Enable a Code Coverage build." OFF)
option(ENABLE_BENCHMARKING "Enable a benchmark build." OFF)
option(ENABLE_LTO "Enable Link Time Optimization (LTO)." OFF)
option(ENABLE_DOXYGEN "Enable documentation project." OFF)
option(DEVELOP "Stylesheet relative to project or to executable" OFF)

##### Deployment #####
if (NOT DEPLOY_DIR)
    set(DEPLOY_DIR "${PROJECT_BINARY_DIR}/_output")
    message("-- ${PROJECT}: Deploys to \"${DEPLOY_DIR}\"")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DEPLOY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${DEPLOY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${DEPLOY_DIR}/arc)

##### CMake modules #####
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
# Qt Configuration
include(Qt/QtConfiguration) # comment out if Qt not needed
# Common defines
include(Defines_Common)
##### CMake modules - sources #####
include(Sources_Common)
##### CMake modules - libs #####
include(Libs)

##### Project/Library Names #####
set(APP ${PROJECT})
set(EXTERNAL_LIB ExternalLib)
set(UNIT_TESTS_APP ${PROJECT}_UnitTests)
set(CODE_COVERAGE_APP ${PROJECT}_CodeCoverage)
set(BENCHMARK_APP ${PROJECT}_Benchmarks)

##### Add first-party libraries #####
add_executable(${PROJECT} ${SOURCES_COMMON} icons/sakoban.rc)
target_include_directories(${PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(${PROJECT} PUBLIC ${LIBS_ALL} ${PROJECT_LIB})

if(DEVELOP)
  target_compile_definitions(${PROJECT} PRIVATE STYLESHEET_PATH="${PROJECT_SOURCE_DIR}/src/style.qss")
else()
  target_compile_definitions(${PROJECT} PRIVATE STYLESHEET_PATH="style.qss")
  file(COPY "src/style.qss" DESTINATION ${DEPLOY_DIR})
endif()

if(NOT UNIX)
  target_link_options(${PROJECT} PRIVATE -mwindows)
endif()
