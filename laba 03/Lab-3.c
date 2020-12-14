//Написать функцию нахождения в массиве целых чисел наименьшего по абсолютной величине числа.
//Если числа по модулю равны, выводится элемент массива с наименьшим номером.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
int find_min(int* s, int N)
{
    int i = 0, min;
    min = s[0];
    for(i = 0;i < N; i++)
        if (mod_el(s, i) < mod_min(min, i))
        {
            min = s[i];
        }
    return min;
}
int mod_el(int* s, int i)
{
    if (s[i] < 0)
    {
        s[i] = s[i] * (-1);
    }
    return s[i];
}
int mod_min(int min, int i)
{
    if (min < 0)
    {
        min = min * (-1);
    }
    return min;
}

int 
main()
{
    int min_number = 0, i = 0, N;
    int* s;
    printf("Input count element of array: ");
    if (scanf("%d", &N) != 1 || N <= 0)
    {
        return printf("Incorrect input.");
    }
    s = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        printf("%d element: ", i);
        if (scanf("%d", &s[i]) != 1)
        {
           return printf("Incorrect input.");
        }
        
    }
        min_number = find_min(s, N);
        printf("Result: %d", min_number);
        free(s);
        return 0;   
}