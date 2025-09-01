#include <mega32.h> #include <alcd.h> #include <delay.h> 
// Globals 
char password[4] = {'0', '4', '=', '4'}; 
char key[4]; 
int index = 0; int flag = 0; int t = 0; 
// External Interrupt 0 ISR 
interrupt [EXT_INT0] void ext_int0_isr(void) {
  if (flag==0){ if (index < 4) {
    key[index] = (PINA & 0x0F) + '0'; lcd_gotoxy(10 + index, 0); 
    lcd_putchar('*'); index++; flag=1; } } }
void main (void)
{ // LCD init 
  lcd_init(16); 
lcd_clear(); 
lcd_gotoxy(0, 0); 
lcd_puts("password ="); 
// I/O init 
DDRA = 0x00; 
DDRC = 0xFF; 
DDRD = 0x00; 
// External interrupt config 
GICR |= (1 << INT0); MCUCR |= (1 << ISC01); 
// Falling edge 
MCUCR &= ~(1 << ISC00);
#asm("sei")
  while (1) { 
delay_ms(1); 
t++; 
if (flag ==1){
if (t>49 ){ flag =0; t=0; } } // When 4 keys are entered 
if (index == 4)
  { if (key[0] == password[0] && key[1] == password[1] && key[2] == password[2] && key[3] == password[3]) { 
lcd_gotoxy(0, 1); lcd_puts(" Correct! "); 
PORTC |= (1 << 0); // Set PC0 
delay_ms(3000); PORTC = 0x00; // Clear all after delay
} 
else
  { lcd_gotoxy(0, 1); 
   lcd_puts(" Not correct! "); 
   PORTC |= (1 << 1); 
   delay_ms(5000); 
   PORTC = 0x00; } 
// Reset for next entry
index = 0; lcd_clear(); 
   lcd_gotoxy(0, 0); 
   lcd_puts("password ="); }
} 
}
