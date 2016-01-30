CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

PROJECT(exampleProcruste)

set(PROJECT_VISUALIZATION_DIR "${CMAKE_SOURCE_DIR}/modules/visualization/shape2D")

#Library Eigen3
find_package(Eigen3 REQUIRED)
include_directories(EIGEN3_INCLUDE_DIR)

#Library VTK
find_package(VTK 6.0 REQUIRED NO_MODULE)
include(${VTK_USE_FILE})
 

# Chercher les fichiers sources
FILE(
    GLOB_RECURSE
    PROJECT_SRCS
    ./*
    ${PROJECT_VISUALIZATION_DIR}/*
)


ADD_EXECUTABLE(${PROJECT_NAME} ${PROJECT_SRCS})


TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${VTK_LIBRARIES})



