//#include "algorithm.h"


#define M1     2
#define DIR1   24

#define M2     3
#define DIR2   26

#define M3     4
#define DIR3   28
//定义寻线传感器接口
int detector1 = 30;
int detector2 = 32;
int detector3 = 34;
int detector4 = 36;

char color[4];
int is_get_object=0;

//四个巡线器当前检测到的值
int  line1; 
int  line2;
int  line3;
int  line4;

int x;//缓存函数
String comdata = "";//字符串函数

int grid_count=0;
int pre_state_flag=0;
int state_change_flag = 0;

int grid_count1=0;
int pre_state_flag1=0;
int state_change_flag1= 0;

int grid_count2=0;
int pre_state_flag2=0;
int state_change_flag2= 0;

int grid_count3=0;
int pre_state_flag3=0;
int state_change_flag3= 0;

int grid_count4=0;
int pre_state_flag4=0;
int state_change_flag4= 0;

int is_qrcode = 0;//是否已经扫描qrcode完毕

unsigned long starttime = 0;

void forward(int pwm){
  digitalWrite(DIR1, 0);
  analogWrite(M1, pwm);
  digitalWrite(DIR2, 1);
  analogWrite(M2, 255-pwm);
  digitalWrite(DIR3, 0);
  analogWrite(M3,0);
  }
void left_minor(int pwm){
  digitalWrite(DIR1, 0);
  analogWrite(M1, pwm);
  digitalWrite(DIR2, 1);
  analogWrite(M2, 255-pwm-30);
  digitalWrite(DIR3, 0);
  analogWrite(M3, 0);
 // analogWrite(M3, 0);
  }
void right_minor(int pwm){
  digitalWrite(DIR1, 0);
  analogWrite(M1, pwm+30);
  digitalWrite(DIR2, 1);
  analogWrite(M2, 255-pwm);
  digitalWrite(DIR3, 0);
  analogWrite(M3, 0);
  }
void backward(int pwm){
  digitalWrite(DIR1, 1);
  analogWrite(M1, 255-pwm);
  digitalWrite(DIR2, 0);
  analogWrite(M2, pwm);
  digitalWrite(DIR3, 0);
  analogWrite(M3,0);
  }
void back_left_minor(int pwm){
  digitalWrite(DIR1, 1);
  analogWrite(M1, 255-pwm);
  digitalWrite(DIR2, 0);
  analogWrite(M2, pwm);
  digitalWrite(DIR3, 1);
  analogWrite(M3, pwm+100);
 // analogWrite(M3, 0);
  }
void back_right_minor(int pwm){
  digitalWrite(DIR1, 1);
  analogWrite(M1, 255-pwm);
  digitalWrite(DIR2, 0);
  analogWrite(M2,pwm);
  digitalWrite(DIR3, 0);
  analogWrite(M3, 255-pwm-100);
  }

void left_paralle(int pwm)
{
   digitalWrite(DIR1, 0);
  analogWrite(M1,pwm );
  digitalWrite(DIR2, 0);
  analogWrite(M2,pwm);
  digitalWrite(DIR3,1);
  analogWrite(M3,255-pwm-183);
 }

void right_paralle(int pwm)
{
   digitalWrite(DIR1, 0);
  analogWrite(M1,pwm );
  digitalWrite(DIR2, 0);
  analogWrite(M2,pwm);
  digitalWrite(DIR3,1);
  analogWrite(M3,pwm+100);
 }
