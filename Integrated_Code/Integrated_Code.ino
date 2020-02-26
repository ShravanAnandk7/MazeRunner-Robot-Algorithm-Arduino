                                         int sen1=0,sen2=1,sen3=2,sen4=3,sen5=4,sen6=5,s1,s2,s3,s4,s5,s6,spd=255,spdl=255,spdr=255,pin1=5,pin2=6,pin3=9,pin4=10;
int fpath=0;                         // path flag
int fmaze=0;                         // maze flag
int readp=0;                           //path read flag
int mx=0,mid=0,mn=0;
int i=0,j=0,l=0,k=0;
int cnt;
char p[1000];

void minmax();
void nodeapproach();
void nodeleft();
void noderight();  
void solve_maze_left();
void solve_maze_right();
void maze_replace();
void performcommand();
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

if((s2 > mx)&&(s1 > mx)&&(s3 > mx)&&(s4 > mx)&&(s5 > mx)&&(s6 > mx))  //+
{     
   straight();
     delay(500);
     if((s2 > mx)&&(s1 > mx)&&(s3 > mx)&&(s4 > mx)&&(s5 > mx)&&(s6 > mx))      //Stop if all the sensors give low reflectance values
   {     sstop();
    if(fmaze==0)
         { Serial.println(fmaze);
          solve_maze_left();
           sstop();
             
          }
          sstop();
     Serial.print("end\n");
     }
     else
        {
           Serial.print("+ NODE\n");
  if(fmaze==0)
  {  back();
     delay(500);
   turnleft();
    p[readp]='L';
    readp++;
      Serial.print("+ NODE\n");
    }
   else 
   {back();
     delay(500);
    performcommand();}
   }
}

          
if((s2>mid)&&(s1>mid)&&(s3<mid)&&(s4<mid)&&(s5<mid)&&(s6<mid))  //u
{
  if(fmaze==0)
  { turn_u_left();
    p[readp]='U';
    readp++;
     Serial.print("U TURN\n");
    }
}


else if((s2>mx)&&(s1>mx)&&(s3>mx)&&(s4>mx)&&(s5<mid)&&(s6<mid))  //  -|
{  Serial.print("LEFT NODE\n");
   if(fmaze==0)
  { 
            turnleft();
           
            p[readp]='L';
            readp++;
  
   }
   else 
   performcommand();

 
}

else if((s2<mid)&&(s1<mid)&&(s3>mx)&&(s4>mx)&&(s5>mx)&&(s6>mx))   //  |-
{
 Serial.print("RIGHT NODE\n");
  if(fmaze==0)
  {         
    straight();
    delay(750); 
    p[readp]='S';
    readp++;
    }
   else 
   performcommand();

  
  }

else if((s2>mx)&&(s4>mx)&&(s5>mx)&&(s3<mid))   //T
{ 
  Serial.print("T NODE\n");
   if(fmaze==0)
  { 
            turnleft();
           
            p[readp]='L';
            readp++;
   }
   else 
   performcommand();

}
   

else if(((s3<mx)&&(s6>mx)&&(s1<mid))||((((s1+s2)<(s5+s6))&&(s3<mid)&&(s2<mid))))                  //Move right
{
  
 Serial.print("right\n");
 
  
  nodeapproach();
 
  caliberright(); 
}
else if((s3>mx)&&(s4>mx)&&(s6<mid)&&(s1<mid))       //go straight
{   
    Serial.print("straight\n");
      nodeapproach();
    straight();
}
else if(((s3<mx)&&(s1>mx)&&(s6<mid))||((((s1+s2)>(s5+s6))&&(s3<mid)&&(s2<mid)&&(s6<mid))))   //Move left
        
{Serial.print("left\n");
  nodeapproach();
   
caliberleft();
}
else
   {
  nodeapproach();
   straight();
    Serial.print("UN DEFINED PATH\n");
    }     
      spd=255;
      spdl=255;
      spdr=255;
} 
                                         //end of program

                                                                                                   //nodal functions
void nodeapproach()
{          if(s1>mid||s3<mid||s5>mid||s2>mid||s6>mid)
                      {
                       //do
                      }
    Serial.print("node approaching\n");  
  }         

                       //end of program

