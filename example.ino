


#include <DFPlayerMini_Fast.h>
#if !defined(UBRR1H)
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX
#endif


DFPlayerMini_Fast myMP3;


const int sensorky = 8;
const int sensormotion = 9;
const int led = 6;


void setup()
{
  Serial.begin(115200);
  Serial.begin(9600);
  
  pinMode(sensorky, INPUT);
  pinMode(sensormotion, INPUT);
  pinMode(led,OUTPUT);

#if !defined(UBRR1H)
  mySerial.begin(9600);
  myMP3.begin(mySerial, true);
#else
  Serial1.begin(9600);
  myMP3.begin(Serial1, true);
#endif

  Serial.println("Setting volume to max");
  myMP3.volume(30);

  Serial.println("ativando");

  myMP3.play(1);


}

void loop()
{  
  digitalWrite(led, HIGH);
  
  if (digitalRead(sensorky) == LOW) {
    Serial.println("Batida detectada");
    myMP3.play(3);
  }


  if (digitalRead(sensormotion) == LOW) {
    Serial.println("Movimento detectado");
    myMP3.play(2);
  }

}