void turn_left(int pwm){
  digitalWrite(DIR1, 0);
  analogWrite(M1, pwm);
  digitalWrite(DIR2, 0);
  analogWrite(M2, pwm);
  digitalWrite(DIR3, 0);
  analogWrite(M3,pwm);
  }
  void turn_right(int pwm){
  digitalWrite(DIR1, 1);
  analogWrite(M1, 255-pwm);
  digitalWrite(DIR2, 1);
  analogWrite(M2,255- pwm);
  digitalWrite(DIR3, 1);
  analogWrite(M3,255-pwm-20);
  }
 void stop(){
  digitalWrite(DIR1, 0);
  analogWrite(M1, 0);
  digitalWrite(DIR2, 0);
  analogWrite(M2, 0);
  digitalWrite(DIR3, 0);
  analogWrite(M3,0);
  } 
  
  void turn_left_l2fl(){
      forward(83);
  delay(1300);
  turn_left(83);
  delay(1000);
  line1 = digitalRead(detector1); 
  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);

  state_change_flag1 = line1;
  state_change_flag2 = line2;
  state_change_flag3 = line3;
  state_change_flag4 = line4;
  grid_count1=0;
  grid_count2=0;
  grid_count3=0;
  grid_count4=0;
  while(grid_count1!=1 || grid_count2!=1){
  line1 = digitalRead(detector1); 
  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);
  if(line1==1){
    grid_count1=1;
    }
  if(line2==1){
    grid_count2=1;
    }
  if(line3==1){
    grid_count3=1;
    } 
}
stop();
grid_count=0;
while(grid_count<1){
  line1 = digitalRead(detector1); 
  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);

    state_change_flag = line1;
  if(state_change_flag!=pre_state_flag&&line1==line3 ){
    pre_state_flag = state_change_flag;
   if(pre_state_flag==0){
    grid_count++;
   }  
}
  if (line3 == HIGH&&line2 == LOW) //当检测到白色，则会变成low
    {    
     back_right_minor(83);
    } 
  else if (line2 == HIGH&&line3 == LOW) //当检测到白色，则会变成low
    {    
      back_left_minor(83);
       
      
    }
  else  //当检测到白色，则会变成low
    {    
      backward(83);
    }
    //如果走过2个格子就停下来
  if(grid_count==1){
  digitalWrite(DIR1, 0);
  analogWrite(M1, 0);
  digitalWrite(DIR2, 0);
  analogWrite(M2, 0);
  digitalWrite(DIR3, 0);
  analogWrite(M3,0);
    }
  }
  stop();
    }
  void turn_right_start(){//启动时用的那个右转
      forward(83);
  delay(1000);
  turn_right(83);
  delay(1000);
  line1 = digitalRead(detector1); 
  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);

  state_change_flag1 = line1;
  state_change_flag2 = line2;
  state_change_flag3 = line3;
  state_change_flag4 = line4;
  grid_count1=0;
  grid_count2=0;
  grid_count3=0;
  grid_count4=0;
  while(grid_count2!=1 || grid_count4!=1){

  line2 = digitalRead(detector2);
  line4 = digitalRead(detector4);

  if(line4==1){
    grid_count4=1;
    }
  if(line2==1){
    grid_count2=1;
    } 
}
stop();
    }

      void turn_left_fl2l(){
      forward(83);
  delay(1300);
  turn_left(83);
  delay(1000);
  line1 = digitalRead(detector1); 
  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);

  state_change_flag1 = line1;
  state_change_flag2 = line2;
  state_change_flag3 = line3;
  state_change_flag4 = line4;
  grid_count1=0;
  grid_count2=0;
  grid_count3=0;
  grid_count4=0;
  while(grid_count1!=1 || grid_count3!=1){
  line1 = digitalRead(detector1); 
  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);
  if(line1==1){
    grid_count1=1;
    }
  if(line3==1){
    grid_count3=1;
    } 
}
stop();
grid_count=0;
while(grid_count<1){
  line1 = digitalRead(detector1); 
  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);

    state_change_flag = line1;
  if(state_change_flag!=pre_state_flag&&line1==line3 ){
    pre_state_flag = state_change_flag;
   if(pre_state_flag==0){
    grid_count++;
   }  
}
  if (line3 == HIGH&&line2 == LOW) //当检测到白色，则会变成low
    {    
     back_right_minor(83);
    } 
  else if (line2 == HIGH&&line3 == LOW) //当检测到白色，则会变成low
    {    
      back_left_minor(83);
       
      
    }
  else  //当检测到白色，则会变成low
    {    
      backward(83);
    }
    //如果走过2个格子就停下来
  if(grid_count==1){
  digitalWrite(DIR1, 0);
  analogWrite(M1, 0);
  digitalWrite(DIR2, 0);
  analogWrite(M2, 0);
  digitalWrite(DIR3, 0);
  analogWrite(M3,0);
    }
  }
  stop();
    }
  
