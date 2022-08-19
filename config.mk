OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
CPP = arm-none-eabi-cpp
CC = arm-none-eabi-gcc -mthumb -mcpu=cortex-m0plus -msoft-float
AS = arm-none-eabi-as -mthumb
LD = arm-none-eabi-ld
AR = arm-none-eabi-ar
GDB = arm-none-eabi-gdb
OPENOCD = openocd -c 'set CPUTAPID 0x0bc11477' -f interface/stlink.cfg -f target/at91samdXX.cfg
SDK_OBJ = ${SDK}/init.o
