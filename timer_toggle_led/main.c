#include <msp430g2231.h>
#include <signal.h>
#include <stdint.h>

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P1DIR |= 0x01;                            // P1.0 output
  CCTL0 = CCIE;                             // CCR0 interrupt enabled
  CCR0 = 50000;
  TACTL = TASSEL_2 + MC_2;                  // SMCLK, contmode

  _BIS_SR(LPM0_bits + GIE);                 // Enter LPM0 w/ interrupt
}

// Timer A0 interrupt service routine
interrupt(TIMERA0_VECTOR) Timer_A(void)
{
  P1OUT ^= 0x01;                            // Toggle P1.0
  CCR0 += 50000;                            // Add Offset to CCR0
}
