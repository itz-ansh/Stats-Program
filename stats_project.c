#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// Global variables
char opt;  // option of Y(Yes) or N(No) 
float a[100]; // element/data storing array
float a1[100]; // a1 --> copy of array a
int n;  // n = no. of elements/data 
float population_variance, sample_variance;
float max, min;
float values_for_frequency[100];
int frequency_array[100];


// Function prototypes
int choose();
void read_data(float [], int*);  // Changed n to pointer
void print_array(float [], int); 
float sum_array(float [], int);
void bubble_sort_nd(float [], int); // nd --> non decreasing
void bubble_sort_ni(float [], int); // ni --> non increasing
void array_copy(float [], float[], int);
void Median();
void Mode();
void Variance();
void Standard_Deviation();
void Max();
void Min();
void frequency_table();

int main() 
{
    // User Interface
    char start;
    int choice;    

    printf("Press Y to start: ");
    scanf(" %c", &start);  // Notice the space before %c to ignore leading newline

    if (start == 'Y' || start == 'y') 
    {
        read_data(a, &n);  // Pass address of n
        choice = choose();  // Call choose() to get the user's choice
    } 
    else 
    {
        printf("Have a great day!\n");
        printf("The program is terminated!");
        exit(0);
    }

    return 0;
}


void read_data(float a[], int *n)  // pass pointer to n
{
    printf("Enter the number of elements (max 100): ");
    scanf("%d", n);  // Modify n directly through the pointer

    printf("Enter the numbers: ");
    for (int i = 0; i < *n; i++) 
        scanf("%f", &a[i]);  // Read as float
}


void print_array(float a[], int n)
{
    for(int i=0;i<n;i++)
        printf("   %.3f", a[i]);
}


