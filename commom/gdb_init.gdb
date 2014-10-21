file stm32_executable.elf
target remote :4242
monitor reset halt
b main
c