
#include "msp430g2x31.inc"

BIT0 equ 0x0001
BIT3 equ 0x0008
BIT6 equ 0x0100
GIE  equ BIT3


	org 0xf800

start:
	mov.w 	#WDTPW|WDTHOLD, &WDTCTL
	bis.b	#BIT0+BIT6, &P1DIR
	bis.b	#BIT3, &P1IE
	bis.b	#BIT3, &P1IES
	bic.b	#BIT3, &P1IFG
	mov	#BIT0, &P1OUT
	bis.b	#GIE, r2
loop:	jmp 	loop

timer1_isr:
	xor.b	#BIT0+BIT6, &P1OUT
	bic.b	#BIT3, &P1IFG
	reti

	org 	0xffe4
	dw 	timer1_isr

	org 	0xfffe
	dw 	start             ; set reset vector to 'init' label
