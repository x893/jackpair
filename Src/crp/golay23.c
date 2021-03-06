/*---------------------------------------------------------------------------*\

  FILE........: golay23.c
  AUTHOR......: Robert Morelos-Zaragoza & David Rowe
  DATE CREATED: 3 March 2013

  To test:

	 src$ gcc golay23.c -o golay23 -Wall -DGOLAY23_UNITTEST -DRUN_TIME_TABLES
	 src$ ./golay23

  To generate tables:
	 src$ gcc golay23.c -o golay23 -Wall -DGOLAY23_MAKETABLES -DRUN_TIME_TABLES

\*---------------------------------------------------------------------------*/

/* File:    golay23.c
 * Title:   Encoder/decoder for a binary (23,12,7) Golay code
 * Author:  Robert Morelos-Zaragoza (robert@spectra.eng.hawaii.edu)
 * Date:    August 1994
 *
 * The binary (23,12,7) Golay code is an example of a perfect code, that is,
 * the number of syndromes equals the number of correctable error patterns.
 * The minimum distance is 7, so all error patterns of Hamming weight up to
 * 3 can be corrected. The total number of these error patterns is:
 *
 *       Number of errors         Number of patterns
 *       ----------------         ------------------
 *              0                         1
 *              1                        23
 *              2                       253
 *              3                      1771
 *                                     ----
 *    Total number of error patterns = 2048 = 2^{11} = number of syndromes
 *                                               --
 *                number of redundant bits -------^
 *
 * Because of its relatively low length (23), dimension (12) and number of
 * redundant bits (11), the binary (23,12,7) Golay code can be encoded and
 * decoded simply by using look-up tables. The program below uses a 16K
 * encoding table and an 8K decoding table.
 *
 * For more information, suggestions, or other ideas on implementing error
 * correcting codes, please contact me at (I'm temporarily in Japan, but
 * below is my U.S. address):
 *
 *                    Robert Morelos-Zaragoza
 *                    770 S. Post Oak Ln. #200
 *                      Houston, Texas 77056
 *
 *             email: robert@spectra.eng.hawaii.edu
 *
 *       Homework: Add an overall parity-check bit to get the (24,12,8)
 *                 extended Golay code.
 *
 * COPYRIGHT NOTICE: This computer program is free for non-commercial purposes.
 * You may implement this program for any non-commercial application. You may
 * also implement this program for commercial purposes, provided that you
 * obtain my written permission. Any modification of this program is covered
 * by this copyright.
 *
 * ==   Copyright (c) 1994  Robert Morelos-Zaragoza. All rights reserved.   ==
 */

#include "golay23.h"

#include <stdio.h>
#include <stdlib.h>
#define X22             0x00400000   /* vector representation of X^{22} */
#define X11             0x00000800   /* vector representation of X^{11} */
#define MASK12          0xfffff800   /* auxiliary vector for testing */
#define GENPOL          0x00000c75   /* generator polinomial, g(x) */

 /* Global variables:
  *
  * pattern = error pattern, or information, or received vector
  * encoding_table[] = encoding table
  * decoding_table[] = decoding table
  * data = information bits, i(x)
  * codeword = code bits = x^{11}i(x) + (x^{11}i(x) mod g(x))
  * numerr = number of errors = Hamming weight of error polynomial e(x)
  * position[] = error positions in the vector representation of e(x)
  * recd = representation of corrupted received polynomial r(x) = c(x) + e(x)
  * decerror = number of decoding errors
  * a[] = auxiliary array to generate correctable error patterns
  */

#include "golayenctable.h"
#include "golaydectable.h"


void nextcomb(int n, int r, int a[])
/*
 * Calculate next r-combination of an n-set.
 */
{
	int  i, j;

	a[r]++;
	if (a[r] <= n)
		return;
	j = r - 1;
	while (a[j] == n - r + j)
		j--;
	for (i = r; i >= j; i--)
		a[i] = a[j] + i - j + 1;
	return;
}

int get_syndrome(int pattern)
/*
 * Compute the syndrome corresponding to the given pattern, i.e., the
 * remainder after dividing the pattern (when considering it as the vector
 * representation of a polynomial) by the generator polynomial, GENPOL.
 * In the program this pattern has several meanings: (1) pattern = infomation
 * bits, when constructing the encoding table; (2) pattern = error pattern,
 * when constructing the decoding table; and (3) pattern = received vector, to
 * obtain its syndrome in decoding.
 */
{
	int aux = X22;

	if (pattern >= X11)
		while (pattern & MASK12) {
			while (!(aux & pattern))
				aux = aux >> 1;
			pattern ^= (aux / X11) * GENPOL;
		}
	return(pattern);
}

/*---------------------------------------------------------------------------*\

  FUNCTION....: golay23_init()
  AUTHOR......: David Rowe
  DATE CREATED: 3 March 2013

  Call this once when you start your program to init the Golay tables.

\*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*\

  FUNCTION....: golay23_encode()
  AUTHOR......: David Rowe
  DATE CREATED: 3 March 2013

  Given 12 bits of data retiurns a 23 bit codeword for transmission
  over the channel.

\*---------------------------------------------------------------------------*/

int golay23_encode(int data) {

	return encoding_table[data];
}

/*---------------------------------------------------------------------------*\

  FUNCTION....: golay23_decode()
  AUTHOR......: David Rowe
  DATE CREATED: 3 March 2013

  Given a 23 bit received codeword, returns the 12 bit corrected data.

\*---------------------------------------------------------------------------*/

int golay23_decode(int received_codeword) {

	return received_codeword ^= decoding_table[get_syndrome(received_codeword)];
}

int golay23_count_errors(int recd_codeword, int corrected_codeword)
{
	int errors = 0;
	int diff, i;

	diff = recd_codeword ^ corrected_codeword;
	for (i = 0; i < 23; i++) {
		if (diff & 0x1)
			errors++;
		diff >>= 1;
	}

	return errors;
}

