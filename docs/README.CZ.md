[![en](https://img.shields.io/badge/language-english-red.svg)](https://github.com/Vaseksch/linefollower_esp32s3_Rev_C/blob/master/docs/README.md)
[![cz](https://img.shields.io/badge/jazyk-česky-blue.svg)](https://github.com/Vaseksch/linefollower_esp32s3_Rev_C/blob/master/docs/README.CZ.md)

# Line Follower Robot

Tento repozitář obsahuje software robota sledujícího čáru (line follower) založeného na platformě ESP32.  
Projekt byl vyvíjen iterativně – od velmi jednoduchých desek pro řízení motorů až po plnohodnotného robota navrženého pro další experimentování a vylepšování.

![IMG_9637-4](https://github.com/user-attachments/assets/bc300b56-2706-4b5e-9edc-961eee3da49d)

---

## Přehled projektu

- **Mikrokontrolér:** ESP32-S3-WROOM-1-N8  
- **Motory:** DC motory (až 12 V)  
- **Motorový driver:** TB6612FNG  
- **Senzory:** reflexní IR senzory QRD1114  

Hlavním cílem projektu je vytvořit spolehlivého a dobře pochopitelného line follower robota při zachování modulární struktury hardwaru i softwaru, která umožňuje snadné úpravy.

---

## Začátky projektu

Projekt začal jednoduchými **prototypovými deskami s ESP**, jejichž jediným cílem bylo ověřit základní řízení motorů.

Nejranější verze byly v podstatě jen **ESP32 desky schopné řídit DC motory**, bez senzorů a bez regulačního algoritmu.  
Tyto prototypy využívaly **motorový driver L9110** a sloužily především k pochopení chování ESP32 v reálných podmínkách.

Později projekt přešel na komplexnější návrh s **driverem L293D**, který umožnil sestavit prvního plně funkčního robota.

Tyto rané verze vytvořily základ pro všechny další hardwarové i softwarové revize.

---

## Hardwarové revize

Projekt prošel několika hardwarovými verzemi.  
Dnes používá pouze **Revision C**, zatímco starší verze sloužily především jako vývojové kroky.

Ve všech verzích byly použity **reflexní IR senzory QRD1114**.

---

### V0.1 – V0.3 (základní prototypy desek)

Raně prototypové desky zaměřené čistě na řízení motorů.

**Účel:**
- Ověření řízení motorů pomocí ESP32  
- Test základního napájení a I/O  

**Specifikace:**
- **MCU:** ESP32-S3-WROOM-1-N8  
- **Driver:** L9110  
- **Motory:** náhodné DC motory (3–6 V)  
- **Senzory:** neimplementovány  

**Další prvky:**
- Stavová LED  
- Programovatelná tlačítka  

![IMG_9517-1](https://github.com/user-attachments/assets/89c1cecd-0679-49cb-b343-e45f74de675c)

Tyto desky ještě nepředstavovaly funkčního robota, ale byly klíčové pro získání potřebných zkušeností.

---

### V1.0 (první funkční robot)

V1.0 byl **první plně funkční line follower robot**.  
Z této verze koncepčně vycházejí všechny další revize.

**Specifikace:**
- **MCU:** ESP32-S3-WROOM-1-N8  
- **Driver:** L293D  
- **Motory:** N20, 1000 RPM, 6 V  
- **Senzory:** QRD1114 (9×)  

**Další prvky:**
- Stavová LED  
- Programovatelná tlačítka  
- Patice pro MPU-6050 (funkční)  
- Přítlačný ventilátor (později opuštěn na základě testování)  

![IMG_9519-2](https://github.com/user-attachments/assets/329b43c2-fe2e-4674-83ad-9eba4dad4214)

Tato verze zformovala celkovou architekturu robota i princip řízení pro budoucí verze.

---

### Revision B (pouze návrh)

Revision B byla pouze návrhová iterace, která nebyla nikdy vyrobena.

**Plánované specifikace:**
- **MCU:** ESP32-S3-WROOM-1-N8  
- **Driver:** L293D  
- **Motory:** N20, 2000 RPM, 6 V  
- **Senzory:** QRD1114 (9×)  

**Plánované prvky:**
- Stavová LED  
- Programovatelná tlačítka  
- Patice pro MPU-6050  
- Patice pro I2C OLED displej  
- Konektor pro externí hlavní vypínač   

Tato revize nebyla nikdy vyrobena, protože nepřinášela dostatečný přínos vzhledem ke své složitosti.

---

### Revision C (aktuální verze)

Revision C je současná verze robota.

**Specifikace:**
- **MCU:** ESP32-S3-WROOM-1-N8   
- **Driver:** TB6612FNG  
- **Motory:** N20, 3000 RPM, 6–12 V  
- **Senzory:** QRD1114 (11×)  

**Další prvky:**
- Stavová LED  
- Programovatelná tlačítka  
- Patice pro MPU-6050  
- Patice pro I2C OLED displej  
- Konektor pro externí hlavní vypínač  
  (nyní zkratovaný, připrava pro soutěžní pravidla)  

![IMG_9626-3](https://github.com/user-attachments/assets/830fa12a-0e92-418a-9b65-99129699a304)

Revision C je považována za dostatečně spolehlivou pro účast na soutěžích.

---

## Software

- Napsán v Arduino-framework C++ pro ESP32  
- Využívá **PD regulátor** pro sledování čáry  
- Jasné oddělení:
  - čtení senzorů  
  - řídicí logiky  
  - výstupu na motory  

Software je strukturován tak, aby umožňoval snadné ladění a další rozšiřování.

![IMG_9587-2](https://github.com/user-attachments/assets/c4036861-77d5-4bbb-8963-39c1b0f81dc4)

---

## Aktuální cíle

- **"Perfektní" odladění PD regulátoru**
  - zlepšení stability v zatáčkách  
  - snížení kmitání  
  - konzistentní chování na různých površích  

---

## Dlouhodobé cíle

- **Bezdrátová komunikace pomocí ESP-NOW**
- **Implementace ToF senzoru**
  - pro detekci překážek a jejich vyhýbání   
