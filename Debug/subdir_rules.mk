################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccstheia151/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/admin/Desktop/BalanceCar-master" -I"C:/Users/admin/Desktop/BalanceCar-master/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/OLED" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/BUZ" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/USOUND" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/MOTOR" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/OPENMV" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/MPU6050" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/MPU6050/eMPL" -I"C:/Users/admin/Desktop/BalanceCar-master/User" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-92322287: ../main.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/sysconfig_1.22.0/sysconfig_cli.bat" --script "C:/Users/admin/Desktop/BalanceCar-master/main.syscfg" -o "." -s "C:/ti/mspm0_sdk_2_04_00_06/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-92322287 ../main.syscfg
device.opt: build-92322287
device.cmd.genlibs: build-92322287
ti_msp_dl_config.c: build-92322287
ti_msp_dl_config.h: build-92322287
Event.dot: build-92322287

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccstheia151/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/admin/Desktop/BalanceCar-master" -I"C:/Users/admin/Desktop/BalanceCar-master/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/OLED" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/BUZ" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/USOUND" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/MOTOR" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/OPENMV" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/MPU6050" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/MPU6050/eMPL" -I"C:/Users/admin/Desktop/BalanceCar-master/User" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: C:/ti/mspm0_sdk_2_04_00_06/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccstheia151/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/admin/Desktop/BalanceCar-master" -I"C:/Users/admin/Desktop/BalanceCar-master/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/OLED" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/BUZ" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/USOUND" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/MOTOR" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/OPENMV" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/MPU6050" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/MPU6050/eMPL" -I"C:/Users/admin/Desktop/BalanceCar-master/User" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


