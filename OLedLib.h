#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

//https://www.arduinolibraries.info/libraries/u8g2
//--------------------
void _update();   //���撟�
void _updateBuffer();   //銝�������銝�摰�甈∪�
void _setI2CAddress(int adr);   //閮剖�撟�2C 雿�
void _initDisplay();   //begin()韏瑕�撟���
void initOLED();   //���LED  憿舐內�
void _setCursor(int x, int y);   //閮剖���虜璅�
void _setDrawColor(int color);   //閮剖����
int _getWidth();   //���撟祝摨�
int _getHeight();  //���撟�漲
int _getMaxCharWidth();  //������耦��憭批祝摨�
int _getMaxCharHeight(); //������耦��憭折�漲
int _getCharWidth(); //������耦撖砍漲
int _getUTF8Width(); //�����TF8撖砍漲
void _clearDisplay();  //皜��
void _setContrast(int t);    //閮剖����
void _clearOled(); //皜�撟�
void _clearBuffer();   //皜銋�����擃�
void _Box(int x, int y, int w,int h);  //��敶�
void _Circle(int x, int y, int r);   //���耦
void _Ellipse(int x, int y, int rx,int ry);    //�璈Ｗ�耦
void _FilledEllipse(int x, int y, int rx,int ry);    //�憛怨璈Ｗ�耦
void _Triangle(int x1, int y1, int x2, int y2,int x3, int y3);   //�銝�耦
void _HLine(int x, int y, int l);  //�瘞游像蝺�
void _VLine(int x, int y, int l);    //���蝺�
void _Line(int x1, int y1, int x2, int y2);    //�蝺�
void _Point(int x, int y);   //�暺�
void _setFont(const uint8_t *font_8x8);    //閮剖��耦
void _setFontDirection(int dir);     //閮剖��耦����
void _setFontMode(int is_transparent);   //閮剖��耦��漲
void _TPrint(int x, int y,  const char *ss);   // ����蔭頛詨����
void _TextPrint(int x, int y,  const char *ss, const uint8_t *font_8x8);   // ����蔭頛詨����
void _UTF8Print(int x, int y,  const char *ss, const uint8_t *font_8x8);   // ����蔭頛詨UTF8����
void _Print(const char *ss);   // 銝���蔭頛詨����
//--------------
// all font document ref URL:https://github.com/olikraus/u8g2/wiki/u8g2reference
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 
void _update()   
{
  u8g2.updateDisplay();
}
void _updateBuffer()   
{
  u8g2.sendBuffer();
}
void _setI2CAddress(int adr)   
{
  u8g2.setI2CAddress(adr);
}
void _initDisplay()   
{
  u8g2.initDisplay();
}
void initOLED()   //���LED  憿舐內�
{
    if (!u8g2.begin())   //憒�� OLED  憿舐內�瘝������
    {
      Serial.println("Couldn't find OLED!");    //�� "Couldn't find sensor!"
      //�銝 OLED  憿舐內�
      while (1);  //瘞賊�香���
    }
     Serial.println("init OLED successful!");
   // _initDisplay() ;
}
void _setCursor(int x, int y)
{
   u8g2.setCursor(x,y);  
}
void _setDrawColor(int color)
{
/*
Font Mode  Draw Color  Glyph Foreground Color  Glyph Background Color
0: solid  0 0 1
0: solid  1 1 0
0: solid  2 XOR 0
1: transparent  0 0 -
1: transparent  1 1 -
1: transparent  2 XOR -
 */
  
   u8g2.setDrawColor(color);  
}

int _getWidth()
{
   return u8g2.getDisplayWidth();  
}
int _getHeight()
{
   return u8g2.getDisplayHeight();  
}
int _getMaxCharWidth()
{
   return u8g2.getMaxCharWidth();  
}
int _getMaxCharHeight()
{
   return u8g2.getMaxCharHeight();  
}
int _getCharWidth()
{
   return u8g2.getStrWidth(" ");  
}

int _getUTF8Width()
{
   return u8g2.getUTF8Width(" ");  
}
void _clearDisplay()
{
  u8g2.clearDisplay();        
  u8g2.sendBuffer();         // transfer internal memory to the display
}
void _setContrast(int t)
{
        
  u8g2.setContrast(t);         // transfer internal memory to the display
}
void _clearOled()
{
  u8g2.clear();         
  u8g2.sendBuffer();         // transfer internal memory to the display
}

void _clearBuffer()
{
  u8g2.clearBuffer();         
  u8g2.sendBuffer();  // Use sendBuffer to transfer the cleared frame buffer to the display.
 }

/*
void drawBitMap(int x, int y, int cnt,int h, static unsigned char bitmap)
{
  
//   x: X-position (left position of the bitmap).
//  y: Y-position (upper position of the bitmap).
//  cnt: Number of bytes of the bitmap in horizontal direction. The width of the bitmap is cnt*8.
//  h: Height of the bitmap.
//  bitmap: Pointer to the start of the bitmap.
   
  u8g2.drawBox(x,y,cnt,h,bitmap);        
 }
*/
void _Box(int x, int y, int w,int h)
{
  /*
   x: X-position (left position of the bitmap).
  y: Y-position (upper position of the bitmap).
  w: width of the bitmap.
  h: Height of the bitmap.
.
   */
  u8g2.drawBox(x,y,w,h);        
 }
