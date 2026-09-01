#include <Wire.h>
#include <MPU6050.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include <I2S.h>

// Define the I2S pins for MAX98357A
#define I2S_DATA_PIN   36  // I2S data
#define I2S_CLOCK_PIN   37  // I2S bit clock
#define I2S_LR_CLOCK_PIN  35  // I2S word clock

// Define the I2C pins for MPU6050
MPU6050 mpu;

// SoftwareSerial for DFPlayer Mini
SoftwareSerial mySoftwareSerial(17, 18); // RX, TX for DFPlayer
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Initialize MPU6050
  Wire.begin();
  mpu.initialize();

  // Initialize DFPlayer Mini
  mySoftwareSerial.begin(9600);
  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println("DFPlayer Mini not detected.");
    while(true); // Infinite loop if DFPlayer is not detected
  }

  // Set up the I2S interface for MAX98357A
  I2S.begin(I2S_PHILIPS_MODE, 16000, 16);  // Use 16-bit data, 16kHz sample rate for example

  Serial.println("DFPlayer Mini and MAX98357A initialized.");
}

void loop() {
  // Get accelerometer values
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // Check if motion is detected
  if (abs(ax) > 10000 || abs(ay) > 10000 || abs(az) > 10000) {
    Serial.println("Motion detected!");
    // Play a sound (1 is the track number in SD card)
    myDFPlayer.play(1);
  }

  delay(100); // Delay between checks
}
