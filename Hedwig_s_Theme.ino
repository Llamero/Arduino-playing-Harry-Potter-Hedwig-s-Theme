// Based on original code by Luke Cyca
// https://lukecyca.com
// https://github.com/lukecyca/TetrisThemeArduino
// Note frequencies based on http://www.phy.mtu.edu/~suits/notefreqs.html
#define _C0    (16.35)
#define _CS0   (17.32)
#define _D0    (18.35)
#define _DS0   (19.45)
#define _E0    (20.60)
#define _F0    (21.83)
#define _FS0   (23.12)
#define _G0    (24.50)
#define _GS0   (25.96)
#define _A0    (27.50)
#define _AS0   (29.14)
#define _B0    (30.87)
#define _C1    (32.70)
#define _CS1   (34.65)
#define _D1    (36.71)
#define _DS1   (38.89)
#define _E1    (41.20)
#define _F1    (43.65)
#define _FS1   (46.25)
#define _G1    (49.00)
#define _GS1   (51.91)
#define _A1    (55.00)
#define _AS1   (58.27)
#define _B1    (61.74)
#define _C2    (65.41)
#define _CS2   (69.30)
#define _D2    (73.42)
#define _DS2   (77.78)
#define _E2    (82.41)
#define _F2    (87.31)
#define _FS2   (92.50)
#define _G2    (98.00)
#define _GS2   (103.83)
#define _A2    (110.00)
#define _AS2   (116.54)
#define _B2    (123.47)
#define _C3    (130.81)
#define _CS3   (138.59)
#define _D3    (146.83)
#define _DS3   (155.56)
#define _E3    (164.81)
#define _F3    (174.61)
#define _FS3   (185.00)
#define _G3    (196.00)
#define _GS3   (207.65)
#define _A3    (220.00)
#define _AS3   (233.08)
#define _B3    (246.94)
#define _C4    (261.63)
#define _CS4   (277.18)
#define _D4    (293.66)
#define _DS4   (311.13)
#define _E4    (329.63)
#define _F4    (349.23)
#define _FS4   (369.99)
#define _G4    (392.00)
#define _GS4   (415.30)
#define _A4    (440.00)
#define _AS4   (466.16)
#define _B4    (493.88)
#define _C5    (523.25)
#define _CS5   (554.37)
#define _D5    (587.33)
#define _DS5   (622.25)
#define _E5    (659.25)
#define _F5    (698.46)
#define _FS5   (739.99)
#define _G5    (783.99)
#define _GS5   (830.61)
#define _A5    (880.00)
#define _AS5   (932.33)
#define _B5    (987.77)
#define _C6    (1046.50)
#define _CS6   (1108.73)
#define _D6    (1174.66)
#define _DS6   (1244.51)
#define _E6    (1318.51)
#define _F6    (1396.91)
#define _FS6   (1479.98)
#define _G6    (1567.98)
#define _GS6   (1661.22)
#define _A6    (1760.00)
#define _AS6   (1864.66)
#define _B6    (1975.53)
#define _C7    (2093.00)
#define _CS7   (2217.46)
#define _D7    (2349.32)
#define _DS7   (2489.02)
#define _E7    (2637.02)
#define _F7    (2793.83)
#define _FS7   (2959.96)
#define _G7    (3135.96)
#define _GS7   (3322.44)
#define _A7    (3520.00)
#define _AS7   (3729.31)
#define _B7    (3951.07)
#define _C8    (4186.01)
#define _CS8   (4434.92)
#define _D8    (4698.63)
#define _DS8   (4978.03)
#define _E8    (5274.04)
#define _F8    (5587.65)
#define _FS8   (5919.91)
#define _G8    (6271.93)
#define _GS8   (6644.88)
#define _A8    (7040.00)
#define _AS8   (7458.62)
#define _B8    (7902.13)

// beats per minute
#define BPM   (320.0)


