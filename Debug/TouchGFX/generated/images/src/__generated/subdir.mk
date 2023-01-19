################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_small_fill_normal.cpp \
../TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_small_fill_pressed.cpp \
../TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_backgrounds_light_precision.cpp \
../TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_fillers_swoop.cpp \
../TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_needles_rough.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.cpp \
../TouchGFX/generated/images/src/__generated/image_icon_theme_images_navigation_arrow_back_50_50_E8F6FB.svg.cpp 

OBJS += \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_small_fill_normal.o \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_small_fill_pressed.o \
./TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_backgrounds_light_precision.o \
./TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_fillers_swoop.o \
./TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_needles_rough.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.o \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_navigation_arrow_back_50_50_E8F6FB.svg.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_small_fill_normal.d \
./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_small_fill_pressed.d \
./TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_backgrounds_light_precision.d \
./TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_fillers_swoop.d \
./TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_needles_rough.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.d \
./TouchGFX/generated/images/src/__generated/image_icon_theme_images_navigation_arrow_back_50_50_E8F6FB.svg.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/__generated/%.o TouchGFX/generated/images/src/__generated/%.su: ../TouchGFX/generated/images/src/__generated/%.cpp TouchGFX/generated/images/src/__generated/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/shared/Projekte/Programmieren/!github/STM_TouchProjects/Tests/simpleBMH/Drivers/BSP/Components/Common" -I"C:/shared/Projekte/Programmieren/!github/STM_TouchProjects/Tests/simpleBMH/Drivers/BSP/Components/ft6x06" -I"C:/shared/Projekte/Programmieren/!github/STM_TouchProjects/Tests/simpleBMH/Drivers/BSP/Components/n25q128a" -I"C:/shared/Projekte/Programmieren/!github/STM_TouchProjects/Tests/simpleBMH/Drivers/BSP/Components/otm8009a" -I"C:/shared/Projekte/Programmieren/!github/STM_TouchProjects/Tests/simpleBMH/Drivers/BSP/STM32469I-Discovery" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../LIBJPEG/App -I../LIBJPEG/Target -I../Middlewares/Third_Party/LibJPEG/include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__generated

clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__generated:
	-$(RM) ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_small_fill_normal.d ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_small_fill_normal.o ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_small_fill_normal.su ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_small_fill_pressed.d ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_small_fill_pressed.o ./TouchGFX/generated/images/src/__generated/image_alternate_theme_images_widgets_button_icon_round_small_fill_pressed.su ./TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_backgrounds_light_precision.d ./TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_backgrounds_light_precision.o ./TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_backgrounds_light_precision.su ./TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_fillers_swoop.d ./TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_fillers_swoop.o ./TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_fillers_swoop.su ./TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_needles_rough.d ./TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_needles_rough.o ./TouchGFX/generated/images/src/__generated/image_glass_theme_images_widgets_gauge_small_needles_rough.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_action_done_50_50_E8F6FB.svg.su ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_navigation_arrow_back_50_50_E8F6FB.svg.d ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_navigation_arrow_back_50_50_E8F6FB.svg.o ./TouchGFX/generated/images/src/__generated/image_icon_theme_images_navigation_arrow_back_50_50_E8F6FB.svg.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__generated

