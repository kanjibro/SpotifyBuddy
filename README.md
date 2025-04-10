# SpotifyBuddy

A DIY Spotify controller built with an ESP32 microcontroller. This project allows you to control playback (play, pause, skip) on Spotify using physical buttons and fetches track info via the Spotify API.

## Features
- Play, pause, and skip tracks with hardware buttons.
- Displays current track name on an OLED screen.
- Connects to Spotify via Wi-Fi and the Spotify Web API.

## Hardware Requirements
- ESP32 Dev Module
- 3 Push Buttons
- SSD1306 OLED Display (128x64)
- Breadboard and jumper wires

## Software Requirements
- Arduino IDE
- Libraries: `WiFi`, `HTTPClient`, `ArduinoJson`, `Adafruit_GFX`, `Adafruit_SSD1306`

## Setup
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/kanjibro/SpotifyBuddy.git
   cd SpotifyBuddy
