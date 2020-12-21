//Написать функцию нахождения в массиве целых чисел наименьшего по абсолютной величине числа.
//Если числа по модулю равны, выводится элемент массива с наименьшим номером.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int mod(int s)
{
    return s < 0 ? -s : s;
}
int find_min(int* s, int N)
{
    int i, min, k;
    min = s[0];
    for (i = 0, k = 0; i < N; i++)
        if (mod(s[i]) < mod(s[k]))
        {
            min = s[i];
            k = i;
        }
    return min;
}
int main()
{
    int min_number = 0, i = 0, N;
    int* s;
    printf("Input count element of array: ");
    if (scanf("%d", &N) != 1 || N <= 0)
    {
        return printf("Incorrect input.");
    }
    s = (int*)malloc(N * sizeof(int));
    if (s == NULL)
    {
        return -1;
    }
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