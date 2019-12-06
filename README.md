This code will play Hedwig's Theme on an Arduino by attaching a piezo transducer to pins 8 and 9.  The "write EEPROM" code will load the song to the EEPROM, and "read EEPROM" will then read the song from the EEPROM and play it.  If an LED is attached to pin 10, it will light the LED insync with the music.

The music playing code is heavily based on following original code by Luke Cyca:
https://lukecyca.com
https://github.com/lukecyca/TetrisThemeArduino
Note frequencies based on http://www.phy.mtu.edu/~suits/notefreqs.html