void turn_right_l2fl(){
      forward(83);
  delay(1000);
  turn_right(83);
  delay(1000);
  line1 = digitalRead(detector1); 
  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);

  state_change_flag1 = line1;
  state_change_flag2 = line2;
  state_change_flag3 = line3;
  state_change_flag4 = line4;
  grid_count1=0;
  grid_count2=0;
  grid_count3=0;
  grid_count4=0;
  while(grid_count3!=1 || grid_count4!=1){

  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);

  if(line4==1){
    grid_count4=1;
    }
  if(line3==1){
    grid_count3=1;
    } 
}
stop();
grid_count=0;
while(grid_count<1){
  line1 = digitalRead(detector1); 
  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);

    state_change_flag = line1;
  if(state_change_flag!=pre_state_flag&&line1==line3 ){
    pre_state_flag = state_change_flag;
   if(pre_state_flag==0){
    grid_count++;
   }  
}
  if (line3 == HIGH&&line2 == LOW) //当检测到白色，则会变成low
    {    
     back_right_minor(83);
    } 
  else if (line2 == HIGH&&line3 == LOW) //当检测到白色，则会变成low
    {    
      back_left_minor(83);
       
      
    }
  else  //当检测到白色，则会变成low
    {    
      backward(83);
    }
    //如果走过1个格子就停下来
  if(grid_count==1){
  digitalWrite(DIR1, 0);
  analogWrite(M1, 0);
  digitalWrite(DIR2, 0);
  analogWrite(M2, 0);
  digitalWrite(DIR3, 0);
  analogWrite(M3,0);
    }
  }
  stop();
    }
void turn_right_fl2l(){
      forward(83);
  delay(1000);
  turn_right(83);
  delay(1000);
  line1 = digitalRead(detector1); 
  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);

  state_change_flag1 = line1;
  state_change_flag2 = line2;
  state_change_flag3 = line3;
  state_change_flag4 = line4;
  grid_count1=0;
  grid_count2=0;
  grid_count3=0;
  grid_count4=0;
  while(grid_count2!=1 || grid_count4!=1){

  line2 = digitalRead(detector2);
  line4 = digitalRead(detector4);

  if(line4==1){
    grid_count4=1;
    }
  if(line2==1){
    grid_count2=1;
    } 
}
stop();
grid_count=0;
while(grid_count<1){
  line1 = digitalRead(detector1); 
  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);

    state_change_flag = line1;
  if(state_change_flag!=pre_state_flag&&line1==line3 ){
    pre_state_flag = state_change_flag;
   if(pre_state_flag==0){
    grid_count++;
   }  
}
  if (line3 == HIGH&&line2 == LOW) //当检测到白色，则会变成low
    {    
     back_right_minor(83);
    } 
  else if (line2 == HIGH&&line3 == LOW) //当检测到白色，则会变成low
    {    
      back_left_minor(83);
       
      
    }
  else  //当检测到白色，则会变成low
    {    
      backward(83);
    }
    //如果走过1个格子就停下来
  if(grid_count==1){
  digitalWrite(DIR1, 0);
  analogWrite(M1, 0);
  digitalWrite(DIR2, 0);
  analogWrite(M2, 0);
  digitalWrite(DIR3, 0);
  analogWrite(M3,0);
    }
  }
  stop();
    }

void forward_on_line(int step_num){
  grid_count=0;
  while(grid_count<step_num){
  line1 = digitalRead(detector1); 
  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);

    state_change_flag = line1;
  if(state_change_flag!=pre_state_flag&&line1==line3){
    pre_state_flag = state_change_flag;
   if(pre_state_flag==0){
    grid_count++;
   }  
}
  if (line4 == HIGH&&line2 == LOW) //当检测到白色，则会变成low
    {    
     left_minor(83);
    } 
  else if (line2 == HIGH&&line4 == LOW) //当检测到白色，则会变成low
    {    
      right_minor(83 );
       
      
    }
  else  //当检测到白色，则会变成low
    {    
      forward(83);
    }

    //如果走过6个格子就停下来
  if(grid_count==step_num){
  digitalWrite(DIR1, 0);
  analogWrite(M1, 0);
  digitalWrite(DIR2, 0);
  analogWrite(M2, 0);
  digitalWrite(DIR3, 0);
  analogWrite(M3,0);
    }
  }
  }
  void forward_on_fine_line(int step_num){
  step_num *=2;
  grid_count=0;
  while(grid_count<step_num){
  line1 = digitalRead(detector1); 
  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);

    state_change_flag = line1;
  if(state_change_flag!=pre_state_flag&&line1==line4){
    pre_state_flag = state_change_flag;
   if(pre_state_flag==0){
    grid_count++;
   }  
}
  if (line3 == HIGH&&line2 == LOW) //当检测到白色，则会变成low
    {    
     left_minor(83);
    } 
  else if (line2 == HIGH&&line3 == LOW) //当检测到白色，则会变成low
    {    
      right_minor(83 );
       
      
    }
  else  //当检测到白色，则会变成low
    {    
      forward(83);
    }

    //如果走过6个格子就停下来
  if(grid_count==step_num){
  digitalWrite(DIR1, 0);
  analogWrite(M1, 0);
  digitalWrite(DIR2, 0);
  analogWrite(M2, 0);
  digitalWrite(DIR3, 0);
  analogWrite(M3,0);
    }
  }
  }
