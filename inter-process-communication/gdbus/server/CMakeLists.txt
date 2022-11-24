cmake_minimum_required (VERSION 2.6)
project (gdbus-sample-server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FindPkgConfig)
pkg_check_modules(GIOMM REQUIRED giomm-2.4)
pkg_check_modules(GLIBMM REQUIRED glibmm-2.4)

# ----------------------------------------
# generate glibmm code
# ----------------------------------------
set(GDBUS_CODEGEN_CMD gdbus-codegen-glibmm3)
set(GDBUS_CODEGEN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../gdbus-gen")

set(SAMPLE_DATA_XML "${CMAKE_CURRENT_SOURCE_DIR}/../idl/SampleData.xml")
set(SAMPLE_DATA_GEN_CODE
    ${GDBUS_CODEGEN_DIR}/SampleData_common.cpp
    ${GDBUS_CODEGEN_DIR}/SampleData_proxy.cpp
    ${GDBUS_CODEGEN_DIR}/SampleData_stub.cpp
)
set(SAMPLE_DATA_GEN_HEADER
    ${GDBUS_CODEGEN_DIR}/SampleData_common.h
    ${GDBUS_CODEGEN_DIR}/SampleData_proxy.h
    ${GDBUS_CODEGEN_DIR}/SampleData_stub.h
)
add_custom_command(OUTPUT ${SAMPLE_DATA_GEN_CODE}
                    COMMAND mkdir -p ${GDBUS_CODEGEN_DIR}
                    COMMAND ${GDBUS_CODEGEN_CMD} --generate-cpp-code=${GDBUS_CODEGEN_DIR}/SampleData ${SAMPLE_DATA_XML}
                    DEPENDS ${SAMPLE_DATA_XML}
)

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
    ${CMAKE_CURRENT_SOURCE_DIR}/SampleDataServer.cpp
    ${GDBUS_CODEGEN_DIR}/SampleData_common.cpp
    ${GDBUS_CODEGEN_DIR}/SampleData_stub.cpp
)

target_link_libraries(${PROJECT_NAME}
    ${GLIBMM_LDFLAGS}
    ${GIOMM_LDFLAGS}
    ${GIO_LDFLAGS}
)

install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build
)