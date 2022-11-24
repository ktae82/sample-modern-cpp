cmake_minimum_required (VERSION 2.6)
project (gdbus-sample-client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FindPkgConfig)
find_package(Threads REQUIRED)
pkg_check_modules(GIOMM REQUIRED giomm-2.4)
pkg_check_modules(GLIBMM REQUIRED glibmm-2.4)

set(GDBUS_CODEGEN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../gdbus-gen")

# ----------------------------------------
# build
# ----------------------------------------
include_directories(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${GLIBMM_INCLUDE_DIRS}
    ${GIOMM_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SampleDataClient.cpp
    ${GDBUS_CODEGEN_DIR}/SampleData_common.cpp
    ${GDBUS_CODEGEN_DIR}/SampleData_proxy.cpp
)

target_link_libraries(${PROJECT_NAME}
    ${GLIBMM_LDFLAGS}
    ${GIOMM_LDFLAGS}
    Threads::Threads
)

install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build
)