#include "include.h"
#include <avr/wdt.h>
#include <Wire.h>

void setup()    // ϵͳ��ʼ������
{ 

 //Wire.begin();
   delay(10);
   Serial.begin(9600); // ���ڲ���������
   delay(10);
   delay(10);
          //   PS2ң�س�ʼ��
   wdt_enable(WDTO_1S);  //  ���ÿ��Ź����ܣ�����ι��ʱ��Ϊ1S
   TCCR1B=((1<<CS10));   //   �޸Ķ�ʱ��2��ʱ��Ƶ�� ��pwm��Ƶ����Ϊ34K(arduino pwmĬ��Ƶ��Ϊ490�����͵�Ƶ�ʻ��ջ����������)
   TCCR2B=((1<<CS20));
   
   pinMode(DIR0,OUTPUT); 
   pinMode(DIR1,OUTPUT); 
   pinMode(DIR2,OUTPUT); 
//   pinMode(DIR3,OUTPUT); 
   
   analogWrite(M0, 0);  
   analogWrite(M1, 0);
   analogWrite(M2, 0);
//   analogWrite(M3, 0);
}
void loop() 
{
   //TaskRun();    
   //wdt_reset();  //  ι������
   change_location(-30,0);
   delay(2000);
   change_location(0,0);
   delay(2000);
}
