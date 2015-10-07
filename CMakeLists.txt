CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

PROJECT(exec)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#LIBRARY vtk
find_package(VTK  REQUIRED)
include(${VTK_USE_FILE})
 

# librairie OpenCV
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


# Chercher les fichiers sources
FILE(
    GLOB_RECURSE
    FICHIERS_SOURCES
    source/*
)

#if(VTK_LIBRARIES)
 # target_link_libraries(ScatterPlot ${VTK_LIBRARIES})
#else()
 # target_link_libraries(ScatterPlot vtkHybrid vtkWidgets)
#endif()

ADD_EXECUTABLE(${PROJECT_NAME} ${FICHIERS_SOURCES})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS} ${VTK_LIBRARIES})



