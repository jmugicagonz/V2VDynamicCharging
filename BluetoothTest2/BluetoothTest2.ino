/*
  Arduino Nano 33 BLE Getting Started
  BLE peripheral with a simple Hello World greeting service that can be viewed
  on a mobile phone
  Adapted from Arduino BatteryMonitor example
*/

#include <ArduinoBLE.h>

static const char* greeting = "Hello World!";
// Device name
const char* nameOfPeripheral = "MyCar";
const char* uuidOfService = "00001101-0000-1000-8000-00805f9b34fb";
const char* uuidOfRxChar = "00001142-0000-1000-8000-00805f9b34fb";
const char* uuidOfTxChar = "00001143-0000-1000-8000-00805f9b34fb";

// BLE Service
BLEService myCarService(uuidOfService);

// Setup the incoming data characteristic (RX).
const int WRITE_BUFFER_SIZE = 256;
bool WRITE_BUFFER_FIZED_LENGTH = false;

BLEService greetingService("180C");  // User defined service

BLEStringCharacteristic greetingCharacteristic("2A56",  // standard 16-bit characteristic UUID
    BLERead, 13); // remote clients will only be able to read this

// RX / TX Characteristics
BLECharacteristic rxChar(uuidOfRxChar, BLEWriteWithoutResponse | BLEWrite, WRITE_BUFFER_SIZE, WRITE_BUFFER_FIZED_LENGTH);
BLEByteCharacteristic txChar(uuidOfTxChar, BLERead | BLENotify | BLEBroadcast);

void setup() {
  Serial.begin(9600);    // initialize serial communication
  while (!Serial);

  pinMode(LED_BUILTIN, OUTPUT); // initialize the built-in LED pin

  if (!BLE.begin()) {   // initialize BLE
    Serial.println("starting BLE failed!");
    while (1);
  }

  BLE.setLocalName("Nano33BLE");  // Set name for connection
  BLE.setAdvertisedService(greetingService); // Advertise service
  greetingService.addCharacteristic(greetingCharacteristic); // Add characteristic to service
  BLE.addService(greetingService); // Add service
  greetingCharacteristic.setValue(greeting); // Set greeting string

  BLE.setAdvertisedService(myCarService);
  myCarService.addCharacteristic(rxChar);
  myCarService.addCharacteristic(txChar);
  BLE.addService(myCarService);

  BLE.advertise();  // Start advertising
  Serial.print("Peripheral device MAC: ");
  Serial.println(BLE.address());
  Serial.println("Waiting for connections...");
}

void loop() {
  BLEDevice central = BLE.central();  // Wait for a BLE central to connect

  // if a central is connected to the peripheral:
  if (central) {
    Serial.print("Connected to central MAC: ");
    // print the central's BT address:
    Serial.println(central.address());
    // turn on the LED to indicate the connection:
    digitalWrite(LED_BUILTIN, HIGH);

    while (central.connected()){txChar.writeValue(2); } // keep looping while connected
    
    // when the central disconnects, turn off the LED:
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("Disconnected from central MAC: ");
    Serial.println(central.address());
  }

}

void onRxCharValueUpdate(BLEDevice central, BLECharacteristic characteristic) {
  // central wrote new value to characteristic, update LED
  Serial.print("Characteristic event, read: ");
  byte test[256];
  int dataLength = rxChar.readValue(test, 256);

  for(int i = 0; i < dataLength; i++) {
    Serial.print((char)test[i]);
  }
  Serial.println();
  Serial.print("Value length = ");
  Serial.println(rxChar.valueLength());
}
