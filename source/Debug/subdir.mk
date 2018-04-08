################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Client.cpp \
../Compte.cpp \
../ContratException.cpp \
../Date.cpp \
../validationFormat.cpp 

OBJS += \
./Client.o \
./Compte.o \
./ContratException.o \
./Date.o \
./validationFormat.o 

CPP_DEPS += \
./Client.d \
./Compte.d \
./ContratException.d \
./Date.d \
./validationFormat.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++03 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


