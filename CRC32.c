#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#define CRC32POLY 0x04C11DB7			/* CRC-32 Polynom */

int datastream[]= {1,0,0,0,1,1,0,0};		/* Exemplarischer Datenstream */
int databits=8;							/* Länge der Daten */
uint32_t crc32 = 0;						/* Schieberegister */


int main(void)
{   int i;
    for (i=0; i<databits; ++i)
        if (((crc32 & 0x80000000) ? 1 : 0) != datastream[i])	/* überprüfen des ersten Bits auf 1 */
            crc32=(crc32<<1) ^ CRC32POLY;						/* Verschieben des Registers nach Links und Bitweise XOR mit Generatorpolynom */
        else
            crc32<<=1;											/* Falls erstes Bit 0, verschiebe Register um 1 Bit nach Links */
    printf("0x%08X\n",crc32);
    return 0;
}