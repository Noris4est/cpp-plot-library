cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

project(cpp_Plot_LIbrary)

set(project_DIR ${CMAKE_CURRENT_LIST_DIR}/../../)

set(OpenCV_DIR /home/vit/opencv/install_4_5_2_contrib)
#set(OpenCV_DIR ${project_DIR}opencv/install_3.4.13)
find_package(OpenCV REQUIRED PATHS ${OpenCV_DIR} NO_DEFAULT_PATH)
message(OpenCV_INCLUDE_DIRS=${OpenCV_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(
cpp_Plot_LIbrary cpp_Plot_LIbrary.cpp
../cplotlib/core.hpp
../cplotlib/figure/figure.hpp
../cplotlib/figure/figure.cpp
../cplotlib/axesManager/axesManager.hpp
../cplotlib/axesManager/axesManager.cpp
../cplotlib/ax/ax.hpp
../cplotlib/ax/ax.cpp
../cplotlib/tools/colors/colors.hpp
#refresh_handler
../cplotlib/refresh_handler/refresh_handler.cpp
../cplotlib/refresh_handler/refresh_handler.hpp
#common types
../cplotlib/commontypes.h
#axobject
../cplotlib/ax/ax_components/axobject.hpp
../cplotlib/ax/ax_components/axobject.cpp
#grid
../cplotlib/ax/ax_components/grid/grid.hpp
../cplotlib/ax/ax_components/grid/grid.cpp
#ticks
../cplotlib/ax/ax_components/ticks/ticks.hpp
../cplotlib/ax/ax_components/ticks/ticks.cpp
#frametext
../cplotlib/tools/frametext/frametext.hpp
../cplotlib/tools/frametext/frametext.cpp
#xlabel, ylabel
../cplotlib/ax/ax_components/label/label.hpp
../cplotlib/ax/ax_components/label/label.cpp
../cplotlib/ax/ax_components/label/xlabel/xlabel.hpp
../cplotlib/ax/ax_components/label/xlabel/xlabel.cpp
../cplotlib/ax/ax_components/label/ylabel/ylabel.hpp
../cplotlib/ax/ax_components/label/ylabel/ylabel.cpp
#title
../cplotlib/ax/ax_components/title/title.hpp
../cplotlib/ax/ax_components/title/title.cpp
#chart_background
../cplotlib/ax/ax_components/chart_background/chart_background.hpp
../cplotlib/ax/ax_components/chart_background/chart_background.cpp
#ax_background
../cplotlib/ax/ax_components/ax_background/ax_background.hpp
../cplotlib/ax/ax_components/ax_background/ax_background.cpp
#ax_border
../cplotlib/ax/ax_components/ax_border/ax_border.cpp
../cplotlib/ax/ax_components/ax_border/ax_border.hpp
#ax_legend
../cplotlib/ax/ax_components/legend/legend.cpp
../cplotlib/ax/ax_components/legend/legend.hpp
#chart_border
../cplotlib/ax/ax_components/chart_border/chart_border.cpp
../cplotlib/ax/ax_components/chart_border/chart_border.hpp
#frame_border
../cplotlib/frame_border/frame_border.hpp
../cplotlib/frame_border/frame_border.cpp
#fig_background
../cplotlib/figure/fig_background/fig_background.hpp
../cplotlib/figure/fig_background/fig_background.cpp
#fig_title
../cplotlib/figure/fig_title/fig_title.hpp
../cplotlib/figure/fig_title/fig_title.cpp
#plots_settings
../cplotlib/ax/plots/plots_settings.hpp

#plot
../cplotlib/ax/plots/plot/plot.hpp
../cplotlib/ax/plots/plot/plot.cpp

#vector_creation_routines
../cplotlib/tools/vector_creation_routines/vector_creation_routines.hpp
../cplotlib/tools/vector_creation_routines/vector_creation_routines.cpp


)

target_link_libraries(cpp_Plot_LIbrary ${OpenCV_LIBS})


