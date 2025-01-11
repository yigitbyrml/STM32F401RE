################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MiddleWares/Third_Party/FreeRTOS/org/croutine.c \
../MiddleWares/Third_Party/FreeRTOS/org/event_groups.c \
../MiddleWares/Third_Party/FreeRTOS/org/list.c \
../MiddleWares/Third_Party/FreeRTOS/org/queue.c \
../MiddleWares/Third_Party/FreeRTOS/org/stream_buffer.c \
../MiddleWares/Third_Party/FreeRTOS/org/tasks.c \
../MiddleWares/Third_Party/FreeRTOS/org/timers.c 

OBJS += \
./MiddleWares/Third_Party/FreeRTOS/org/croutine.o \
./MiddleWares/Third_Party/FreeRTOS/org/event_groups.o \
./MiddleWares/Third_Party/FreeRTOS/org/list.o \
./MiddleWares/Third_Party/FreeRTOS/org/queue.o \
./MiddleWares/Third_Party/FreeRTOS/org/stream_buffer.o \
./MiddleWares/Third_Party/FreeRTOS/org/tasks.o \
./MiddleWares/Third_Party/FreeRTOS/org/timers.o 

C_DEPS += \
./MiddleWares/Third_Party/FreeRTOS/org/croutine.d \
./MiddleWares/Third_Party/FreeRTOS/org/event_groups.d \
./MiddleWares/Third_Party/FreeRTOS/org/list.d \
./MiddleWares/Third_Party/FreeRTOS/org/queue.d \
./MiddleWares/Third_Party/FreeRTOS/org/stream_buffer.d \
./MiddleWares/Third_Party/FreeRTOS/org/tasks.d \
./MiddleWares/Third_Party/FreeRTOS/org/timers.d 


# Each subdirectory must supply rules for building sources it contributes
MiddleWares/Third_Party/FreeRTOS/org/%.o MiddleWares/Third_Party/FreeRTOS/org/%.su MiddleWares/Third_Party/FreeRTOS/org/%.cyclo: ../MiddleWares/Third_Party/FreeRTOS/org/%.c MiddleWares/Third_Party/FreeRTOS/org/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/yigit/STM32CubeIDE/workspace_1.16.0/STM32F401RE/FreeRTOSConfig" -I"C:/Users/yigit/STM32CubeIDE/workspace_1.16.0/STM32F401RE/MiddleWares/Third_Party/FreeRTOS/org/include" -I"C:/Users/yigit/STM32CubeIDE/workspace_1.16.0/STM32F401RE/MiddleWares/Third_Party/FreeRTOS/org/portable/GCC/ARM_CM4F" -I"C:/Users/yigit/STM32CubeIDE/workspace_1.16.0/STM32F401RE/mydriver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-org

clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-org:
	-$(RM) ./MiddleWares/Third_Party/FreeRTOS/org/croutine.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/croutine.d ./MiddleWares/Third_Party/FreeRTOS/org/croutine.o ./MiddleWares/Third_Party/FreeRTOS/org/croutine.su ./MiddleWares/Third_Party/FreeRTOS/org/event_groups.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/event_groups.d ./MiddleWares/Third_Party/FreeRTOS/org/event_groups.o ./MiddleWares/Third_Party/FreeRTOS/org/event_groups.su ./MiddleWares/Third_Party/FreeRTOS/org/list.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/list.d ./MiddleWares/Third_Party/FreeRTOS/org/list.o ./MiddleWares/Third_Party/FreeRTOS/org/list.su ./MiddleWares/Third_Party/FreeRTOS/org/queue.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/queue.d ./MiddleWares/Third_Party/FreeRTOS/org/queue.o ./MiddleWares/Third_Party/FreeRTOS/org/queue.su ./MiddleWares/Third_Party/FreeRTOS/org/stream_buffer.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/stream_buffer.d ./MiddleWares/Third_Party/FreeRTOS/org/stream_buffer.o ./MiddleWares/Third_Party/FreeRTOS/org/stream_buffer.su ./MiddleWares/Third_Party/FreeRTOS/org/tasks.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/tasks.d ./MiddleWares/Third_Party/FreeRTOS/org/tasks.o ./MiddleWares/Third_Party/FreeRTOS/org/tasks.su ./MiddleWares/Third_Party/FreeRTOS/org/timers.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/timers.d ./MiddleWares/Third_Party/FreeRTOS/org/timers.o ./MiddleWares/Third_Party/FreeRTOS/org/timers.su

.PHONY: clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-org

