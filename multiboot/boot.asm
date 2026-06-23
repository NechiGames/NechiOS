section .multiboot
align 4
dd 0x1BADB002
dd 0
dd -(0x1BADB002)
section .text
global _start
extern kernel_main
ST:
call kernel_main
loop:
cli
hlt
jmp loop
; new update :)
; This is my lang btw ;)
