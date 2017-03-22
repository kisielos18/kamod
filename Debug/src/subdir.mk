################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/crc.c \
../src/debug.c \
../src/main.c \
../src/stm32_Hw.c \
../src/stm32f4xx_it.c \
../src/syscalls.c \
../src/system_stm32f4xx.c \
../src/tm_stm32f4_gpio.c \
../src/tm_stm32f4_i2c.c \
../src/tm_stm32f4_usart.c 

OBJS += \
./src/crc.o \
./src/debug.o \
./src/main.o \
./src/stm32_Hw.o \
./src/stm32f4xx_it.o \
./src/syscalls.o \
./src/system_stm32f4xx.o \
./src/tm_stm32f4_gpio.o \
./src/tm_stm32f4_i2c.o \
./src/tm_stm32f4_usart.o 

C_DEPS += \
./src/crc.d \
./src/debug.d \
./src/main.d \
./src/stm32_Hw.d \
./src/stm32f4xx_it.d \
./src/syscalls.d \
./src/system_stm32f4xx.d \
./src/tm_stm32f4_gpio.d \
./src/tm_stm32f4_i2c.d \
./src/tm_stm32f4_usart.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F4 -DSTM32 -DNUCLEO_F411RE -DSTM32F411RETx -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F411xE -I"E:/stm_workspace/nucleo-f411re_stdperiph_lib" -I"E:/stm_workspace/kamod/inc" -I"E:/stm_workspace/nucleo-f411re_stdperiph_lib/CMSIS/core" -I"E:/stm_workspace/nucleo-f411re_stdperiph_lib/CMSIS/device" -I"E:/stm_workspace/nucleo-f411re_stdperiph_lib/StdPeriph_Driver/inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


