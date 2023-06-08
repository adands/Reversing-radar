#include <WiFi.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include "OLedLib.h"
#include "HCRS04Lib.h"
#include "LED.h"

const char ssid[]     = "SSID";// change to your WIFI SSID
const char password[] = "SSIDpassword";// change to your WIFI Password
IPAddress server_addr(xxx,xxx,xxx,xxx);// change to you server ip, note its form split by "," not "."
int MYSQLPort =3310;   //mysql port default is 3306
char user[] = "yourMySQL";// Your MySQL user login username(default is root),and note to change MYSQL user root can access from local to internet(%)
char pass[] = "MySQLpassword";// Your MYSQL password

WiFiClient client;            
MySQL_Connection conn((Client *)&client);
  
void setup() {
  // put your setup code here, to run once:
  
  initALL() ; //蝟餌絞蝖祇��/頠�����
  _clearBuffer();   //皜銋�����擃�
  _setFont(u8g2_font_logisoso16_tf);  //閮剖��耦

  Serial.begin(115200);
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);  
  //try to connect to WIFI 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  //try to connect to mysql server
  if (conn.connect(server_addr, 3306, user, pass)) {
     delay(1000);
  }
  else{
    Serial.println("Connection failed.");
  }
  delay(2000);  
  //insert, change database name and values by string and char[]
  char INSERT_SQL[] = "INSERT INTO tempandhumd.datalog (temp,humd) VALUES ('35','60')";//傳入的值固定為溫度,濕度為35,60
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);  
  cur_mem->execute(INSERT_SQL);//execute SQL
  delete cur_mem;
  conn.close();                  // close the connection
  Serial.println("Data Saved.");
  
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
