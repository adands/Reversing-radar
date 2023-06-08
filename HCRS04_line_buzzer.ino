
#include "OLedLib.h"
#include "HCRS04Lib.h"
#include "LED.h"

void setup() {
  // put your setup code here, to run once:
  
  initALL() ; //蝟餌絞蝖祇��/頠�����
  _clearBuffer();   //皜銋�����擃�
  _setFont(u8g2_font_logisoso16_tf);  //閮剖��耦


  
}

void loop() {
  // put your main code here, to run repeatedly:

    unsigned long distancevalue = ReadDistance();
    String msg ="距離:"+String(distancevalue)+"cm";
    Serial.print(distancevalue);                   //�� temp霈�摰�
    Serial.print("cm");                   //�� " C"  

    _clearOled(); //皜�撟�

    printDistanceonOled(distancevalue) ;
    shine(distancevalue);
    delay(2000);      //撱園2蝘��
    


}

void initALL()  //蝟餌絞蝖祇��/頠�����
{

    Serial.begin(9600);   //������ �����蒂閮剔9600 bps
    Serial.println("System Start"); //�� "System Start"
    initHCSR04();   //���TU21D 皞急獐摨行�葫�
    initOLED();   //���LED 12832憿舐內璅∠��
    initLEDlight();
}
