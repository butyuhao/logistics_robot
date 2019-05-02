int Led = 13; //定义LED 接口
int detector2 = 30;//定义寻线传感器接口
int detector3 = 36;
int line2,line3;//定义数字变量val
void setup()
{ 
  pinMode(Led, OUTPUT); //定义LED 为输出接口  
  pinMode(detector2, INPUT);
  pinMode(detector3, INPUT);//定义寻线传感器为输出接口
  Serial.begin(9600);
  }
  void loop(){ 
    line2 = digitalRead(detector2); //将数字接口3的值读取赋给val  
    line3 = digitalRead(detector3);//将数字接口3的值读取赋给line2
 
    if (line2 == HIGH) //当检测到白色，则会变成low 
    {    digitalWrite(Led, HIGH);  
    Serial.println(2);}  
    else  {    digitalWrite(Led, LOW);  }

    if (line3 == HIGH) //当检测到白色，则会变成low
    {    digitalWrite(Led, HIGH);  
    Serial.println(3);}  
    else  {    digitalWrite(Led, LOW);  }
    }
    

    
    
