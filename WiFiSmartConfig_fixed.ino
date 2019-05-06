#include "WiFi.h"
boolean attemptConnect() {
int i;

//Wait for WiFi to connect to AP
  Serial.println("Waiting for WiFi");
  for (i=50; i && (WiFi.status() != WL_CONNECTED); --i) {
    delay(500);
    Serial.print(".");
  }
  return (i != 0);
}

void setup() {
  Serial.begin(115200);

  //Init WiFi as Station, start SmartConfig
  WiFi.mode(WIFI_AP_STA);

  WiFi.begin();

  if ( ! attemptConnect()) {
    WiFi.beginSmartConfig();
  
    //Wait for SmartConfig packet from mobile
    Serial.println("Waiting for SmartConfig.");
    while (!WiFi.smartConfigDone()) {
      delay(500);
      Serial.print(".");
    }
    WiFi.stopSmartConfig();
    
    Serial.println("");
    Serial.println("SmartConfig received.");
  }
  WiFi.begin();

  if ( ! attemptConnect()) {
    Serial.println("Wifi connect failed (again)");
    ESP.restart();
  } else {

  Serial.println("WiFi Connected.");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
