# Local wireless stack (cannot use consolidated common which lacks wireless)
Q60_MAX_COMMON_DIR = q60_max_common

OPT_DEFS += -DLK_WIRELESS_ENABLE
OPT_DEFS += -DNO_USB_STARTUP_CHECK
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

SRC += \
    $(Q60_MAX_COMMON_DIR)/wireless/wireless.c \
    $(Q60_MAX_COMMON_DIR)/wireless/report_buffer.c \
    $(Q60_MAX_COMMON_DIR)/wireless/lkbt51.c \
    $(Q60_MAX_COMMON_DIR)/wireless/indicator.c \
    $(Q60_MAX_COMMON_DIR)/wireless/wireless_main.c \
    $(Q60_MAX_COMMON_DIR)/wireless/transport.c \
    $(Q60_MAX_COMMON_DIR)/wireless/lpm.c \
    $(Q60_MAX_COMMON_DIR)/wireless/lpm_stm32f401.c \
    $(Q60_MAX_COMMON_DIR)/wireless/battery.c \
    $(Q60_MAX_COMMON_DIR)/wireless/bat_level_animation.c \
    $(Q60_MAX_COMMON_DIR)/wireless/rtc_timer.c \
    $(Q60_MAX_COMMON_DIR)/wireless/keychron_wireless_common.c

# Local keychron common (extended version with factory test & task pipeline)
OPT_DEFS += -DFACTORY_TEST_ENABLE

SRC += \
    $(Q60_MAX_COMMON_DIR)/keychron_task.c \
    $(Q60_MAX_COMMON_DIR)/keychron_common.c \
    $(Q60_MAX_COMMON_DIR)/factory_test.c

VPATH += $(TOP_DIR)/keyboards/keychron/q60_max/$(Q60_MAX_COMMON_DIR)
VPATH += $(TOP_DIR)/keyboards/keychron/q60_max/$(Q60_MAX_COMMON_DIR)/wireless

# Custom SPI RGB matrix driver (upstream QMK only has I2C variant)
SRC += snled27351-spi.c
QUANTUM_LIB_SRC += spi_master.c
VPATH += $(TOP_DIR)/keyboards/keychron/q60_max
