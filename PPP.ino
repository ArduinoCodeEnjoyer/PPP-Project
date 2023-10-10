#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <AccelStepper.h>
#include <PID_v1.h>

const int enaPin = 13; //enable
const int dirPin = 10; //spin direction
const int stepPin = 11; //stepper motor pin

const int prev = 9;
const int ok = 8;
const int next = 7;

int limsw = 12;

double TargetTemp = 200;
int okstate, nextstate, prevstate;

double Kp = 20;
double Ki = 0;
double Kd = 10;

int stepSpd = 100;

int MaxMap = 140;

#define HC 6

double TempOutput;

// ตัวแปรต่างของ Thermistor
const float referenceResistance = 100000.0;  // Thermistor resistance at reference temperature (ohms)
const float referenceTemperature = 25.0;     // Reference temperature in Celsius
const float betaValue = 3950.0;              // Beta value of the thermistor

// กำหนดขา Thermistor
const int thermistorPin = A0;

// ตัวแปร Low-pass filter
const float alpha = 0.09;  // ค่าการปรับความเรียบของสัญญาณ (0 < alpha < 1)
//const float alpha = 0.075;  // ค่าการปรับความเรียบของสัญญาณ (0 < alpha < 1)
double filteredTemperature = 0.0;  // ค่าเริ่มต้น

#define motorInterfaceType 1

LiquidCrystal_I2C lcd(0x27, 20, 4);
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);
PID myPID(&filteredTemperature, &TempOutput, &TargetTemp , Kp, Ki, Kd, DIRECT);

void setup() {
  lcd.init();
  readTempNoDis();
  myPID.SetMode(AUTOMATIC);
  
  //Assign pinMode
  pinMode(prev, INPUT_PULLUP);
  pinMode(ok, INPUT_PULLUP);
  pinMode(next, INPUT_PULLUP);
  pinMode(limsw, INPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(HC, OUTPUT);

  analogWrite(HC, 0);
  
  //Initialize stepper motor parameters
  digitalWrite(dirPin, HIGH);
  digitalWrite(enaPin, HIGH);
  stepper.setMaxSpeed(2000);

  //Initialize UI
  lcd.clear();
  lcd.backlight();
  delay(500);
  lcd.clear();
  lcd.print("       PPP");
  lcd.setCursor(5, 1);
  lcd.print("Project");
  delay(4000);
  lcd.clear();
  homescreen();

  Serial.begin(9600);
}

void loop() {
  homescreen();
  buttonstate();
}
