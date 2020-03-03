project( ui )
cmake_minimum_required( VERSION 2.8.3 )

set( CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} $ENV{QT5_DIR} )
set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC ON )

find_package(Qt5Widgets REQUIRED)
find_package( OpenCV REQUIRED )
#find_package(catkin REQUIRED)
find_package(PCL 1.7.2 REQUIRED)

#catkin_package(
#     CATKIN_DEPENDS roscpp std_msgs geometry_msgs sensor_msgs
#     INCLUDE_DIRS include ${PCL_INCLUDE_DIRS}
#		 )

qt5_wrap_ui(UI_HEADERS ui/mainwindow.ui)
include_directories(include
                    #${catkin_INCLUDE_DIRS}
                    ${PCL_INCLUDE_DIRS}
		    
                    )
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable( ${PROJECT_NAME} src/main.cpp src/mainwindow.cpp include/mainwindow.h ${UI_HEADERS})
target_link_libraries( ${PROJECT_NAME}
                       Qt5::Widgets
                       #${catkin_LIBRARIES}
                       ${PCL_LIBRARIES}
${OpenCV_LIBS})

