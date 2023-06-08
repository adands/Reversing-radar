
int trigPin = 12;
int echoPin = 14;
unsigned long distancevalue  = 0; 
char tmpvalue[100];

void initHCSR04()
{
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}
unsigned long ReadDistance()
{ 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);     // 蝯� Trig 擃雿���� 10敺桃��
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  return pulseIn(echoPin,HIGH)*34/1000/2;
}


void printDistanceonOled(unsigned long h) //��頞瘜Ｘ��銋�摨行OLED銝�
{
  sprintf(tmpvalue,"%d",h) ;
  Serial.print("Distance:");
  Serial.print(tmpvalue);
  Serial.print(" cm\n");

  _TPrint(45,31,"cm");
  _TPrint(10,31,tmpvalue);


}
