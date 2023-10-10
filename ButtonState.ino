void buttonstate() {
  buttons();
  if (prevstate == LOW) {
    start();
  }
  if (okstate == LOW) {
    lcd.clear();
    delay(250);
    while (prevstate == HIGH) {
      buttons();
      lcd.setCursor(0, 0);
      lcd.print("1.Back         ");
      lcd.setCursor(0, 1);
      lcd.print("2.Set Temp");
      if (okstate == LOW) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Temp : " + String(TargetTemp));
        delay(500);
        buttons();
        while (okstate == HIGH) {
          buttons();
          if (nextstate == LOW) {
            TargetTemp = TargetTemp + 1;
            lcd.setCursor(0, 0);
            lcd.print("Temp : " + String(TargetTemp));
            delay(250);
          }
          else if (prevstate == LOW) {
            TargetTemp = TargetTemp - 1;
            lcd.setCursor(0, 0);
            lcd.print("Temp : " + String(TargetTemp));
            delay(250);
          }
        }
        delay(250);
      }
      else if (okstate == LOW) {
        TargetTemp = 200;
        lcd.noDisplay();
        delay(250);
        lcd.display();
      }
    }
    lcd.clear();
    homescreen();
    delay(100);
  }
  else if (nextstate == LOW) {
    lcd.clear();
    delay(250);
    lcd.setCursor(0, 0);
    lcd.print("1.Back");
    lcd.setCursor(10, 0);
    lcd.print("2.More");
    lcd.setCursor(0, 1);
    lcd.print("3.PID Temp Tune");
    while (prevstate == HIGH) {
      buttons();
      if (nextstate == LOW) {
        lcd.clear();
        delay(250);
        lcd.setCursor(0, 0);
        lcd.print("PID : " + String(Kp));
        while (okstate == HIGH) {
          buttons();
          if (nextstate == LOW) {
            Kp = Kp + 0.1;
            lcd.setCursor(0, 0);
            lcd.print("PID : " + String(Kp));
            delay(250);
          }
          else if (prevstate == LOW) {
            Kp = Kp - 0.1;
            lcd.setCursor(0, 0);
            lcd.print("PID : " + String(Kp));
            delay(250);
          }
        }
        lcd.clear();
        delay(250);
      }
      else if (okstate == LOW) {
        lcd.clear();
        delay(250); 
        while (prevstate == HIGH) {
          buttons();
          lcd.setCursor(0, 0);
          lcd.print("1.Back");
          lcd.setCursor(8, 0);
          lcd.print("2.MaxMap");
          if (nextstate == LOW) {
            lcd.noDisplay();
            delay(250);
            lcd.display();
          }
          else if (okstate == LOW) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("MaxMapVal : " + String(MaxMap));
            delay(500);
            buttons();
            while (okstate == HIGH) {
              buttons();
              if (nextstate == LOW) {
                MaxMap = MaxMap + 1;
                lcd.setCursor(0, 0);
                lcd.print("MaxMapVal : " + String(MaxMap));
                delay(250);
              }
              else if (prevstate == LOW) {
                MaxMap = MaxMap - 1;
                lcd.setCursor(0, 0);
                lcd.print("MaxMapVal : " + String(MaxMap));
                delay(250);
              }
            }
            lcd.clear();
            delay(250);
          }
        }
      }
      lcd.setCursor(0, 0);
      lcd.print("1.Back    ");
      lcd.setCursor(10, 0);
      lcd.print("2.More");
      lcd.setCursor(0, 1);
      lcd.print("3.PID Temp Tune");
      delay(100);
      buttons();
    }
  }
  homescreen();
  delay(100);
  buttons();
}
