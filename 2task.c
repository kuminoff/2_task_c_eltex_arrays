#include <stdio.h>
#define number_N 7

int i, j;
const int MAX = 100;

int square_matrix()
{
    int array[number_N][number_N] = {0};

    for (i = 0; i < number_N; i++)
    {
        for (j = 0; j < number_N; j++)
        {
            array[i][j] = i * number_N + j + 1;
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int reverse_array()
{
    int tmp = 0;

    int array[number_N];

    printf("\ninitial array: ");

    for (i = 0; i < number_N; i++)
    {
        array[i] = i + 1;
        printf("%d  ", array[i]);
    }

    for (i = 0; i < number_N / 2; i++)
    {
        tmp = array[i];
        array[i] = array[number_N - i - 1];
        array[number_N - i - 1] = tmp;
    }

    printf("\nreversed array: ");

    for (i = 0; i < number_N; i++)
    {
        printf("%d  ", array[i]);
    }

    return 0;
}

int top_triangle_zeros()
{
    int array[number_N][number_N] = {0};
    for (j = 0; j < number_N; j++)
    {
        for (i = 0; i < number_N; i++)
        {
            if (i >= number_N - j)
            {
                array[i][j] = 0;
            }
            else
            {
                array[i][j] = 1;
            }
        }
    }
    for (i = 0; i < number_N; i++)
    {
        for (j = 0; j < number_N; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int snail_matrix()
{
    int A[number_N][number_N];
    int row1 = 0, col1 = 0, row2 = number_N - 1, col2 = number_N - 1, iter = 1;

    while (iter <= (number_N * number_N))
    {
        for (int i = col1; i <= col2; i++)
        {
            A[row1][i] = iter++;
        }

        for (int j = row1 + 1; j <= row2; j++)
        {
            A[j][col2] = iter++;
        }

        for (int i = col2 - 1; i >= col1; i--)
        {
            A[row2][i] = iter++;
        }

        for (int j = row2 - 1; j >= row1 + 1; j--)
        {
            A[j][col1] = iter++;
        }

        row1++;
        row2--;
        col1++;
        col2--;
    }

    printf("Matrix snail:\n");

    for (int i = 0; i < number_N; i++)
    {
        for (int j = 0; j < number_N; j++)
        {
            printf("%d \t", A[i][j]);
        }

        printf("\n");
    }

    return 0;
}

int main()
{
    // 1. Вывести квадратную матрицу по заданному N
    // 2. Вывести заданный массив размером в обратном порядке
    // 3. Заполнить верхний треугольник матрицы 1, а нижний 0
    // 4. Заполнить матрицу числами от 1 до N^2 улиткой

    int task_num;

    printf("Select task from 1-4: ");
    scanf("%d", &task_num);

    switch (task_num)
    {
    case 1:
        square_matrix();
        break;

    case 2:
        reverse_array();
        break;

    case 3:
        top_triangle_zeros();
        break;

    case 4:
        snail_matrix();
        break;

    default:
        printf("Task number %u not found\n", task_num);
    }

    return 0;
}