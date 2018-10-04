################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../app/detect.cpp \
../app/main.cpp 

OBJS += \
./app/detect.o \
./app/main.o 

CPP_DEPS += \
./app/detect.d \
./app/main.d 


# Each subdirectory must supply rules for building sources it contributes
app/%.o: ../app/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/opencv2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


