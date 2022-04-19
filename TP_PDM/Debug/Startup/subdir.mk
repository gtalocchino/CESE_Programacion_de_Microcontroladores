################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f429xx.s 

OBJS += \
./Startup/startup_stm32f429xx.o 

S_DEPS += \
./Startup/startup_stm32f429xx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/CMSIS/Include" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/BSP/STM32F4xx_Nucleo_144" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Inc" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/Core/Inc" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/BSP/Inc" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/Drivers/BSP/Src" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/App" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/App/Inc" -I"/home/gianfranco/Documents/CESE/Programacion de Microcontroladores/Repos/PdM_workspace/TP_PDM/App/Src" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32f429xx.d ./Startup/startup_stm32f429xx.o

.PHONY: clean-Startup

