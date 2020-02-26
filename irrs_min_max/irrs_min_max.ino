int sen1=0,mx,mn,val,mid,sen2=1,sen3=2,sen4=3,sen5=4,i,j,sen6=5,s1,s2,s3,s4,s5,s6,spd=255,pin1=9,pin2=11;
char s[1];
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
for(int i=0; i<5000; i++)
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
//mid=mid+100;
//mx=mx-100;
Serial.print(mn);
Serial.print("....");
Serial.print(mid);
Serial.print("....");
Serial.print("....");
Serial.print(mx);
Serial.print("\n");
}
