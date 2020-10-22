//HONK MORE , WAIT MORE"
#include<reg51.h>
#define lcd P2
#define count P3
sbit sound=P1^4; 
sbit rs=P1^0; //register select
sbit rw=P1^1; //RW
sbit en=P1^2;//enable
sbit red=P1^5;
sbit yellow=P1^6;
sbit green=P1^7;
sbit buzzer=P1^3;
void lcd_init();
void cmd(unsigned char);
void dat(unsigned char);
void delay(unsigned int );
void lcd_string(char *s);
void lcd_counter();
void condition2();
void condition1();
unsigned int i,j;
void main()
{
	  buzzer=0;
	  red=yellow=green=0;         
    condition1();    
}	
void condition1(){
	lcd_init();
	lcd_string("Punishing Signal");
            cmd(0xc0);
            lcd_string("   Normal");
					while(1){
						unsigned char seg[10]={0x90,0x80,0xf8,0x82,0x92,0x99,0xb0,0xa4,0xf9,0xc0};
	for(i=0;i<10;i++)
	{
		if(sound==0)
		{
		 red=1;
		count=seg[i];
		//for(j=0;j<33000;j++);
			delay(40);
		}
		else
			condition2();
		
	}
					  red=0;
					  yellow=1;
					  for(i=0;i<30000;i++);
					 yellow=0;
					green=1;
					for(i=0;i<40000;i++);
					green=0;
					}
        //}
    }

void condition2()
{
lcd_init();
	
lcd_string("Sound Detected");
					  cmd(0xc0);
	lcd_string("Honk more,Wait more");
	while(1){				 
	unsigned char seg[10]=/*{0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};*/{0x90,0x80,0xf8,0x82,0x92,0x99,0xb0,0xa4,0xf9,0xc0};
	for(i=0;i<10;i++)
	{
		if(sound==1){
		 red=1;
			buzzer=1;
		count=seg[i];
		for(j=0;j<33000;j++);}
		else
			condition1();
	}
        }
}
 
void lcd_init()
{
    cmd(0x38);
    cmd(0x0e);
    cmd(0x06);
    cmd(0x01);
    cmd(0x80);
}
 
void cmd(unsigned char a)
{
    lcd=a;
    rs=0;
    rw=0;
    en=1;
    delay(10);
    en=0;
}
 
void dat(unsigned char b)
{
    lcd=b;
    rs=1;
    rw=0;
    en=1;
    delay(10);
    en=0;
}
void lcd_string(char *s)
{
    while(*s) {
       dat(*s++);
     }
}
void delay(unsigned int time)
{
    unsigned int i,j;
	for(i=0;i<time;i++)
    for(j=0;j<1275;j++);
}