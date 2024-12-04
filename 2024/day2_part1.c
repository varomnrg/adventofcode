#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ARR_SIZE 100
#define MAX_INPUT 1028
#define MAX_INCREASE 3

void sort(int arr[], int n);

int main()
{
    int arr[ARR_SIZE];
    int totalSafe = 0;
    char line[MAX_INPUT];

    while (fgets(line, MAX_INPUT, stdin) != NULL)
    {
        int num;
        int size = 0;
        char *token = strtok(line, " ");

        while (token != NULL)
        {
            sscanf(token, "%d", &num);
            arr[size++] = num;
            token = strtok(NULL, " ");
        }

        if (size < 2)
        {
            continue;
        }

        int isReactorSafe = 1;
        int isIncreasing = (arr[0] < arr[1]);

        for (int i = 0; i < size - 1; i++)
        {
            int num1 = arr[i];
            int num2 = arr[i + 1];

            if (abs(num1 - num2) > MAX_INCREASE)
            {
                isReactorSafe = 0;
                break;
            }

            if (num1 == num2)
            {
                isReactorSafe = 0;
                break;
            }

            if (isIncreasing)
            {
                if (num1 > num2)
                {
                    isReactorSafe = 0;
                    break;
                }
            }
            else
            {
                if (num1 < num2)
                {
                    isReactorSafe = 0;
                    break;
                }
            }

            if (num1 < num2)
            {
                isIncreasing = 1;
            }
            else if (num1 > num2)
            {
                isIncreasing = 0;
            }
        }

        if (isReactorSafe == 1)
        {
            totalSafe++;
        }

        if (feof(stdin))
        {
            break;
        }
    }

    printf("Total Safe Reactor : ");
    printf("%i\n", totalSafe);

    return 0;
}