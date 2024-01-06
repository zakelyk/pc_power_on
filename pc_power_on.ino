#define BLYNK_TEMPLATE_ID "TMPL6tViMuwR6"
#define BLYNK_TEMPLATE_NAME "PC Power Control"
#define BLYNK_AUTH_TOKEN "b3yRyPOjlew0QcWmb0AUUlZSCK8rHzyU"

#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

#define relay_pin D0
#define button_pin D1

const char* ssid = "BCT E2";
const char* pass = "kosonginaja";
bool status;

void setup() {
  // put your setup code here, to run once:
  digitalWrite(relay_pin, LOW);
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(relay_pin, OUTPUT);
  pinMode(button_pin, INPUT);
  status = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  int button = digitalRead(button_pin);
  Serial.print("BUtton Input : "); Serial.println(button);
  if(button==HIGH){
    status = true;
  }
  breaker();
  if(status == true){
    digitalWrite(relay_pin, HIGH);
    Blynk.virtualWrite(V1, "ON");
    Blynk.virtualWrite(V0, 1);
    Serial.println("Relay On");
  } else {
    Blynk.virtualWrite(V1, "OFF");
    Blynk.virtualWrite(V0, 0);
    Serial.println("Relay OFF");
    digitalWrite(relay_pin, LOW);
  }
}

BLYNK_WRITE(V0)
{
  int relayState = param.asInt(); // Mendapatkan nilai dari tombol Blynk
  if(relayState == 1){
    status = true;
    Serial.println("From Blynk Status True");
  }
}

BLYNK_WRITE(V1){
  String isON = param.asStr();
  if(isON == "ON"){
    status = true;
    Serial.println("From Blynk Status True");
  }else{
    status = false;
    Serial.println("From Blynk Status False");
    delay(60000);
  }
}

void breaker(){
  if (Serial.available() > 0) {
    String consoleInput = Serial.readStringUntil('\n');
    if (consoleInput == "false") {
      status = false;
      Serial.println("Status diubah menjadi False dari console.");
    }
  }
}


