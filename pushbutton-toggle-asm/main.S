	#include "msp430g2231.h"


	.text
	.global	main

main:	mov	#__stack, r1		; Set the stack pointer
	mov	#WDTPW+WDTHOLD, &WDTCTL	; Stop watchdog timer
	bis.b	#BIT0 | BIT6, &P1DIR
	bis.b	#BIT3, &P1IE
	bis.b	#BIT3, &P1IES
	bic.b	#BIT3, &P1IFG
	mov	#BIT0, &P1OUT
	bis.b	#GIE, r2

	br	#__stop_progExec__

#define INTERRUPT_BASE	ffe0

	.global	Port_1
       	.global	vector_ffe4



vector_ffe4:
Port_1: xor.b	#BIT0 | BIT6, &P1OUT
	bic.b	#BIT3, &P1IFG
	reti
