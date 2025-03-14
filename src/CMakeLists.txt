set(src_lib_name mainDevice)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(communicator communicator.cpp)
add_library(ioControl ioControl.cpp)
add_library(lightControl lightControl.cpp)
add_library(movementControl movementControl.cpp)

add_library(${src_lib_name} mainDevice.cpp)
target_link_libraries(${src_lib_name} PUBLIC communicator ioControl lightControl movementControl)
