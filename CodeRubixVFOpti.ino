//access the built-in servo library
#include <Servo.h>
#include "khaibao.h"
Servo Serv1a;  //create a servo turn object named Serv1a
Servo Serv1b;  //create a servo in out named Serv1b
Servo Serv2a;  //create a servo object named Serv2a
Servo Serv2b;  //create a servo object named Serv2b
Servo Serv3a;  //create a servo object named Serv3a
Servo Serv3b;  //create a servo object named Serv3b
Servo Serv4a;  //create a servo object named Serv4a
Servo Serv4b;  //create a servo object named Serv4b


const int shrt = 400;  
const int vshrt = 100; 

void ini() {
  // dung
  Serv1a.write(dung1a)
  Serv2a.write(dung2a);
  Serv3a.write(dung3a);
  Serv4a.write(dung4a);
  // xa
  Serv1b.write(xa1b);
  Serv2b.write(xa2b);
  Serv3b.write(xa3b);
  Serv4b.write(xa4b);
  delay(100);
  // attach the servo motors to their pins
  Serv1b.attach(pinServ1b);
  Serv2b.attach(pinServ2b);
  Serv3b.attach(pinServ3b);
  Serv4b.attach(pinServ4b);
  delay(200);
  Serv1a.attach(pinServ1a);
  delay(200);
  Serv2a.attach(pinServ2a);
  delay(200);
  Serv3a.attach(pinServ3a);
  delay(200);
  Serv4a.attach(pinServ4a);
  delay(200);
}
void Move() {
  // xa
  Serv1b.write(xa1b);
  Serv2b.write(xa2b);
  Serv3b.write(xa3b);
  Serv4b.write(xa4b);
  delay(shrt);

  // dung
  Serv1a.write(dung1a);
  delay(shrt);
  Serv2a.write(dung2a);
  delay(shrt);
  Serv3a.write(dung3a);
  delay(shrt);
  Serv4a.write(dung4a);
  delay(shrt);

  // gan
  Serv1b.write(gan1b);
  Serv2b.write(gan2b);
  Serv3b.write(gan3b);
  Serv4b.write(gan4b);
  delay(100);
}
void End() {
  // xa
  Serv1b.write(xa1b);
  Serv2b.write(xa2b);
  Serv3b.write(xa3b);
  Serv4b.write(xa4b);
  delay(1000);
}
void FF() {
  delay(shrt);
  Serv1b.write(xa1b);
  delay(shrt);
  Serv1a.write(ngang1a);
  delay(shrt);
  Serv1b.write(gan1b);
  delay(shrt);
  Serv1a.write(dung1a);
}
void FF_() {
  delay(shrt);
  Serv1a.write(ngang1a);
  delay(shrt);
  Serv1b.write(xa1b);
  delay(shrt);
  Serv1a.write(dung1a);
  delay(shrt);
  Serv1b.write(gan1b);
  delay(shrt);
}
void BB() {
  delay(shrt);
  Serv2b.write(xa2b);
  delay(shrt);
  Serv2a.write(ngang2a);
  delay(shrt);
  Serv2b.write(gan2b);
  delay(shrt);
  Serv2a.write(dung2a);
}
void BB_() {
  delay(vshrt);
  Serv2a.write(ngang2a);
  delay(shrt);
  Serv2b.write(xa2b);
  delay(shrt);
  Serv2a.write(dung2a);
  delay(shrt);
  Serv2b.write(gan2b);
}
void RR() {
  delay(vshrt);
  Serv4a.write(ngang4a);
  delay(shrt);
  Serv4b.write(xa4b);
  delay(shrt);
  Serv4a.write(dung4a);
  delay(shrt);
  Serv4b.write(gan4b);
}
void RR_() {
  delay(shrt);
  Serv4b.write(xa4b);
  delay(shrt);
  Serv4a.write(ngang4a);
  delay(shrt);
  Serv4b.write(gan4b);
  delay(shrt);
  Serv4a.write(dung4a);
}
void LL() {
  delay(shrt);
  Serv3b.write(xa3b);
  delay(shrt);
  Serv3a.write(ngang3a);
  delay(shrt);
  Serv3b.write(gan3b);
  delay(shrt);
  Serv3a.write(dung3a);
}
void LL_() {
  delay(vshrt);
  Serv3a.write(ngang3a - 5 );
  delay(shrt);
  Serv3b.write(xa3b);
  delay(shrt);
  Serv3a.write(dung3a);
  delay(shrt);
  Serv3b.write(gan3b);
}
void UUBE4() {
  delay(shrt);
  Serv3b.write(xa3b);
  Serv4b.write(xa4b);
  delay(shrt);
  Serv4a.write(ngang4a);
  Serv3a.write(ngang3a);
  delay(shrt);
  Serv3b.write(gan3b);
  Serv4b.write(gan4b);
  delay(shrt);
  Serv1b.write(xa1b);
  Serv2b.write(xa2b);
  delay(shrt);
  Serv4a.write(dung4a);
  Serv3a.write(dung3a); 
  delay(shrt);
  Serv1b.write(gan1b);
  Serv2b.write(gan2b);
  delay(shrt);
}










