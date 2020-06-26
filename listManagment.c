#include <stdio.h>  /*Call the library Standard Input and Output (for the use of basic functions such as printf & scanf).*/
#include <stdlib.h> /*We call on the Standard General Utilities Library (for use of atoi & atof).*/
#include <math.h>   /*We call the library mathematical (to use the functions sqrt & pow).*/

#define MAX_SIZE 100 /*Constant that indicates the maximum number of table capacity array [],we use constant for easier future change (FLEXIBILITY).*/

int     MenuEn();                               /*Standard Function of Menu Options in ENGLISH and price control that gives the user WRONG CHOICE (eg, character or symbol).*/
int     InputList    (double array[],int size); /*Standard function for the user to fill the list of numbers and price control that gives the user WRONG PRICE (eg characters or symbols).*/
void    PrintList    (double array[],int size); /*Standard function for displaying the list on the screen.*/
double  AverageList  (double array[],int size); /*Standard functions to calculate the average.*/
double  MaxList      (double array[],int size); /*Standard function for calculating the maximum.*/
double  MinList      (double array[],int size); /*Standard function for calculating the minimum.*/
double  StandDevList (double array[],int size); /*Template function to calculate the standard deviation.*/

/*-------------------------Master Program Simple Statistical Analysis-------------------------*/

int main(void)
{
    int choice,size,checkFlag=0;
    char ArraySize[128];
    double array[MAX_SIZE]; /* Statement table with 100 seats REAL NUMBERS with precision 15 DEMICAL PLACES.*/
                            /* !!!IMPORTANT !!! In our lab machines have ERROR in calculates 0.0000002685. */
                            /* THIS IS THE REASON THAT SHOWS ONLY PRECISION 6 DEMICAL PLACES AND NOT 15 (%.15lf).*/
                            /* BECAUSE WE WANT OUR PROGRAM BE UNIVERSAL KEEP THE ACCURACY OF 15 DEMICAL PLACES.
                            /* JUST DON'T SHOW THE ERROR OF LAB PC'S.*/

   do{ /*Check for input price between [1-100]. I do not put in the space 0 because there would have NO ENTRY.*/
        printf("Please, enter the number of elements you want to have the program. \n(The number must be between 1 and 100):");
        scanf ("%s",&ArraySize);

    if((ArraySize[0]=='0') || (ArraySize[0]=='-')) /*Check to see if the first digit is '0 'or' - '.*/
        size = atoi(ArraySize); /*If is '0 'or' - 'using the atoi get the number  integer.*/
    else
        if (atoi(ArraySize)==0) /*Otherwise, if the first digit is '0 'but atoi gives 0 means that given CHARACTERS OR SYMBOLS.*/
                {
                printf("Please, give again the number of elements !!! \n\n");
                size=110;/*Make the loop is re-run until you get the desired - numeric value I want.*/
                }
        else /*Here we have the case that the first digit is not '0 ' (from 1-9) and atoi giving the number in integer form. */
                size = atoi(ArraySize);

    printf("\n");
   }while(size<1 || size>100);


    do /*Check if the user selection (choice) is between 0 and 5.*/
    {
        choice=MenuEn();

        if (choice==1)
        {
            InputList(array,size);
            checkFlag=checkFlag+1; /*Liberation flag when the first one chosen.*/
        }
        if (choice==2)
        {
            if (checkFlag==0) /*Flag control run to not first the selection of 2 or 3 or 4 or 5 before that of 1 (the filling of the array).*/
                printf("!!! Must select 1 first !!!\n");
            else
                PrintList (array,size); /*Call function to Print the list.*/
        }

        if (choice==3)
        {
            if (checkFlag==0) /*Flag control run to not first the selection of 2 or 3 or 4 or 5 before that of 1 (the filling of the array).*/
                printf("!!! Must select 1 first !!!\n");
            else
                printf("Average is : %lf \n\n",AverageList (array,size));/*Call function for calculating the Average*/
        }

        if (choice==4)
        {
            if (checkFlag==0) /*Flag control run to not first the selection of 2 or 3 or 4 or 5 before that of 1 (the filling of the array).*/
               printf("!!! Must select 1 first !!!\n");
            else
               {
                printf("Max number is : %lf \n",MaxList(array,size));/*Call function to calculate the Maximum*/
                printf("Min number is : %lf \n\n",MinList(array,size));/*Call the function for calculating the Minimum*/
               }
        }
        if (choice==5)
        {
            if (checkFlag==0) /*Flag control run to not first the selection of 2 or 3 or 4 or 5 before that of 1 (the filling of the array).*/
                printf("!!! Must select 1 first !!!\n");
            else
                printf("The standard deviation is : %lf \n\n",StandDevList(array,size));/*Call function to calculate the Standard Deviation.*/
        }
        if ((choice>5) || (choice<0))
            printf("*** Try to choice between [0 - 5] next time. ***\n\n");


    } while (choice!=0);
    printf("GoodBye !!!\n");
return 0;
}

