//常量区域
#define P1_DIR_PIN 12
#define P2_DIR_PIN 4
#define ALL_ENA_PIN 13
#define ALL_PUL_PIN 8

const int VRX = A0;
const int VRY = A1;

//变量区域
#define STEP_DELAY 5 // 步进延时，单位：微秒

void setup() {
    pinMode(ALL_ENA_PIN, OUTPUT);
    pinMode(ALL_PUL_PIN, OUTPUT);
    pinMode(P1_DIR_PIN, OUTPUT);
    pinMode(P2_DIR_PIN, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    int xValue = analogRead(VRX); // 读取X轴值  
    int yValue = analogRead(VRY); // 读取Y轴值
    if (xValue < 500)
    {
        digitalWrite(P1_DIR_PIN, 1);
        digitalWrite(ALL_PUL_PIN, 1);
        delayMicroseconds(10);
        digitalWrite(ALL_PUL_PIN, 0);
        delay(STEP_DELAY);
    }
    else if (xValue > 600)
    {
        digitalWrite(P1_DIR_PIN, 0);
        digitalWrite(ALL_PUL_PIN, 1);
        delayMicroseconds(10);
        digitalWrite(ALL_PUL_PIN, 0);
        delay(STEP_DELAY);
    }
    if (yValue < 500)
    {
        digitalWrite(P2_DIR_PIN, 1);
        digitalWrite(ALL_PUL_PIN, 1);
        delayMicroseconds(10);
        digitalWrite(ALL_PUL_PIN, 0);
        delay(STEP_DELAY);
    }
    else if (yValue > 550)
    {
        digitalWrite(P2_DIR_PIN, 0);
        digitalWrite(ALL_PUL_PIN, 1);
        delayMicroseconds(10);
        digitalWrite(ALL_PUL_PIN, 0);
        delay(STEP_DELAY);
    }
}