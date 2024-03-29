cmake_minimum_required(VERSION 3.0.2)
set(PROJECT_NAME "morse_translator")
project(${PROJECT_NAME})

add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs message_generation)

################################################
## Declare ROS messages, services and actions ##
################################################

## Generate services in the 'srv' folder
add_service_files(
  FILES
  MorseTranslator.srv
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs  # Or other packages containing msgs
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  CATKIN_DEPENDS roscpp message_generation
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

file(GLOB_RECURSE EXECUTABLE_SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${EXECUTABLE_SOURCES})
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_generate_messages_cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} Threads::Threads)

#############
## Testing ##
#############
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/test/src/*.cpp")

add_library(${PROJECT_NAME}-lib ${EXECUTABLE_SOURCES})
catkin_add_gtest(${PROJECT_NAME}-test ${TEST_SOURCES})
add_dependencies(${PROJECT_NAME}-test ${PROJECT_NAME}_generate_messages_cpp)
target_link_libraries(${PROJECT_NAME}-test ${catkin_LIBRARIES} Threads::Threads ${PROJECT_NAME}-lib)