/*-------------------------The implementations of functions------------------------------------*/

int MenuEn()
{
    char menu[128];
    int choice;

    printf("+------------------------+\n");
    printf("| Menu:                  |\n");
    printf("| 1. Input List          |\n");
    printf("| 2. Print List          |\n");
    printf("| 3. Calculate Average   |\n");
    printf("| 4. Calculate Max & Min |\n");
    printf("| 5. Standard deviation  |\n");
    printf("| 0. Exit                |\n");
    printf("+------------------------+\n");
    printf("Please, select a number from 0 to 5: ");
    scanf("%s",&menu);
    printf("\n");

    if((menu[0]=='0') || (menu[0]=='-') ||(menu[0]=='\n'))/*Check to see if the first digit is '0' or '-' or '\ n'*/
            choice = atoi(menu); /*If it is '0' or '-' or '\ n' using the atoi get the number in integer form.*/
    else
        if (atoi(menu)==0)/*Otherwise, if the first digit is not '0 but atoi gives 0 means that given CHARACTERS OR SYMBOLS.*/
                return 6 ; /*Returned this value to display the corresponding message in the main function.*/
        else /*Here we have the case where the first digit is not '0 '(from 1 to 9) and atoi giving the number in integer form. */
                choice = atoi(menu);
    return choice;
}

int InputList (double array[],int size)
{
    int i;
    char number[128];

    for(i=0;i<size;i++)
    {
        printf("Please, give the element of array[%d] : ",i);
        scanf("%s",&number);

        if((number[0]=='0') || (number[0]=='-') ) /*Check to see if the first fifio is '0'or '-'*/
            array[i] = atof(number); /*If it is '0 'or' - 'using the atof to get the number to real number form.*/
        else
            if (atof(number)==0) /*Otherwise, if the first digit is not '0 but atoi gives 0 means that given CHARACTERS OR SYMBOLS.*/
                {
                    printf("Please, give again the element of array[%d] !!!\n",i);
                    i=i-1; /*Once we see that price was wrong, do it again again on the same loop.*/
                }
            else /*Here we have the case where the first digit is not '0 '(from 1 to 9) and atoi giving the number to real number form*/
                array[i] = atof(number);
    }
    printf("\n");
    return 0;
}

void PrintList (double array[],int size)
{
    int i=0;
    for(i=0;i<size;i++)
        printf("Element of array[%d] is = %lf \n",i,array[i]); /*Print all elements in the array array set by the user.*/
    printf("\n");
}

double AverageList (double array[],int size)
{
    int i;
    float average,sum=0;

    for(i=0 ; i<size ; i++)
       sum = sum+array[i]; /*Sum of all elements in the array array set by the user.*/

    average = (sum/size); /*Application of the classical type: sum / size.*/
    return average;
}

double MaxList(double array[],int size)
{
    int i;
    float max;

    max = array[0]; /*Initialization value.*/
    for(i=0;i<size;i++)
    {
        if (array[i]> max)
            max=array[i]; /*Sequential comparison of all the data provided by the use of 1-to-1 in order to find the maximum.*/
    }
    return max;
}

double MinList(double array[],int size)
{
    int i;
    float min;

    min=array[0];/*Initialization value.*/
    for(i=0;i<size;i++)
    {
        if (array[i]< min)
           min=array[i];/*Sequential comparison of all the data provided by the use of 1-to-1 in order to find the minimum.*/
    }
    return min;
}

double StandDevList(double array[],int size)
{
    int i;
    double average,sum=0;
    double StandDev;

    average = AverageList(array,size);

    for(i=0;i<size;i++)
    {
        sum =sum + pow(array[i]-average, 2);/*[Sigma(array[i]-Average)^2] for all elements of the array array set by the user.*/
    }
    StandDev=(sum/size);/*S^2=(Sigma(array[i]-Average)^2/size)*/
    return sqrt(StandDev); /*S'= Square root of (S^2) */
}
/*FOOTNOTE: IN OUR CHECKS IF SOMEONE GIVE FIRST NUMBER AND AFTER CHARACTER(IN THE SAME strg)
AND THE NUMBER IS WITHIN THE LIMITS OF EACH CIRCUMSTANCES, THE NUMBER PART BECOME ACCEPTED
BECAUSE SOMEONE WHEN PRESS BUTTON ENTER, CAN PRESS A CHARACTER ACCIDENTALLY.*/