int choose() 
{
    int choice;

    printf("\n0 --> exit\n");
    printf("1 --> re-enter data set\n");
    printf("2 --> print the data\n");
    printf("3 --> sort the data\n");
    printf("4 --> sum of elements\n");
    printf("5 --> mean\n");
    printf("6 --> median\n");
    printf("7 --> mode\n");
    printf("8 --> variance\n");
    printf("9 --> standard deviation\n");
    printf("10 --> maximum\n");
    printf("11 --> minimum\n");
    printf("12 --> frequency table\n\n");


    printf("What statistical data do you want to compute? Choose: ");
    
    scanf("%d", &choice);
    printf("\n");

    if (choice == 0)    // exit
    {
        printf("Have a great day!\n");
        printf("The program is terminated!\n");
        exit(0);
    }

    else if (choice == 1)  // re-enter data set
    {
        read_data(a, &n);  // Pass address of n
        printf("\n\nDo you want to compute any statistical data? (Press Y or N): ");
        scanf(" %c", &opt);
        if (opt == 'Y' || opt == 'y') 
            choice = choose();  // Call choose() to get the user's choice
        else 
        {
            printf("Have a great day!\n");
            printf("The program is terminated!\n");
            exit(0);
        }
    }

    else if (choice == 2)  // print the data set 
    {
        print_array(a,n); 
        
        printf("\n\nDo you want to compute any statistical data? (Press Y or N): ");
        scanf(" %c", &opt);
        if (opt == 'Y' || opt == 'y') 
            choice = choose();  // Call choose() to get the user's choice
        else 
        {
            printf("Have a great day!\n");
            printf("The program is terminated!\n");
            exit(0);
        }
    }

    else if (choice == 3)  // sorting
    {
        char sort_choice[3];
        
        printf("nd --> non decreasing\n");
        printf("ni --> non increasing\n");
        printf("The re-arranged format should be? ");
        scanf("%s", sort_choice);
        if (strcmp(sort_choice, "nd") == 0)
        { 
            bubble_sort_nd(a,n);
            print_array(a,n);
        }
        else if (strcmp(sort_choice, "ni") == 0)
        {
            bubble_sort_ni(a,n);
            print_array(a,n);
        }
        else 
        {
            printf("Sorting in non-decreasing order:- \n");
            bubble_sort_nd(a,n);
            print_array(a,n);
        }

        printf("\n\nDo you want to compute another statistical data?? (Press Y or N): ");
        scanf(" %c", &opt);
        if (opt == 'Y' || opt == 'y') 
            choice = choose();  // Call choose() to get the user's choice
        else 
        {
            printf("Have a great day!\n");
            printf("The program is terminated!\n");
            exit(0);
        }       
    }  

    else if (choice == 4)  // sum of numbers 
    {
        float sum = sum_array(a, n);  // Use float for sum
        printf("The sum of the numbers = %f\n", sum);  // Use %f for float

        printf("\n\nDo you want to compute another statistical data?? (Press Y or N): ");
        scanf(" %c", &opt);
        if (opt == 'Y' || opt == 'y') 
            choice = choose();  // Call choose() to get the user's choice
        else 
        {
            printf("Have a great day!\n");
            printf("The program is terminated!\n");
            exit(0);
        }       
    } 

    else if (choice == 5)   // mean of data
    {
        float mean; 

        mean = sum_array(a, n) / n;  // calculating mean
        printf("The mean or average of the given data = %f\n", mean);

        printf("\n\nDo you want to compute another statistical data?? (Press Y or N): ");
        scanf(" %c", &opt);
        if (opt == 'Y' || opt == 'y') 
            choice = choose();  // Call choose() to get the user's choice
        else 
        {
            printf("Have a great day!\n");
            printf("The program is terminated!\n");
            exit(0);
        }
    }

    else if (choice == 6)    // median of the data
    {
        Median();

        printf("\n\nDo you want to compute another statistical data?? (Press Y or N): ");
        scanf(" %c", &opt);
        if (opt == 'Y' || opt == 'y') 
            choice = choose();  // Call choose() to get the user's choice
        else 
        {
            printf("Have a great day!\n");
            printf("The program is terminated!\n");
            exit(0);
        }       
    }

    else if (choice == 7)   // mode of data
    {
        Mode();

        printf("\n\nDo you want to compute another statistical data? (Press Y or N): ");
        scanf(" %c", &opt);
        if (opt == 'Y' || opt == 'y') 
            choice = choose();  // Call choose() to get the user's choice
        else 
        {
            printf("Have a great day!\n");
            printf("The program is terminated!\n");
            exit(0);
        }
    }

    else if (choice == 8)   // variance
    {
        Variance();
        
        printf("Population variance of the data set = %f", population_variance);
        printf("\nSample variance of the data set = %f", sample_variance); 

        printf("\n\nWould you like to compute standard deviation as well?? (Press Y or N): ");
        scanf(" %c", &opt);
        if (opt == 'Y' || opt == 'y')
        {
            Standard_Deviation();

            printf("\n\nDo you want to compute another statistical data? (Press Y or N): ");
            scanf(" %c", &opt);
            if (opt == 'Y' || opt == 'y') 
                choice = choose();  // Call choose() to get the user's choice
            else 
            {
                printf("Have a great day!\n");
                printf("The program is terminated!\n");
                exit(0);
            }
        }
        else 
        {      
            printf("\n\nDo you want to compute another statistical data? (Press Y or N): ");
            scanf(" %c", &opt);
            if (opt == 'Y' || opt == 'y') 
                choice = choose();  // Call choose() to get the user's choice
            else 
            {
                printf("Have a great day!\n");
                printf("The program is terminated!\n");
                exit(0);
            }
        }
    }

    else if (choice == 9)   // standard deivation
    {
        Variance();
        Standard_Deviation();

        printf("\n\nDo you want to compute another statistical data? (Press Y or N): ");
        scanf(" %c", &opt);
        if (opt == 'Y' || opt == 'y') 
            choice = choose();  // Call choose() to get the user's choice
        else 
        {
            printf("Have a great day!\n");
            printf("The program is terminated!\n");
            exit(0);
        }
    }

    else if (choice == 10)  // maximum
    {
        Max();
        printf("The maximum number in the array = %f", max);

        printf("\n\nDo you want to compute any statistical data? (Press Y or N): ");
        scanf(" %c", &opt);
        if (opt == 'Y' || opt == 'y') 
            choice = choose();  // Call choose() to get the user's choice
        else 
        {
            printf("Have a great day!\n");
            printf("The program is terminated!\n");
            exit(0);
        }
    }

    else if (choice == 11)  // minimum
    {
        Min();
        printf("The minimum number in the array = %f", min);

        printf("\n\nDo you want to compute any statistical data? (Press Y or N): ");
        scanf(" %c", &opt);
        if (opt == 'Y' || opt == 'y') 
            choice = choose();  // Call choose() to get the user's choice
        else 
        {
            printf("Have a great day!\n");
            printf("The program is terminated!\n");
            exit(0);
        }
    }

    else if (choice == 12)  // frequency table
    {
        frequency_table();

        printf("\n\nDo you want to compute any statistical data? (Press Y or N): ");
        scanf(" %c", &opt);
        if (opt == 'Y' || opt == 'y') 
            choice = choose();  // Call choose() to get the user's choice
        else 
        {
            printf("Have a great day!\n");
            printf("The program is terminated!\n");
            exit(0);
        }
    }

    else
    {
        printf("No such option present!");
        printf("\nWould you like to choose again?? (Press Y or N): ");
        scanf(" %c", &opt);
        if (opt == 'Y' || opt == 'y') 
            choice = choose();  // Call choose() to get the user's choice
        else
        {
            printf("Have a great day!\n");
            printf("The program is terminated!\n");
            exit(0);
        }
    }

    return choice;
}


float sum_array(float a[], int n) 
{
    if (n == 0)
        return 0;
    else
        return a[n - 1] + sum_array(a, n - 1);  // Recursive step: current element + sum of the rest
}


void bubble_sort_nd(float a[], int n)
{
    int i, j;
    float t;
    int flag = 1;
    for(i=0; i<n-1 && flag==1; i++)  // i ---> represents 'pass'
    {
        flag = 0;
        for(j=0; j<n-1-i; j++)
        {
            if (a[j]>a[j+1])        // non-decreasing
            {   
                //swapping
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                flag = 1;
            }
        }
    }
}


