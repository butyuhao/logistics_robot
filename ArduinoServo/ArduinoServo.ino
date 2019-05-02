#include "include.h"
#include <avr/wdt.h>
#include <Wire.h>
int Led = 13; //定义LED 接口
int detector2 = 53;//定义寻线传感器接口
int detector3 = 51
;
int line2,line3;//定义数字变量val
void setup()    // ϵͳ��ʼ������
{ 

 //Wire.begin();
   delay(10);
   pinMode(Led, OUTPUT); //定义LED 为输出接口  
   pinMode(detector2, INPUT);
   pinMode(detector3, INPUT);//定义寻线传感器为输出接口
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
   
   analogWrite(M0, 0); //1 
   analogWrite(M1, 0);//2
   analogWrite(M2, 0);//3
//   analogWrite(M3, 0);
}
void loop() 
{
   //TaskRun();    
   //wdt_reset();  //  ι������
  /* line2 = digitalRead(detector2); //将数字接口3的值读取赋给val  
   line3 = digitalRead(detector3);//将数字接口3的值读取赋给line2
   if (line2 == LOW) //当检测到白色，则会变成low 
    {    digitalWrite(Led, HIGH); 
    change_location(-30,20,FALSE,FALSE); 
    Serial.println(2);
    }  
   else  {    digitalWrite(Led, LOW);  }

   if (line3 == LOW) //当检测到白色，则会变成low
    {     
    change_location(-30,-20,FALSE,FALSE); 
    }  
    if(line2==HIGH && line3==HIGH){
      
      change_location(-30,0,FALSE,FALSE); 
      }
     */
    // while(1){
     // change_location(0,0,FALSE,FALSE);
     // }
     digitalWrite(DIR0, 1);
     analogWrite(M0, 255);
     
      
   //当没有走到格子，就一直走
}
