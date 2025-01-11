################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MiddleWares/Third_Party/FreeRTOS/org/Source/croutine.c \
../MiddleWares/Third_Party/FreeRTOS/org/Source/event_groups.c \
../MiddleWares/Third_Party/FreeRTOS/org/Source/list.c \
../MiddleWares/Third_Party/FreeRTOS/org/Source/queue.c \
../MiddleWares/Third_Party/FreeRTOS/org/Source/stream_buffer.c \
../MiddleWares/Third_Party/FreeRTOS/org/Source/tasks.c \
../MiddleWares/Third_Party/FreeRTOS/org/Source/timers.c 

OBJS += \
./MiddleWares/Third_Party/FreeRTOS/org/Source/croutine.o \
./MiddleWares/Third_Party/FreeRTOS/org/Source/event_groups.o \
./MiddleWares/Third_Party/FreeRTOS/org/Source/list.o \
./MiddleWares/Third_Party/FreeRTOS/org/Source/queue.o \
./MiddleWares/Third_Party/FreeRTOS/org/Source/stream_buffer.o \
./MiddleWares/Third_Party/FreeRTOS/org/Source/tasks.o \
./MiddleWares/Third_Party/FreeRTOS/org/Source/timers.o 

C_DEPS += \
./MiddleWares/Third_Party/FreeRTOS/org/Source/croutine.d \
./MiddleWares/Third_Party/FreeRTOS/org/Source/event_groups.d \
./MiddleWares/Third_Party/FreeRTOS/org/Source/list.d \
./MiddleWares/Third_Party/FreeRTOS/org/Source/queue.d \
./MiddleWares/Third_Party/FreeRTOS/org/Source/stream_buffer.d \
./MiddleWares/Third_Party/FreeRTOS/org/Source/tasks.d \
./MiddleWares/Third_Party/FreeRTOS/org/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
MiddleWares/Third_Party/FreeRTOS/org/Source/%.o MiddleWares/Third_Party/FreeRTOS/org/Source/%.su MiddleWares/Third_Party/FreeRTOS/org/Source/%.cyclo: ../MiddleWares/Third_Party/FreeRTOS/org/Source/%.c MiddleWares/Third_Party/FreeRTOS/org/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/yigit/STM32CubeIDE/workspace_1.16.0/STM32F401RE/MiddleWares/Third_Party/FreeRTOS/org/Source/include" -I"C:/Users/yigit/STM32CubeIDE/workspace_1.16.0/STM32F401RE/MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"C:/Users/yigit/STM32CubeIDE/workspace_1.16.0/STM32F401RE/FreeRTOSConfig" -I"C:/Users/yigit/STM32CubeIDE/workspace_1.16.0/STM32F401RE/mydriver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-org-2f-Source

clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-org-2f-Source:
	-$(RM) ./MiddleWares/Third_Party/FreeRTOS/org/Source/croutine.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/Source/croutine.d ./MiddleWares/Third_Party/FreeRTOS/org/Source/croutine.o ./MiddleWares/Third_Party/FreeRTOS/org/Source/croutine.su ./MiddleWares/Third_Party/FreeRTOS/org/Source/event_groups.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/Source/event_groups.d ./MiddleWares/Third_Party/FreeRTOS/org/Source/event_groups.o ./MiddleWares/Third_Party/FreeRTOS/org/Source/event_groups.su ./MiddleWares/Third_Party/FreeRTOS/org/Source/list.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/Source/list.d ./MiddleWares/Third_Party/FreeRTOS/org/Source/list.o ./MiddleWares/Third_Party/FreeRTOS/org/Source/list.su ./MiddleWares/Third_Party/FreeRTOS/org/Source/queue.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/Source/queue.d ./MiddleWares/Third_Party/FreeRTOS/org/Source/queue.o ./MiddleWares/Third_Party/FreeRTOS/org/Source/queue.su ./MiddleWares/Third_Party/FreeRTOS/org/Source/stream_buffer.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/Source/stream_buffer.d ./MiddleWares/Third_Party/FreeRTOS/org/Source/stream_buffer.o ./MiddleWares/Third_Party/FreeRTOS/org/Source/stream_buffer.su ./MiddleWares/Third_Party/FreeRTOS/org/Source/tasks.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/Source/tasks.d ./MiddleWares/Third_Party/FreeRTOS/org/Source/tasks.o ./MiddleWares/Third_Party/FreeRTOS/org/Source/tasks.su ./MiddleWares/Third_Party/FreeRTOS/org/Source/timers.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/Source/timers.d ./MiddleWares/Third_Party/FreeRTOS/org/Source/timers.o ./MiddleWares/Third_Party/FreeRTOS/org/Source/timers.su

.PHONY: clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-org-2f-Source

