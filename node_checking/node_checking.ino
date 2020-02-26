int sen1=0,sen2=1,sen3=2,sen4=3,sen5=4,sen6=5,s1,s2,s3,s4,s5,s6;
int mx=0,mid=0,mn=0;
int i=0,j=0,cnt=0;
void minmax();
void nodeapproach();
void nodeleft();


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

if(((s3<mx)&&(s6>mx)&&(s2<mid))||((s1<mid)&&(s2<mid)&&(s5<mid)&&(s3<mx)&&(s4<mx)&&(s6>mx)))                    //Move right
{
  nodeapproach();
 Serial.print("right\n");
}
else if((s3>mx)&&(s4>mx)&&(s6<mid)&&(s2<mid))       //go straight
{
  
  nodeapproach();
    Serial.print("straight\n");
}
else if(((s3<mx)&&(s2>mx)&&(s6<mid)&&(s1<mid))||((s1<mid)&&(s2>mx)&&(s3<mx)&&(s4<mx)&&(s5<mid)&&(s6<mid)))         //Move left
{
  nodeapproach();
Serial.print("left\n");
}

else if((s1 > mx)&&(s2 > mx)&&(s3 > mx)&&(s4 > mx)&&(s5 > mx)&&(s6 > mx))      //Stop if all the sensors give low reflectance values
{     
  Serial.print("end\n");
}
       else 
               nodeleft();
               //noderight();              
} 
                                         //end of program

                                                  //nodal functions
void nodeapproach()
{           if(s1>mid||s3<mid||s5>mid||s2>mid||s6>mid)
                      {
                        Serial.print("node approaching\n");                      
                      }
  }                             

void nodeleft()              //nodal functions for left justified
{ 
               
if((s1<mid)&&(s2<mid)&&(s3<mid)&&(s4<mid)&&(s5<mid)&&(s6<mid))  //u
{
  Serial.print("U TURN\n");
}

else if((s1<mid)&&(s2>mx)&&(s3>mx)&&(s4>mx)&&(s5<mid)&&(s6>mx))  //+
{
  Serial.print("+ NODE\n");
}

else if((s1<mid)&&(s2>mx)&&(s3>mx)&&(s4>mx)&&(s5<mid)&&(s6<mid))  //  -|
{
  Serial.print("LEFT NODE\n");
}

else if((s1<mid)&&(s2<mid)&&(s3>mx)&&(s4>mx)&&(s5<mid)&&(s6>mx))   //  |-
{
  Serial.print("RIGHT NODE\n");
  }

else if((s1<mid)&&(s2>mx)&&(s3<mid)&&(s4>mx)&&(s5<mid)&&(s6>mx))   //T
{Serial.print("T NODE\n");
}
   else
   {
    
  nodeapproach();
    Serial.print("straight\n");
    }
}       
void minmax()
{
  
for(int i=0; i<500; i++)
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
