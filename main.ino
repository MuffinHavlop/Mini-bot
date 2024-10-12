#define REMOTEXY_MODE__ESP32CORE_BLUETOOTH
#include <BluetoothSerial.h>
#define REMOTEXY_BLUETOOTH_NAME "NATUS"
#include <RemoteXY.h>
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =  
  { 255,4,0,0,0,70,0,18,0,0,0,31,1,106,200,1,1,4,0,1,
  64,29,36,36,4,63,31,70,111,114,119,97,114,100,0,1,8,29,36,36,
  4,63,31,66,97,99,107,0,1,61,118,38,38,4,12,31,70,111,114,119,
  97,114,100,0,1,6,118,39,39,4,12,31,66,97,99,107,0 };
struct {
  uint8_t button_01;
  uint8_t button_02; 
  uint8_t button_03; 
  uint8_t button_04; 
  uint8_t connect_flag; 
} RemoteXY;   
#pragma pack(pop)
const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 12;
const int IN4 = 13;
const int enablePin1 = 18; 
const int enablePin2 = 19; 
bool motor1Active = false;
bool motor2Active = false;
BluetoothSerial SerialBT;
void setup() 
{
  RemoteXY_Init (); 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  SerialBT.begin("SOD'S NATUS");
}
void loop() 
{ 
  RemoteXY_Handler ();
  if (RemoteXY.button_01 == 1) {
    motor1Active = true;
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else if (RemoteXY.button_02 == 1) {
    motor1Active = true;
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  } else {
    motor1Active = false;
  }
  if (RemoteXY.button_03 == 1) {
    motor2Active = true;
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (RemoteXY.button_04 == 1) {
    motor2Active = true;
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else {
    motor2Active = false;
  }
  digitalWrite(enablePin1, motor1Active);
  digitalWrite(enablePin2, motor2Active);
}
