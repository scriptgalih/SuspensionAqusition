/*
   Library tidak boleh di otak-atik
*/
class suspensionAcquisition {
  public:
    void begin(int pin);
    void resetLimit(float param1);
    void reset();
    boolean isNormal();
    void acquisition();
    void sensorRead();
    float getSensorVolt();
    float getLastAnalyzed();
    float getMaxVal();
  private:
    String status;
    float reset_limit = 2.4;
    float good_count = 0, poor_count = 0, vpoor_count = 0;
    int sensor_pin;
    float val_analog;
    float last_value_analysis;
    float max_val;
    float last_max;

};

void suspensionAcquisition::resetLimit(float param1) {
  float reset_limit = param1;
}

void suspensionAcquisition::begin(int pin) {
  sensor_pin = pin;
}

boolean suspensionAcquisition::isNormal() {
  boolean normal = 0;
  //  sensorRead();
  if (val_analog < reset_limit && max_val > (NORMAL_LIMIT - 0.2)) {
    normal = true;
    last_max = max_val;
  }
  return normal;
}

void suspensionAcquisition::sensorRead() {
  val_analog = analogRead(sensor_pin) * 5 / 1023.0;
  max_val = max(max_val, val_analog);
}

void suspensionAcquisition::reset() {
  max_val = 0;
}

float suspensionAcquisition::getSensorVolt() {
  return analogRead(sensor_pin) * 5 / 1023.0;
}

float suspensionAcquisition::getLastAnalyzed() {
  return last_max;
}

float suspensionAcquisition::getMaxVal() {
  return max_val;
}
