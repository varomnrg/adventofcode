#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define ARR_SIZE 100
#define MAX_INPUT 1028
#define MAX_INCREASE 3

int isReportSafe(int arr[], int size);
int isReportSafeWithRemoval(int arr[], int size, int *levelToRemove);

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

        int levelToRemove;
        int isReactorSafe = isReportSafe(arr, size);

        if (!isReactorSafe)
        {
            isReactorSafe = isReportSafeWithRemoval(arr, size, &levelToRemove);
        }

        if (isReactorSafe)
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

int isReportSafe(int arr[], int size)
{
    int isIncreasing = (arr[0] < arr[1]);

    for (int i = 0; i < size - 1; i++)
    {
        int num1 = arr[i];
        int num2 = arr[i + 1];

        if (abs(num1 - num2) > MAX_INCREASE)
        {
            return 0;
        }

        if (num1 == num2)
        {
            return 0;
        }

        if (isIncreasing)
        {
            if (num1 > num2)
            {
                return 0;
            }
        }
        else
        {
            if (num1 < num2)
            {
                return 0;
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

    return 1;
}

int isReportSafeWithRemoval(int arr[], int size, int *levelToRemove)
{
    for (int i = 0; i < size; i++)
    {
        int tempArr[ARR_SIZE];
        int j;
        for (j = 0; j < i; j++)
        {
            tempArr[j] = arr[j];
        }
        for (j = i + 1; j < size; j++)
        {
            tempArr[j - 1] = arr[j];
        }

        if (isReportSafe(tempArr, size - 1))
        {
            *levelToRemove = i;
            return 1;
        }
    }

    return 0;
}
