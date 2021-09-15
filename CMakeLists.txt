project(MPI_Proyect)
cmake_minimum_required(VERSION 3.15)
find_package(MPI REQUIRED)

include_directories(${MPI_INCLUDE_PATH})

add_executable(app src/main.cc)
target_link_libraries(app ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
  set_target_properties(app PROPERTIES
    COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
  set_target_properties(app PROPERTIES
    LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()