void UUAFT() {
  delay(shrt);
  Serv1b.write(xa1b);
  Serv2b.write(xa2b);
  delay(shrt);
  Serv4a.write(ngang4a);
  Serv3a.write(ngang3a);
  delay(shrt);
  Serv1b.write(gan1b);
  Serv2b.write(gan2b);
  delay(shrt);
  Serv3b.write(xa3b);
  Serv4b.write(xa4b);
  delay(shrt);
  Serv4a.write(dung4a);
  Serv3a.write(dung3a);
  delay(shrt);
  Serv3b.write(gan3b);
  Serv4b.write(gan4b);
}
void UU() {
  UUBE4();
  FF();
  UUAFT();
}
void UU_() {
  UUBE4();
  FF_();
  UUAFT();
}
void DDBE4() {
  delay(shrt);
  Serv1b.write(xa1b);
  Serv2b.write(xa2b);
  delay(shrt);
  Serv4a.write(ngang4a);
  Serv3a.write(ngang3a);
  delay(shrt);
  Serv1b.write(gan1b);
  Serv2b.write(gan2b);
  delay(shrt);
  Serv3b.write(xa3b);
  Serv4b.write(xa4b);
  delay(shrt);
  Serv4a.write(dung4a);
  Serv3a.write(dung3a);
  delay(shrt);
  Serv3b.write(gan3b);
  Serv4b.write(gan4b);
  delay(shrt);
}
void DDAFT() {
  delay(shrt);
  Serv3b.write(xa3b);
  Serv4b.write(xa4b);
  delay(shrt);
  Serv4a.write(ngang4a);
  Serv3a.write(ngang3a);
  delay(shrt);
  Serv3b.write(gan3b);
  Serv4b.write(gan4b);
  delay(shrt);
  Serv1b.write(xa1b);
  Serv2b.write(xa2b);
  delay(shrt);
  Serv4a.write(dung4a);
  Serv3a.write(dung3a); 
  delay(shrt);
  Serv1b.write(gan1b);
  Serv2b.write(gan2b);
}
void DD() {
  DDBE4();
  FF();
  DDAFT();
}
void DD_() {
  DDBE4();
  FF_();
  DDAFT();
}

void setup() {
  Serial.begin(9600);
  ini();
  Serial.println("Done!");
  Serial.println("Input the rubik cube");
  Serial.println("Type MOVE to start");
}


void loop() {
  if (solved == false) {
    // wait for solve steps
    if (Serial.available() > 0) {
      data = Serial.readStringUntil('\n');
      Serial.print("data: ");
      Serial.println(data);

      if (data == "END") {
        solved = true;
        End();
        Serial.print(" MOVE?");
      } else {
        L = data.length();
        index = 1;
        String S[int(L / 2) + 1];

        /*String analyze*/
        trash = 0;
        /*Data tracking*/
        count = 0;
        while (index > 0) {
          index = data.indexOf(' ');
          //                          Serial.println(index);
          if (index > 0) {
            S[trash] = data.substring(0, index);
          } else {
            S[trash] = data.substring(0, L);
          }
          //                          Serial.println(S[trash]);
          trash = trash + 1;
          count = index + 1;
          data = data.substring(count, L);
        }
        /* OUTPUT: s (sequence of solve steps)*/
        trash = 0;
        while (trash < int(L / 2) + 1) {

          //////////////////////////////// Start coding here ///////////////////////////////////////////
          if (S[trash] == "F") {
            FF();
          }
          if (S[trash] == "B") {
            BB_();
          }
          if (S[trash] == "R") {
            RR();
          }
          if (S[trash] == "L") {
            LL();
          }
          if (S[trash] == "D") {
            DD();
          }
          if (S[trash] == "U") {
            UU();
          }

          //////////////////////////////// CounterClockWise ///////////////////////////////////////////

          if (S[trash] == "F'") {
            FF_();
          }
          if (S[trash] == "B'") {
            BB();
          }
          if (S[trash] == "R'") {
            RR_();
          }
          if (S[trash] == "L'") {
            LL_();
          }
          if (S[trash] == "D'") {
            DD_();
          }
          if (S[trash] == "U'") {
            UU_();
          }
          /////////////////////////////// Double ///////////////////////////////////////////
          if (S[trash] == "F2") {
              FF();
              FF();
            }
          if (S[trash] == "B2") {
            BB();
            BB();
          }
          if (S[trash] == "R2") {
            RR();
            RR();
          }
          if (S[trash] == "L2") {
            LL();
            LL();
          }
          if (S[trash] == "D2") {
            DDBE4();
            FF();
            FF();
            DDAFT();
          }
          if (S[trash] == "U2") {
            UUBE4();
            FF();
            FF();
            UUAFT();
          }

          //////////////////////////////// Stop coding here ///////////////////////////////////////////
          Serial.print(S[trash]);
          Serial.print(" ");
          trash = trash + 1;
        }
        Serial.println(" ");
        Serial.println("MOVED!");
        data = "";
      }
    }
  } else {
    if (Serial.available() > 0) {
      data = Serial.readStringUntil('\n');
      if (data == "MOVE") {
        Move();
        solved = false;
        Serial.println("Input solving steps");
      }
      data = "";
    }
    data = "";
  }
}
