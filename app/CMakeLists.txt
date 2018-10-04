add_executable(Detect main.cpp Detect.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)
target_link_libraries (Detect ${OpenCV_LIBS})