void turn_around_on_fl(){
  
    digitalWrite(DIR1, 1);
  analogWrite(M1, 195);
  digitalWrite(DIR2, 1);
  analogWrite(M2, 195);
  digitalWrite(DIR3, 1);
  analogWrite(M3,175);
delay(2000);
 line1 = digitalRead(detector1); 
  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);

  state_change_flag1 = line1;
  state_change_flag2 = line2;
  state_change_flag3 = line3;
  state_change_flag4 = line4;
  grid_count1=0;
  grid_count2=0;
  grid_count3=0;
  grid_count4=0;
  while(grid_count2!=1 || grid_count3!=1){

  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);

  if(line3==1){
    grid_count3=1;
    }
  if(line2==1){
    grid_count2=1;
    } 
}
stop();
}
void backward_on_line(int step_num){
  grid_count=0;
  while(grid_count<step_num){
  line1 = digitalRead(detector1); 
  line2 = digitalRead(detector2);
  line3 = digitalRead(detector3);
  line4 = digitalRead(detector4);

    state_change_flag = line1;
  if(state_change_flag!=pre_state_flag&&line1==line3){
    pre_state_flag = state_change_flag;
   if(pre_state_flag==0){
    grid_count++;
   }  
}
  if (line4 == HIGH&&line2 == LOW) //当检测到白色，则会变成low
    {    
     back_right_minor(83);
    } 
  else if (line2 == HIGH&&line4 == LOW) //当检测到白色，则会变成low
    {    
      back_left_minor(83);
       
      
    }
  else  //当检测到白色，则会变成low
    {    
      backward(83);
    }
    Serial.println("grid_count");
    Serial.println(grid_count);
    //如果走过2个格子就停下来
  if(grid_count==step_num){
   
      digitalWrite(DIR1, 0);
  analogWrite(M1, 0);
  digitalWrite(DIR2, 0);
  analogWrite(M2, 0);
  digitalWrite(DIR3, 0);
  analogWrite(M3,0);
      
          
    }
  }
  }
void get_color(int num){
  int digit;
  for(int i=1;i<=3;i++){
  digit = num%10;
  num = num/10;
  if(digit==1){
    color[i] = 'r';
    }
  if(digit==2){
    color[i] = 'g';
    }
  if(digit==3){
    color[i] = 'b';
    }
    }
  
  
  }  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//computer
  Serial2.begin(9600);//openmv
  Serial3.begin(9600);//qrcode
  
  pinMode(DIR1,OUTPUT); 
   pinMode(DIR2,OUTPUT); 
   pinMode(DIR3,OUTPUT); 


  starttime = millis();
}
void run_task(){
  forward_on_line(1);
  turn_right_start();
  forward_on_line(6);
  backward_on_line(3);
  forward_on_line(1);
  turn_right_l2fl();
  }

void loop() {
//开始读取二维码



 while(is_qrcode==0){
      if (Serial2.available() > 0)//判读是否串口有数据
  {
    String comdata = "";//缓存清零
    while (Serial2.available() > 0)//循环串口是否有数据
    {
      comdata += char(Serial2.read());//叠加数据到comdata
      delay(2);//延时等待响应
    }
    if (comdata.length() > 0)//如果comdata有数据
    {
      Serial2.println(comdata);//打印comdata数据
      Serial.println(comdata);
      is_qrcode=0;//读取完毕
    }
  }}

/*
while((millis()-starttime)<=830){
  forward_on_fine_line(1);
  Serial.println(millis()-starttime);
  }
*/ 
/*   
stop();
//以下是一个物料台的判断
is_get_object=0;
//判断是不是
//是的话赋值为1
if(is_get_object==0){
  left_paralle(80);
delay(1500);
stop();
//判断是不是
//是的话赋值为1
  }
if(is_get_object==0){
  right_paralle(80);
delay(3000);
stop();
//判断是不是
//是的话赋值为1
  }
 left_paralle(80);
 delay(1500);
 stop();
*/

  //右转
  //抬起机械臂扫描
  //移动到目标块前
  //抓取
  //回到标准位置（中心）
  //行驶到对面中心
  //扫描
  //到正确的位置上
  //放下木块
  //回到中心点
  //转到背面
  //开回
  while(1);
  
}
