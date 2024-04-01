/*
This is a program written to take a string inputted of random letters and number, filter out the numbers and return a sum, count and average of those entered.
The user can run through as many times as they want until they opt out, values returned will be per run, not a total.
Written on the 04/10/2023 by Bailey Raven
*/

#include <stdio.h>//Including stdio.h library

float mean(int sum, int N); //Function declaration

int main() // Main program
{
    
    char ans; //Declaring answer variable
    
    do // Creating the loop allowing the user to loop through upon answer
    {
        
        char singleChar, character; // Declaring the character variables
        int sum = 0, count = 0, singleint; // Declaring the integer variables
        FILE *fin, *fr; // Delcaring the file pointer variables

        fin = fopen("myFile.txt", "w"); // Opening the file myFile.txt for writing

        if (fin == NULL) // Runs if the file cannot open, checks to see if the file pointer is empty or not
        {
            printf("Error opening file!\n"); // Error message thrown if file cannot open
            ans = 'n'; //Sets ans variable to n to close program
        }

        printf("Enter a list of Characters and Integers with no spaces:\n"); // Promting user to enter values
        do // Looping through and printing each char entered to the file until a space or new line is detected, runs at least once due to do while used
        {
            scanf("%c", &singleChar); // Reads and scans each character entered, then assings to singleChar variable
            fprintf(fin, "%c", singleChar); // Prints each character to the file
        } while (singleChar != ' ' && singleChar != '\n'); // Keeps running until a space or new line is detected
       
        fclose(fin); // Closing file

        fr = fopen("myFile.txt", "r"); // Opening the file for reading
        if (fr == NULL) // Runs if the file cannot open, checks to see if the file pointer is empty or not
        {
            printf("Error opening file!\n"); // Error message thrown if file cannot open
            ans = 'n'; //Sets ans variable to n to close program
        }

        printf("The numbers you entered are:\n");
        while (fscanf(fr, "%c", &character) != EOF) // Filters out the integers from characters until the end of the file
        {
            if (character >= '0' && character <= '9') // Finds out if the character is an integer or not, will not run if not
            {
                printf("%c ", character); // Printes the integer to the terminal
                singleint = character - '0'; // Converts character to an integer
                sum += singleint; // Adds the integer value to the sum
                count++; // Adds one to the count
            }
        }
        if (count == 0) // If else to find out if you've entered any intagers, this runs if not intagers are entered
        {
            printf("You have not entered any integers.\n"); // Prints if no integers are entered
        }
        else // Runs if any integers are entered
        {   
            printf("\nThe sum of your integers is: %d\n", sum); // Prints the sum of integers entered
            printf("The number of integers you entered is: %d\n", count); // Prints the number of integers entered
            float avg = mean(sum, count);   // Calculating the average via mean function
            printf("The average of your integers is: %.2f\n", avg); // Prints the average to 2 decimal places
        } 

        if (ans != 'n')  // Runs of ans does not equal 'n', as if it does this would be declared in arror messages thrown at file openings
        {  
            printf("Do you want go again? (press Y for yes, or any other character to end): "); // Questioning the user if they want to play again
            scanf("%c", &ans); // Prompts the entering of the answer variable
            char clear = scanf("%c", &clear); // Clears the newline which is returned in the scanf above (line 69) and assings to clear variable, which otherwise would not allow a second input from the user
        }


        fclose(fr); // Closing the file
    } while (ans == 'y' || ans == 'Y'); // Condition for the loop to keep working

    return 0; // Returns zero to signify the ending of the main function and satisfy the int return type at the top
}

float mean(int sum, int N) // Mean function definition
{
    float avg = ((float)sum / (float)N); // Calcuating the average
    return avg; // Returning the average
};
