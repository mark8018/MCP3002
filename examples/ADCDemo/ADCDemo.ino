#include <MCP3002.h>
#include <SPI.h>

MCP3002 adc(SS);

void setup() {
  adc.begin();
  Serial.begin(115200);
}

void loop() {
  char temp[10];
  static int ctr = 0;
  if (ctr == 0) {
    Serial.println();
    Serial.println("SingleEnded| Differential");
    Serial.println("    0    1 |             ");
    Serial.println("-------------------------");
  }
  ctr++;
  if (ctr == 10) {
    ctr = 0;
  }
  for (int i = 0; i < 2; i++) {
    sprintf(temp, "%5d", adc.analogRead(i));
    Serial.print(temp);
  }
  Serial.print(" |");
  sprintf(temp, "%5d", adc.analogReadDif());
  Serial.print(temp);
  Serial.println();
  delay(500);
}
