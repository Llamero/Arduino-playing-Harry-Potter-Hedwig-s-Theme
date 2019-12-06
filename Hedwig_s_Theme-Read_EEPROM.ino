// Based on orignal code by Luke Cyca
// https://lukecyca.com
// https://github.com/lukecyca/TetrisThemeArduino

#include <EEPROM.h>
// Time (in microseconds) to spend on each note while simulating polyphony
// If this is too small, low frequency notes will be inaudible.
#define POLY_DELTA (14400)
// beats per minute
#define BPM   (320.0)

int a = 0;
void setup(){
  Serial.begin(250000);
  DDRB = B00111111;
  DDRD = B00000010;
  PORTD = B00000100;
}

void loop(){
  PORTB = B00000000;
  playSong();
}

uint8_t led_on = 0;
// duration is in microseconds
void play_one_note(float frequency, unsigned long duration) {
  unsigned long period = 1000000.0/frequency;

  for (unsigned int cycles=duration/period; cycles>0; cycles--) {
    // half the time on
    PORTB = B00000010 + led_on;
    delayMicroseconds( period/2 );

    // half the time off
    PORTB = B00000001 + led_on;
    delayMicroseconds( period/2 );
  }

  // If the duration wasn't a multiple of the period, delay the remainder
  delayMicroseconds(duration % period);
}



// duration is in microseconds
void play_two_notes(float freq1, float freq2, unsigned long duration) {
    for (unsigned long t=0; t<duration; t+=2*POLY_DELTA) {
      play_one_note(freq1, POLY_DELTA);
      play_one_note(freq2, POLY_DELTA);
    }
}

void playSong(){
  int address_array[4];
  int address = 50;
  int index = 0;
  int b = 0;
  for(a=0; a<4; a++){
    if(a%2){
      while(EEPROM.read(address++) > 0);
      address_array[a] = address-1;
    }
    else{
      while(EEPROMReadInt(address) > 0) address += 2;
      address_array[a] = address;
      address += 2;
    }
    
    Serial.print(address_array[a]);
    Serial.print(", ");
  }
  Serial.println();
  b=0;
  index = 0;
  uint16_t lead_notes[(address_array[index]-50)/2];
  for(a=50; a<address_array[index]; a+=2){
    lead_notes[b++] = EEPROMReadInt(a);
    Serial.print(lead_notes[b-1]);
    Serial.print(", ");
  }
  Serial.println(sizeof(lead_notes));
  b=0;
  uint8_t lead_times[address_array[index+1]-address_array[index]-2];
  for(a=address_array[index]+2; a<address_array[index+1]; a++){
    lead_times[b++] = EEPROM.read(a);
    Serial.print(lead_times[b-1]);
    Serial.print(", ");
  } 
  Serial.println(sizeof(lead_times));
  b=0;
  index++;
  uint16_t bass_notes[(address_array[index+1]-address_array[index]-1)/2];
  for(a=address_array[index]+1; a<address_array[index+1]; a+=2){
    bass_notes[b++] = EEPROMReadInt(a);
    Serial.print(bass_notes[b-1]);
    Serial.print(", ");
  }
  Serial.println(sizeof(bass_notes));
  b=0;
  index++;
  uint8_t bass_times[address_array[index+1]-address_array[index]-2];
  for(a=address_array[index]+2; a<address_array[index+1]; a++){
    bass_times[b++] = EEPROM.read(a);
    Serial.print(bass_times[b-1]);
    Serial.print(", ");    
  }
  Serial.println(sizeof(bass_times));
  
  int lead_note_count = sizeof(lead_notes) / sizeof(uint16_t);
  int bass_note_count = sizeof(bass_notes) / sizeof(uint16_t);
  uint8_t curr_lead_note = 0;
  uint8_t curr_bass_note = 0;
  float curr_lead_note_time_remaining = lead_times[curr_lead_note];
  float curr_bass_note_time_remaining = bass_times[curr_bass_note];
  float lead_freq, bass_freq, note_value;
  unsigned long duration;

  while (curr_lead_note < lead_note_count && curr_bass_note < bass_note_count) {
    lead_freq = lead_notes[curr_lead_note];
    bass_freq = bass_notes[curr_bass_note];
    note_value = min(curr_lead_note_time_remaining, curr_bass_note_time_remaining);
    duration = note_value * 1000000 * (60.0/BPM);

    if (lead_freq > 0 && bass_freq > 0) {
      play_two_notes(lead_freq, bass_freq, duration);
    } else if (lead_freq > 0) {
      play_one_note(lead_freq, duration);
    } else if (bass_freq > 0) {
      play_one_note(bass_freq, duration);
    } else {
      delay( duration/1000 );
    }

    // Advance lead note
    curr_lead_note_time_remaining -= note_value;
    if (curr_lead_note_time_remaining < 0.001) {
      curr_lead_note++;
      curr_lead_note_time_remaining = lead_times[curr_lead_note];
    }

    // Advance bass note
    curr_bass_note_time_remaining -= note_value;
    if (curr_bass_note_time_remaining < 0.001) {
      curr_bass_note++;
      curr_bass_note_time_remaining = bass_times[curr_bass_note];
      if(curr_bass_note%2) led_on = B00000100; 
      else led_on = 0; 
    }
  }
  
}


//This function will read a 2 byte integer from the eeprom at the specified address and address + 1
uint16_t EEPROMReadInt(int p_address)
{
 byte lowByte = EEPROM.read(p_address);
 byte highByte = EEPROM.read(p_address + 1);
 return ((lowByte << 0) & 0xFF) + ((highByte << 8)& 0xFF00);

}
