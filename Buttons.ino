void buttons(){
  prevstate = digitalRead(prev);
  okstate = digitalRead(ok);
  nextstate = digitalRead(next);
  limsw = digitalRead(limsw);
//  Serial.print("     prev ");
//  Serial.print(prevstate);
//  Serial.print("     ok ");
//  Serial.print(okstate);
//  Serial.print("     next ");
//  Serial.print(nextstate);
//  Serial.print("     limsw ");
//  Serial.print(limsw);
//  Serial.println();
}
