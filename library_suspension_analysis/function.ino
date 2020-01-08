/*
   Fungsi tidak boleh di otak-atik
*/
float getAverage(float arr[], int size) {
  int i = 0;
  float avg, sum = 0;

  for (i = 0; i < size; ++i) {
    sum += arr[i];
  }
  avg = (sum) / size;

  return avg;
}

void Analyze(float average_sensor) {

  if (average_sensor >= NORMAL_LIMIT && average_sensor <= POOR_LIMIT) {
    status = "Good";
    good_count++;
  } else if (average_sensor > POOR_LIMIT && average_sensor <= VERY_POOR_LIMIT) {
    status = "poor";
    poor_count++;
  } else if (average_sensor > VERY_POOR_LIMIT) {
    status = "vpoor";
    vpoor_count++;
  }
  Serial.print("\t"); Serial.print(average_sensor); Serial.print("\t");
  Serial.println(status);
}

void viewResult() {
  Serial.print(good_count); Serial.print("\t");
  Serial.print(poor_count); Serial.print("\t");
  Serial.print(vpoor_count); Serial.print("\t");
  Serial.println();
  while (1);
}

void viewResultLCD() {
  sprintf(text_lcd, "RESULT");
  lcd.setCursor(0, 0);
  lcd.print(text_lcd);

  sprintf(text_lcd, "N:%2i P:%2i VP:%2i", (int)good_count, (int)poor_count, (int)vpoor_count);
  lcd.setCursor(0, 1);
  lcd.print(text_lcd);
}

void rerataLCD(){
  lcd.setCursor(9,0);
  lcd.print("    ");
  lcd.setCursor(9,0);
  lcd.print(average);
  
}
