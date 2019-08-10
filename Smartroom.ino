int count=0;
int ldr1read=0,ldr2read=0;
int ldr1port=A3;// enter
int ldr2port=A4;// exit
int light=10;
int fan=8;

char incoming;
String data;

void setup() {
   pinMode(ldr1port,INPUT);
pinMode(ldr2port,INPUT);
pinMode(fan,OUTPUT);
pinMode(light,OUTPUT);
Serial.begin(9600);
  digitalWrite(light,LOW);

}

void loop() {
  ldr1read=analogRead(ldr1port);
ldr2read=analogRead(ldr2port);
Serial.println(ldr1read);
Serial.println(ldr2read);

 while(Serial.available())
 {
  delay(10);
  incoming = Serial.read();

  data +=incoming;
  }



  if(data.length()>0)
  {
  Serial.println(data);

 if(data=="fanoff")
 {
  digitalWrite(fan,LOW);
 delay(3000);
  }

  else if(data=="fanon")
  {
      digitalWrite(fan,HIGH);
       delay(3000);
    }

  else if(data=="lighton")
  {
  
        digitalWrite(light,HIGH);
         delay(3000);
    
    }
    else if(data == "lightoff")
    
    {
         digitalWrite(light,LOW);
          delay(3000);
      }

      else if(data== "count")
      {
    
        Serial.print(count);
   
            delay(3000);
        }
    
    data="";
    }




if(ldr1read>150)
{
count++;
digitalWrite(fan,HIGH);
digitalWrite(light,HIGH);
Serial.print(count);
    delay(3000);
  }

  if(ldr2read<100)
{
count--;
Serial.print(count);
if(count<=0)
{
  digitalWrite(fan,LOW);
digitalWrite(light,LOW);
  }
  
if(count<0)
{
  count=0;}
  
    delay(3000);
  }


  

}
