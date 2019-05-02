#include "include.h"
#include <string.h>
#include "algorithm.h"
#include <Math.h>
bool R_Running = FALSE;
bool L_Running = FALSE;
 

 float v1 ;
 float v2 ; 
 float v3 ;
 float v12,v13;
 float v21,v23;
 float v31,v32;
 float scale = 0; 
 float sscale = 0; 
 ActThreeVell vell_t;


void change_location(int X,int Y,bool Left, bool Right) {

  float x,y,z;
  x = X;
  y = Y;
  z = 0;

   if(x == 0 && y == 0)

   	{
       digitalWrite(DIR0, 0);
       digitalWrite(DIR1, 0);
	   digitalWrite(DIR2, 0);
	   analogWrite(M0, 0);
       analogWrite(M1, 0);
	   analogWrite(M2, 0);
    }


else{
   
    scale  = sqrt(x*x + y*y) / 128.0;    // ��ҡ��ƫ���λ�ú���� pwm ��Ӧ��
    if(scale > 1.0)
		 scale = 1.0;

    ThreeWheelVellControl2(x,y,0,0);   //  ��С�� x��   y������ٶ� ת��Ϊ3��������ٶ�
   vell_t = vell;

    v1 = abs(vell.v1);
    v2 = abs(vell.v2); 
    v3 = abs(vell.v3);

    sscale = 245.0*scale;
   if(v1 >=  v2 && v1 >= v3){

      v12 = v1 / v2 ;
      v13 = v1 / v3;

	  vell.v1 = sscale;
	  vell.v2 = sscale/v12;
      vell.v3 = sscale/v13;
   }
  else if(v2 >=  v1 && v2 >= v3){

      v21 = v2 / v1 ;
      v23 = v2 / v3;
	  vell.v2 = sscale;
	  vell.v1 = sscale/v21;
      vell.v3 = sscale/v23;

   }

  else if(v3 >=  v1 && v3 >= v2){

      v31 = v3 / v1 ;
      v32 = v3 / v2;
	  vell.v3 = sscale;
	  vell.v1 = sscale/v31;
      vell.v2 = sscale/v32;

   }
   if(vell_t.v1 < 0) vell.v1 = -vell.v1;
   if(vell_t.v2 < 0) vell.v2 = -vell.v2;
   if(vell_t.v3 < 0) vell.v3 = -vell.v3;

 
   #if 1
  { 
    static char cnt = 0;
	if(cnt++ == 10){
	cnt = 0 ;	
    Serial.print("v1= ");
	Serial.println(vell_t.v1);
    Serial.print("v2= ");
	Serial.println(vell_t.v2);
    Serial.print("v3= ");
	Serial.println(vell_t.v3);
	Serial.print("scale= ");
	Serial.println(scale);
    }
  }
    #endif

   if((int)vell.v1 >= 0){   // ���ø���������ٶȺͷ���
     digitalWrite(DIR0, 0);
	 analogWrite(M0, (int)vell.v1);
      
   }
   else if((int)vell.v1 < 1){
		digitalWrite(DIR0, 1);
		analogWrite(M0, 255+(int)vell.v1);
	 }

  if((int)vell.v2 >= 0){
	  digitalWrite(DIR1, 0);
	  analogWrite(M1, (int)vell.v2);
	   
	}
	else if((int)vell.v2 < 0){
		 digitalWrite(DIR1, 1);
		 analogWrite(M1, 255+(int)vell.v2);
	  }

   if((int)vell.v3 >= 0){
	   digitalWrite(DIR2, 0);
	   analogWrite(M2, (int)vell.v3);	
	 }
	 else if(vell.v3 < 0){
		  digitalWrite(DIR2, 1);
		  analogWrite(M2, 255+(int)vell.v3);
	   }
   }
if (Left==TRUE)    // ˳ʱ��ת
{
   
   #if 1
    digitalWrite(DIR0, 0);
    analogWrite(M0, 160);
    digitalWrite(DIR1, 0);
    analogWrite(M1, 160);
    digitalWrite(DIR2, 0);
    analogWrite(M2, 160);
	#endif  	  
 }

else if(Right==TRUE) {     // ��ʱ��ת
	digitalWrite(DIR0, 1);
    analogWrite(M0, 95);
    digitalWrite(DIR1, 1);
    analogWrite(M1, 95);
    digitalWrite(DIR2, 1);
    analogWrite(M2, 95);
 }

}
