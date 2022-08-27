# CRC32 Generator
Hausarbeit SoSe 2022 Aufgabe 6

Dieses Programm berechnet einen 32 Bit CRC hashwert eines Datenstreams.
Verwendet wird hierfür das Standardpolynom für CRC32: 0x04C11DB7,  und der Annahme das, dass MSB zuerst übermittelt wird.

Mathematisch ist der Hash-Wert der Rest aus einer Bitweisen nicht-übertragsbasierten arithmetischen Division des Nachrichtenwertes, geteilt durch das (Generator-)Polynom.

Der Ablauf gestaltet wich wie folgt:
1. MSB des Datenbits prüfen.
2. Wenn MSB-Bit =1, dann XOR der Daten mit CRC poly und Linksverschiebung um 1
3. Wenn MSB-Bit=0, dann nur Verschiebung der Daten um 1 nach links.
4. Nach der Verarbeitung aller Bits ist der Rest CRC.