void minmax()
{
  
for(int i=0; i<50; i++)
{
int val = 0;
for(int j=0; j<=5; j++) 
{                      
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
                    
  
void nodeleft()              //nodal functions for left justified
{ 
               
if((s2<mid)&&(s1<mid)&&(s3<mid)&&(s4<mid)&&(s5<mid)&&(s6<mid))  //u
{
  {
  if(fmaze==0)
  { turn_u_left();
    p[readp]='U';
    readp++;
     Serial.print("U TURN\n");
    }
   else 
   performcommand();
}

}

else if((s2 > mx)&&(s1 > mx)&&(s3 > mx)&&(s4 > mx)&&(s5 > mx)&&(s6 > mx))  //+
{     
   straight();
     delay(1000);
     if((s2 > mx)&&(s1 > mx)&&(s3 > mx)&&(s4 > mx)&&(s5 > mx)&&(s6 > mx))      //Stop if all the sensors give low reflectance values
   {     sstop();
    if(fmaze==0)
         { Serial.println(fmaze);
          solve_maze_left();
           sstop();
          }
          sstop();
          delay(1000);
     Serial.print("end\n");
     }
     else
        {
           Serial.print("+ NODE\n");
  if(fmaze==0)
  { turnleft();
    p[readp]='L';
    readp++;
      Serial.print("+ NODE\n");
    }
   else 
   {performcommand();}
   }
}

else if((s2>mx)&&(s1>mx)&&(s3>mx)&&(s4>mx)&&(s5<mid)&&(s6<mid))  //  -|
{  Serial.print("LEFT NODE\n");
   if(fmaze==0)
  { 
            turnleft();
           
            p[readp]='L';
            readp++;
  
   }
   else 
   performcommand();

 
}

else if((s2<mid)&&(s1<mid)&&(s3>mx)&&(s4>mx)&&(s5>mx)&&(s6>mx))   //  |-
{
 Serial.print("RIGHT NODE\n");
  if(fmaze==0)
  {         
    straight();
    delay(750); 
    p[readp]='S';
    readp++;
    }
   else 
   performcommand();

  
  }

else if((s2>mid)&&(s4>mx)&&(s5>mid)&&(s6>mx)&&(s3<mid))   //T
{ 
  Serial.print("T NODE\n");
   if(fmaze==0)
  { 
            turnleft();
           
            p[readp]='L';
            readp++;
   }
   else 
   performcommand();

}
   else
   {
  nodeapproach();
   straight();
    Serial.print("UN DEFINED PATH\n");
    }
}     
void noderight()                              //nodal functions for right justified
{  

                              
if((s2>mid)&&(s1>mid)&&(s3<mid)&&(s4<mid)&&(s5<mid)&&(s6<mid))   //u
{
  if(fmaze==0)
  { turn_u_left();
    p[readp]='U';
    readp++;
     Serial.print("U TURN\n");
    }
   else 
   performcommand();
}
else if((s2 > mx)&&(s1 > mx)&&(s3 > mx)&&(s4 > mx)&&(s5 > mx)&&(s6 > mx))  //+
{     
   straight();
     delay(300);
     if((s2 > mx)&&(s1 > mx)&&(s3 > mx)&&(s4 > mx)&&(s5 > mx)&&(s6 > mx))      //Stop if all the sensors give low reflectance values
   {     sstop();
   
     Serial.print("end\n");
    if(fmaze==0)
    {
    solve_maze_right();}
     }
     else
        {
           Serial.print("+ NODE\n");
  if(fmaze==0)
  
  {
  back();
  delay(300);
    turnright();
    p[readp]='R';
    readp++;
      Serial.print("+ NODE\n");
    }
   else 
   performcommand();

    
        }
}

else if((s2>mx)&&(s1>mx)&&(s3>mx)&&(s4>mx)&&(s5<mid)&&(s6<mid)) //  -|
{
  if(fmaze==0)
  { 
            straight();
            delay(750);
            p[readp]='S';
            readp++;
  Serial.print("LEFT NODE\n");
   }
   else 
   performcommand();
}

else if((s2<mid)&&(s1<mid)&&(s3>mx)&&(s4>mx)&&(s5>mx)&&(s6>mx))     //  |-
{
  if(fmaze==0)
  {         
    turnright(); 
    p[readp]='R';
     Serial.print("RIGHT NODE\n");
    readp++;
    }
   else 
   performcommand();
}

else if((s2>mid)&&(s4>mx)&&(s5>mid)&&(s6>mx)&&(s3<mid))    //T
{
  if(fmaze==0)
  { turnright();
  p[readp]='R';
  Serial.print("T NODE\n");
    readp++;
    }
   else 
   performcommand();
}

  }
  
                                                 //maze solving functions
 void solve_maze_left()          
{
  p[readp]='\0';
  for(k=0;k<(readp-1);k++)
  {
   for(i=0;i<(readp-1);i++)
  {
     if(p[i]=='L'&&p[i+1]=='U'&&p[i+2]=='R')
     {    p[i]='U';
        maze_replace();        
     }
     if(p[i]=='L'&&p[i+1]=='U'&&p[i+2]=='S')
     {    p[i]='R';
        maze_replace();
     }
     if(p[i]=='R'&&p[i+1]=='U'&&p[i+2]=='L')
     {    p[i]='U';
        maze_replace();
     }
     if(p[i]=='S'&&p[i+1]=='U'&&p[i+2]=='L')
     {    p[i]='R';
        maze_replace();
     }
     if(p[i]=='L'&&p[i+1]=='U'&&p[i+2]=='L')
     {    p[i]='S';
        maze_replace();
     }  
  }
  }
                     fmaze=1;
                       Serial.print("maze solved left");
}

void solve_maze_right()
{
  
  p[readp]='\0';
  for(k=0;k<(readp-1);k++)
  {
   for(i=0;p[i]!='\0';i++)
  {
     if(p[i]=='R'&&p[i+1]=='U'&&p[i+2]=='L')
     {    p[i]='U';
        maze_replace();        
     }
     if(p[i]=='R'&&p[i+1]=='U'&&p[i+2]=='S')
     {    p[i]='L';
        maze_replace();
     }
     if(p[i]=='L'&&p[i+1]=='U'&&p[i+2]=='R')
     {    p[i]='U';
        maze_replace();
     }
     if(p[i]=='S'&&p[i+1]=='U'&&p[i+2]=='R')
     {    p[i]='L';
        maze_replace();
     }
     if(p[i]=='R'&&p[i+1]=='U'&&p[i+2]=='R')
     {    p[i]='S';
        maze_replace();
     }  
  }
  }  
     fmaze=1;
      Serial.print("maze solved right");
}

void maze_replace()
{
j=i;
        do 
         {p[j+1]=p[j+3];
         j++;
         }while(p[j+1]!='\0');
p[j+1]='\0';
p[j+2]='\0';
}                                                            //perform function

void performcommand()
{Serial.println(p[fpath]);
  switch (p[fpath])
    {   case 'L':
            turnleft();   
        break;
        case 'R':
            turnright();
        break;
        case 'S':
            straight();
            delay(1500);     
        break;
    }
    fpath++;
    Serial.print("command performed");
    Serial.println(fpath);

 }                                                             //caliberate functions

void caliberleft()
{
 spdl=0;
 spdr=255;
 spd=255; 
  analogWrite(pin1,spdl);
  digitalWrite(pin2,spd); 
  analogWrite(pin3,spdr);
  digitalWrite(pin4,0); 
 spdl=255;

}

void caliberright()
{ spdr=0;
 spd=255;
spdl=255; 
  analogWrite(pin1,spdl);
  digitalWrite(pin2,0); 
  analogWrite(pin3,spdr);
  digitalWrite(pin4,spd); 
 spdr=255;
}

//straight back functions


void straight()
{
   spdr=255;
  spdl=255; 
  analogWrite(pin1,spdl);
  digitalWrite(pin2,0); 
  analogWrite(pin3,spdr);
  digitalWrite(pin4,0); 
 
}


void sstop()
{ spd=0;
  digitalWrite(pin1,0); 
  analogWrite(pin2,spd);
  digitalWrite(pin3,0); 
  analogWrite(pin4,spd);
spd=255;
}

void back()
{ 
  
  spdl=255;
  spdr=255;
  digitalWrite(pin1,0); 
  analogWrite(pin2,spdl);
  digitalWrite(pin3,0); 
  analogWrite(pin4,spdr);
  
}
                                           //functions for delay turn

void turnleft()
{ spdl=0;
  spdr=255;
  spd=255;
  analogWrite(pin1,spdl);
  digitalWrite(pin2,spd);
  analogWrite(pin3,spdr); 
  digitalWrite(pin4,0);
  delay(750);
 
    straight();
    delay(300);
 spdl=255;
}

void turnright()
{ spdl=255;
  spdr=0;
  spd=255; 
   analogWrite(pin1,spdl);
  digitalWrite(pin2,0);
  analogWrite(pin3,spdr);
  digitalWrite(pin4,spd);
    delay(750);
    straight();
    delay(300);

 spdr=255;
}
void turn_u_left()
{ spdl=0;
  spdr=255;
  spd=255;
  analogWrite(pin1,spdl);
  digitalWrite(pin2,spd); 
  analogWrite(pin3,spdr);
  digitalWrite(pin4,0); 
  delay(1500);
  
    straight();
    delay(300);
 spdl=255;

}

void turn_u_right()
{ spdl=255; 
   spd=255;
  spdr=0; 
  analogWrite(pin1,spdl);
  digitalWrite(pin2,0); 
  analogWrite(pin3,spdr);
  digitalWrite(pin4,spd);
  delay(1500);
  
    straight();
    delay(300);
 spdr=255;
}
