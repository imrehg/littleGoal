const int team0 =  1;      // the number of the LED pin
const int team1 = 5;
const int sign = 9;

void setup() {
  // set the digital pin as output:
  pinMode(team0, OUTPUT);      
  pinMode(team1, OUTPUT);      
  pinMode(sign, OUTPUT);      

  if (Serial) {
    Serial.begin(9600);
  }
}

void loop()
{
  String content = "";
  char character;

  if (Serial.available() > 0) {

    while(Serial.available()) {
      character = Serial.read();
      content.concat(character);
    }

    if (content != "") {
      Serial.println(content);
      content.trim();
      if (content == "0") {
        cheer(0);
      } else if (content == "1") {
        cheer(1);
      } else if (content == "2") {
        cheer(2);
      }
    }
  }
}

void cheer(int team) {
   int pin = -1;

   if (team == 0) {
      pin = team0;
   } else if (team == 1) {
      pin = team1;
   } else {

       for (int i = 0; i < 10; i++) {  
         digitalWrite(team0, HIGH);
         delay(100);
         digitalWrite(team1, HIGH);
         delay(100);
         digitalWrite(team0, LOW);
         delay(100);
         digitalWrite(team1, LOW);
         delay(100);
       } 
   }

   if (pin >= 0) {
     for (int i = 0; i < 10; i++) {  
     digitalWrite(pin, HIGH);
     digitalWrite(sign, HIGH);
     delay(200);
     digitalWrite(pin, LOW);
     digitalWrite(sign, LOW);
     delay(200);
     }
   }
}
