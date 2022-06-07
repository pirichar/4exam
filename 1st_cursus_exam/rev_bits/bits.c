#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

unsigned char reverse_bits(unsigned char n) {
    int i = 0;
    unsigned char result = 0;
    // res              n
    // 0000 0000  ---  0010 0110
    // 0000 0000  ---  0001 0011
    // 0000 0010  ---  0000 1001
    // 0000 0110  ---  0000 0100
    // 0000 0110  ---  0000 0100

    while (i < 8) {
        result <<= 1; // result *= 2
        result |= (n & 1);
        n >>= 1; // octet /= 2
        ++i;
    }
    return (result);
}

int main(int argc, char** argv) {
    // 67 -> 01000011
    int n = reverse_bits(0b00100110);

    int i = 7;
    while (i >= 0) {
        if (n & (1 << i))
            printf("1");
        else
            printf("0");
        --i;
    }
    printf("\n");
}

/*
             1111 0000 --- 0000 1111
    v = (v & 0xF0) >> 4 | (v & 0x0F) << 4;
             1100 1100 --- 0011 0011
    v = (v & 0xCC) >> 2 | (v & 0x33) << 2;
             1010 1010 --- 0101 0101
    v = (v & 0xAA) >> 1 | (v & 0x55) << 1;
    return v;
*/

// 0100 0110 -> 0110 0100

/*
unsigned char	reverse_bits(unsigned char octet)
{
	int i;
	unsigned char result;

	i = 8;
	result = 0;
	while (i > 0)
	{
		result = result * 2 + (octet % 2);
		octet /= 2;
		i--;
	}
	return (result);
}

Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
*/
// void	print_bits(unsigned char octet)
// {
// 	int i;

// 	i = 128;
// 	while (i > 0)
// 	{
// 		if (octet >= i)
// 		{
// 			write(1, "1", 1);
// 			octet %= i;
// 			i /= 2; 
// 		}
// 		else
// 		{
// 			write(1, "0", 1);
// 			i /= 2;
// 		}
// 	}
// }