const uint16_t lead_notes[] = {
  // part 1
  _E5, _A5, _C6, _B5, _A5, _E6, _D6, _B5, _A5, _C6, _B5, _G5, _AS5, _E5, _A5, _C6, _B5,
  _A5, _E6, _G6, _FS6, _F6, _D6, _F6, _E6, _DS6, _DS5, _C6, _A5, _C6, _E6, _C6, _E6, _C6,
  _F6, _E6, _DS6, _DS6, _E6, _C6, _A5, _DS5, _E5, _E6, _C6, _E6, _C6, _E6, _C6, _G6, _FS6, _F6, _D6,
  _F6, _E6, _DS6, _DS5, _C6, _A5, _E6, _E6, _E6, _E6, _E6, _E6, _DS6, _E6, _F6, _E6, _DS6, _E6, _C6, _D6, _D6, _CS6, _D6, _F5, _E5, _A5, _C6, _DS6,
  _E6, _E6, _E6, _E6, _E6, _E6, _DS6, _E6, _G6, _F6, _E6, _F6, _AS0, _F6, _E6, _DS6, _E6, _A5, _C6, _B5,
  _E6, _E6, _E6, _E6, _E6, _E6, _DS6, _E6, _F6, _E6, _DS6, _E6, _C6, _D6, _D6, _CS6, _D6, _F5, _E5, _A5, _C6, _DS6,
  _E6, _E6, _E6, _E6, _E6, _E6, _DS6, _E6, _G6, _F6, _E6, _F6, _AS0, _F6, _E6, _DS6, _E6, _A5, _C6, _B5
  

};
uint8_t lead_times[] = {
  // part 1
  2, 3, 1, 2, 4, 2, 6, 6, 3, 1, 2, 4, 2, 12, 3, 1, 2,
  4, 2, 4, 2, 4, 2, 3, 1, 2, 4, 2, 10, 2, 4, 2, 4, 2,
  4, 2, 4, 2, 3, 1, 2, 4, 2, 10, 2, 4, 2, 4, 2, 4, 2, 4, 2,
  3, 1, 2, 4, 2, 12, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 2, 2, 1, 1, 4,
  1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 2, 4, 4,
  1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 2, 2, 1, 1, 4,
  1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 2, 4, 2
  

};

const uint16_t bass_notes[] = {
  // part 1
  _E4, _A4, _A4, _A4, _A4, _A4, _DS5, _E4, _A4, _C5, _B4, _E4, _A4, _C5,
  _E5, _C5, _AS4, _A4, _FS4, _A4, _C5, _E5, _E4, _A4, _C5, _E5, _E4,
  _A4, _C5, _E5, _E4, _A4, _C5, _B4, _E4, _A4, _C5, _E5, _E4, _A4, _C5, _E5, _C5, _AS4,
  _A4, _FS4, _A4, _C6, _C6, _C6, _C6, _C6, _C6, _B5, _C6, _DS6, _C6, _B5, _C6, _A5, _B5, _B5, _AS4, _B5, _D5, _C5, _E5, _C0, _B5,
  _C6, _C6, _C6, _C6, _C6, _C6, _B5, _C6, _DS6, _CS6, _C6, _CS6, _AS5, _CS6, _C6, _B5, _C6, _E5, _E5, _E5,
  _C6, _C6, _C6, _C6, _C6, _C6, _B5, _C6, _DS6, _C6, _B5, _C6, _A5, _B5, _B5, _AS4, _B5, _D5, _C5, _E5, _C0, _B5,
  _C6, _C6, _C6, _C6, _C6, _C6, _B5, _C6, _DS6, _CS6, _C6, _CS6, _AS5, _CS6, _C6, _B5, _C6, _E5, _E5, _E5,

};
uint8_t bass_times[] = {
  // part 1 131
  2, 6, 6, 6, 6, 6, 4, 2, 4, 2, 4, 2, 4, 2,
  6, 6, 6, 6, 6, 4, 2, 4, 2, 4, 2, 4, 2,
  4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 6, 6, 6,
  6, 6, 12, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 2, 2, 1, 1, 4,
  1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 2, 4, 4,
  1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 2, 2, 1, 1, 4,
  1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 2, 4, 2
  
};







void setup() {
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void loop() {


}
