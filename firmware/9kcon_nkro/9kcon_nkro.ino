#include "HID-Project.h"
#include <EEPROM.h>
int currMode = EEPROM.read(0);

/* Number of microseconds between HID reports
   2000 = 500hz                               */
#define REPORT_DELAY 500

/* delay 임의의 딜레이 삽입 */
#define DELAY 4

/*  boolean
    boolean 함수의 세트를 설정하는곳 */
 boolean A_set = false;              
 boolean B_set = false;             
 boolean C_set = false;
 boolean D_set = false;
 boolean E_set = false;
 boolean F_set = false;              
 boolean G_set = false;             
 boolean H_set = false;
 boolean I_set = false;

/* Button Keybinds
   키보드 설정       */
#define BIND_1     'e'
#define BIND_2     'w'
#define BIND_3     'q'
#define BIND_4     'd'
#define BIND_5     's'
#define BIND_6     'a'
#define BIND_7     'c'
#define BIND_8     'x'
#define BIND_9     'z'


/*   Button Pinout
     버튼 핀아웃     */
#define BT_1        A3
#define BT_2        A2
#define BT_3        A1
#define BT_4        A0
#define BT_5        15
#define BT_6        14
#define BT_7        16
#define BT_8        10
#define BT_9        1


// LED Pinout
#define BT_1_LED  9
#define BT_2_LED  8
#define BT_3_LED  7
#define BT_4_LED  6
#define BT_5_LED  5
#define BT_6_LED  4
#define BT_7_LED  3
#define BT_8_LED  2
#define BT_9_LED  0

char bindKeys[] = { BIND_1, BIND_2, BIND_3, BIND_4, BIND_5, BIND_6, BIND_7, BIND_8, BIND_9};
char bolean[] = { A_set, B_set, C_set, D_set, E_set, F_set, G_set, H_set, I_set };
char buttonPins[] = { BT_1, BT_2, BT_3, BT_4, BT_5, BT_6, BT_7, BT_8, BT_9 };
char ledPins[] = { BT_1_LED, BT_2_LED, BT_3_LED, BT_4_LED, BT_5_LED, BT_6_LED, BT_7_LED, BT_8_LED, BT_9_LED };
char buttonCount = sizeof(buttonPins) / sizeof(buttonPins[0]);


void setup() {
  /* setup I/O for pins
     핀버튼 인풋 풀업 설정  */
  for (int i = 0; i < buttonCount; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
  }
  /*  NKRO, Serial Declaration
      NKRO키보드, 시리얼 선언     */
  NKROKeyboard.begin();
  Serial.begin(9600);

    /* Startup mode
     스타트업 모드 선언 */
  int Button1State = digitalRead(A1); //Read leftbutton 왼쪽버튼 읽기
  int Button2State = digitalRead(A2); //Read rightbutton 오른쪽버튼 읽기
  // Button 1 is held down: Controller Mode
  // 버튼1이 눌린 상태에서 usb 연결시 : 컨트롤러모드
  if (Button1State == LOW && Button2State == HIGH) {
    if (currMode != 1) {
      EEPROM.update(0, 1); 
      delay(200);
    }
  } else if (Button2State == LOW && Button1State == HIGH) {
    /* Button 2 is held down: Keyboard Mode
       버튼2가 눌린 상태에서 usb 연결시 : 무드등 모드 */
    if (currMode != 2) {
      EEPROM.update(0, 2);
      delay(200);
    }
  }
}

/*Read EEPROM, if 1 then Controller_mode, if 2 Mood_mode
  EEPROM 읽어 1이면 컨트롤러, 2면 무드등 모드로 전환         */
void loop() {
  if (EEPROM.read(0) == 1) {
    ninekeyA();
  } else if (EEPROM.read(0) == 2) {
    ninekeyB();
  }
}

/* below here are code of controller_mode
  컨트롤러 모드의 코드입니다                 */
void ninekeyA() {
  /* 버튼의 상태를 읽습니다, 만약 신호가 LOW라면 키보드 입력을 합니다
     Read the buttons, if it's low, output a keyboard press  */
  for (int i = 0; i < buttonCount; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      if(bolean[i] == false) {
      NKROKeyboard.add(bindKeys[i]);
      NKROKeyboard.send();
      digitalWrite(ledPins[i], HIGH);
     bolean[i] = true;
      } 
    }  else {
      if(bolean[i] == true) {
      NKROKeyboard.release(bindKeys[i]);
      digitalWrite(ledPins[i], LOW);
      bolean[i] = false;
      }
    }
   }

 /*Delay  딜레이*/
 delay(DELAY);
 }

 void ninekeyB() {
  /* 버튼의 상태를 읽습니다, 만약 신호가 LOW라면 키보드 입력을 합니다
     Read the buttons, if it's low, output a keyboard press  */
  for (int i = 0; i < buttonCount; i++) {
      digitalWrite(ledPins[i], HIGH);
   }

 /*Delay  딜레이*/
 delay(DELAY);
 }
