#include <analogWrite.h>

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = " cVWmVy230IIODjuarQqMtk-jUABRcUfc";

//// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Ktayal";
char pass[] = "1357924680";

int row[3];
int redValue = 0;
int greenValue = 0;
int blueValue = 0;
int modeValue;
int redPin = 15, greenPin = 2, bluePin = 4;
int color[7][3] = {{88, 0, 0}, {152, 0, 229}, {0, 238, 14}, {0, 248, 12}, {132, 172, 0}, {0, 13, 231}, {255, 255, 255}};

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}


BLYNK_WRITE(V0)
{
  redValue = map(param.asInt(), 0, 255, 255, 0);
}

BLYNK_WRITE(V1)
{
  greenValue = map(param.asInt(), 0, 255, 255, 0);
}

BLYNK_WRITE(V2)
{
  blueValue = map(param.asInt(), 0, 255, 255, 0);
}

BLYNK_WRITE(V3)
{
  modeValue = param.asInt();
}

void discoMode() {
  int rowNo = random(0, 8);
  int delayTime = random(200, 700);
  redValue = map(color[rowNo][0], 0, 255, 255, 0);
  greenValue = map(color[rowNo][1], 0, 255, 255, 0);
  blueValue = map(color[rowNo][2], 0, 255, 255, 0);
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
  delay(delayTime);
}

void loop() {
  Blynk.run();
  if (modeValue == 0)
  {
    discoMode();
  }
  else {
    analogWrite(redPin, redValue);
    analogWrite (greenPin, greenValue);
    analogWrite(bluePin, blueValue);
  }
}
