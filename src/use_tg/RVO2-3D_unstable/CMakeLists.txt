cmake_minimum_required(VERSION 2.8.3)
project(RVO2-3D_unstable)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS pqp HACD_Lib functions)

## System dependencies are found with CMake's conventions
# find_package(assimp REQUIRED)


###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
 INCLUDE_DIRS include
 LIBRARIES RVO2-3D_unstable
 CATKIN_DEPENDS pqp functions HACD_Lib
#  DEPENDS assimp
)

###########
## Build ##
###########

include_directories(include/RVO2-3D_unstable include ${catkin_INCLUDE_DIRS})

add_library(${PROJECT_NAME} src/Agent.cpp src/KdTree.cpp src/RVOSimulator.cpp src/Convexer.cpp)
target_link_libraries(${PROJECT_NAME} functions pqp assimp HACD_Lib)

add_executable(convexer src/test_convexer.cpp)
target_link_libraries(convexer ${PROJECT_NAME} functions pqp assimp HACD_Lib)