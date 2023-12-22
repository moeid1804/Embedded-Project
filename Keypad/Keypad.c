/*
 * Keypad.c
 *
 * Created: 14/10/2019 1:35:59 PM
 * Author: Lost Heaven
 */

#include <mega16.h>
#include <alcd.h>
#include <delay.h>

//void E_write(unsigned int add,unsigned char* data);
//unsigned char E_read(unsigned int add);
char keypad();

void main(void)
{
    char number = 0;
    int line = 0;

    DDRC = 0b00000111;
    PORTC = 0b11111000;
    lcd_init(16);

    while (1)
    {
        number = keypad();
        lcd_gotoxy(line % 16, line / 16);
        lcd_putchar(number);
        line++;

        if (line >32) // Display 32 digits in two lines
        {
            lcd_clear();
            lcd_putchar(number);
            line = 1;
        }
    }
}


char keypad()
{
  while(1)
  {
   PORTC.0 = 0; //C0 is on, C1 and C2 are off
   PORTC.1 = 1;
   PORTC.2 = 1;
   
   switch (PINC)
          {
          case 0b11110110 :
          while(PINC.3 == 0);  // While the button is pressed, Wait!
          return '1';
          break;

          case 0b11101110 :
          while(PINC.4 == 0); 
          return '4';
          break;
          
          case 0b11011110 :
          while(PINC.5 == 0);  
          return '7';
          break;
          
          case 0b10111110 :
          while(PINC.6 == 0);  
          return '*';
          break;
          }
    
   PORTC.0 = 1; //C1 is on, C0 and C2 are off
   PORTC.1 = 0;
   PORTC.2 = 1;
   
   switch (PINC)
          {
          case 0b11110101 :
          while(PINC.3 == 0);  // While the button is pressed, Wait!
          return '2';
          break;

          case 0b11101101 :
          while(PINC.4 == 0);  
          return '5';
          break;
          
          case 0b11011101 :
          while(PINC.5 == 0);  /
          return '8';
          break;
          
          case 0b10111101 :
          while(PINC.6 == 0);  
          return '0';
          break;
          }
         
   PORTC.0 = 1; //C2 is on, C0 and C1 are off
   PORTC.1 = 1;
   PORTC.2 = 0;
   
   switch (PINC)
          {
          case 0b11110011 :
          while(PINC.3 == 0);  // While the button is pressed, Wait!
          return '3';
          break;

          case 0b11101011 :
          while(PINC.4 == 0);  
          return '6';
          break;
          
          case 0b11011011 :
          while(PINC.5 == 0);  
          return '9';
          break;
          
          case 0b10111011 :
          while(PINC.6 == 0);  
          return '#';
          break;
          }
   
  }
  }

