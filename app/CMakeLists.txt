add_executable(detectHumans main.cpp Data.cpp Detect.cpp Train.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})

target_link_libraries (detectHumans ${OpenCV_LIBS})
