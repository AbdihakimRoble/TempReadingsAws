#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "certs.h"  

// Wi-Fi inställningar
const char* ssid = "2.4g"; 
const char* password = "nbfrakne";  

// AWS IoT inställningar
const char* mqtt_server = "a3aijxzs7glmgu-ats.iot.eu-north-1.amazonaws.com";  
const int mqtt_port = 8883;
const char* mqtt_topic = "iot/temperature";  
const char* mqtt_client_id = "iotconsole-868f5cdb-9e38-4266-b3d4-a32d541b67e7";  

WiFiClientSecure espClient;
PubSubClient client(espClient);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 0, 60000);  // UTC-tid, uppdateras varje 60 sek

int sensor_id_counter = 1;

float generateTemperature() {
  return random(100, 300) / 10.0; 
}

String getTimestamp() {
  timeClient.update();
  time_t rawTime = timeClient.getEpochTime();
  time_t localTime = rawTime + 2 * 3600; // UTC+2 för Sverige sommaren
  struct tm* timeInfo = gmtime(&localTime);
  char buffer[25];
  strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%SZ", timeInfo);
  return String(buffer);
}


void waitForTimeSync() {
  Serial.print("Väntar på tidssynkronisering via NTP...");
  timeClient.begin();
  timeClient.update();

  unsigned long start = millis();
  while (timeClient.getEpochTime() < 24 * 3600) { 
    delay(500);
    timeClient.update();
    Serial.print(".");
    if (millis() - start > 10000) { 
      Serial.println("\nTidssynkronisering tog för lång tid, fortsätter ändå...");
      break;
    }
  }
  Serial.println("\nTid synkad: " + getTimestamp());
}

void connectWiFi() {
  Serial.print("Ansluter till Wi-Fi...");
  WiFi.begin(ssid, password);
  int attempts = 0;
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    attempts++;
    if (attempts > 20) {
      Serial.println("\nWi-Fi kunde inte ansluta! Startar om...");
      ESP.restart();
    }
  }
  
  Serial.println("\nWi-Fi anslutet!");
  Serial.print("Din IP-adress: ");
  Serial.println(WiFi.localIP());
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Meddelande mottaget på topic: ");
  Serial.println(topic);
  Serial.print("Payload: ");
  for (unsigned int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void connectMQTT() {
  while (!client.connected()) {
    Serial.print("Ansluter till AWS IoT Core...");
    if (client.connect(mqtt_client_id)) {
      Serial.println(" Ansluten!");
      client.subscribe(mqtt_topic);  // Prenumerera på topic
      client.setCallback(mqttCallback); // Sätt callback-funktion
    } else {
      Serial.print(" Misslyckades, felkod: ");
      Serial.println(client.state());
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  connectWiFi();

  waitForTimeSync();

  espClient.setCACert(aws_root_ca);
  espClient.setCertificate(device_cert);
  espClient.setPrivateKey(private_key);

  client.setServer(mqtt_server, mqtt_port);

  connectMQTT();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }
  if (!client.connected()) {
    connectMQTT();
  }

  float temperature = generateTemperature();
  String sensor_id = "sensor_" + String(sensor_id_counter);
  String timestamp = getTimestamp();

  String payload = "{\"sensor_id\": \"" + sensor_id + "\", \"temperature\": " + String(temperature, 1) + ", \"timestamp\": \"" + timestamp + "\"}";

  if (client.publish(mqtt_topic, payload.c_str())) {
    Serial.print("Data skickad: ");
    Serial.println(payload);
  } else {
    Serial.println("Misslyckades att skicka data!");
  }

  sensor_id_counter++;

  client.loop();

  delay(10000);
}
