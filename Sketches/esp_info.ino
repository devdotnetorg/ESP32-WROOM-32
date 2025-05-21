#include "arduino.h"
#include "esp_system.h"
#include "esp_chip_info.h"

void setup() {
  Serial.begin(115200);
  delay(3000);
  Serial.println();

  // Print chip information
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);

  Serial.print("Chip model: ");
  Serial.println(ESP.getChipModel());

  Serial.printf("This is %s chip with %d CPU core(s) at %d MHz, WiFi%s%s \n",
                "ESP32",
                chip_info.cores,
                (int) ESP.getCpuFreqMHz(),
                (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
                (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

  Serial.print("SDK version: ");
  Serial.println(ESP.getSdkVersion());

  Serial.printf("Silicon revision: %d\n", chip_info.revision);
  
  #if defined(ESP_ARDUINO_VERSION_STR)
    Serial.print("Core (is build version): ");
    Serial.println(ESP.getCoreVersion());
  #else
    Serial.println("The build version is not defined, therefor it must be version 2.");
  #endif
 
  Serial.printf("%dMB %s flash at %d Hz\n",
                ESP.getFlashChipSize() / (1024 * 1024),
                (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external",
                (int)ESP.getFlashChipSpeed());

  // Check PSRAM
  if (chip_info.features & CHIP_FEATURE_EMB_PSRAM) {
    Serial.printf("This chip has %dMB embedded PSRAM\n", ESP.getPsramSize() / (1024 * 1024));
  } else {
    Serial.println("This chip does not have embedded PSRAM");
  }

  // Print RAM size
  Serial.printf("Total heap: %d\n", ESP.getHeapSize());
  Serial.printf("Free heap: %d\n", ESP.getFreeHeap());
  Serial.printf("Total PSRAM: %d\n", ESP.getPsramSize());
  Serial.printf("Free PSRAM: %d\n", ESP.getFreePsram());

}

void loop() {
  // Do nothing
}
