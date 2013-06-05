#include "wiring.c"

// Unit size in milliseconds
#define UNIT 75

void setup() {
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(14, OUTPUT);
}

void loop(){
  digitalWrite(14, LOW);
  morse_string("hello world");
  digitalWrite(14, HIGH);
  delay_LPM1(2000); 
}

// modify the delay function to 
void delay_LPM1(uint32_t milliseconds)
{
	uint32_t wakeTime = wdtCounter + (milliseconds * WDT_TICKS_PER_MILISECOND);
        while(wdtCounter < wakeTime)
                /* Wait for WDT interrupt in LMP1 */
                __bis_status_register(LPM1_bits+GIE);
}

void long_blink(){
  digitalWrite(2, HIGH);
  delay_LPM1(UNIT * 3);
  digitalWrite(2, LOW);
  delay_LPM1(UNIT);
}

void short_blink(){
  digitalWrite(2, HIGH);
  delay_LPM1(UNIT);
  digitalWrite(2, LOW);
  delay_LPM1(UNIT);
}

void no_blink(){
  delay_LPM1(UNIT * 3);
}

void word_space(){
  delay_LPM1(UNIT*4); // Three unit delay_LPM1 in every letter
}

void morse_string(String message){
  for(int i = 0; i < message.length(); i++){
    morse_letter(message[i]);
  }
}

void morse_letter(char letter){
  noInterrupts();
  if(letter == ' '){
    word_space();
    return;
  }
  switch(letter){
      case 'a': // .-
      case 'A':
        short_blink(); long_blink(); no_blink(); break;
      case 'b': // -...
      case 'B':
        long_blink(); short_blink(); short_blink(); short_blink(); no_blink(); break;
      case 'c': // -.-.
      case 'C':
        long_blink(); short_blink(); long_blink(); short_blink(); no_blink(); break;
      case 'd': // -..
      case 'D':
        long_blink(); short_blink(); short_blink(); no_blink(); break;
      case 'e': // .
      case 'E':
        short_blink(); no_blink(); break;
      case 'f': // ..-.
      case 'F':
        short_blink(); short_blink(); long_blink(); short_blink(); no_blink(); break;
      case 'g': // --.
      case 'G':
        long_blink(); long_blink(); short_blink(); no_blink(); break;
      case 'h': // ....
      case 'H':
        short_blink(); short_blink(); short_blink(); short_blink(); no_blink(); break;
      case 'i': // ..
      case 'I':
        short_blink(); short_blink(); no_blink(); break;
      case 'j': // .---
      case 'J':
        short_blink(); long_blink(); long_blink(); long_blink(); no_blink(); break;
      case 'k': // -.-
      case 'K':
        long_blink(); short_blink(); long_blink(); no_blink(); break;
      case 'l': // .-..
      case 'L':
        short_blink(); long_blink(); short_blink(); short_blink(); no_blink(); break;
      case 'm': // --
      case 'M':
        long_blink(); long_blink(); no_blink(); break;
      case 'n': // -.
      case 'N':
        long_blink(); short_blink(); no_blink(); break;
      case 'o': // ---
      case 'O':
        long_blink(); long_blink(); long_blink(); no_blink(); break;
      case 'p': // .--.
      case 'P':
        short_blink(); long_blink(); long_blink(); short_blink(); no_blink(); break;
      case 'q': // --.-
      case 'Q':
        long_blink(); long_blink(); short_blink(); long_blink(); no_blink(); break;
      case 'r': // .-.
      case 'R':
        short_blink(); long_blink(); short_blink(); no_blink(); break;
      case 's': // ...
      case 'S':
        short_blink(); short_blink(); short_blink(); no_blink(); break;
      case 't': // -
      case 'T':
        long_blink; no_blink(); break;
      case 'u': // ..-
      case 'U':
        short_blink(); short_blink(); long_blink(); no_blink(); break;
      case 'v': // ...-
      case 'V':
        short_blink(); short_blink(); short_blink(); long_blink(); no_blink(); break;
      case 'w': // .--
      case 'W':
        short_blink(); long_blink(); long_blink(); no_blink(); break;
      case 'x': // -..-
      case 'X':
        long_blink(); short_blink(); short_blink(); long_blink(); no_blink(); break;
      case 'y': // -.--
      case 'Y':
        long_blink(); short_blink(); long_blink(); long_blink(); no_blink(); break;
      case 'z': // --..
      case 'Z':
        long_blink(); long_blink(); short_blink(); short_blink(); no_blink(); break;
      case '0': // -----
        long_blink(); long_blink(); long_blink(); long_blink(); long_blink(); no_blink(); break;
      case '1': // .----
        short_blink(); long_blink(); long_blink(); long_blink(); long_blink(); no_blink(); break;
      case '2': // ..---
        short_blink(); short_blink(); long_blink(); long_blink(); long_blink(); no_blink(); break;
      case '3': // ...--
        short_blink(); short_blink(); short_blink(); long_blink(); long_blink(); no_blink(); break;
      case '4': // ....-
        short_blink(); short_blink(); short_blink(); short_blink(); long_blink(); no_blink(); break;
      case '5': // .....
        short_blink(); short_blink(); short_blink(); short_blink(); short_blink(); no_blink(); break;
      case '6': // -....
        long_blink(); short_blink(); short_blink(); short_blink(); short_blink(); no_blink(); break;
      case '7': // --...
        long_blink(); long_blink(); short_blink(); short_blink(); short_blink(); no_blink(); break;
      case '8': // ---..
        long_blink(); long_blink(); long_blink(); short_blink(); short_blink(); no_blink(); break;
      case '9': // ----.
        long_blink(); long_blink(); long_blink(); long_blink(); short_blink(); no_blink(); break;
    }
    interrupts();
}
