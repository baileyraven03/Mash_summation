#include <stdio.h>

float mean(int sum, int N);

int main()
{
    char ans;
    // Declaring variables
    do
    {
        char singleChar, character;
        int sum = 0, count = 0, singleint;
        FILE *fin, *fr;

        fin = fopen("myFile.txt", "w");
        if (fin == NULL)
        {
            printf("Error opening file!\n");
            ans = 'n';
        }

        // Promting user to enter values
        printf("Enter a list of Characters and Integers with no spaces:\n");
        // Print the list of characters
        do
        {
            scanf("%c", &singleChar);
            fprintf(fin, "%c", singleChar);
        } while (singleChar != ' ' && singleChar != '\n');
        // Resetting singleChar
        singleChar = '\0';
        // Closing file
        fclose(fin);

        fr = fopen("myFile.txt", "r");
        if (fr == NULL)
        {
            printf("Error opening file!\n");
        }
        printf("The numbers you entered are:\n");

        while (fscanf(fr, "%c", &character) != EOF)
        {
            if (character >= '0' && character <= '9')
            {
                printf("%c ", character);
                singleint = character - '0';
                sum += singleint;
                count++;
            }
            fscanf(fr, "%c", &character);
        }
        if (count == 0)
        {
            printf("You have not entered any integers.\n");
        }
        else
        {
            printf("\nThe sum of your integers is: %d\n", sum);
            printf("The number of integers you entered is: %d\n", count);
            // Calculating & printing average
            float avg = mean(sum, count);
            printf("The average of your integers is: %.2f\n", avg);
        }
        printf("Do you want go again? (press Y for yes, or any other character to end): ");
        scanf("%c", &ans);

        fclose(fr);
    } while (ans == 'Y' || ans == 'y');

    return 0;
}

float mean(int sum, int N)
{
    float avg = ((float)sum / (float)N);
    return avg;
};