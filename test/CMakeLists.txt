set(GTEST_SHUFFLE 1)

add_executable(
    detectHuman-test
    main.cpp
    testData.cpp
    ../app/Data.cpp
    testTrain.cpp
    ../app/Train.cpp
    testDetect.cpp
    ../app/Detect.cpp
)

target_include_directories(detectHuman-test PUBLIC ../vendor/googletest/googletest/include 
	../vendor/googletest/googlemock/include ${CMAKE_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})		

target_link_libraries(detectHuman-test PUBLIC gtest  gmock ${OpenCV_LIBS})

