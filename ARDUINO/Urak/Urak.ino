//常量区域
#define P1_ENA_PIN 13
#define P1_DIR_PIN 12
#define P1_PUL_PIN 8

#define P2_ENA_PIN 7
#define P2_DIR_PIN 4
#define P2_PUL_PIN 2


const int VRX = A0;
const int VRY = A1;

//变量区域
#define STEP_DELAY 5 // 步进延时，单位：微秒

void setup() {
    pinMode(P1_ENA_PIN, OUTPUT);
    pinMode(P1_DIR_PIN, OUTPUT);
    pinMode(P1_PUL_PIN, OUTPUT);

    pinMode(P2_ENA_PIN, OUTPUT);
    pinMode(P2_DIR_PIN, OUTPUT);
    pinMode(P2_PUL_PIN, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    int xValue = analogRead(VRX); // 读取X轴值  
    int yValue = analogRead(VRY); // 读取Y轴值 
    if (xValue < 500)
    {
        digitalWrite(P1_DIR_PIN, HIGH);
        digitalWrite(P1_PUL_PIN, HIGH);
        delayMicroseconds(10);
        digitalWrite(P1_PUL_PIN, LOW);
        delay(STEP_DELAY);
    }
    else if (xValue > 600)
    {
        digitalWrite(P1_DIR_PIN, LOW);
        digitalWrite(P1_PUL_PIN, HIGH);
        delayMicroseconds(10);
        digitalWrite(P1_PUL_PIN, LOW);
        delay(STEP_DELAY);
    }
    if (yValue < 500)
    {
        digitalWrite(P2_DIR_PIN, HIGH);
        digitalWrite(P2_PUL_PIN, HIGH);
        delayMicroseconds(10);
        digitalWrite(P2_PUL_PIN, LOW);
        delay(STEP_DELAY);
    }
    else if (yValue > 550)
    {
        digitalWrite(P2_DIR_PIN, LOW);
        digitalWrite(P2_PUL_PIN, HIGH);
        delayMicroseconds(10);
        digitalWrite(P2_PUL_PIN, LOW);
        delay(STEP_DELAY);
    }
}