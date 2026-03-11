#include <Arduino.h>
#include <dhtnew.h>

DHTNEW mySensor(5);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);      // set LED pin as output
  digitalWrite(LED_BUILTIN, LOW);    // switch off LED pin

  Serial1.begin(9600);            // initialize UART with baud rate of 9600
  Serial1.println();
  Serial.print("DHTNEW_LIB_VERSION: ");
  Serial.println(DHTNEW_LIB_VERSION);
  Serial.println();
}
void loop() {
  while (Serial1.available() >= 0) {
    char receivedData = Serial1.read();   // read one byte from serial buffer and save to receivedData
    if (receivedData == '1') {
      digitalWrite(LED_BUILTIN, HIGH); // switch LED On
    }
    else if (receivedData == '0') {
      digitalWrite(LED_BUILTIN, LOW);  // switch LED Off
    }
  }

  uint32_t start = micros();
  int chk = mySensor.read();
  uint32_t stop = micros();

  if (chk != DHTLIB_WAITING_FOR_READ) {
    switch (chk) {
      case DHTLIB_OK:
        Serial.print("OK,\t");
        break;
      case DHTLIB_ERROR_CHECKSUM:
        Serial.print("Checksum error,\t");
        break;
      case DHTLIB_ERROR_TIMEOUT_A:
        Serial.print("Time out A error,\t");
        break;
      case DHTLIB_ERROR_TIMEOUT_B:
        Serial.print("Time out B error,\t");
        break;
      case DHTLIB_ERROR_TIMEOUT_C:
        Serial.print("Time out C error,\t");
        break;
      case DHTLIB_ERROR_TIMEOUT_D:
        Serial.print("Time out D error,\t");
        break;
      case DHTLIB_ERROR_SENSOR_NOT_READY:
        Serial.print("Sensor not ready,\t");
        break;
      case DHTLIB_ERROR_BIT_SHIFT:
        Serial.print("Bit shift error,\t");
        break;
      default:
        Serial.print("Unknown: ");
        Serial.print(chk);
        Serial.print(",\t");
        break;
    }

    Serial.print(mySensor.getHumidity(), 1);
    Serial.print(",\t");
    Serial.print(mySensor.getTemperature(), 1);
    Serial.print(",\t");

    uint32_t duration = stop - start;

    Serial.print(duration);
    Serial.print(",\t");
    Serial.println(mySensor.getType());
  }
}
