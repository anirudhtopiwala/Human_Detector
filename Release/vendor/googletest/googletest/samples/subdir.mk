################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../vendor/googletest/googletest/samples/sample1.cc \
../vendor/googletest/googletest/samples/sample10_unittest.cc \
../vendor/googletest/googletest/samples/sample1_unittest.cc \
../vendor/googletest/googletest/samples/sample2.cc \
../vendor/googletest/googletest/samples/sample2_unittest.cc \
../vendor/googletest/googletest/samples/sample3_unittest.cc \
../vendor/googletest/googletest/samples/sample4.cc \
../vendor/googletest/googletest/samples/sample4_unittest.cc \
../vendor/googletest/googletest/samples/sample5_unittest.cc \
../vendor/googletest/googletest/samples/sample6_unittest.cc \
../vendor/googletest/googletest/samples/sample7_unittest.cc \
../vendor/googletest/googletest/samples/sample8_unittest.cc \
../vendor/googletest/googletest/samples/sample9_unittest.cc 

CC_DEPS += \
./vendor/googletest/googletest/samples/sample1.d \
./vendor/googletest/googletest/samples/sample10_unittest.d \
./vendor/googletest/googletest/samples/sample1_unittest.d \
./vendor/googletest/googletest/samples/sample2.d \
./vendor/googletest/googletest/samples/sample2_unittest.d \
./vendor/googletest/googletest/samples/sample3_unittest.d \
./vendor/googletest/googletest/samples/sample4.d \
./vendor/googletest/googletest/samples/sample4_unittest.d \
./vendor/googletest/googletest/samples/sample5_unittest.d \
./vendor/googletest/googletest/samples/sample6_unittest.d \
./vendor/googletest/googletest/samples/sample7_unittest.d \
./vendor/googletest/googletest/samples/sample8_unittest.d \
./vendor/googletest/googletest/samples/sample9_unittest.d 

OBJS += \
./vendor/googletest/googletest/samples/sample1.o \
./vendor/googletest/googletest/samples/sample10_unittest.o \
./vendor/googletest/googletest/samples/sample1_unittest.o \
./vendor/googletest/googletest/samples/sample2.o \
./vendor/googletest/googletest/samples/sample2_unittest.o \
./vendor/googletest/googletest/samples/sample3_unittest.o \
./vendor/googletest/googletest/samples/sample4.o \
./vendor/googletest/googletest/samples/sample4_unittest.o \
./vendor/googletest/googletest/samples/sample5_unittest.o \
./vendor/googletest/googletest/samples/sample6_unittest.o \
./vendor/googletest/googletest/samples/sample7_unittest.o \
./vendor/googletest/googletest/samples/sample8_unittest.o \
./vendor/googletest/googletest/samples/sample9_unittest.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/googletest/googletest/samples/%.o: ../vendor/googletest/googletest/samples/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


