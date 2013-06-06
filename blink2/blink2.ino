void setup() {                
     P1DIR |= BIT6;                  // P1.6 to output
   CCR0 = 65536-1;                // PWM Period
   CCTL1 = OUTMOD_7;        // CCR1 reset/set
   CCR1 = 100;                       // CCR1 PWM duty cycle
   TACTL = TASSEL_2 + MC_1 + ID_3;   // SMCLK, up mode, divide clock by 8
   CCTL0 = CCIE;                   //Enable timer interrupts
   _BIS_SR(LPM0_bits);         // Enter LPM0   
}

void loop() {
	//Don't do anything here...we are waiting for interrupts!
}

#pragma vector=TIMER0_A0_VECTOR    //These two lines say this is an ISR
__interrupt void Timer_A(void) {                //cont.
P1OUT ^= BIT6;                                //Toggle pin 1.0
}


