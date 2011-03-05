#include <msp430g2231.h>
#include <signal.h>
#include <stdint.h>

#define LED0			BIT0
#define LED1			BIT6
#define LED_OUT		P1OUT

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

	P1DIR |= (LED0|LED1); // Set P1.0 to output direction
  P1OUT = LED0;        // Turn on LED0


	P1IE 	|= BIT3; // P1.3 interrupt enabled
	P1IES |= BIT3; // P1.3 Hi/lo edge
	P1IFG &= ~BIT3; // P1.3 IFG cleared

	_BIS_SR(GIE); // Enter LPM4 w/interrupt
}

// Port 1 interrupt service routine
interrupt(PORT1_VECTOR) Port_1(void)
{
	LED_OUT ^= (LED0|LED1);
	P1IFG 	&= ~BIT3; // P1.3 IFG cleared. Acknowledge the transition
}
