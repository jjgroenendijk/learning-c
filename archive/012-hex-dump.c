#include <stdio.h>

void hexdumpLong(long data);

int main()
{
    long l1 = 100;
    long l2 = 255;
    long l3 = 999300;

    hexdumpLong(l1);
    hexdumpLong(l2);
    hexdumpLong(l3);

    return 0;
}

void hexdumpLong(long data)
{
    const unsigned char *pData = ( const unsigned char *)& data;

    printf ("%10li = ", data );

    for ( size_t i = 0; i < sizeof (long); i++)
    {
        printf ("%02x ", pData[i]);
    }

    printf("\n");
}
