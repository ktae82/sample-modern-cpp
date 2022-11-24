cmake_minimum_required (VERSION 2.6)
project (strategy-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories( ${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable( ${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/StrategyAAA.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/StrategyBBB.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/StrategyCCC.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Worker.cpp
)
