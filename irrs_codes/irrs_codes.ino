int sen1=0,sen2=1,spd=255,sen3=2,sen4=3,sen5=4,sen6=5,s1,s2,s3,s4,s5,s6,spdl=255,spdr=255,pin1=5,pin2=6,pin3=9,pin4=10;
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

void loop() 
{
  // put your main code here, to run repeatedly:

analogWrite(pin1,spdl);
  digitalWrite(pin2,spd); 
   analogWrite(pin3,spdr);
  digitalWrite(pin4,spd); 
 
  
   delay(1500);
  
  spdr=55;
  spd=0;
  spdl=255;
        s1=analogRead(sen1);   
        Serial.println(s1);
       Serial.print("...");
       
        s2=analogRead(sen2);   
        Serial.println(s2);
       Serial.print(".......");
        s3=analogRead(sen3);   
        Serial.println(s3);
       Serial.print("..........");
        s4=analogRead(sen4);   
        Serial.println(s4);
       Serial.print(".............");
        s5=analogRead(sen5);   
        Serial.println(s5);
       Serial.print("................");
        s6=analogRead(sen6);   
        Serial.println(s6);
       
       
      
}
