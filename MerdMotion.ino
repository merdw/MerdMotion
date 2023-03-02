#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int inputpin = 8;
int pirstate = LOW;
int val = 0;
void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("Merd Motion");
  display.display();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(inputpin, INPUT);
  Serial.begin(115200);
}

void loop()
{
  
  val = digitalRead(inputpin);

  if (val == 1)
  {
    digitalWrite(LED_BUILTIN, HIGH);

    if (pirstate == LOW)
    {

      Serial.println(" HAREKET ALGILANDI!"); //consolea yazdır.
      display.clearDisplay();
      display.setCursor(0, 12);
      display.print("HAREKET ALGILANDI!"); //ekrana yazdır
      display.display();
      pirstate = HIGH;
    }
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);

    if (pirstate == HIGH)
    {
      Serial.println(" HAREKET BITTI!"); //consolea yazdır.
      display.clearDisplay();
      display.setCursor(0, 12);
      display.print("HAREKET BITTI!"); //ekrana yazdır
      display.display();
      pirstate = LOW;
    }
  }

}
