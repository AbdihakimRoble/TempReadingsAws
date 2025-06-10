# INSTALLATION OCH KÖRNING

Det här dokumentet guidar dig genom installation och konfigurering av hela IoT-projektet med ESP32, AWS IoT Core, Node-RED, InfluxDB och Grafana.

---

## 1. Klona repot

```bash
git clone https://github.com/AbdihakimRoble/TempReadingsAws.git
cd TempReadingsAws
```

### 2. Förbered ESP32

#### Installera Arduino IDE
→ Ladda ner Arduino IDE

---

## Installera ESP32 Board Support

* Gå till File > Preferences
* Lägg till i "Additional Board URLs":

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

* Gå till Tools > Board > Boards Manager
* Sök efter esp32 och installera paketet från Espressif

### 📁 Ladda upp koden till ESP32
* Öppna filen TempReadingsAwS.ino i Arduino IDE
* **Ange WiFi-uppgifter och AWS-certifikat i koden**
* Välj rätt board: Tools > Board > ESP32 Dev Module (eller motsvarande)
* Kompilera och ladda upp

[fortsätter med resten av formateringen...]
​
Vill du ha resten av texten konverterad också? Jag kan fortsätta med den återstående delen.
14 resultat
ja allt
Här är hela texten konverterad till markdown:
# INSTALLATION OCH KÖRNING

Det här dokumentet guidar dig genom installation och konfigurering av hela IoT-projektet med ESP32, AWS IoT Core, Node-RED, InfluxDB och Grafana.

---

## 1. Klona repot

```bash
git clone https://github.com/AbdihakimRoble/TempReadingsAws.git
cd TempReadingsAws
```

### 2. Förbered ESP32

#### Installera Arduino IDE
→ Ladda ner Arduino IDE

---

## Installera ESP32 Board Support

* Gå till File > Preferences
* Lägg till i "Additional Board URLs":

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

* Gå till Tools > Board > Boards Manager
* Sök efter esp32 och installera paketet från Espressif

### 📁 Ladda upp koden till ESP32
* Öppna filen TempReadingsAwS.ino i Arduino IDE
* **Ange WiFi-uppgifter och AWS-certifikat i koden**
* Välj rätt board: Tools > Board > ESP32 Dev Module (eller motsvarande)
* Kompilera och ladda upp

## 3. Konfigurera AWS IoT Core

* Gå till AWS Console
* Navigera till IoT Core > Things > Create thing
* Skapa en policy som tillåter:

```makefile
iot:Connect
iot:Publish
iot:Subscribe
iot:Receive
```

* Skapa ett certifikat & ladda ner:
  * certificate.pem.crt
  * private.pem.key
  * AmazonRootCA1.pem
* Anslut certifikatet till din "Thing" och policy
* Notera din IoT Endpoint URL (under Settings)

## 4. Starta och konfigurera Node-RED

### 🧰 Installera Node.js
→ Ladda ner Node.js

### 🌐 Installera Node-RED

```bash
npm install -g --unsafe-perm node-red
```

### ▶ Starta Node-RED

```bash
node-red
```

* Öppna i webbläsaren: http://localhost:1880

### 📥 Importera Node-RED-flöde
* Klicka meny (☰) → Import
* Klistra in JSON från node-red-flows.json (finns i repo)
* Konfigurera MQTT med:
  * AWS IoT Endpoint
  * Certifikat & nycklar

## 5. Installera och konfigurera InfluxDB

* → Ladda ner InfluxDB
* Starta InfluxDB och skapa:
  * En bucket (ex. temperature_data)
  * En organization
  * En API token
* I Node-RED:
  * Använd influxdb out-noden för att skriva till InfluxDB

## 6. Installera och konfigurera Grafana

* → Ladda ner Grafana
* Starta Grafana på: http://localhost:3000

Standard login: admin / admin

### ➕ Lägg till InfluxDB som datasource
* URL: http://localhost:8086
* Organization och bucket enligt ovan
* Använd din API token som autentisering

### 📊 Skapa en dashboard
* Lägg till ett linjediagram
* Visa temperatur över tid från InfluxDB

## 7. Testa hela flödet ✅

* ESP32 skickar data via MQTT till AWS IoT Core
* Node-RED tar emot och skickar till InfluxDB
* Grafana visar realtidsdata från databasen

### 🔧 Felsökning

| Problem | Lösning |
|---------|---------|
| WiFi-problem | Kontrollera SSID/lösenord i koden |
| MQTT misslyckas | Kontrollera certifikat och IoT-policy |
| Ingen data i Grafana | Se att Node-RED skickar till rätt bucket |
| Fel vid kompilering | Kontrollera att alla bibliotek är installerade |

### 📈 Nästa steg
* Lägg till fler sensorer
* Skicka pushnotiser via t.ex. Telegram
* Lägg till larm i Grafana

  ## Lycka till!
