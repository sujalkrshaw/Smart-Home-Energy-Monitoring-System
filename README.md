# ⚡ Smart Home Energy Monitoring System

![ESP32](https://img.shields.io/badge/ESP32-IoT-blue?style=for-the-badge\&logo=espressif)
![MQTT](https://img.shields.io/badge/MQTT-Communication-orange?style=for-the-badge)
![Node--RED](https://img.shields.io/badge/Node--RED-Dashboard-red?style=for-the-badge\&logo=nodered)
![Arduino](https://img.shields.io/badge/Arduino-IDE-green?style=for-the-badge\&logo=arduino)
![Wokwi](https://img.shields.io/badge/Wokwi-Simulation-purple?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-brightgreen?style=for-the-badge)

---

## 📌 Project Overview

The **Smart Home Energy Monitoring System** is an IoT-based solution that enables real-time monitoring of household energy consumption using **ESP32**, **MQTT**, **Node-RED Dashboard**, and **OLED Display**.

The system continuously tracks:

* ⚡ Voltage
* 🔌 Current
* 📊 Power Consumption
* 💡 Energy Usage
* 💰 Electricity Cost
* 🚨 Alert Status

All data is transmitted using MQTT and visualized through a real-time dashboard.

---

## 🎯 Problem Statement

Traditional electricity meters provide limited visibility into energy consumption patterns.

Users often:

* Don't know which appliances consume the most energy.
* Receive electricity bills without understanding usage trends.
* Cannot detect abnormal power consumption in real time.

This project solves these challenges by providing continuous monitoring and live analytics.

---

## 🚀 Features

### 📡 Real-Time Monitoring

* Voltage Monitoring
* Current Monitoring
* Power Calculation
* Energy Consumption Tracking
* Cost Estimation

### 📈 Live Dashboard

* Analog Gauges
* Real-Time Charts
* Status Indicators
* Energy Analytics

### 🔔 Smart Alert System

| Condition     | Alert      |
| ------------- | ---------- |
| Power < 800W  | NORMAL     |
| Power > 800W  | HIGH_USAGE |
| Power > 1000W | CRITICAL   |

### 📺 OLED Display

Displays live readings directly on the ESP32 system.

### 🌐 MQTT Communication

Reliable real-time communication between:

ESP32 → MQTT Broker → Node-RED → Dashboard

---

## 🏗️ System Architecture

```text
ESP32
   │
   ▼
MQTT Broker
   │
   ▼
Node-RED
   │
   ▼
Dashboard
   │
   ▼
User Monitoring
```

---

## 🔄 Workflow

### Step 1

ESP32 generates electrical parameters.

### Step 2

Power is calculated:

Power = Voltage × Current

### Step 3

Energy consumption is updated.

### Step 4

Electricity cost is estimated.

### Step 5

Data is converted into JSON format.

Example:

```json
{
  "voltage":230,
  "current":4.89,
  "power":1124.70,
  "energy":0.0013,
  "cost":0.01,
  "alert":"CRITICAL"
}
```

### Step 6

MQTT publishes data.

### Step 7

Node-RED receives the data.

### Step 8

Dashboard updates automatically.

### Step 9

Alerts are generated when limits are exceeded.

---

## 🛠️ Hardware Components

* ESP32 Development Board
* OLED SSD1306 Display
* Green LED
* Red LED
* Buzzer
* Breadboard
* Jumper Wires

---

## 💻 Software Requirements

* Arduino IDE
* Node.js
* Node-RED
* Mosquitto MQTT Broker
* Wokwi Simulator

---

## 📚 Libraries Used

```cpp
WiFi.h
PubSubClient.h
Wire.h
Adafruit_GFX.h
Adafruit_SSD1306.h
```

---

## 📂 Project Structure

```text
Smart-Home-Energy-Monitoring-System
│
├── dashboard
├── docs
├── esp32_code
├── node_red
├── reports
├── wokwi
├── README.md
└── requirements.txt
```

---

## 📷 Screenshots

### ESP32 Circuit

Add image here:

```text
images/circuit.png
```

### OLED Display

Add image here:

```text
images/oled_display.png
```

### Node-RED Flow

Add image here:

```text
images/node_red_flow.png
```

### Dashboard

Add image here:

```text
images/dashboard.png
```

---

## 📊 Results

Successfully achieved:

✅ Real-Time Monitoring

✅ MQTT Communication

✅ Live Dashboard Visualization

✅ Cost Estimation

✅ Critical Usage Alerts

✅ OLED Display Integration

---

## 🔮 Future Enhancements

### Sensor Integration

* ACS712 Current Sensor
* ZMPT101B Voltage Sensor

### Database Storage

* SQLite
* MySQL
* InfluxDB

### Smart Notifications

* Email Alerts
* Telegram Alerts
* WhatsApp Alerts

### Appliance Automation

* Relay Module Control
* Fan Control
* AC Control
* Heater Control

### Artificial Intelligence

* Energy Prediction
* Monthly Bill Forecasting
* Consumption Analytics

---

## 🎓 Learning Outcomes

Through this project I learned:

* IoT System Design
* ESP32 Programming
* MQTT Communication
* Node-RED Dashboard Development
* Real-Time Data Visualization
* Energy Analytics

---

## 👨‍💻 Author

**Sujal Kumar Shaw**

B.Tech Student | IoT Developer | Embedded Systems Enthusiast

GitHub: https://github.com/YOUR_USERNAME

---

## ⭐ Support

If you found this project useful:

⭐ Star the repository

🍴 Fork the repository

📢 Share with others

---

### Made with ❤️ using ESP32, MQTT, Node-RED and IoT
