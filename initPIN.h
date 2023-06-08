#define _Debug 1    //頛詨��閮
#define _debug 1    //頛詨��閮
#define initDelay   6000    //����辣�����
#define loopdelay 500   //loop 撱園����


#include <WiFi.h>   //雿輻蝬脰楝�撘澈
#include <WiFiClient.h>   //雿輻蝬脰楝��蝡臬撘澈
#include <WiFiMulti.h>    //憭暺雯頝臬撘澈

WiFiMulti wifiMulti;    //����暺��蝺隞�



String IpAddress2String(const IPAddress& ipAddress) ;




  IPAddress ip ;    //蝬脰楝����P雿�銋�����摮�
  String IPData ;   //蝬脰楝����P雿�銋摮�
  String APname ;   //蝬脰楝�暺�摮�
  String MacData ;   //蝬脰楝����雯頝臬蝺刻��摮� 
  long rssi ;   //蝬脰楝��蝺���撥摨�'銋摮�
  int status = WL_IDLE_STATUS;  //���雯頝舐�����
  

#define LEDPin 2

void initWiFi()   //蝬脰楝��蝺���銝暺�
{
  //����蝺暺���
  wifiMulti.addAP("NCNUIOT", "12345678");  //��銝�蝯暺�
  wifiMulti.addAP("NCNUIOT2", "12345678");  //��銝�蝯暺�
  wifiMulti.addAP("ABC", "12345678");  //��銝�蝯暺�

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  //���� "Connecting to "
  wifiMulti.run();  //憭雯頝舐暺身摰��蝺�
 while (WiFi.status() != WL_CONNECTED)     //�����蝺���
  {
    // wifiMulti.run() ����暺��蝺隞塚��脰�歇蝬����暺�脰���蝺��
    // 銝������蝺�������銝鳴�������銝��
    // WL_CONNECTED ����暺���
    Serial.print(".");   //����
    delay(500) ;  //���500 ms
     wifiMulti.run();   //憭雯頝舐暺身摰��蝺�
  }
    Serial.println("WiFi connected");   //���� WiFi connected
    Serial.print("AP Name: ");   //���� AP Name:
    APname = WiFi.SSID();
    Serial.println(APname);   //���� WiFi.SSID()==>敺暺�迂
    Serial.print("IP address: ");   //���� IP address:
    ip = WiFi.localIP();
    IPData = IpAddress2String(ip) ;
    Serial.println(IPData);   //���� WiFi.localIP()==>敺暺��P雿�
    //��������暺���P雿�
  

 
}
void ShowInternet()   //蝘��蝬脰楝��蝺���
{
  Serial.print("MAC:") ;
  Serial.print(MacData) ;
  Serial.print("\n") ;
  Serial.print("SSID:") ;
  Serial.print(APname) ;
  Serial.print("\n") ;
  Serial.print("IP:") ;
  Serial.print(IPData) ;
  Serial.print("\n") ;    
  //OledLineText(1,"MAC:"+MacData) ;
  //OledLineText(2,"IP:"+IPData);
  
  //ShowMAC() ;
  //ShowIP()  ;
}
//--------------------
//----------Common Lib
long POW(long num, int expo)
{
  long tmp =1 ;
  if (expo > 0)
  { 
        for(int i = 0 ; i< expo ; i++)
          tmp = tmp * num ;
         return tmp ; 
  } 
  else
  {
   return tmp ; 
  }
}


String SPACE(int sp)
{
    String tmp = "" ;
    for (int i = 0 ; i < sp; i++)
      {
          tmp.concat(' ')  ;
      }
    return tmp ;
}


