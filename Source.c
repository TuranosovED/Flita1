#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

void clearbufer()
{
    char l;
    while (1)
    {
        l = getchar();
        if (l == '\n')break;
    }
}

int Vvod()
{
    int triger; // 0 - некоректный ввод 1 - коректный ввод, очистка stdin не требуется, 2 - коректный ввод, но буфер переполнен, требуется очистка
    char c;
    while (1)
    {
        char* s = (char*)calloc(10, sizeof(char));
        triger = 1;
        printf("%s%c", "Enter number, please: ", '\n');
        for (int i = 0; i < 10; i++)
        {
            c = getchar();
            if ((int)c >= 48 && (int)c < 58 && c != '\n')
            {
                triger = 2;
                s[i] = c;
            }
            else if (c == '\n')
            {
                if (s[0] == '\0')triger = 0;
                else triger = 1;
                break;
            }
            else
            {
                triger = 0;
                clearbufer();
                break;
            }
        }
        if (triger == 1)return atoi(s);
        else if (triger == 2)
        {
            clearbufer();
            return atoi(s);
        }
        else
        {
            printf("%s%c", "Try again, please ", '\n');
            system("pause");
            system("cls");
        }
        free(s);
    }
}

int CheakForRepeat(int* a, int number,int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == number)return 0;
    }
    return 1;
}

void Print(int* a, int size)
{
    printf("%c", '\n');
    for (int i = 0; i < size; i++)
    {
        printf("%d%c", a[i],' ');
    }
    printf("%c", '\n');
}

int BinarConversion(int number)
{
    if (number > 1)BinarConversion(number / 2);
    printf("%d", number % 2);
    return number;
}

int main()
{
    int element;
    int triger;
    int size;
    printf("%s%c", "Enter size of multiplicity", '\n');
    scanf("%d", &size);
    clearbufer();
    int* a = (int*)calloc(size, sizeof(int));
    for (int i = 0; i < size;)
    {
        element = Vvod();
        if (CheakForRepeat(a, element, size) == 1)
        {
            a[i] = element;
            i++;
        }
        else
        {
            printf("%s%c", "element is already included in the set, try again", '\n');
            system("pause");
            system("cls");
        }
    }
    Print(a, size);
    for (int i = 0; i < size; i++)
    {
        BinarConversion(a[i]);
        printf("%c", ' ');
    }
    printf("%c", '\n');
    system("pause");
    return 0;
}
