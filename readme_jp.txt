Tiny NS-Tower for Arduboy

■転送方法
windows版「Arduino IDE」の付属ツールを使って転送します。

このフォルダにある「test.bat」をテキストエディタで開いて
VAL1～VAL4（2行目～5行目）を環境に合わせて修正してください。

ArduboyをUSB接続して「test.bat」を実行すれば転送されます。


■ルール
上を目指して登ってください。ゴールは30階です。


■遊び方
Ａ or 左ボタン　ジャンプ
上ボタン　　　　リセット


■開発環境
・Windows 8.1 pro
・Arduino IDE 1.6.7
・Arduino IDE 1.0.6(make.exeのみ使用。最新に入っていない為)
・Visual Studio 2015 C#
・Python 2.7 + pil


■履歴
v1.00 2016/03/06    とりあえず完成


AVR Memory Usage
----------------
Device: atmega32u4

Program:   16086 bytes (49.1% Full)
(.text + .data + .bootloader)

Data:       1554 bytes (60.7% Full)
(.data + .bss + .noinit)
