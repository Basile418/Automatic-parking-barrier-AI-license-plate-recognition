#include "esp_camera.h"
#include <WiFi.h>
#define CAMERA_MODEL_AI_THINKER // Has PSRAM
//#include "camera_pins.h"

const char* ssid = "Esp32cam";
const char* password = "esp32cam";
const int pirPin = 14;  // GPIO pour la détection de mouvement (PIR) sur le module AI Thinker



void setup() {
  Serial.begin(115200);

  pinMode(pirPin, INPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connexion au WiFi...");
  }
  Serial.println("Connecté au WiFi");

  // Configuration de la caméra
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = 5;
  config.pin_d1 = 18;
  config.pin_d2 = 19;
  config.pin_d3 = 21;
  config.pin_d4 = 36;
  config.pin_d5 = 39;
  config.pin_d6 = 34;
  config.pin_d7 = 35;
  config.pin_xclk = 0;
  config.pin_pclk = 22;
  config.pin_vsync = 25;
  config.pin_href = 23;
  config.pin_sscb_sda = 26;
  config.pin_sscb_scl = 27;
  config.pin_pwdn = 32;
  config.pin_reset = -1;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_SVGA;
  config.jpeg_quality = 12;
  config.fb_count = 2;

  // Initialisation de la caméra
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Échec de l'initialisation de la caméra (%d)\n", err);
    return;
  }
  Serial.println("Caméra initialisée");
}

void loop() {
  if (digitalRead(pirPin) == HIGH) {
    Serial.println("Mouvement détecté!");

    // Capturer une photo
    camera_fb_t *fb = esp_camera_fb_get();
    if (!fb) {
      Serial.println("Échec de la capture de la photo");
      return;
    }

    // Envoyer la photo via WiFi
    WiFiClient client;
    if (client.connect("172.20.10.2", 5000)) {  // Remplacez avec l'adresse IP de votre ordinateur
      client.println("POST /upload_photo.php HTTP/1.1");
      client.println("Host: 172.20.10.2");
      client.println("Content-Type: image/jpeg");
      client.println("Content-Length: " + String(fb->len));
      client.println();
      client.write(fb->buf, fb->len);
      client.println();
      client.stop();
      Serial.println("Photo envoyée avec succès");
    } else {
      Serial.println("Échec de la connexion au serveur");
    }

    // Libérer la mémoire utilisée par la photo
    esp_camera_fb_return(fb);

    // Attendre avant de capturer une nouvelle image
    delay(3000);
  }

  // Attendre 1 seconde entre chaque vérification de mouvement
  delay(3000);
}
