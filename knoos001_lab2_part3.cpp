/*        Your Name & E-mail: Kianoosh Nooshi - knoos001@ucr.edu
 
 *
 
 *          Discussion Section: 22

 *         Assignment: Lab #2  Exercise #3
 
 *         goal: using potentiometer read values and have lights flicker in a pattern which correspond to that specificly assigned potentiometer value
    

 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.

 *

 *         Demo Link: <https://youtu.be/PmFoNTiYt1c>

 */int B[4] = {2, 3, 4, 5};
int PD = 6;
int PU = 7;

int num = 750;
bool wasClicked = false;
void setup() {

  // put your setup code here, to run once:

  for (int i = 0; i < 4; i++) {
    pinMode(B[i], OUTPUT);
  }
  Serial.begin(9600);
}

void flash() {
    for (int i = 0; i < 4; i++) {
      digitalWrite(B[i], HIGH);
    }
    delay(500);
    for (int i = 0; i < 4; i++) {
      digitalWrite(B[i], LOW);
    }
    delay(500);
    Serial.println(analogRead(A0));
}


void loop() {
  int potentiometer = analogRead(A0);
    potentiometer = map(potentiometer, 0, 1023, 0, 16);
  
  for (int i = 0; i < 4; i++){
    if (bitRead(potentiometer, i) == 0){
      digitalWrite(B[i], LOW);
    } else {
      digitalWrite(B[i], HIGH);
    }
  }
  
  Serial.println(potentiometer);
  
 
  
  
}
