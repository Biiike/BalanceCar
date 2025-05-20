################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccstheia151/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/admin/Desktop/BalanceCar-master" -I"C:/Users/admin/Desktop/BalanceCar-master/Debug" -I"C:/ti/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_04_00_06/source" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/OLED" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/BUZ" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/USOUND" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/MOTOR" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/OPENMV" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/MPU6050" -I"C:/Users/admin/Desktop/BalanceCar-master/Hardware/MPU6050/eMPL" -I"C:/Users/admin/Desktop/BalanceCar-master/User" -gdwarf-3 -MMD -MP -MF"User/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


