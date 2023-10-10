void Heating() {
  readTempNoDis();
  myPID.Compute();
  int MapTempOutput = map(TempOutput, 0, 255, 0, MaxMap);
  analogWrite(HC, MapTempOutput);
//  Serial.print("TempOutput = ");
//  Serial.print(MapTempOutput);
//  Serial.println();
}
