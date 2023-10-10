void readTempNoDis() {
  int rawReading = analogRead(thermistorPin);
  float voltage = rawReading * (5.0 / 1023.0);  // แปลงค่าที่อ่านได้เป็นแรงดันไฟ(V)
  float resistance = (5.0 * referenceResistance) / voltage - referenceResistance;

  // คำนวณอุณหภูมิด้วยสมการ Steinhart-Hart
  float steinhart = resistance / referenceResistance;  // R/R₀
  steinhart = log(steinhart);  // ln(R/R₀)
  steinhart /= betaValue;       // (1/B) * ln(R/R₀)
  steinhart += 1.0 / (referenceTemperature + 273.15);  // + (1/T₀)
  float temperature = 1.0 / steinhart - 273.15;  //แปลงเป็นหน่วย Celsius

  // ใช้สมการ low-pass filter
  filteredTemperature = (alpha * temperature) + ((1 - alpha) * filteredTemperature);
}
