#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <driver/i2s.h>
#include <ESP32Servo.h>

// ==================== PIN DEFINITIONS ====================
// User Switches[cite: 1]
const int PIN_USER_SW1 = 37;
const int PIN_USER_SW2 = 38;

// Motor Driver 1 (DRV8833)[cite: 1]
const int PIN_M1_AIN1 = 18;
const int PIN_M1_AIN2 = 21;
const int PIN_M1_BOUT1 = 19; // or BIN1 depending on layout
const int PIN_M1_BOUT2 = 40;

// Motor Driver 2 (DRV8833)[cite: 1]
const int PIN_M2_AIN1 = 14;
const int PIN_M2_AIN2 = 15;
const int PIN_M2_BIN1 = 16;
const int PIN_M2_BIN2 = 17;

// MAX98357A I2S Audio Amplifier[cite: 1]
#define I2S_BCLK 5
#define I2S_LRC  6
#define I2S_DOUT 4
#define SAMPLE_RATE 16000
#define I2S_NUM I2S_NUM_0

// Servo Pins (Example using Servo 2 on GPIO 7)[cite: 1]
const int PIN_SERVO_2 = 7;
Servo servo2;

// Global Sensors & Variables
Adafruit_MPU6050 mpu;
unsigned long lastAudioTime = 0;

// ==================== SETUP I2S AUDIO ====================
void setupI2S() {
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = I2S_COMM_FORMAT_STAND_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false,
    .tx_desc_auto_clear = true
  };

  i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_BCLK,
    .ws_io_num = I2S_LRC,
    .data_out_num = I2S_DOUT,
    .data_in_num = I2S_PIN_NO_CHANGE
  };

  i2s_driver_install(I2S_NUM, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM, &pin_config);
}

// Helper to play a quick audio chirp via MAX98357A
void playBeepChirp() {
  int waveFreq = 440; // 440 Hz tone
  int numSamples = SAMPLE_RATE / waveFreq;
  int16_t sampleBuffer[numSamples];

  for (int i = 0; i < numSamples; i++) {
    float t = (float)i / SAMPLE_RATE;
    sampleBuffer[i] = (int16_t)(8000 * sin(2 * 3.14159 * waveFreq * t));
  }

  size_t bytesWritten;
  for (int j = 0; j < 10; j++) {
    i2s_write(I2S_NUM, sampleBuffer, sizeof(sampleBuffer), &bytesWritten, portMAX_DELAY);
  }
}

// ==================== SETUP ====================
void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println("Starting All-In-One Firmware for Custom ESP32 Board...");

  // 1. Initialize User Input Switches[cite: 1]
  pinMode(PIN_USER_SW1, INPUT_PULLUP);
  pinMode(PIN_USER_SW2, INPUT_PULLUP);

  // 2. Initialize Motor Driver Pins[cite: 1]
  pinMode(PIN_M1_AIN1, OUTPUT);
  pinMode(PIN_M1_AIN2, OUTPUT);
  pinMode(PIN_M1_BOUT1, OUTPUT);
  pinMode(PIN_M1_BOUT2, OUTPUT);

  pinMode(PIN_M2_AIN1, OUTPUT);
  pinMode(PIN_M2_AIN2, OUTPUT);
  pinMode(PIN_M2_BIN1, OUTPUT);
  pinMode(PIN_M2_BIN2, OUTPUT);

  // 3. Initialize Servos[cite: 1]
  servo2.attach(PIN_SERVO_2);

  // 4. Initialize I2C and MPU6050[cite: 1]
  Wire.begin();
  if (!mpu.begin()) {
    Serial.println("Warning: MPU6050 not found. Check I2C wiring.");
  } else {
    Serial.println("MPU6050 initialized successfully.");
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  }

  // 5. Initialize Audio Amplifier[cite: 1]
  setupI2S();
  Serial.println("Initialization complete.");
}

// ==================== LOOP ====================
void loop() {
  // Read User Switches (Active LOW)[cite: 1]
  bool sw1Pressed = (digitalRead(PIN_USER_SW1) == LOW);
  bool sw2Pressed = (digitalRead(PIN_USER_SW2) == LOW);

  if (sw1Pressed) {
    Serial.println("USER_SW1 pressed: Running forward test on Motor 1");
    // Drive Motor 1 forward
    digitalWrite(PIN_M1_AIN1, HIGH);
    digitalWrite(PIN_M1_AIN2, LOW);
  } else {
    // Stop Motor 1
    digitalWrite(PIN_M1_AIN1, LOW);
    digitalWrite(PIN_M1_AIN2, LOW);
  }

  if (sw2Pressed) {
    Serial.println("USER_SW2 pressed: Sweeping Servo 2");
    servo2.write(180);
  } else {
    servo2.write(0);
  }

  // Read MPU6050 IMU Data[cite: 1]
  sensors_event_t a, g, temp;
  if (mpu.getEvent(&a, &g, &temp)) {
    Serial.print("Accel [X: "); Serial.print(a.acceleration.x);
    Serial.print(", Y: "); Serial.print(a.acceleration.y);
    Serial.print(", Z: "); Serial.print(a.acceleration.z);
    Serial.println(" m/s^2]");
  }

  // Play periodic audio chirp every 5 seconds
  if (millis() - lastAudioTime > 5000) {
    lastAudioTime = millis();
    playBeepChirp();
  }

  delay(500);
}