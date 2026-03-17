#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <time.h>

const char* ssid = "YOUR-WIFI";
const char* password = "YOUR-PASSOWORD";

#define TFT_CS   14
#define TFT_DC   15
#define TFT_RST  21
#define TFT_BL   22

#define TFT_MOSI 6
#define TFT_SCLK 7

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP,"pool.ntp.org",3600,60000);

String days[7]={"Sonntag","Montag","Dienstag","Mittwoch","Donnerstag","Freitag","Samstag"};

bool blink=true;

void drawWiFiBars()
{
  int strength=WiFi.RSSI();
  int bars=0;

  if(strength>-55) bars=4;
  else if(strength>-65) bars=3;
  else if(strength>-75) bars=2;
  else bars=1;

  for(int i=0;i<bars;i++)
  {
    tft.fillRect(290+i*6,25-i*4,4,4+i*4,ST77XX_WHITE);
  }
}

void setup()
{
  Serial.begin(115200);

  pinMode(TFT_BL,OUTPUT);
  digitalWrite(TFT_BL,HIGH);

  SPI.begin(TFT_SCLK,-1,TFT_MOSI);

  tft.init(172,320);
  tft.setRotation(1);

  tft.fillScreen(ST77XX_BLACK);

  WiFi.begin(ssid,password);

  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
  }

  timeClient.begin();
}

void loop()
{
  timeClient.update();

  time_t raw=timeClient.getEpochTime();
  struct tm *ti=localtime(&raw);

  tft.fillRect(0,40,320,130,ST77XX_BLACK);

  drawWiFiBars();

  String timeStr=timeClient.getFormattedTime();

  if(!blink)
  timeStr.setCharAt(2,' ');

  blink=!blink;

  char dateStr[20];
  sprintf(dateStr,"%02d.%02d.%04d",
  ti->tm_mday,
  ti->tm_mon+1,
  ti->tm_year+1900);

  String dayStr=days[ti->tm_wday];

  tft.setTextSize(5);
  tft.setTextColor(ST77XX_CYAN);
  tft.setCursor(30,50);
  tft.print(timeStr);

  tft.setTextSize(2);
  tft.setTextColor(ST77XX_GREEN);
  tft.setCursor(110,110);
  tft.print(dayStr);

  tft.setTextSize(2);
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(110,135);
  tft.print(dateStr);

  delay(1000);
}
