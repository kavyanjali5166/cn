#include <stdio.h>
#include <string.h>

unsigned int crc(const char *data)
{
    unsigned int poly = 0x180F;
    unsigned int crc = 0x0005;

    for (i = 0; i < strlen(data); i++)
    {
        unsigned char byte = data[i];

        for (j = 0; j < 8; j++)
        {
            int bit = ((byte >> (7 - j)) & 1) ^ ((crc >> 11) & 1);
            crc <<= 1;
            if (bit)
                crc ^= poly;
            crc &= 0x0FFF;
        }
    }
    return crc;
}

int main()
{
    char data[100];

    printf("Enter a string:");
    scanf("%s", data);

    printf("CRC12 = %03X\n", crc(data));
}
