/* littleGoal! notifier */
const int team0pin =  9;
const int team1pin = 5;
const int signpin = 1;

const int cmdDelay = 25;  /* near the minimum amount of delay between sending command to two different servos */
const int swingDelay = 250;
const int loopCount = 10;

void setup() {
  // set the digital pin as output:
  pinMode(team0pin, OUTPUT);
  pinMode(team1pin, OUTPUT);
  pinMode(signpin, OUTPUT);

  if (Serial) {   /* needed by the Leonardo types */
    Serial.begin(115200);
  }
}

void loop()
{
  String content = "";
  char character;

  /* Get the control input */
  if (Serial.available() > 0) {

    while(Serial.available()) {
      character = Serial.read();
      content.concat(character);
    }

    if (content != "") {
      Serial.println(content);  /* give some feedback */
      content.trim();
      if (content == "H") {
        /* Home team score */
        cheer(0);
      } else if (content == "A") {
        /* Away team score */
        cheer(1);
      } else if (content == "G") {
        /* "Game" type of signal */
        cheer(2);
      }
    }
  }
}

/* Do the cheering! */
void cheer(int cheertype) {
  bool team0on = false;
  bool team1on = false;
  bool signon = false;

  if (cheertype == 0) {
    team0on = true;
    signon = true;
  } else if (cheertype == 1) {
    team1on = true;
    signon = true;
  } else {
    team0on = true;
    team1on = true;
  }

  for (int i = 0; i < loopCount; i++) {
     if (team0on) {
       digitalWrite(team0pin, HIGH);
     }
     if (team1on) {
       if (team0on) { delay(cmdDelay); }
       digitalWrite(team1pin, HIGH);
     }
     if (signon) {
       digitalWrite(signpin, HIGH);
     }
     delay(swingDelay);

     if (team0on) {
       digitalWrite(team0pin, LOW);
     }
     if (team1on) {
       if (team0on) { delay(cmdDelay); }
       digitalWrite(team1pin, LOW);
     }
     if (signon) {
       digitalWrite(signpin, LOW);
     }
     delay(swingDelay);
   }
}
