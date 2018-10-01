################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../vendor/googletest/googletest/xcode/Samples/FrameworkSample/widget.cc \
../vendor/googletest/googletest/xcode/Samples/FrameworkSample/widget_test.cc 

CC_DEPS += \
./vendor/googletest/googletest/xcode/Samples/FrameworkSample/widget.d \
./vendor/googletest/googletest/xcode/Samples/FrameworkSample/widget_test.d 

OBJS += \
./vendor/googletest/googletest/xcode/Samples/FrameworkSample/widget.o \
./vendor/googletest/googletest/xcode/Samples/FrameworkSample/widget_test.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/googletest/googletest/xcode/Samples/FrameworkSample/%.o: ../vendor/googletest/googletest/xcode/Samples/FrameworkSample/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


