#include <Arduino.h>

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

//BLE server name
#define bleServerName "Leon_ESP32"

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 500;

bool deviceConnected = false;
int key, oldKey;
int keyState = 0;

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/
#define SERVICE_UUID "d103f067-bc43-4cbd-a97e-96c378e34180"

// Humidity Characteristic and Descriptor
BLECharacteristic keyCharacteristics("ca73b3ba-39f6-4ab3-91ae-186dc9577d99", BLECharacteristic::PROPERTY_NOTIFY);
BLEDescriptor keyDescriptor(BLEUUID((uint16_t)0x2903));

//Setup callbacks onConnect and onDisconnect
class MyServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
  };
  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
  }
};

void setup() {
  // Start serial communication 
  Serial.begin(115200);

  // Create the BLE Device
  BLEDevice::init(bleServerName);

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *bmeService = pServer->createService(SERVICE_UUID);

  // Key
  bmeService->addCharacteristic(&keyCharacteristics);
  keyDescriptor.setValue("Key pressed");
  keyCharacteristics.addDescriptor(new BLE2902());
  
  // Start the service
  bmeService->start();

  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pServer->getAdvertising()->start();
  Serial.println("Waiting a client connection to notify...");
}

void loop() {
  if (deviceConnected) {
    if ((millis() - lastTime) > timerDelay) {
      // Read the key status
      key = digitalRead(15);
      if(oldKey == 1 && key == 0){
        keyState = !keyState;
      }
      //Set key Characteristic value and notify connected client
      keyCharacteristics.setValue(keyState);
      keyCharacteristics.notify();   
      Serial.print("key: ");
      Serial.println(keyState);
      
      lastTime = millis();
      oldKey = key;
    }
  }
}