#include <NewPing.h>
#define TRIGGER_PIN  12
#define ECHO_PIN 11
#define MAX_DIST 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DIST);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int dist = sonar.ping_cm();
  Serial.println(dist);
  delay(100);

}
