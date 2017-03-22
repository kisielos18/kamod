################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32f411xe.s 

OBJS += \
./startup/startup_stm32f411xe.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo %cd%
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"E:/stm_workspace/nucleo-f411re_stdperiph_lib" -I"E:/stm_workspace/kamod/inc" -I"E:/stm_workspace/nucleo-f411re_stdperiph_lib/CMSIS/core" -I"E:/stm_workspace/nucleo-f411re_stdperiph_lib/CMSIS/device" -I"E:/stm_workspace/nucleo-f411re_stdperiph_lib/StdPeriph_Driver/inc" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


