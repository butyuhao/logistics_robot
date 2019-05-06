#define M1     2
#define DIR1   24

#define M2     3
#define DIR2   26

#define M3     4
#define DIR3   28

int detector1 = 30;//定义寻线传感器接口
int detector2 = 32;
int detector3 = 34;
int detector4 = 36;

int grid_count=0;
int pre_state_flag=0;
int state_change_flag = 0;

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
  analogWrite(M3,255-pwm-100);
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
 
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  pinMode(DIR1,OUTPUT); 
   pinMode(DIR2,OUTPUT); 
   pinMode(DIR3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int  line1 = digitalRead(detector1); 
int  line2 = digitalRead(detector2);
int  line3 = digitalRead(detector3);
int  line4 = digitalRead(detector4);
 state_change_flag = line1;
  if(state_change_flag!=pre_state_flag){
    pre_state_flag = state_change_flag;
   if(pre_state_flag==0){
    grid_count++;
   }
   
    }

/*注释掉的为后行
  if (line4 == HIGH&&line2 == LOW) //当检测到白色，则会变成low
    {    
     back_right_minor(60);
    } 
  else if (line2 == HIGH&&line4 == LOW) //当检测到白色，则会变成low
    {    
      back_left_minor(60);
       
      
    }
  else  //当检测到白色，则会变成low
    {    
      backward(60);
    }
    Serial.println("grid_count");
    Serial.println(grid_count);
    //如果走过2个格子就停下来
  if(grid_count==2){
    while(1){
      digitalWrite(DIR1, 0);
  analogWrite(M1, 0);
  digitalWrite(DIR2, 0);
  analogWrite(M2, 0);
  digitalWrite(DIR3, 0);
  analogWrite(M3,0);
      
            }
    }
    */
left_paralle(60);
}
