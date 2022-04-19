################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Src/acutators.c \
../Drivers/BSP/Src/bsp.c \
../Drivers/BSP/Src/hw.c \
../Drivers/BSP/Src/indicators.c \
../Drivers/BSP/Src/log.c \
../Drivers/BSP/Src/sensor.c \
../Drivers/BSP/Src/serial.c 

OBJS += \
./Drivers/BSP/Src/acutators.o \
./Drivers/BSP/Src/bsp.o \
./Drivers/BSP/Src/hw.o \
./Drivers/BSP/Src/indicators.o \
./Drivers/BSP/Src/log.o \
./Drivers/BSP/Src/sensor.o \
./Drivers/BSP/Src/serial.o 

C_DEPS += \
./Drivers/BSP/Src/acutators.d \
./Drivers/BSP/Src/bsp.d \
./Drivers/BSP/Src/hw.d \
./Drivers/BSP/Src/indicators.d \
./Drivers/BSP/Src/log.d \
./Drivers/BSP/Src/sensor.d \
./Drivers/BSP/Src/serial.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Src/%.o: ../Drivers/BSP/Src/%.c Drivers/BSP/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DHAL_ADC_MODULE_ENABLED -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/CMSIS/Include" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/BSP/STM32F4xx_Nucleo_144" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/Core/Inc" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/BSP/Inc" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/BSP/Src" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/App" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/App/Inc" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/App/Src" -O0 -ffunction-sections -fdata-sections -Wall -Wno-pointer-sign -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Src

clean-Drivers-2f-BSP-2f-Src:
	-$(RM) ./Drivers/BSP/Src/acutators.d ./Drivers/BSP/Src/acutators.o ./Drivers/BSP/Src/bsp.d ./Drivers/BSP/Src/bsp.o ./Drivers/BSP/Src/hw.d ./Drivers/BSP/Src/hw.o ./Drivers/BSP/Src/indicators.d ./Drivers/BSP/Src/indicators.o ./Drivers/BSP/Src/log.d ./Drivers/BSP/Src/log.o ./Drivers/BSP/Src/sensor.d ./Drivers/BSP/Src/sensor.o ./Drivers/BSP/Src/serial.d ./Drivers/BSP/Src/serial.o

.PHONY: clean-Drivers-2f-BSP-2f-Src

