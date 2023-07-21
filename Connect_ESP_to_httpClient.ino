#include <WiFi.h>
#include <HTTPClient.h>
#define USE_SERIAL Serial

const char* SSID = "Wokwi-GUEST";
const char* password = "";
const String url="https://s-m.com.sa/f.html";
String payload = "";

void setup() {
  Serial.begin(115200);
  WiFi.begin(SSID, password);
  pinMode(25,OUTPUT);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("OK! IP=");
  Serial.println(WiFi.localIP());

  Serial.print("Fetching " + url + "... ");
}

void loop() {

    HTTPClient http;
    http.begin(url);
    int httpResCode = http.GET();

    // httpResCode will be negative on error
    if(httpResCode > 0) {
        // HTTP header has been send and Server response header has been handled
        USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpResCode);
        payload = http.getString();
        USE_SERIAL.println();
        USE_SERIAL.println(payload);
        
        if(payload == "forward") {
            digitalWrite(25,HIGH);
        } else {
            digitalWrite(25,LOW);
        }
    } else {
        USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpResCode).c_str());
    }

    http.end();
    delay(5000);
}