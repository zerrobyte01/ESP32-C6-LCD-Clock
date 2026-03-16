# ESP32-C6 LCD Clock (1.47\" ST7789)

Simple WiFi clock using an **ESP32‑C6** and **1.47\" ST7789 LCD**.

<img width="278" height="250" alt="image" src="https://github.com/user-attachments/assets/6ab81134-29ab-4f0d-bf4b-4cc26f9331fb" />

The device connects to WiFi, synchronizes time from an **NTP server**, and shows:

- Current time
- Day of the week
- Date
- WiFi signal strength

## Features

- NTP automatic time sync
- WiFi signal bars
- German weekday display
- Blinking clock colon
- Clean LCD layout

## Hardware

- ESP32‑C6
- 1.47\" ST7789 LCD Display
- WiFi connection

## Wiring

| LCD | ESP32 |
|----|----|
| MOSI | GPIO 6 |
| SCLK | GPIO 7 |
| CS | GPIO 14 |
| DC | GPIO 15 |
| RST | GPIO 21 |
| BL | GPIO 22 |

## Libraries

Install in Arduino IDE:

- WiFi
- WiFiUdp
- NTPClient
- Adafruit_GFX
- Adafruit_ST7789

## Setup

Edit WiFi credentials in the code:

```cpp
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";
```

Upload to your ESP32‑C6.

## Folder Structure

```
ESP32-C6-LCD-Clock
 ├── src
 │── ESP32_LCD_Clock.ino
 ├── images
 ├── esp32-clock.JPG
 ├── docs
 ├── README.md
 └── LICENSE
```

## License

MIT
