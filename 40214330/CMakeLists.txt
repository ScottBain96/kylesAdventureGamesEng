cmake_minimum_required(VERSION 3.9)
# Require modern C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Games-Engineering_Coursework2018)

#### Setup Directories ####
#Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
# Output all DLLs from all libs into main build folder
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

#### Add External Dependencies ####
add_subdirectory("lib/sfml")
set(SFML_INCS "lib/sfml/include")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")

#### B2D - Box2D physics library ####
add_subdirectory("lib/b2d/Box2D")
#include_directories("lib/b2d/Box2D/")
set(B2D_INCS "lib/b2d/Box2D/")
link_directories("${CMAKE_BINARY_DIR}/lib/b2d/lib")


#### Coursework2018 ####
file(GLOB_RECURSE SOURCES source/*.cpp source/*.h)
add_executable(cw ${SOURCES})
target_include_directories(cw SYSTEM PRIVATE ${SFML_INCS} ${B2D_INCS})
target_link_libraries(cw sfml-graphics sfml-audio Box2D)
add_custom_target(copy_resources ALL COMMAND ${CMAKE_COMMAND}
-E copy_directory
"${PROJECT_SOURCE_DIR}/res"
${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIGURATION>/res
)
set_target_properties(
  cw PROPERTIES
  VS_DEBUGGER_WORKING_DIRECTORY
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
)
add_dependencies(cw copy_resources)


#### Link Dependencies ####
foreach (exe ${EXECUTABLES})
#Set working directory to build dir in visual studio
set_target_properties(
  ${exe} PROPERTIES VS_DEBUGGERWORKING_DIRECTORY
${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
)
target_link_libraries (${exe}
#lib maths #We'll make this later.
optimized sfml-graphics debug sfml-graphics-d
optimized sfml-audio debug sfml-audio-d
optimized sfml-window debug sfml-window-d
optimized sfml-system debug sfml-system-d
optimized sfml-graphics debug sfml-graphics-d
optimized sfml-main
)
add_dependencies (${exe} sfml-graphics sfml-audio copy_resources)
endforeach()