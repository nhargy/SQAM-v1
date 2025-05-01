cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(SQAM-v1)

find_package(Geant4 REQUIRED ui_all vis_all)

include_directories(include)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)

file(GLOB MACRO_FILES "*.mac")

file(COPY ${MACRO_FILES} DESTINATION ${PROJECT_BINARY_DIR})

add_executable(SQAM-v1-EXE main.cc ${sources})
target_link_libraries(SQAM-v1-EXE ${Geant4_LIBRARIES})
add_custom_target(SQAM-v1 DEPENDS SQAM-v1-EXE)
