#include <M5Stack.h>
#include <Avatar.h>

using namespace m5avatar;

Avatar avatar;

const Expression expressions[] = {
  Expression::Angry,
  Expression::Sleepy,
  Expression::Happy,
  Expression::Sad,
  Expression::Doubt,
  Expression::Neutral
};

const int expressionsSize = sizeof(expressions) / sizeof(Expression);
int idx = 0;

void setup() 
{
  M5.begin();
  M5.Lcd.setBrightness(30);
  M5.Lcd.clear();

  avatar.init();
  avatar.setExpression(expressions[idx]);
  idx = 0;
}

void loop() 
{
  int adc = analogRead(36);
  adc = map(adc, 4095, 0, 0, 255);

  M5.update();
  if (adc <=5)
  {
    avatar.setExpression(expressions[idx]);
    idx = 3;
  }
  else if (adc > 10 && adc < 40)
  {
    avatar.setExpression(expressions[idx]);
    idx = 2;
  }
  Serial.println(adc);
  delay(2);
}

