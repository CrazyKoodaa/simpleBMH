################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f469nihx.s 

S_DEPS += \
./Core/Startup/startup_stm32f469nihx.d 

OBJS += \
./Core/Startup/startup_stm32f469nihx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/shared/Projekte/Programmieren/!github/STM_TouchProjects/Tests/simpleBMH/Drivers/BSP/Components/Common" -I"C:/shared/Projekte/Programmieren/!github/STM_TouchProjects/Tests/simpleBMH/Drivers/BSP/Components/ft6x06" -I"C:/shared/Projekte/Programmieren/!github/STM_TouchProjects/Tests/simpleBMH/Drivers/BSP/Components/n25q128a" -I"C:/shared/Projekte/Programmieren/!github/STM_TouchProjects/Tests/simpleBMH/Drivers/BSP/Components/otm8009a" -I"C:/shared/Projekte/Programmieren/!github/STM_TouchProjects/Tests/simpleBMH/Drivers/BSP/STM32469I-Discovery" -I"C:/shared/Projekte/Programmieren/!github/STM_TouchProjects/Tests/simpleBMH/Drivers/CMSIS/Include" -I"C:/shared/Projekte/Programmieren/!github/STM_TouchProjects/Tests/simpleBMH/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/shared/Projekte/Programmieren/!github/STM_TouchProjects/Tests/simpleBMH/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/shared/Projekte/Programmieren/!github/STM_TouchProjects/Tests/simpleBMH/Middlewares/ST/touchgfx/framework/include" -I"C:/shared/Projekte/Programmieren/!github/STM_TouchProjects/Tests/simpleBMH/Middlewares/Third_Party/FreeRTOS/Source/include" -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f469nihx.d ./Core/Startup/startup_stm32f469nihx.o

.PHONY: clean-Core-2f-Startup

