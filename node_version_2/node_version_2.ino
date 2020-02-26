int sen1=0,sen2=1,sen3=2,sen4=3,sen5=4,sen6=5,s1,s2,s3,s4,s5,s6,spd=255,spdl=255,spdr=255,pin1=5,pin2=6,pin3=9,pin4=10;
int mx=0,mid=0,mn=0;
int i=0,j=0,cnt=0;
void minmax();
void nodeapproach();
void nodeleft();

void caliberleft();
void caliberright();
void straight();
void sstop();
void back();
void turnleft();
void turnright();
void turn_u_left();
void turn_u_right();

void setup() {
  
              // put your setup code here, to run once:
             pinMode(sen1,INPUT);
             pinMode(sen2,INPUT);
             pinMode(sen3,INPUT);
             pinMode(sen4,INPUT);
             pinMode(sen5,INPUT);
             pinMode(sen6,INPUT);

      Serial.begin(9600);
      
          }

void loop() {
  // put your main code here, to run repeatedly:

        
        s1=analogRead(sen1);   
        s2=analogRead(sen2);
        s3=analogRead(sen3);
        s4=analogRead(sen4);
        s5=analogRead(sen5);
        s6=analogRead(sen6);
                            //Calibrating the sensor, finding max and min reflectance values

        
   if(cnt==0)
                 { minmax();}
                         //start of callibration
if(((s3<mx)&&(s6>mx)&&(s1<mid))||((((s1+s2)<(s5+s6))&&(s3<mid)&&(s2<mid))))                    //Move right
{
  
 Serial.print("right\n");
  nodeapproach();
  spdr=0;
  spd=255;
  caliberright(); 
}
else if((s3>mx)&&(s4>mx)&&(s6<mid)&&(s1<mid))       //go straight
{
    Serial.print("straight\n");
      nodeapproach();
    straight();
}
else if(((s3<mx)&&(s1>mx)&&(s6<mid))||((((s1+s2)>(s5+s6))&&(s3<mid)&&(s2<mid)&&(s6<mid))))   //Move left
        
{
Serial.print("left\n");
  nodeapproach();
    spdl=0;
    spd=255;
caliberleft();
}


       else 
              straight();            
} 
                                         //end of program

                                                  //nodal functions
void nodeapproach()
{           if(s2>mid||s3<mid||s5>mid||s6>mid)
                      {
                        Serial.print("node approaching\n");                      
                      }
  }                             

void nodeleft()              //nodal functions for left justified
{ 
               
if((s2<mid)&&(s1<mid)&&(s3<mid)&&(s4<mid)&&(s5<mid)&&(s6<mid))  //u
{
  Serial.print("U TURN\n");
}

else if((s2 > mx)&&(s1 > mx)&&(s3 > mx)&&(s4 > mx)&&(s5 > mx)&&(s6 > mx))  //+
{     straight();
     delay(1000);
        s1=analogRead(sen1);   
        s2=analogRead(sen2);
        s3=analogRead(sen3);
        s4=analogRead(sen4);
        s5=analogRead(sen5);
        s6=analogRead(sen6);
     if((s2 > mx)&&(s1 > mx)&&(s3 > mx)&&(s4 > mx)&&(s5 > mx)&&(s6 > mx))      //Stop if all the sensors give low reflectance values
   {     
     Serial.print("end\n");
     }
     else
        {   
            delay(1500);
     Serial.print("+ NODE\n");
}}

else if((s2>mx)&&(s1>mx)&&(s3>mx)&&(s4>mx)&&(s5<mid)&&(s6<mid))  //  -|
{ 
   turnleft();
  Serial.print("LEFT NODE\n");
}

else if((s2<mid)&&(s1<mid)&&(s3>mx)&&(s4>mx)&&(s5>mx)&&(s6>mx))   //  |-
{
  straight();
            delay(1500);
  Serial.print("RIGHT NODE\n");
  }

else if((s2>mid)&&(s4>mx)&&(s5>mid)&&(s6>mx))   //T
{Serial.print("T NODE\n");
}
   else
   {
  nodeapproach();
   straight();
    Serial.print("UN DEFINED PATH\n");
    }
}       
void minmax()
{
  
for(int i=0; i<5000; i++)
{
int val = 0;
for(int j=0; j<=5; j++) 
{            if(j==2)
             {j=j+1;}          
val = analogRead(j);
if(val >= mx)
mx = val;
if(val <= mn)
mn = val;
}
delay(1);
}
mid = ((mx + mn)/2);
mid=mid+150;
mx=mx-200;
  cnt++; }              
  
void caliberleft()
{ 
  analogWrite(pin1,spdl);
  digitalWrite(pin2,0); 
  analogWrite(pin3,spdr);
  analogWrite(pin4,spd); 
 spdl=255;
 spdr=255;
}

void caliberright()
{ 
  analogWrite(pin1,spdl);
  digitalWrite(pin2,0); 
  analogWrite(pin3,spdr);
  digitalWrite(pin4,spd); 
 spdr=255;
spdl=255;
}

//straight back functions


void straight()
{ 
  analogWrite(pin1,spdl);
  digitalWrite(pin2,0); 
  analogWrite(pin3,spdr);
  digitalWrite(pin4,0); 
  spdr=255;
  spdl=255;
}


void sstop()
{ spdl=0;
  spdr=0;
  digitalWrite(pin1,0); 
  analogWrite(pin2,spdl);
  digitalWrite(pin3,0); 
  analogWrite(pin4,spdr);
  spdl=255;
  spdr=255;
}

void back()
{ 
  digitalWrite(pin1,0); 
  analogWrite(pin2,spdl);
  digitalWrite(pin3,0); 
  analogWrite(pin4,spdr);
  spdl=255;
  spdr=255;
}
                                           //functions for delay turn

void turnleft()
{ spdl=0;
  spdr=255;
  analogWrite(pin1,spdl);
  analogWrite(pin2,spd); 
  digitalWrite(pin4,0);
  analogWrite(pin3,spdr);
  delay(750);
 spdl=255;
 spdr=255;
}

void turnright()
{ spdl=255;
  spdr=0;
  
  analogWrite(pin3,spdr);
  digitalWrite(pin4,0); 
   digitalWrite(pin2,0);
    analogWrite(pin1,spdl);
    delay(750);
 spdl=255;
 spdr=255;
}

void turn_u_left()
{ spdl=0;
  spdr=255;
  analogWrite(pin1,spdl);
  digitalWrite(pin2,0); 
  digitalWrite(pin4,0); 
  analogWrite(pin3,spdr);
  delay(1500);
 spdl=255;
 spdr=255;
}

void turn_u_right()
{ spdl=255;
  spdr=0;
  analogWrite(pin3,spdr);
  digitalWrite(pin4,0); 
  digitalWrite(pin2,0); 
  analogWrite(pin1,spdl);
  delay(1500);
 spdl=255;
 spdr=255;
}
