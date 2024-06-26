#include <Wire.h>
#include <Servo.h>
#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
#include <U8g2lib.h>

#define SCL_OLED 21
#define SDA_OLED 20

U8G2_SH1106_128X64_NONAME_F_SW_I2C OLED(U8G2_R0,SCL_OLED, SDA_OLED, /*reset=*/U8X8_PIN_NONE );

Servo servo[20];
int servo_position[20];
int receivedArray[20];
float increment[20];
unsigned long final_time;
unsigned long partial_time;
int steps = 1;
int speed = 1000;

const unsigned char epd_bitmap__a_frm32_80 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x07, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0x07, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x1f, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void move_servo(int time, int  servo_target[]) {

  if (time > 10) {
    for (int i = 0; i < 20; i++) {
      increment[i] = ((servo_target[i]) - servo_position[i]) / (time / 10.0);
    }
    final_time =  millis() + time;

    for (int iteration = 1; millis() < final_time; iteration++) {
      partial_time = millis() + 10;

      for (int i = 0; i < 20; i++) {
        servo[i].write((int)(servo_position[i] + (iteration * increment[i])));
      }
      while (millis() < partial_time);
    }
  }
  else {
    for (int i = 0; i < 20; i++) {
      servo[i].write((int)servo_target[i]);
    }
  }
  for (int i = 0; i < 20; i++) {
    servo_position[i] = servo_target[i];
  }
}

void initial_face() {
  OLED.drawXBMP(0, 0, 128, 64, epd_bitmap__a_frm32_80);
  OLED.sendBuffer(); 
}
void walk(int steps, int speed) {

  int degree_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  int degree_array2[20] = {110, 150, 150, 30, 110, 90, 105, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  int degree_array3[20] = {110, 150, 120, 65, 110, 90, 105, 30, 30, 150, 90, 90, 20, 30, 30, 120, 150, 150, 90, 90};
  int degree_array4[20] = {90, 150, 120, 65, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array1);
  move_servo(speed, degree_array2);
  move_servo(speed, degree_array3);
  move_servo(speed, degree_array4);
  for (int i = 1; i <= steps; i++) {
    int degree_array5[20] = {75, 150, 150, 30, 90, 90, 70, 30, 30, 150, 70, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int degree_array6[20] = {75, 150, 150, 30, 90, 90, 70, 30, 60, 120, 70, 90, 60, 30, 30, 160, 150, 150, 90, 90};
    int degree_array7[20] = {90, 150, 150, 30, 90, 90, 90, 30, 60, 120, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int degree_array8[20] = {110, 150, 150, 30, 110, 90, 105, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int degree_array9[20] = {110, 150, 120, 65, 110, 90, 105, 30, 30, 150, 90, 90, 20, 30, 30, 120, 150, 150, 90, 90};
    int degree_array10[20] = {90, 150, 120, 65, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    move_servo(speed, degree_array5);
    move_servo(speed, degree_array6);
    move_servo(speed, degree_array7);
    move_servo(speed, degree_array8);
    move_servo(speed, degree_array9);
    move_servo(speed, degree_array10);
  }
  int degree_array11[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, degree_array11);
}
void right(int steps, int speed) {

  int pwm_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array1);
  for (int i = 1; i <= steps; i++) {
    int pwm_array2[20] = {75, 150, 150, 30, 90, 90, 70, 30, 30, 150, 70, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array3[20] = {75, 150, 145, 30, 90, 80, 70, 30, 30, 150, 70, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array4[20] = {90, 150, 145, 30, 90, 80, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array5[20] = {110, 150, 150, 30, 110, 80, 105, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array6[20] = {110, 150, 150, 30, 110, 90, 105, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array7[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    move_servo(speed, pwm_array2);
    move_servo(speed, pwm_array3);
    move_servo(speed, pwm_array4);
    move_servo(speed, pwm_array5);
    move_servo(speed, pwm_array6);
    move_servo(speed, pwm_array7);
  }
  int pwm_array8[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array8);
}

void left(int steps, int speed) {

  int pwm_array1[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array1);
  for (int i = 1; i <= steps; i++) {
    int pwm_array2[20] = {110, 150, 150, 30, 110, 90, 105, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array3[20] = {110, 150, 150, 30, 110, 90, 105, 30, 35, 150, 90, 100, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array4[20] = {90, 150, 150, 30, 90, 90, 90, 30, 35, 150, 90, 100, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array5[20] = {75, 150, 150, 30, 90, 90, 70, 30, 30, 150, 70, 100, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array6[20] = {75, 150, 150, 30, 90, 90, 70, 30, 30, 150, 70, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    int pwm_array7[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
    move_servo(speed, pwm_array2);
    move_servo(speed, pwm_array3);
    move_servo(speed, pwm_array4);
    move_servo(speed, pwm_array5);
    move_servo(speed, pwm_array6);
    move_servo(speed, pwm_array7);
  }
  int pwm_array8[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  move_servo(speed, pwm_array8);
}

void setup() {
  Serial.begin(115200);
  OLED.begin(); 
  OLED.setBusClock(1000000);
  OLED.clearBuffer();

  int servo_pins[20] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 22, 23};
  for (int i = 0; i < 20; i++) {
    servo[i].attach(servo_pins[i]);
  }
  int initial[20] = {90, 150, 150, 30, 90, 90, 90, 30, 30, 150, 90, 90, 30, 30, 30, 150, 150, 150, 90, 90};
  for (int i = 0; i < 20; i++) {
    servo_position[i] = initial[i];
  }
  move_servo(2000, initial);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    if (input == "WALK") {
      walk(1,1000);
    } else if (input == "RIGHT") {
      right(1,1000);
    } else if (input == "LEFT") {
      left(1,1000);
    } else {
      delay(500);
    }
  }
}
