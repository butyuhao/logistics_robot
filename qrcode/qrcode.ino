
int x;//缓存函数
String comdata = "";//字符串函数
void setup() {
  Serial.begin(9600);//打开串口波特率9600
}
 
void loop() {
 
    while (Serial.available() > 0)  
    {
        comdata += char(Serial.read());
        delay(2);
    }
    
   if (comdata.length() > 0)
    {
       Serial.println(comdata);
       comdata = "";
    }
}
