project( demo_3d )

cmake_minimum_required(VERSION 3.3...3.12 FATAL_ERROR)
foreach(p
    CMP0071 # 3.10: Let AUTOMOC and AUTOUIC process GENERATED files
    )
  if(POLICY ${p})
    cmake_policy(SET ${p} NEW)
  endif()
endforeach()

set( CMAKE_INCLUDE_CURRENT_DIR ON )

#------------find vtk
find_package(VTK COMPONENTS
  vtkCommonCore
  vtkFiltersCore
  vtkInfovisCore
  vtkInteractionStyle
  vtkViewsQt
  vtkIOPLY
  vtkIOGeometry
  QUIET
)
if (NOT VTK_FOUND)
  message("${PROJECT_NAME}: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif()
message (STATUS "VTK_VERSION: ${VTK_VERSION}")
include(${VTK_USE_FILE})

if("${VTK_QT_VERSION}" STREQUAL "")
  message(FATAL_ERROR "VTK was not built with Qt")
endif()
include(${VTK_USE_FILE})

#-------------find qt
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED QUIET)


qt5_wrap_ui(UI_HEADERS ui/mainwindow.ui)


include_directories(include ${VTK_INCLUDE_DIRS})



add_executable( ${PROJECT_NAME} MACOSX_BUNDLE src/main.cpp src/mainwindow.cpp include/mainwindow.h ${UI_HEADERS})
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets ${VTK_LIBRARIES})

