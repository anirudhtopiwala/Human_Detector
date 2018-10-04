################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../vendor/googletest/googletest/src/gtest-all.cc \
../vendor/googletest/googletest/src/gtest-death-test.cc \
../vendor/googletest/googletest/src/gtest-filepath.cc \
../vendor/googletest/googletest/src/gtest-port.cc \
../vendor/googletest/googletest/src/gtest-printers.cc \
../vendor/googletest/googletest/src/gtest-test-part.cc \
../vendor/googletest/googletest/src/gtest-typed-test.cc \
../vendor/googletest/googletest/src/gtest.cc \
../vendor/googletest/googletest/src/gtest_main.cc 

CC_DEPS += \
./vendor/googletest/googletest/src/gtest-all.d \
./vendor/googletest/googletest/src/gtest-death-test.d \
./vendor/googletest/googletest/src/gtest-filepath.d \
./vendor/googletest/googletest/src/gtest-port.d \
./vendor/googletest/googletest/src/gtest-printers.d \
./vendor/googletest/googletest/src/gtest-test-part.d \
./vendor/googletest/googletest/src/gtest-typed-test.d \
./vendor/googletest/googletest/src/gtest.d \
./vendor/googletest/googletest/src/gtest_main.d 

OBJS += \
./vendor/googletest/googletest/src/gtest-all.o \
./vendor/googletest/googletest/src/gtest-death-test.o \
./vendor/googletest/googletest/src/gtest-filepath.o \
./vendor/googletest/googletest/src/gtest-port.o \
./vendor/googletest/googletest/src/gtest-printers.o \
./vendor/googletest/googletest/src/gtest-test-part.o \
./vendor/googletest/googletest/src/gtest-typed-test.o \
./vendor/googletest/googletest/src/gtest.o \
./vendor/googletest/googletest/src/gtest_main.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/googletest/googletest/src/%.o: ../vendor/googletest/googletest/src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


