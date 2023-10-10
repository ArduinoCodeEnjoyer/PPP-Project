void start(){
  TargetTemp = TargetTemp + 25;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MaxMap:" + String(MaxMap));
  lcd.setCursor(0,1);
  lcd.print("Temp:" + String(TargetTemp));
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PID:" + String(Kp));
  delay(2000);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Starting...");
  delay(1500);
  lcd.clear();
  delay(500);
  buttons();
  lcd.setCursor(0,1);
  lcd.print("1.Stop");
  while(prevstate == HIGH){
    buttons();
    readTemp();
//    lcd.setCursor(0,1);
//    lcd.print("1.Stop");
    //runStep(2000);
    Heating();
    while(prevstate == HIGH and filteredTemperature >= TargetTemp - 25){
      buttons();
      Heating();
      readTempNoDis();
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(500);
    }
//    if(prevstate == LOW){
//      while(prevstate == HIGH){
//        settingsstate();
//        readTemp();
//        runStep(500);
//        Heating();
//      }
//    }
  }
  analogWrite(HC, 0);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Stopping...");
  delay(1500);
  lcd.noDisplay();
  delay(1000);
  lcd.display();
}
