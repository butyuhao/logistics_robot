int Led = 13; //定义LED 接口
int buttonpin = 8;//定义寻线传感器接口
int line1,line2;//定义数字变量val
void setup()
{ 
  pinMode(Led, OUTPUT); //定义LED 为输出接口  
  pinMode(buttonpin, INPUT); //定义寻线传感器为输出接口
  Serial.begin(9600);
  }
  void loop(){ 
    line1 = digitalRead(buttonpin); //将数字接口3的值读取赋给val  
    line2 = digitalRead(10);//将数字接口3的值读取赋给line2
 
    if (line1 == HIGH) //当寻线传感器检测有信号时，LED 闪烁 
    {    digitalWrite(Led, HIGH);  
    Serial.println(1);}  
    else  {    digitalWrite(Led, LOW); 
    Serial.println(0); }
    }
