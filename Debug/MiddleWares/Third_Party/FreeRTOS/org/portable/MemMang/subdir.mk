################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MiddleWares/Third_Party/FreeRTOS/org/portable/MemMang/heap_4.c 

OBJS += \
./MiddleWares/Third_Party/FreeRTOS/org/portable/MemMang/heap_4.o 

C_DEPS += \
./MiddleWares/Third_Party/FreeRTOS/org/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
MiddleWares/Third_Party/FreeRTOS/org/portable/MemMang/%.o MiddleWares/Third_Party/FreeRTOS/org/portable/MemMang/%.su MiddleWares/Third_Party/FreeRTOS/org/portable/MemMang/%.cyclo: ../MiddleWares/Third_Party/FreeRTOS/org/portable/MemMang/%.c MiddleWares/Third_Party/FreeRTOS/org/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/yigit/STM32CubeIDE/workspace_1.16.0/STM32F401RE/FreeRTOSConfig" -I"C:/Users/yigit/STM32CubeIDE/workspace_1.16.0/STM32F401RE/MiddleWares/Third_Party/FreeRTOS/org/include" -I"C:/Users/yigit/STM32CubeIDE/workspace_1.16.0/STM32F401RE/MiddleWares/Third_Party/FreeRTOS/org/portable/GCC/ARM_CM4F" -I"C:/Users/yigit/STM32CubeIDE/workspace_1.16.0/STM32F401RE/mydriver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-org-2f-portable-2f-MemMang

clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-org-2f-portable-2f-MemMang:
	-$(RM) ./MiddleWares/Third_Party/FreeRTOS/org/portable/MemMang/heap_4.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/portable/MemMang/heap_4.d ./MiddleWares/Third_Party/FreeRTOS/org/portable/MemMang/heap_4.o ./MiddleWares/Third_Party/FreeRTOS/org/portable/MemMang/heap_4.su

.PHONY: clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-org-2f-portable-2f-MemMang

