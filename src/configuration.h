#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

#define SWITCH_1_PIN    2
#define SWITCH_2_PIN    3
#define SWITCH_3_PIN    4
#define SWITCH_4_PIN    5
#define SWITCH_5_PIN    6

#define DHT22_1_PIN     7
#define DHT22_2_PIN     8

#define PM25_RX_PIN     0
#define PM25_TX_PIN     1

#define LED_1_PIN       9
#define LED_2_PIN       10
#define LED_3_PIN       11

#define BUZZER_PIN      12

#define UART_COMM_RX    13
#define UART_COMM_TX    14

#define DHTTYPE DHT22

enum MessageType {
    MSG_TEMPERATURE_1 = 0x01,
    MSG_TEMPERATURE_2 = 0x02,
    MSG_HUMIDITY_1 = 0x03,
    MSG_HUMIDITY_2 = 0x04,
    MSG_PM25 = 0x05,
    MSG_SWITCH_STATE = 0x06,
    MSG_LED_COMMAND = 0x07,
    MSG_BUZZER_COMMAND = 0x08,
    MSG_ACK = 0x09,
    MSG_ERROR = 0x0A
};

struct DataPacket {
    uint8_t start_marker;
    uint8_t message_type;
    float value;
    uint8_t checksum;
    uint8_t end_marker;
};

struct SwitchStates {
    bool switch1;
    bool switch2;
    bool switch3;
    bool switch4;
    bool switch5;
};

struct SensorData {
    float controlbox_temp;
    float sensorbox_temp;
    float controlbox_humidity;
    float sensorbox_humidity;
    float pm25;
    unsigned long timestamp;
};

#define START_MARKER 0xFF
#define END_MARKER 0xFE
#define BAUD_RATE 115200
#define UART_COMM_BAUD 9600
#define PM25_BAUD 9600

#define DEBOUNCE_DELAY 50
#define SENSOR_READ_INTERVAL 2000

#define TEMP_HIGH_THRESHOLD 30.0
#define TEMP_LOW_THRESHOLD 15.0
#define HUMIDITY_HIGH_THRESHOLD 70.0
#define PM25_HIGH_THRESHOLD 35.0

#endif // CONFIG_H