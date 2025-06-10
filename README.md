# IoT Projekt: Temperaturmätning med ESP32, AWS och Grafana

## Översikt
Detta projekt är en komplett IoT-lösning för insamling, lagring och visualisering av temperaturdata i realtid. En ESP32-enhet samlar in temperaturdata, som skickas via säkrad MQTT-kommunikation till AWS IoT Core. Data lagras i DynamoDB och InfluxDB, och visualiseras i realtid med Grafana via Node-RED.

---

## Systemkrav

- Arduino IDE version 2.0 eller senare
- Node.js version 14 eller senare för Node-RED
- AWS-konto med rättigheter att skapa IoT Core resurser
- Certifikat och nycklar för TLS 1.2 MQTT-kommunikation
- Grafana version 8 eller senare
## Arkitektur och Dataflöde
---
![ddd - Imgur](https://github.com/user-attachments/assets/aa7f76a2-ab9d-4995-9453-3c0152176711)


*Figur 1: Översikt över IoT-arkitekturen och dataflödet i projektet.*

Dataflödet fungerar så här:  
- ESP32 samlar in och tidstämplar temperaturdata.  
- Data skickas krypterat via MQTT till AWS IoT Core.  
- Data sparas i DynamoDB för långsiktig lagring och historik.  
- Node-RED vidarebefordrar data till InfluxDB, en tidsseriedatabas optimerad för realtidsanalys.  
- Grafana ansluter till InfluxDB och visar data i snygga, interaktiva dashboards i realtid.

---

## Visualisering och databaser

### InfluxDB - Tidsseriedata i realtid  
![z6dLrG0 - Imgur](https://github.com/user-attachments/assets/255d0647-7e28-45bc-ae8f-7a32bfe39456)

*Figur 2: InfluxDB lagrar temperaturdata som tidsserier vilket möjliggör snabb och effektiv hämtning för realtidsvisualisering.*

### Grafana Dashboard - Realtidsgraf  
 ![d2V4jDT - Imgur](https://github.com/user-attachments/assets/f8a9f7ae-84b8-4c55-8233-e0103f28e9ee)

*Figur 3: Grafana visar realtidsdata från InfluxDB i form av intuitiva och interaktiva grafer.*

### DynamoDB - Strukturerad datalagring  
![5iuwdVY - Imgur](https://github.com/user-attachments/assets/99235ab0-335a-4d6f-8dfb-a301ba940642)

*Figur 4: DynamoDB används för att lagra JSON-dokument med temperaturdata för långsiktig analys och arkivering.*

### MQTT - Dataflöde via AWS IoT Core  
![Ipiy4Cv - Imgur](https://github.com/user-attachments/assets/19d64937-e7c6-4291-926c-33edd563f76e)

*Figur 5: Data skickas säkert från ESP32 till AWS IoT Core via MQTT med TLS-kryptering.*

### Node-RED - Visuell flödeshantering
![MBsn5Qg - Imgur](https://github.com/user-attachments/assets/f4aade34-7db3-4e5d-8724-ea235f18f78e)


*Figur 6: Node-RED används för att skapa visuella flöden som processar och vidarebefordrar MQTT-data från AWS IoT Core till InfluxDB.*
---

## Varför valde vi InfluxDB för visualisering?

- **Optimerad för tidsseriedata:** InfluxDB hanterar stora datamängder med tidsstämplar effektivt, perfekt för sensorvärden som förändras snabbt.  
- **Hög prestanda:** Snabb inläsning och aggregering möjliggör realtidsvisualisering.  
- **Integrerad med Grafana:** Enkel konfiguration och kraftfulla visualiseringsmöjligheter.  
- **Flexibelt frågespråk (Flux):** Möjliggör avancerade analyser direkt i databasen.  

---

## Jämförelse med DynamoDB

| Funktion                  | DynamoDB                              | InfluxDB                               |
|--------------------------|-------------------------------------|---------------------------------------|
| Datatyp                  | JSON-dokument                       | Tidsseriedata med tidsstämplar        |
| Optimering               | Skalbar NoSQL-datalagring           | Optimerad för tidsserie- och sensorflöden |
| Användningsområde        | Långsiktig lagring och analys       | Realtidsanalys och visualisering       |
| Grafana-integration      | Kräver mellanlager                  | Direktstöd i Grafana                    |
| Frågespråk               | PartiQL (SQL-liknande)              | Flux (tidsseriefrågor)                  |

---

## Säkerhet

- All MQTT-kommunikation är krypterad med TLS 1.2.  
- Certifikatbaserad autentisering säkerställer auktoriserade enheter.  
- AWS IAM-policys reglerar åtkomst och rättigheter.  
- Tidssynkronisering med NTP garanterar korrekta tidsstämplar.  

---

## Projektets styrkor

- Fullständig IoT-lösning från sensor till visualisering.  
- Säker dataöverföring via MQTT med TLS.  
- Realtidsvisualisering via InfluxDB och Grafana.  
- Skalbar molninfrastruktur med AWS-tjänster.  
- Enkel datahantering och routing med Node-RED.  

---

## Förbättringsområden

- Utökning med fler sensorer och gateway-enheter.  
- Integration av push-notiser via externt API (t.ex. Telegram).  
- Fördjupad IoT-säkerhet, t.ex. AWS IoT Device Defender.  
- Mer avancerade dashboards med larmfunktioner i Grafana.  

---

## Installation och körning
För en detaljerad installationsguide, se [INSTALL.md](INSTALL.md)

---

## Kontakt och support

För frågor eller samarbete:  
**Abdihakim Roble**  
Email: abdihskib@gmail.com  
GitHub: [[https://github.com/dittkonto](https://github.com/AbdihakimRoble)]

---

*Dokumentation skapad för IoT-kursprojekt, 2025.*

MIT License

Copyright (c) 2025 Abdihakim Roble

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

