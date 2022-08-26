#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "AYMARD JEFF NGUIMFACK NGOUATOU"
#define YEAR "2022"

int dec_num, radix;     // define variables for decimal and radix number

void Dec2RadixI(int decValue, int radValue);


int main () {

// ++++++ Information about program ++++++ //
printf("********************************************\n");
printf(" "TITLE "\n");
printf(" Written by: " AUTHOR "\n");
printf(" Date: " YEAR "\n");
printf("********************************************\n");
// +++++++++++++++++++++++++++++++++++++++ //

// -- Input decimal number -- //
printf("Enter a decimal number (-1 to EXIT): ");     
scanf("%d", &dec_num);              

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
// +++++++++++++ Section runs and prompts user as long as input decimal number is positive +++++++++++++ //
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

while (dec_num >=0){
    printf("The number you input is %d\n", dec_num);
    printf("Enter a radix for the converter between 2 and 16: ");
    scanf("%d", &radix);                         // input radix number
    while ((radix <2) || (radix > 16)) {         // validate radix number
        printf("Enter a radix for the converter between 2 and 16: ");
        scanf("%d", &radix);}
    
    printf("The radix you have entered is %d\n", radix);

    // -- Only call conversion function if input number is greater or equal to 1 -- //
    if (dec_num>=1) {Dec2RadixI(dec_num, radix);}          
    else printf("\nThe equivalent radix-%d number is: 0\n\n", radix); // otherwise equivalent radix num = 0
    
    // -- User is prompted to enter new decimal number, if previous input is not negative -- //
    printf("*********************************\n");
    printf("Enter a decimal number (-1 to EXIT): ");  
    scanf("%d", &dec_num);

    };

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


printf("EXIT");

return 0;
}

// =================================================================================================== //
// ================== FUNCTION TO CONVERT FROM DECIMAL TO EQUIVALENT RADIX-I SYMBOL ================== //
// =================================================================================================== //

    void Dec2RadixI(int decValue, int radValue) {

    // ----------- Compute log base(radix) of decimal number ----------- //
    printf("\n --- Calculations ---\n");
    double log_res = log10(decValue)/log10(radValue);          // variable storing result of log base operation
    printf("The log%d of %d is %.2lf\n",radValue , decValue , log_res);
    double log2_res = log10(decValue)/log10(2);
    printf("The log2 of %d is %.2lf\n", decValue , log2_res);

    int max_pwr = floor(log_res);      // max_pwr stores the highest power needed in base radix number system
    int pwr = max_pwr;                    // initialize pwr to max_pwr, so that it can be decremented during conversion
    int i =0;
    
    int radConvert [max_pwr];      //  array to store converted number


    for (i=0; i<=max_pwr; i++)
    {                                               // pow() function receives and returns double
        double temp_exp = (pow(radValue, pwr));     // so create temporary double variable, to calculate exponent  
        int exp = temp_exp;                         // then pass its value to integer variable, "exp"

        // -- Integer result of Decimal Number / Radix -- //
        int int_res = decValue/exp;
        printf("The integer result %d divided by %d^%d is %d \n",decValue, radValue, pwr, int_res);

        // -- Remainder of Decimal Number / Radix -- //
        int rem = decValue%(exp);
        printf("The remainder is %d \n", rem);

        // -- Determining each number in equivalent radix -- //
        
        radConvert[i] = int_res;                    // add the coverted number element to array for equivalent radix
        decValue = decValue - int_res * exp ;       // find the next decimal value, to convert next integer result

        pwr-=1;     // decrement radix power

    }
   
    // ----- Output equivalent radix number ----- //

    printf("\nThe equivalent radix-%d number is: ", radValue);

    // Loop through array and output each radix number element //
    for (i=0; i<=max_pwr; i++)       
    {                                                                // if integer result >= 10 (eg for hex radix)
        if (radConvert[i]>=10) {printf("%c", radConvert[i]+55);}     // then use ASCII representation for radix number element
        else {printf("%d", radConvert[i]);};
    }
    printf("\n\n");

    };

// =================================================================================================== //
// =================================================================================================== //
// =================================================================================================== //


