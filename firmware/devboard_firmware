
#include <Wire.h>
#include <ESP32Servo.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <ESP_I2S.h>
#include <math.h>

const int SDA_PIN = 15;
const int SCL_PIN = 16;

const int MOTOR_PINS[4][2] = {
  {4, 5},
  {6, 7},
  {8, 9},
  {10, 11}
};

const int BUTTON_PINS[3] = {12, 13, 14};

const int SERVO_PINS[6] = {
  35, 36, 37, 38, 39, 40
};

const int I2S_BCLK = 17;
const int I2S_LRC = 18;
const int I2S_DOUT = 21;

Adafruit_MPU6050 mpu;
Servo servos[6];
I2SClass audio;

bool motorTest = false;
bool audioReady = false;

bool lastButtonState[3] = {
  HIGH, HIGH, HIGH
};

unsigned long lastIMURead = 0;

void stopMotors() {
  for (int i = 0; i < 4; i++) {
    analogWrite(MOTOR_PINS[i][0], 0);
    analogWrite(MOTOR_PINS[i][1], 0);
  }
}

void setMotor(int motor, int speed) {
  if (motor < 0 || motor > 3) return;

  speed = constrain(speed, -255, 255);

  if (speed > 0) {
    analogWrite(MOTOR_PINS[motor][0], speed);
    analogWrite(MOTOR_PINS[motor][1], 0);
  } else if (speed < 0) {
    analogWrite(MOTOR_PINS[motor][0], 0);
    analogWrite(MOTOR_PINS[motor][1], -speed);
  } else {
    analogWrite(MOTOR_PINS[motor][0], 0);
    analogWrite(MOTOR_PINS[motor][1], 0);
  }
}

void centerServos() {
  for (int i = 0; i < 6; i++) {
    servos[i].write(90);
  }
}

void playTone(int frequency, int durationMs) {
  if (!audioReady) return;

  const int sampleRate = 16000;
  const int samplesPerBlock = 256;
  int16_t samples[samplesPerBlock];

  int totalSamples = sampleRate * durationMs / 1000;
  int generated = 0;

  while (generated < totalSamples) {
    int count = min(samplesPerBlock, totalSamples - generated);

    for (int i = 0; i < count; i++) {
      float phase = 2.0f * PI * frequency *
                    (generated + i) / sampleRate;

      samples[i] = (int16_t)(6000.0f * sinf(phase));
    }

    audio.write((uint8_t *)samples, count * sizeof(int16_t));
    generated += count;
  }

  int16_t silence[128] = {};
  audio.write((uint8_t *)silence, sizeof(silence));
}

void readButtons() {
  bool current[3];

  for (int i = 0; i < 3; i++) {
    current[i] = digitalRead(BUTTON_PINS[i]);

    if (lastButtonState[i] == HIGH &&
        current[i] == LOW) {

      if (i == 0) {
        motorTest = !motorTest;

        if (motorTest) {
          for (int m = 0; m < 4; m++) {
            setMotor(m, 100);
          }
          Serial.println("Motor test ON");
        } else {
          stopMotors();
          Serial.println("Motors stopped");
        }
      }

      if (i == 1) {
        playTone(1000, 200);
        Serial.println("Audio test");
      }

      if (i == 2) {
        centerServos();
        Serial.println("All servos centered");
      }
    }

    lastButtonState[i] = current[i];
  }
}

void readIMU() {
  if (millis() - lastIMURead < 100) return;
  lastIMURead = millis();

  sensors_event_t acceleration;
  sensors_event_t gyro;
  sensors_event_t temperature;

  if (mpu.getEvent(&acceleration, &gyro, &temperature)) {
    Serial.print("Accel (m/s^2): ");
    Serial.print(acceleration.acceleration.x);
    Serial.print(", ");
    Serial.print(acceleration.acceleration.y);
    Serial.print(", ");
    Serial.print(acceleration.acceleration.z);

    Serial.print(" | Gyro (rad/s): ");
    Serial.print(gyro.gyro.x);
    Serial.print(", ");
    Serial.print(gyro.gyro.y);
    Serial.print(", ");
    Serial.println(gyro.gyro.z);
  }
}

void readSerialCommands() {
  if (!Serial.available()) return;

  String command = Serial.readStringUntil('\n');
  command.trim();

  if (command.startsWith("S")) {
    int separator = command.indexOf(':');

    if (separator > 1) {
      int index = command.substring(1, separator).toInt();
      int angle = command.substring(separator + 1).toInt();

      if (index >= 0 && index < 6) {
        servos[index].write(constrain(angle, 0, 180));

        Serial.printf("Servo %d -> %d degrees\n",
                      index, constrain(angle, 0, 180));
      }
    }
  }

  if (command.startsWith("M")) {
    int separator = command.indexOf(':');

    if (separator > 1) {
      int index = command.substring(1, separator).toInt();
      int speed = command.substring(separator + 1).toInt();

      if (index >= 0 && index < 4) {
        setMotor(index, speed);
        Serial.printf("Motor %d -> %d\n", index, speed);
      }
    }
  }

  if (command == "STOP") {
    motorTest = false;
    stopMotors();
    Serial.println("All motors stopped");
  }

  if (command == "BEEP") {
    playTone(1000, 200);
  }
}

void setup() {
  Serial.begin(115200);
  delay(500);

  Wire.begin(SDA_PIN, SCL_PIN);

  for (int i = 0; i < 4; i++) {
    pinMode(MOTOR_PINS[i][0], OUTPUT);
    pinMode(MOTOR_PINS[i][1], OUTPUT);
  }

  stopMotors();

  for (int i = 0; i < 3; i++) {
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
  }

  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  for (int i = 0; i < 6; i++) {
    servos[i].setPeriodHertz(50);
    servos[i].attach(SERVO_PINS[i], 1000, 2000);
  }

  centerServos();

  if (mpu.begin(0x68, &Wire)) {
    Serial.println("MPU6050 detected");
    mpu.setAccelerometerRange(MPU6050_RANGE_4_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  } else {
    Serial.println("MPU6050 not detected. Check wiring.");
  }

  audio.setPins(I2S_BCLK, I2S_LRC, I2S_DOUT);

  audioReady = audio.begin(
    I2S_MODE_STD,
    16000,
    I2S_DATA_BIT_WIDTH_16BIT,
    I2S_SLOT_MODE_MONO
  );

  if (audioReady) {
    Serial.println("I2S audio ready");
  } else {
    Serial.println("I2S audio initialization failed");
  }

  Serial.println("Custom ESP32 board ready");
  Serial.println("Button 1: toggle motor test");
  Serial.println("Button 2: play tone");
  Serial.println("Button 3: center servos");
  Serial.println("Serial: S0:90, M0:150, STOP, BEEP");
}

void loop() {
  readButtons();
  readIMU();
  readSerialCommands();

  delay(5);
}
