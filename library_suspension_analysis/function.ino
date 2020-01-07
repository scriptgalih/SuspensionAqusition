/*
 * Fungsi tidak boleh di otak-atik
 */
 float getAverage(float arr[], int size) {
  int i, sum = 0;
  double avg;

  for (i = 0; i < size; ++i) {
    sum += arr[i];
  }
  avg = double(sum) / size;

  return avg;
}

void Analyze(float average_sensor) {

  if (average_sensor >= NORMAL_LIMIT && average_sensor <= POOR_LIMIT) {
    status = "Good";
    good_count++;
  } else if (average_sensor >= POOR_LIMIT && average_sensor <= VERY_POOR_LIMIT) {
    status = "poor";
    poor_count++;
  } else if (average_sensor >= VERY_POOR_LIMIT) {
    status = "vpoor";
    vpoor_count++;
  }
  
}

void viewResult(){
  Serial.print(good_count); Serial.print("\t");
  Serial.print(poor_count); Serial.print("\t");
  Serial.print(vpoor_count); Serial.print("\t");
  Serial.println();
  while(1);
}
