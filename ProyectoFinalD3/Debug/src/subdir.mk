################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc175x_6x.c \
../src/crp.c \
../src/main.c \
../src/sampleS1_data.c \
../src/sampleS5_data.c 

C_DEPS += \
./src/cr_startup_lpc175x_6x.d \
./src/crp.d \
./src/main.d \
./src/sampleS1_data.d \
./src/sampleS5_data.d 

OBJS += \
./src/cr_startup_lpc175x_6x.o \
./src/crp.o \
./src/main.o \
./src/sampleS1_data.o \
./src/sampleS5_data.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_CMSIS=CMSISv2p00_LPC17xx -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\cirov\Documents\MCUXpressoIDE_25.6.136\workspace\CMSISv2p00_LPC17xx\Drivers\inc" -I"C:\Users\cirov\Documents\MCUXpressoIDE_25.6.136\workspace\ProyectoFinalD3\inc" -I"C:\Users\cirov\Documents\MCUXpressoIDE_25.6.136\workspace\CMSISv2p00_LPC17xx\inc" -include"C:\Users\cirov\Documents\MCUXpressoIDE_25.6.136\workspace\ProyectoFinalD3\inc\samples.h" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/cr_startup_lpc175x_6x.d ./src/cr_startup_lpc175x_6x.o ./src/crp.d ./src/crp.o ./src/main.d ./src/main.o ./src/sampleS1_data.d ./src/sampleS1_data.o ./src/sampleS5_data.d ./src/sampleS5_data.o

.PHONY: clean-src

