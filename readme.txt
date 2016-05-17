Tiny NS-Tower for Arduboy

## installation
Request : Arduino IDE 1.6.x

1. download from github
2. pls edit test.bat(windows) or test.sh(osx) for your computer(must change COM port number)
3. execute test.bat
4. play it


## Rule
player climb tower. goal is 30 floor.


## Controls
A / left : jump
up       : reset


## My development
compiler        : windows Arduino IDE 1.6.8(avr-gcc) + 1.0.6(make.exe)
image converter : python 2.6 + PIL
etc             : Visual Studio 2015 C#


## History
v1.02 2016/05/14    support arduboy 1.0.
v1.01 2016/03/24    forget moving plate init.
                    change game balance.
v1.00 2016/03/06    first version


Arduboy 1.0 infomation.

AVR Memory Usage
----------------
Device: atmega32u4

Program:   16090 bytes (49.1% Full)
(.text + .data + .bootloader)

Data:       1554 bytes (60.7% Full)
(.data + .bss + .noinit)
