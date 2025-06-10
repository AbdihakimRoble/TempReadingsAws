# INSTALLATION OCH KÖRNING

Det här dokumentet guidar dig genom installation och konfigurering av hela IoT-projektet med ESP32, AWS IoT Core, Node-RED, InfluxDB och Grafana.

---

## 1. Klona repot

```bash
git clone https://github.com/AbdihakimRoble/TempReadingsAws.git
cd TempReadingsAws
2. Förbered ESP32
Installera Arduino IDE
→ Ladda ner Arduino IDE

Installera ESP32 Board Support

Gå till File > Preferences

Lägg till i “Additional Board URLs”:

bash
Kopiera
Redigera
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
Gå till Tools > Board > Boards Manager

Sök efter esp32 och installera paketet från Espressif.

Öppna filen TempReadingsAwS.ino i Arduino IDE.

Ange WiFi-uppgifter och AWS-certifikat

I koden: fyll i WiFi-namn/lösenord.

Kopiera in rätt certifikat i certs.h.

Välj rätt kort och port

Välj din ESP32-modell under Tools > Board

Välj korrekt port under Tools > Port

Kompilera och ladda upp till ESP32.

3. Konfigurera AWS IoT Core
Gå till AWS Console

Navigera till IoT Core → Things → Create thing

Skapa en policy som tillåter iot:Connect, iot:Publish, iot:Subscribe, iot:Receive

Skapa ett certifikat & ladda ner:

certificate.pem.crt

private.pem.key

AmazonRootCA1.pem

Anslut certifikatet till din “Thing” och policy

Notera din IoT Endpoint URL (från Settings)

4. Starta och konfigurera Node-RED
Installera Node.js
→ Ladda ner Node.js

Installera Node-RED

bash
Kopiera
Redigera
npm install -g --unsafe-perm node-red
Starta Node-RED

bash
Kopiera
Redigera
node-red
Öppna i webbläsaren: http://localhost:1880

Importera Node-RED-flöde

Klicka meny (☰) → Import

Klistra in JSON från node-red-flows.json (finns i repo)

Konfigurera MQTT-anslutning med:

AWS IoT endpoint

Certifikat & nycklar

5. Installera och konfigurera InfluxDB
Ladda ner från: InfluxDB Downloads

Starta InfluxDB och skapa:

En bucket (ex. temperature_data)

En organization

En API token

I Node-RED:

Anslut till InfluxDB

Använd influxdb out-noden för att skriva temperaturdata

6. Installera och konfigurera Grafana
Ladda ner från: Grafana Downloads

Starta Grafana på http://localhost:3000
(Standard login: admin / admin)

Lägg till InfluxDB som datasource:

URL: http://localhost:8086

Organization och bucket enligt ovan

API-token som autentisering

Skapa dashboard med linjediagram som visar temperatur över tid

7. Testa hela flödet
✅ ESP32 skickar data via MQTT till AWS IoT Core
✅ Node-RED tar emot och skickar vidare till InfluxDB
✅ Grafana visar realtidsgraf från databasen

Felsökning
WiFi-problem? Kontrollera SSID/lösenord i koden

MQTT-anslutning misslyckas? Dubbelkolla certifikat och policy

Data syns inte i Grafana? Se om Node-RED skickar till rätt bucket/databas

ESP32-kompilering misslyckas? Kontrollera att alla bibliotek är installerade

Nästa steg
Lägg till fler sensorer

Skicka pushnotiser via Telegram

Lägg till larm i Grafana
