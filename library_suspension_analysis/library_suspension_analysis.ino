#include "header.h"
#include "suspensionAcquisition.h"




suspensionAcquisition suspensi_1, suspensi_2, suspensi_3, suspensi_4;


void setup() {
  pinMode(7, 0);
  digitalWrite(7, 1);
  // put your setup code here, to run once:
  Serial.begin(115200);
  suspensi_1.begin(PIN_SUSPENSI_1);
  suspensi_2.begin(PIN_SUSPENSI_2);
  suspensi_3.begin(PIN_SUSPENSI_3);
  suspensi_4.begin(PIN_SUSPENSI_4);

  suspensi_1.resetLimit(2.4);
  suspensi_2.resetLimit(2.4);
  suspensi_3.resetLimit(2.4);
  suspensi_4.resetLimit(2.4);
}

void loop() {
  suspensi_1.sensorRead();
  suspensi_2.sensorRead();
  suspensi_3.sensorRead();
  suspensi_4.sensorRead();


  Serial.print(suspensi_1.getSensorVolt()); Serial.print("\t");
  Serial.print(suspensi_2.getSensorVolt()); Serial.print("\t");
  Serial.print(suspensi_3.getSensorVolt()); Serial.print("\t");
  Serial.print(suspensi_4.getSensorVolt()); Serial.print("\t");

  Serial.print("jumlah Normal, poor, v_poor"); Serial.print("\t");
  Serial.print(good_count); Serial.print("\t");
  Serial.print(poor_count); Serial.print("\t");
  Serial.print(vpoor_count); Serial.print("\t");
  //  Serial.print(isAllNormal); Serial.print("\t");
  if (suspensi_1.isNormal() && suspensi_2.isNormal() && suspensi_3.isNormal() && suspensi_4.isNormal() && !isAllNormal) {
    float balance[TOTAL_SUSPENSION] = {suspensi_1.getLastAnalyzed(),
                                       suspensi_2.getLastAnalyzed(),
                                       suspensi_3.getLastAnalyzed(),
                                       suspensi_4.getLastAnalyzed()
                                      };

    Analyze(getAverage(balance, TOTAL_SUSPENSION));


    Serial.print("analyzed");
    delay(1000);
    isAllNormal = true;
    suspensi_1.reset();
    suspensi_2.reset();
    suspensi_3.reset();
    suspensi_4.reset();
    //    while (1);
  } else if (!suspensi_1.isNormal()) {
    isAllNormal = false;
  }
  Serial.println();

  //  if (digitalRead(53) == LOW) {
  //    viewResult();
  //  }
}
