@ECHO OFF


avrdude -c usbasp -p atmega328p -D -U flash:w:main.hex:i


PAUSE