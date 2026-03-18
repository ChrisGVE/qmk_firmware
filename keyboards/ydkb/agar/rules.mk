# MCU name
MCU = STM32F103
BOARD = MAPLEMINI_STM32_F103

# Bootloader selection
MCU_LDSCRIPT = STM32F103CBT6_uf2_bootloader
BOOTLOADER = custom

# Custom matrix file
CUSTOM_MATRIX = yes
SRC += matrix.c

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
OPT_DEFS += -DCORTEX_VTOR_INIT=0x4000
