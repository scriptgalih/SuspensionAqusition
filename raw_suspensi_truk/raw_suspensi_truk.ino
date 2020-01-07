#define sens1 A10

float max_sens;
String status;
float batas_bawah_1 = 2.4;
float batas_normal = 2.8;
float batas_poor = 3.1;
float batas_vpoor = 3.45;
float good_count, poor_count, vpoor_count;
void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);


}

void loop() {
  // put your main code here, to run repeatedly:

  float val_analog = analogRead(sens1) * 5 / 1023.0;
  max_sens = max(max_sens, val_analog);
  Serial.print(val_analog); Serial.print("\t");
  Serial.print(max_sens); Serial.print("\t");
  Serial.print(good_count); Serial.print("\t");
  Serial.print(poor_count); Serial.print("\t");
  Serial.print(vpoor_count); Serial.print("\t");
  Serial.print(status); Serial.print("\n");

  
  if (val_analog <= batas_bawah_1) {
    if (max_sens >= batas_normal && max_sens <= batas_poor) {
      status = "Good";
      good_count++;
    } else if (max_sens >= batas_poor && max_sens <= batas_vpoor) {
      status = "poor";
      poor_count++;
    } else if (max_sens >= batas_vpoor) {
      status = "vpoor";
      vpoor_count++;
    }
    max_sens = 0;
  }
}
