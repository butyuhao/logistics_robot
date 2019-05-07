#include <Adafruit_SSD1306.h>
#include <splash.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#if (SSD1306_LCDHEIGHT != 64)
#endif
void setup()   {
Serial.begin(9600);
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)
// init done
display.display();
delay(2000);

display.clearDisplay();
// draw a single pixel画一个像素点
display.drawPixel(10, 10, WHITE);
display.display();
delay(2000);
display.clearDisplay();

// 文字显示测试
display.setTextSize(2);//字体大小
display.setTextColor(WHITE);//文字颜色
display.setCursor(0,0);//设置游标位置

}
void loop() {
display.println("T1:438");
display.println("T2:843");
// 'inverted' text白底黑字

display.display();
//delay(2000);
//display.clearDisplay();
}
