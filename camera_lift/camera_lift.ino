
#include <Servo.h>    // 声明调用Servo.h库
Servo myservo1; // 创建4个舵机对象，1是机械手抓取部分
Servo myservo2;
Servo myservo3;
Servo myservo4;
int pos1 = 0;          // 变量pos用来存储舵机位置
int pos2 = 0;  
int pos3 = 0;  
int pos4 = 0;  
int i=0;               //执行计数

void setup() { 
    myservo1.attach(13);  // 将引脚9上的舵机与声明的舵机对象连接起来
    myservo2.attach(12);
    myservo3.attach(11);
    myservo4.attach(7);
    Serial.begin(9600);
} 


void loop() {
  // put your main code here, to run repeatedly:
 for(i ;i<=1;i++){//执行两次到达指定位置
  // 大臂
 
     for(pos4 =150; pos4>=30; pos4-=1) {    // 舵机从180°转回到0°，每次减小1°                               
       myservo4.write(pos4);        // 写角度到舵机     
       delay(40);                 // 延时15ms让舵机转到指定位置

 
    } 

 //舵机2
    for(pos2 = 150; pos2>=30; pos2-=1) {    // 舵机从180°转回到0°，每次减小1°                               
       myservo2.write(pos2);        // 写角度到舵机     
       delay(15);                 // 延时15ms让舵机转到指定位置
       Serial.println(0);
    } 
    
   delay(10);


 //中臂
 
 
      for(pos3 = 180; pos3>=90; pos3-=1) {    // 舵机从180°转回到0°，每次减小1°                               
       myservo3.write(pos3);        // 写角度到舵机     
       delay(20);                 // 延时15ms让舵机转到指定位置
       Serial.println(0);
    } 
}
}