void bubble_sort_ni(float a[], int n)
{
    int i, j;
    float t;
    int flag = 1;
    for(i=0; i<n-1 && flag==1; i++)  // i ---> represents 'pass'
    {
        flag = 0;
        for(j=0; j<n-1-i; j++)
        {
            if (a[j]<a[j+1])      // non-increasing
            {   
                //swapping
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                flag = 1;
            }
        }
    }
}


void array_copy(float a[], float b[], int n)
{
    for (int i=0; i<n; i++)
        a1[i] = a[i];
}


void Median()
{
    int m; float median;
    int p, q;
    bubble_sort_nd(a,n);

    if (n%2!=0) // no. of elements is odd
    {
        m = ((n+1)/2) - 1 ;
        median = a[m];
        printf("Median of the given data: %f", median);
    }
    else
    {
        p = (n/2) - 1 ;
        q = ((n/2) + 1) - 1 ;  // q = n/2
        median = (a[p]+a[q])/2 ;
        printf("Median of the given data: %f", median);
    }
}


void Mode()
{
    int most_count = 0; // Highest frequency of any number
    float mode_array[10];  
    int mode_frequency_array[10];
    int p = 0; // Index to track number of modes
 
    for (int j = 0; j < n; j++)
    {
        int count = 0;
        // Count occurrences of a[j]
        for (int k = 0; k < n; k++)
        {
            if (a[j] == a[k])
                count++; // count = count + 1
        }
        // If a new highest count is found, reset the mode array
        if (count > most_count)
        {
            most_count = count;
            p = 0;  // Reset mode count
            mode_array[p] = a[j];  // Store the new mode
            mode_frequency_array[p] = most_count; // Store frequency
            p++;  // Move to next index for possible additional modes
        }
        // If the count equals the current highest count, add to mode array
        else if (count == most_count && most_count > 1)
        {
            int already_exists = 0;
            // Check if the mode is already stored to avoid duplicates
            for (int m = 0; m < p; m++) 
            {
                if (mode_array[m] == a[j])
                {
                    already_exists = 1;
                    break;
                }
            }
            if (!already_exists)
            {
                mode_array[p] = a[j];
                mode_frequency_array[p] = most_count;
                p++;
            }
        }
    }
    // printf("\n");

    if (mode_frequency_array[0]>1)
    {
        // Print the modes and their frequencies
        printf("Mode(s) of the data \t\t     Frequency\n");
        for (int r = 0; r < p; r++)
        {
            printf("%f \t\t\t\t %d\n", mode_array[r], mode_frequency_array[r]);
        }
    }

    else
    {
        printf("There is no mode for this dataset!");
        printf("\n\nDo you want to compute another statistical data? (Press Y or N): ");
        scanf(" %c", &opt);
        if (opt == 'Y' || opt == 'y') 
            choose();  // Call choose() to get the user's choice
        else 
        {
            printf("Have a great day!\n");
            printf("The program is terminated!\n");
            exit(0);
        }
    }

}


void Variance()
{
    float mean; 
    float sum_for_var_calc = 0;

    // calculating mean
    mean = sum_array(a, n) / n;  

    // Subtract the mean from each data point and square the result
    for (int i=0; i<n; i++)
    {
        float subtract = pow((a[i] - mean), 2);  // int subtract = (a[i] - mean) * (a[i] - mean)
        // Sum these squared differences
        sum_for_var_calc = sum_for_var_calc + subtract;
    } 

    population_variance = sum_for_var_calc / n;
    sample_variance = sum_for_var_calc / (n-1) ;
}


void Standard_Deviation()
{
    printf("\nStandard deviation for population: %f", sqrt(population_variance));
    printf("\nStandard deviation for sample: %f", sqrt(sample_variance));
}


void Max()
{
    max = a[0];  //Let karlo
    for(int i=0; i<n; i++)
        if (a[i]>max)
            max = a[i];
}


void Min()
{
    min = a[0];  //Let karlo
    for(int i=0; i<n; i++)
        if (a[i]<min)
            min = a[i];
}


void frequency_table()
{
    int count, i, j;
    int p = 0;
    bubble_sort_nd(a,n);
    for (int i=0; i<n; i ++)
    {    
        count = 0;
        for (int j=0; j<n; j++)
            if (a[j]==a[i])
                count++;    
        int already_exists = 0;
        // Check if the value is already stored to avoid duplicates
        for (int m = 0; m < n; m++) 
        {
            if (values_for_frequency[m] == a[i])
            {
                already_exists = 1;
                break;
            }
        }
        if (!already_exists)
        {
            values_for_frequency[p] = a[i];
            frequency_array[p] = count;
            p++;     
        }
    }

    // Print the values and their frequencies
    printf("Values\t\t\t Frequency\n");
    for (int k = 0; k < p; k++)
    {
        printf("%.2f \t\t\t    %d\n", values_for_frequency[k], frequency_array[k]);
    }
}