String strzero(long num, int len, int base)
{
  String retstring = String("");
  int ln = 1 ;
    int i = 0 ; 
    char tmp[10] ;
    long tmpnum = num ;
    int tmpchr = 0 ;
    char hexcode[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'} ;
    while (ln <= len)
    {
        tmpchr = (int)(tmpnum % base) ;
        tmp[ln-1] = hexcode[tmpchr] ;
        ln++ ;
         tmpnum = (long)(tmpnum/base) ;
 
        
    }
    for (i = len-1; i >= 0 ; i --)
      {
          retstring.concat(tmp[i]);
      }
    
  return retstring;
}



unsigned long unstrzero(String hexstr, int base)
{
  String chkstring  ;
  int len = hexstr.length() ;
  
    unsigned int i = 0 ;
    unsigned int tmp = 0 ;
    unsigned int tmp1 = 0 ;
    unsigned long tmpnum = 0 ;
    String hexcode = String("0123456789ABCDEF") ;
    for (i = 0 ; i < (len ) ; i++)
    {
  //     chkstring= hexstr.substring(i,i) ; 
      hexstr.toUpperCase() ;
           tmp = hexstr.charAt(i) ;   // give i th char and return this char
           tmp1 = hexcode.indexOf(tmp) ;
      tmpnum = tmpnum + tmp1* POW(base,(len -i -1) )  ;
 
        
    }
  return tmpnum;
}

String  print2HEX(int number) {
  String ttt ;
  if (number >= 0 && number < 16)
  {
    ttt = String("0") + String(number,HEX);
  }
  else
  {
      ttt = String(number,HEX);
  }
  return ttt ;
} 
String GetMacAddress()    //���雯頝臬蝺刻��
{
  // the MAC address of your WiFi shield
  String Tmp = "" ;
  byte mac[6];
  
  // print your MAC address:
  WiFi.macAddress(mac);
  for (int i=0; i<6; i++)
    {
        Tmp.concat(print2HEX(mac[i])) ;
    }
    Tmp.toUpperCase() ;
  return Tmp ;
}

void ShowMAC()  //�銝脣���蝬脰楝���Ⅳ
{
  
  Serial.print("MAC Address:(");  //�� "MAC Address:("
  Serial.print(MacData) ;   //�� MacData 霈�摰�
  Serial.print(")\n");    //�� ")\n"


}
String IpAddress2String(const IPAddress& ipAddress)
{
  //��ipAddress[0-3]��摰對�誑16�脖��
  return String(ipAddress[0]) + String(".") +\
  String(ipAddress[1]) + String(".") +\
  String(ipAddress[2]) + String(".") +\
  String(ipAddress[3])  ; 
}




String chrtoString(char *p)
{
    String tmp ;
    char c ;
    int count = 0 ;
    while (count <100)
    {
        c= *p ;
        if (c != 0x00)
          {
            tmp.concat(String(c)) ;
          }
          else
          {
              return tmp ;
          }
       count++ ;
       p++;
       
    }
}


void CopyString2Char(String ss, char *p)
{
         //  sprintf(p,"%s",ss) ;

  if (ss.length() <=0)
      {
           *p =  0x00 ;
          return ;
      }
    ss.toCharArray(p, ss.length()+1) ;
   // *(p+ss.length()+1) = 0x00 ;
}

boolean CharCompare(char *p, char *q)
  {
      boolean flag = false ;
      int count = 0 ;
      int nomatch = 0 ;
      while (flag <100)
      {
          if (*(p+count) == 0x00 or *(q+count) == 0x00)
            break ;
          if (*(p+count) != *(q+count) )
              {
                 nomatch ++ ; 
              }
             count++ ; 
      }
     if (nomatch >0)
      {
        return false ;
      }
      else
      {
        return true ;
      }
      
        
  }


String Double2Str(double dd,int decn)
{
    int a1 = (int)dd ;
    int a3 ;
    if (decn >0)
    {    
        double a2 = dd - a1 ;
        a3 = (int)(a2 * (10^decn));
    }
    if (decn >0)
    {
        return String(a1)+"."+ String(a3) ;
    }
    else
    {
      return String(a1) ;
    }
  
}
