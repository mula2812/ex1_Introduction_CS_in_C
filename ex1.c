/******************
Name: ilan mulakandov
ID: 325842847
Assignment: 1
*******************/
#include <stdio.h>

// REMIDER : YOU CANT USE ANY CONTROL FLOW OPERATIONS OR FUNCTIONS, ONLY BITWISE. not even "==, &&, ||, !="

int main()
{
    // Ascii
    printf("Ascii:\n");
    /*. Scan one character from the user.
        Then, refer to it as an integer.
        a. Print its value.
        b:
        Print “0”, if its integer representation is even.
        print “1” if its integer representation is odd. */

    // Answer to Ascii
    char userChar;
    const int determinerValue = 1;
    printf("Please enter a character\n");
    
    // space before %c to avoid reading newline character
    scanf(" %c", &userChar);
    
    printf("Its numerical value is: %d\n", userChar);
    
    // using bitwise AND with determinerValue to determine if the LSB is 0 or 1 (even or odd)
    printf("0 for even, 1 for odd: %d\n", userChar & determinerValue);
    
    

    // 2's complement and other representations
    printf("\n2’s complement to other representations:\n");
    /*. Scan a negative integer. [2’s complement].
        Print its value in 1’s complement.
        Print its value as unsigned. */

    // Answer to 2's complement and other representations
    int negativeUserInt;
    printf("Please enter a negative integer\n");
    
    // space before %d to avoid reading newline character
    scanf(" %d", &negativeUserInt); 
    
    /* using bitwise NOT to get 1's complement and printing it with a negative sign
    because negativeUserInt get positive value after NOT operation
    (the MSB of negtive number is 1 and after doing NOT is turning to 0)*/
    printf("1's complement: -%d\n", ~negativeUserInt);

    // printing negativeUserInt as unsigned using %u format specifier
    printf("unsigned: %u\n", negativeUserInt);



    // Shifting right and left
    printf("\nShifting right and left:\n");
    /*. Scan 3 integers.
    The first one - the value you will play with.
    The second and the third - how much to shift right and left, respectively.
    Print the value after shifting right and then shifting left. */
    
    // Answer to Shifting right and left
    int valueToShift, rightShiftingAmout, leftShiftingAmout;
    printf("Please enter 3 integers\n");

    // space before %d to avoid reading newline character
    scanf(" %d %d %d", &valueToShift, &rightShiftingAmout, &leftShiftingAmout);

    /*Shifting the selected number (valueToShift)
    to the right by the amount of times corresponding to the user input (rightShiftingAmout)
    then shifting to the left by the amount of leftShiftingAmout*/
    printf("After shifting right and left: %d\n", ((valueToShift >> rightShiftingAmout) << leftShiftingAmout));


 
    // Even - Odd
    printf("\nEven - Odd:\n");
    /* Scan 3 Integers.
    If at least two of them are even - print 0.
    If at least two of them are odd - print 1. */
    
    // Answer to Even - Odd
    int firstInt, secondInt, thirdInt;
    int firstIntLSB, secondIntLSB, thirdIntLSB;
    int firstAndSecondResult, firstAndThirdResult, secondAndThirdResult;
    printf("Please enter 3 integers\n");

    // space before %d to avoid reading newline character
    scanf(" %d %d %d", &firstInt, &secondInt, &thirdInt);

    /* using determinerValue = 1 from Ascii section
    to determine if the LSB of each integer is 0 or 1 (even or odd)*/
    firstIntLSB = firstInt & determinerValue;
    secondIntLSB = secondInt & determinerValue;
    thirdIntLSB = thirdInt & determinerValue;

    /* using bitwise AND to check if a pair of LSBs is equal to 1 (both numbers are odd) 
    otherwise it is a sign that at least one of them is even*/
    firstAndSecondResult = firstIntLSB & secondIntLSB;
    firstAndThirdResult = firstIntLSB & thirdIntLSB;
    secondAndThirdResult = secondIntLSB & thirdIntLSB;

    /* combining the results of the three pairs using bitwise OR
    if at least two of them are odd, finalResult will be 1, otherwise 0*/
    int finalResult = firstAndSecondResult | firstAndThirdResult | secondAndThirdResult;
    printf("0 - most of them are even, 1 - most of them are odd: %d\n", finalResult);
   
    
    
    // Different Bases
    printf("\nDifferent Bases:\n");
    /*  Scan two numbers:
        One in octal base, one in Hexadecimal base.
        Print their LSB’s.
        Print their MSB’s. */
    
    // Answer to Different Bases
    printf("Please enter two numbers in octal and hexadecimal bases\n");
    int octalNumber, hexadecimalNumber;
    int octalMSB = 0, hexMSB = 0;
    int octalLSB = 0, hexLSB = 0;
    const int timeToShiftNumberUntilGetMsb = 31; // assuming 32-bit integers
    // space before %o and %x to avoid reading newline character
    scanf(" %o %x", &octalNumber, &hexadecimalNumber);

    /* using AND operator with determinerValue from privious sections
    to get the LSB of both numbers,
    the AND with the 1 get 1 if the LSB is 1 otherwise 0
    (that why it really return the LSB itself) */
    octalLSB = octalNumber & determinerValue;
    hexLSB = hexadecimalNumber & determinerValue;

    /* shifting the numbers 31 times to the right to get the MSB to the LSB position
    then using AND operator with determinerValue to get the MSB 
    (that now placed at the LSB of the new number) of both numbers */
    octalMSB = (octalNumber >> timeToShiftNumberUntilGetMsb) & determinerValue;
    hexMSB = (hexadecimalNumber >> timeToShiftNumberUntilGetMsb) & determinerValue;

    printf("LSBs: %d %d\n", octalLSB, hexLSB);
    printf("MSBs: %d %d\n", octalMSB, hexMSB);

    
    printf("Bye!");

    return 0;
}