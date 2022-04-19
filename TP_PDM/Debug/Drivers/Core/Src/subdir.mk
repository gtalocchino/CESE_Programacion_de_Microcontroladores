################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Core/Src/stm32f4xx_it.c \
../Drivers/Core/Src/syscalls.c \
../Drivers/Core/Src/sysmem.c 

OBJS += \
./Drivers/Core/Src/stm32f4xx_it.o \
./Drivers/Core/Src/syscalls.o \
./Drivers/Core/Src/sysmem.o 

C_DEPS += \
./Drivers/Core/Src/stm32f4xx_it.d \
./Drivers/Core/Src/syscalls.d \
./Drivers/Core/Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Core/Src/%.o: ../Drivers/Core/Src/%.c Drivers/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DHAL_ADC_MODULE_ENABLED -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/CMSIS/Include" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/BSP/STM32F4xx_Nucleo_144" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/Core/Inc" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/BSP/Inc" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/BSP/Src" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/App" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/App/Inc" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/App/Src" -O0 -ffunction-sections -fdata-sections -Wall -Wno-pointer-sign -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Core-2f-Src

clean-Drivers-2f-Core-2f-Src:
	-$(RM) ./Drivers/Core/Src/stm32f4xx_it.d ./Drivers/Core/Src/stm32f4xx_it.o ./Drivers/Core/Src/syscalls.d ./Drivers/Core/Src/syscalls.o ./Drivers/Core/Src/sysmem.d ./Drivers/Core/Src/sysmem.o

.PHONY: clean-Drivers-2f-Core-2f-Src

