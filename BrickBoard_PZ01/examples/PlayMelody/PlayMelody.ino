#include <BrickBoard.h>
#include <BrickBoard_PZ01.h>

// 학교종이 땡땡땡
uint16_t melody[] = {
  NOTE_G4,  4,  NOTE_G4,  4,  NOTE_A4,  4,  NOTE_A4,  4,
  NOTE_G4,  4,  NOTE_G4,  4,  NOTE_E4,  8,  NOTE_G4,  4,
  NOTE_G4,  4,  NOTE_E4,  4,  NOTE_E4,  4,  NOTE_D4,  12,
  0,  4,
  
  NOTE_G4,  4,  NOTE_G4,  4,  NOTE_A4,  4,  NOTE_A4,  4,
  NOTE_G4,  4,  NOTE_G4,  4,  NOTE_E4,  8,  NOTE_G4,  4,
  NOTE_E4,  4,  NOTE_D4,  4,  NOTE_E4,  4,  NOTE_C4,  12,
  0,  4,
};


BrickBoard_PZ01  myBuzzer(PA);

void setup() 
{
}

void loop() 
{
  myBuzzer.playMelody(melody, sizeof(melody));
  while(true);
}


/*
// 어머님 은혜
uint16_t melody[] = {
  NOTE_E4,  4,   NOTE_F4,  2,   NOTE_G4,  4,   NOTE_C5,  2,
  NOTE_C5,  2,   NOTE_B4,  2,   NOTE_A4,  2,   NOTE_G4,  6,
  NOTE_A4,  4,   NOTE_G4,  2,   NOTE_G4,  2,   NOTE_F4,  2,
  NOTE_E4,  2,   NOTE_D4, 10,   0,        2,
  
  NOTE_E4,  4,   NOTE_F4,  2,   NOTE_G4,  4,   NOTE_C5,  2,
  NOTE_C5,  2,   NOTE_B4,  2,   NOTE_A4,  2,   NOTE_G4,  6,
  NOTE_A4,  4,   NOTE_G4,  2,   NOTE_F4,  2,   NOTE_E4,  2,
  NOTE_D4,  2,   NOTE_C4,  10,  0,        2,

  NOTE_D4,  4,   NOTE_D4,  2,   NOTE_G4,  4,   NOTE_F4,  2,
  NOTE_E4,  2,   NOTE_D4,  2,   NOTE_C4,  2,   NOTE_D4,  6,
  NOTE_E4,  4,   NOTE_E4,  2,   NOTE_F4,  2,   NOTE_G4,  2,
  NOTE_A4,  2,   NOTE_G4,  10,  0,        2,

  NOTE_C5,  4,   NOTE_C5,  2,   NOTE_B4,  4,   NOTE_A4,  2,
  NOTE_G4,  2,   NOTE_A4,  2,   NOTE_G4,  2,   NOTE_E4,  6,
  NOTE_A4,  4,   NOTE_A4,  2,   NOTE_G4,  2,   NOTE_A4,  2,
  NOTE_B4,  2,   NOTE_C5, 10,   0,        2,
};
*/
