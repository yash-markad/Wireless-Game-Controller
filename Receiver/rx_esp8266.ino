// Receiving data form transmitter over Mac protocol 


#include <ESP8266WiFi.h>
#include <espnow.h>

// Structure example to receive data
// Must match the sender structure
typedef struct test_struct {
    float x;
    float y;
    float z;
} test_struct;

// Create a struct_message called myData
test_struct myData;

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(myData));
//  Serial.print("x: ");
//  Serial.println(myData.x);
//  Serial.print("y: ");
//  Serial.println(myData.y);
//  Serial.print("z: ");
//  Serial.println(myData.z);
//  Serial.println();
    delay(400);
//    Serial.print("x: ");
    Serial.print(myData.x);
//    Serial.print("y: ");
    Serial.print(",");
    Serial.print(myData.y);
    Serial.println("");
    delay(400);
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  
}