void _Circle(int x, int y, int r)
{
  /*
   x: X-position (left position of the bitmap).
  y: Y-position (upper position of the bitmap).
u8g2 : Pointer to the u8g2 structure (C interface only).
x0, y0: Position of the center of the circle.
rad: Defines the size of the circle: Radus = rad.
opt: Selects some or all sections of the circle.
    U8G2_DRAW_UPPER_RIGHT
    U8G2_DRAW_UPPER_LEFT
    U8G2_DRAW_LOWER_LEFT
    U8G2_DRAW_LOWER_RIGHT
    U8G2_DRAW_ALL
.
   */
  u8g2.drawCircle(x,y,r,U8G2_DRAW_ALL);        
 }

void _Ellipse(int x, int y, int rx,int ry)
{
  /*
   x: X-position (left position of the bitmap).
  y: Y-position (upper position of the bitmap).
u8g2 : Pointer to the u8g2 structure (C interface only).
x0, y0: Position of the center of the filled circle.
rx, ry: Defines the size of the ellipse.
opt: Selects some or all sections of the circle.
    U8G2_DRAW_UPPER_RIGHT
    U8G2_DRAW_UPPER_LEFT
    U8G2_DRAW_LOWER_LEFT
    U8G2_DRAW_LOWER_RIGHT
    U8G2_DRAW_ALL
.
   */
  u8g2.drawEllipse(x,y,rx,ry,U8G2_DRAW_ALL);        
 }

void _FilledEllipse(int x, int y, int rx,int ry)
{
  /*
   x: X-position (left position of the bitmap).
  y: Y-position (upper position of the bitmap).
u8g2 : Pointer to the u8g2 structure (C interface only).
x0, y0: Position of the center of the filled circle.
rx, ry: Defines the size of the ellipse.
opt: Selects some or all sections of the circle.
    U8G2_DRAW_UPPER_RIGHT
    U8G2_DRAW_UPPER_LEFT
    U8G2_DRAW_LOWER_LEFT
    U8G2_DRAW_LOWER_RIGHT
    U8G2_DRAW_ALL
.
   */
  u8g2.drawFilledEllipse(x,y,rx,ry,U8G2_DRAW_ALL);  
}
void _Triangle(int x1, int y1, int x2, int y2,int x3, int y3)
{
  /*
   x: X-position (left position of the bitmap).
  y: Y-position (upper position of the bitmap).

   */
  u8g2.drawTriangle(x1,y1,x2,y2,x3,y3);        
 }
void _HLine(int x, int y, int l)
{
  /*
   x: X-position (left position of the bitmap).
  y: Y-position (upper position of the bitmap).

   */
  u8g2.drawHLine(x,y,l);        
 }
void _VLine(int x, int y, int l)
{
  /*
   x: X-position (left position of the bitmap).
  y: Y-position (upper position of the bitmap).
  l:ength of the vertical line.
   */
  u8g2.drawVLine(x,y,l);        
 }
void _Line(int x1, int y1, int x2, int y2)
{
  /*
u8g2 : Pointer to the u8g2 structure (C interface only).
x0: X-position of the first point.
y0: Y-position of the first point.
x1: X-position of the second point.
y1: Y-position of the second point.

   */
  u8g2.drawLine(x1,y1,x2,y2);        
 }

void _Point(int x, int y)
{
  /*
u8g2 : Pointer to the u8g2 structure (C interface only).
x0: X-position of the first point.
y0: Y-position of the first point.
x1: X-position of the second point.
y1: Y-position of the second point.

   */
  u8g2.drawPixel(x,y);        
 }
void _setFont(const uint8_t *font_8x8)
{
   u8g2.setFont(font_8x8);  
}
void _setFontDirection(int dir)
{
  /*
Description: The arguments defines the drawing direction of all strings or glyphs.
Argument  String Rotation Description
0 0 degree  Left to right
1 90 degree Top to down
2 180 degree  Right to left
3 270 degree  Down to top   */
   u8g2.setFontDirection(dir);  
}
void _setFontMode(int is_transparent)
{
  //is_transparent: Enable (1) or disable (0) transparent mode.
   u8g2.setFontMode(is_transparent);  
}

void _TPrint(int x, int y,  const char *ss)
{
  /*
u8g2 : Pointer to the u8g2 structure (C interface only).
x0: X-position of the first point.
y0: Y-position of the first point.
x1: X-position of the second point.
y1: Y-position of the second point.

   */
  u8g2.drawStr(x,y,ss);
  u8g2.sendBuffer();        
 }

void _TextPrint(int x, int y,  const char *ss, const uint8_t *font_8x8)
{
  /*
u8g2 : Pointer to the u8g2 structure (C interface only).
x0: X-position of the first point.
y0: Y-position of the first point.
x1: X-position of the second point.
y1: Y-position of the second point.

   */
   u8g2.setFont(font_8x8);  
  u8g2.drawStr(x,y,ss);        
 }
void _UTF8Print(int x, int y,  const char *ss, const uint8_t *font_8x8)
{
  /*
u8g2 : Pointer to the u8g2 structure (C interface only).
x0: X-position of the first point.
y0: Y-position of the first point.
x1: X-position of the second point.
y1: Y-position of the second point.
ss: UTF-8 encoded text.
   */
   u8g2.setFont(font_8x8);  
  u8g2.drawStr(x,y,ss);        
 }

void _Print(const char *ss)
{
  /*

ss: UTF-8 encoded text.
   */

  u8g2.print(ss);        
 }
