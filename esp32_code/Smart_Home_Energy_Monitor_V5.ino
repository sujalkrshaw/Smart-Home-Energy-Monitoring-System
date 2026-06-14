#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// =========================
// OLED SETTINGS
// =========================
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  -1
);

// =========================
// WIFI SETTINGS
// =========================
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// =========================
// MQTT SETTINGS
// =========================
const char* mqtt_server = "broker.emqx.io";
const char* mqtt_topic = "sujal/home/energy";

WiFiClient espClient;
PubSubClient client(espClient);

// =========================
// PINS
// =========================
const int GREEN_LED = 18;
const int RED_LED   = 19;
const int BUZZER    = 23;

// =========================
// ENERGY VARIABLES
// =========================
float voltage = 230.0;
float current = 0.0;
float power = 0.0;
float energy = 0.0;
float cost = 0.0;

const float tariff = 8.0;

String alertStatus = "NORMAL";

// =========================
// WIFI CONNECT
// =========================
void setup_wifi() {

  Serial.println();
  Serial.print("Connecting WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

// =========================
// MQTT CONNECT
// =========================
void reconnect() {

  while (!client.connected()) {

    Serial.print("Connecting MQTT...");

    String clientId = "ESP32EnergyMonitor-";
    clientId += String(random(1000));

    if (client.connect(clientId.c_str())) {

      Serial.println("Connected");

    } else {

      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" retrying...");

      delay(2000);
    }
  }
}

// =========================
// SETUP
// =========================
void setup() {

  Serial.begin(115200);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {

    Serial.println("OLED Initialization Failed!");

    while (true);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);

  randomSeed(millis());

  setup_wifi();

  client.setServer(mqtt_server, 1883);

  Serial.println();
  Serial.println("================================");
  Serial.println("SMART HOME ENERGY MONITOR V5");
  Serial.println("================================");
}

// =========================
// LOOP
// =========================
void loop() {

  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  // Simulated Current
  current = random(50, 500) / 100.0;

  // Calculations
  power = voltage * current;

  energy += power / 3600000.0;

  cost = energy * tariff;

  // Alert Logic
  if (power > 1000) {

    alertStatus = "CRITICAL";

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);

  }
  else if (power > 800) {

    alertStatus = "HIGH_USAGE";

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);

  }
  else {

    alertStatus = "NORMAL";

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
  }

  // MQTT JSON Payload
  String payload = "{";

  payload += "\"voltage\":" + String(voltage, 0) + ",";
  payload += "\"current\":" + String(current, 2) + ",";
  payload += "\"power\":" + String(power, 2) + ",";
  payload += "\"energy\":" + String(energy, 4) + ",";
  payload += "\"cost\":" + String(cost, 2) + ",";
  payload += "\"alert\":\"" + alertStatus + "\"";

  payload += "}";

  client.publish(mqtt_topic, payload.c_str());

  // Serial Output
  Serial.println();
  Serial.println("================================");

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" A");

  Serial.print("Power: ");
  Serial.print(power);
  Serial.println(" W");

  Serial.print("Energy: ");
  Serial.print(energy, 4);
  Serial.println(" kWh");

  Serial.print("Cost: Rs ");
  Serial.println(cost, 2);

  Serial.print("Alert: ");
  Serial.println(alertStatus);

  Serial.println(payload);

  // OLED Display
  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(0, 0);
  display.print("Smart Energy");

  display.setCursor(0, 12);
  display.print("V:");
  display.print(voltage, 0);
  display.print("V");

  display.setCursor(64, 12);
  display.print("I:");
  display.print(current, 2);
  display.print("A");

  display.setCursor(0, 24);
  display.print("P:");
  display.print(power, 0);
  display.print("W");

  display.setCursor(0, 36);
  display.print("E:");
  display.print(energy, 4);
  display.print("kWh");

  display.setCursor(0, 48);
  display.print("Rs:");
  display.print(cost, 2);

  display.setCursor(70, 48);
  display.print(alertStatus);

  display.display();

  delay(1000);
}
