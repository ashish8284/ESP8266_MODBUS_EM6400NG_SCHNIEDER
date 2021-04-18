#include <ModbusRTU.h>
ModbusRTU mb;

#include <SoftwareSerial.h>
int DE_RE = 4; //D4  For MAX485 chip
int RX = 12;
int TX = 13;
#include "IntToFloat.h"

SoftwareSerial S(RX, TX);//D6/D7  (RX , TX)

uint16_t Mread0[2];

bool cbWrite(Modbus::ResultCode event, uint16_t transactionId, void* data) {
  Serial.printf_P("Request result: 0x%02X, Mem: %d\n", event, ESP.getFreeHeap());
  return true;
}

void setup() {
  Serial.begin(115200);
  S.begin(9600, SWSERIAL_8N1);
  mb.begin(&S, DE_RE); //Assing Software serial port to Modbus instance for MAX485 chip having DI,DE,RE,RO Pin at TTL side
  mb.master(); //Assing Modbus function as master
  Serial.println(); //Print empty line
  Serial.println(sizeof(Mread0)); //Reaing size of first array
}
void loop() {
  if (!mb.slave()) {
    mb.readHreg(1, 2699, Mread0, 2 , cbWrite);  //(SlaevID,Address,Buffer,Range of data,Modus call)
    Serial.println(InttoFloat(Mread0[0], Mread0[1]));
  }
  mb.task();
  delay(1000);
  yield();
}
