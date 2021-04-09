void setup()
{
  float number = 9.434346502;
  Serial.begin(9600);
  Serial.print(number, 2);
}
void loop()
{
  // put your main code here, to run repeatedly:
  int num = random(1, 23);
  Serial.println(num);
  delay(3000);

//  if (Serial.available() > 0)
//  {
//    int data = Serial.read();
//    Serial.println(data);
//  }
}
