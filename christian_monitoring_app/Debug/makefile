################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./startup_msp432p401r_ccs.obj" \
"./system_msp432p401r.obj" \
"./MSP432P4xx/adc14.obj" \
"./MSP432P4xx/aes256.obj" \
"./MSP432P4xx/comp_e.obj" \
"./MSP432P4xx/cpu.obj" \
"./MSP432P4xx/crc32.obj" \
"./MSP432P4xx/cs.obj" \
"./MSP432P4xx/dma.obj" \
"./MSP432P4xx/flash.obj" \
"./MSP432P4xx/fpu.obj" \
"./MSP432P4xx/gpio.obj" \
"./MSP432P4xx/i2c.obj" \
"./MSP432P4xx/interrupt.obj" \
"./MSP432P4xx/mpu.obj" \
"./MSP432P4xx/pcm.obj" \
"./MSP432P4xx/pmap.obj" \
"./MSP432P4xx/pss.obj" \
"./MSP432P4xx/ref_a.obj" \
"./MSP432P4xx/reset.obj" \
"./MSP432P4xx/rtc_c.obj" \
"./MSP432P4xx/spi.obj" \
"./MSP432P4xx/sysctl.obj" \
"./MSP432P4xx/systick.obj" \
"./MSP432P4xx/timer32.obj" \
"./MSP432P4xx/timer_a.obj" \
"./MSP432P4xx/uart.obj" \
"./MSP432P4xx/wdt_a.obj" \
"../msp432p401r.cmd" \
"C:/ti/devices/driverlib/MSP432P4xx/ccs/msp432p4xx_driverlib.lib" \
"C:/ti/devices/driverlib/MSP432P4xx/keil/msp432p4xx_driverlib.lib" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include MSP432P4xx/subdir_vars.mk
-include MSP432P4xx/ccs/subdir_vars.mk
-include MSP432P4xx/ewarm/subdir_vars.mk
-include MSP432P4xx/gcc/subdir_vars.mk
-include MSP432P4xx/keil/subdir_vars.mk
-include subdir_rules.mk
-include MSP432P4xx/subdir_rules.mk
-include MSP432P4xx/ccs/subdir_rules.mk
-include MSP432P4xx/ewarm/subdir_rules.mk
-include MSP432P4xx/gcc/subdir_rules.mk
-include MSP432P4xx/keil/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
christian_monitoring_app.out \

EXE_OUTPUTS__QUOTED += \
"christian_monitoring_app.out" \

BIN_OUTPUTS += \
christian_monitoring_app.hex \

BIN_OUTPUTS__QUOTED += \
"christian_monitoring_app.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(A_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "christian_monitoring_app.out"

# Tool invocations
christian_monitoring_app.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(A_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"christian_monitoring_app.map" --heap_size=1024 --stack_size=512 -i"C:/ti/ccs1011/ccs/ccs_base/arm/include" -i"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/lib" -i"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="christian_monitoring_app_linkInfo.xml" --rom_model -o "christian_monitoring_app.out" $(ORDERED_OBJS) $(A_SRCS)
	@echo 'Finished building target: "$@"'
	@echo ' '

christian_monitoring_app.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-arm_20.2.1.LTS/bin/armhex" --memwidth=8 --romwidth=8 -o "christian_monitoring_app.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "startup_msp432p401r_ccs.obj" "system_msp432p401r.obj" "MSP432P4xx\adc14.obj" "MSP432P4xx\aes256.obj" "MSP432P4xx\comp_e.obj" "MSP432P4xx\cpu.obj" "MSP432P4xx\crc32.obj" "MSP432P4xx\cs.obj" "MSP432P4xx\dma.obj" "MSP432P4xx\flash.obj" "MSP432P4xx\fpu.obj" "MSP432P4xx\gpio.obj" "MSP432P4xx\i2c.obj" "MSP432P4xx\interrupt.obj" "MSP432P4xx\mpu.obj" "MSP432P4xx\pcm.obj" "MSP432P4xx\pmap.obj" "MSP432P4xx\pss.obj" "MSP432P4xx\ref_a.obj" "MSP432P4xx\reset.obj" "MSP432P4xx\rtc_c.obj" "MSP432P4xx\spi.obj" "MSP432P4xx\sysctl.obj" "MSP432P4xx\systick.obj" "MSP432P4xx\timer32.obj" "MSP432P4xx\timer_a.obj" "MSP432P4xx\uart.obj" "MSP432P4xx\wdt_a.obj" 
	-$(RM) "main.d" "startup_msp432p401r_ccs.d" "system_msp432p401r.d" "MSP432P4xx\adc14.d" "MSP432P4xx\aes256.d" "MSP432P4xx\comp_e.d" "MSP432P4xx\cpu.d" "MSP432P4xx\crc32.d" "MSP432P4xx\cs.d" "MSP432P4xx\dma.d" "MSP432P4xx\flash.d" "MSP432P4xx\fpu.d" "MSP432P4xx\gpio.d" "MSP432P4xx\i2c.d" "MSP432P4xx\interrupt.d" "MSP432P4xx\mpu.d" "MSP432P4xx\pcm.d" "MSP432P4xx\pmap.d" "MSP432P4xx\pss.d" "MSP432P4xx\ref_a.d" "MSP432P4xx\reset.d" "MSP432P4xx\rtc_c.d" "MSP432P4xx\spi.d" "MSP432P4xx\sysctl.d" "MSP432P4xx\systick.d" "MSP432P4xx\timer32.d" "MSP432P4xx\timer_a.d" "MSP432P4xx\uart.d" "MSP432P4xx\wdt_a.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

