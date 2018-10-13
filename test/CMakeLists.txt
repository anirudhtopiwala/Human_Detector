set(GTEST_SHUFFLE 1)

add_executable(
    detectHuman-test
    main.cpp
    test.cpp
    ../app/Detect.cpp
    ../app/Data.cpp
    ../app/Train.cpp
)

target_include_directories(detectHuman-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})
target_link_libraries(detectHuman-test PUBLIC gtest ${OpenCV_LIBS})

