################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../vendor/googletest/googlemock/src/gmock-all.cc \
../vendor/googletest/googlemock/src/gmock-cardinalities.cc \
../vendor/googletest/googlemock/src/gmock-internal-utils.cc \
../vendor/googletest/googlemock/src/gmock-matchers.cc \
../vendor/googletest/googlemock/src/gmock-spec-builders.cc \
../vendor/googletest/googlemock/src/gmock.cc \
../vendor/googletest/googlemock/src/gmock_main.cc 

CC_DEPS += \
./vendor/googletest/googlemock/src/gmock-all.d \
./vendor/googletest/googlemock/src/gmock-cardinalities.d \
./vendor/googletest/googlemock/src/gmock-internal-utils.d \
./vendor/googletest/googlemock/src/gmock-matchers.d \
./vendor/googletest/googlemock/src/gmock-spec-builders.d \
./vendor/googletest/googlemock/src/gmock.d \
./vendor/googletest/googlemock/src/gmock_main.d 

OBJS += \
./vendor/googletest/googlemock/src/gmock-all.o \
./vendor/googletest/googlemock/src/gmock-cardinalities.o \
./vendor/googletest/googlemock/src/gmock-internal-utils.o \
./vendor/googletest/googlemock/src/gmock-matchers.o \
./vendor/googletest/googlemock/src/gmock-spec-builders.o \
./vendor/googletest/googlemock/src/gmock.o \
./vendor/googletest/googlemock/src/gmock_main.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/googletest/googlemock/src/%.o: ../vendor/googletest/googlemock/src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


