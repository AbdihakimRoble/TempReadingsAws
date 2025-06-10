# IoT Projekt: Temperaturmätning med ESP32, AWS och Grafana

## Översikt
Detta projekt är en komplett IoT-lösning för insamling, lagring och visualisering av temperaturdata i realtid. En ESP32-enhet samlar in temperaturdata, som skickas via säkrad MQTT-kommunikation till AWS IoT Core. Data lagras i DynamoDB och InfluxDB, och visualiseras i realtid med Grafana via Node-RED.

---

## Arkitektur och Dataflöde

![Arkitekturdiagram] ![ddd - Imgur](https://github.com/user-attachments/assets/aa7f76a2-ab9d-4995-9453-3c0152176711)


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
![InfluxDB realtidsgraf](path/to/influxdb-image.png)  
*Figur 2: InfluxDB lagrar temperaturdata som tidsserier vilket möjliggör snabb och effektiv hämtning för realtidsvisualisering.*

### Grafana Dashboard - Realtidsgraf  
![Grafana dashboard](path/to/grafana-image.png)  
*Figur 3: Grafana visar realtidsdata från InfluxDB i form av intuitiva och interaktiva grafer.*

### DynamoDB - Strukturerad datalagring  
![DynamoDB lagring](path/to/dynamodb-image.png)  
*Figur 4: DynamoDB används för att lagra JSON-dokument med temperaturdata för långsiktig analys och arkivering.*

### MQTT - Dataflöde via AWS IoT Core  
![MQTT värdevisning](path/to/mqtt-image.png)  
*Figur 5: Data skickas säkert från ESP32 till AWS IoT Core via MQTT med TLS-kryptering.*

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
| Optimering               | Skalbar NoSQL-datalagring          | Optimerad för tidsserie- och sensorflöden |
| Användningsområde        | Långsiktig lagring och analys      | Realtidsanalys och visualisering       |
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

För detaljerad installationsguide och källkod, se `/docs`-mappen i detta repo.

---

## Kontakt och support

För frågor eller samarbete:  
**Ditt Namn**  
Email: ditt.email@example.com  
GitHub: [https://github.com/dittkonto](https://github.com/dittkonto)

---

*Dokumentation skapad för IoT-kursprojekt, 2025.*

