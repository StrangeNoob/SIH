const int analogInPin = A9; 
int sensorValue = 0; 
unsigned long int avgValue; 
float b;
int buf[10],temp;

void setup() {
  Serial.begin(9600);
}
 
void loop() {
   for(int i=0;i<10;i++) 
   { 
    buf[i]=analogRead(analogInPin);
    delay(750);
   }
   for(int i=0;i<9;i++)
   {
    for(int j=i+1;j<10;j++)
    {
     if(buf[i]>buf[j])
     {
      temp=buf[i];
      buf[i]=buf[j];
      buf[j]=temp;
     }
    }
   }
   
   int sensorValue = analogRead(A10);
   float voltage = sensorValue * (5.0 / 1024.0);
   avgValue=0;
   for(int i=2;i<8;i++)
   avgValue+=buf[i];
   float pHVol=(float)avgValue*5.0/1024/6;
   float phValue = -5.70 * pHVol + 21.34;
   Serial.print("PH sensor = ");
   Serial.println(phValue*1.7+3.05);
   Serial.println ("Turbidity Output : ");
   Serial.println(voltage);
   Serial.println();
   delay(20);
}
