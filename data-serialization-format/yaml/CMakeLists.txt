cmake_minimum_required (VERSION 2.6)
project (yaml-cpp-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories( ${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable( ${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ProductFactory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ProductList.cpp 
)

target_link_libraries( ${PROJECT_NAME}
    yaml-cpp
)

install(
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/data/products.yaml
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build
)
