#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#define MaxNumberOfdigits 11

typedef struct Array
{
    int32_t value;
    struct Array *next;
}Array;

void push(Array **head,int value)
{
    Array *buffer = (Array*)malloc(sizeof(Array));
    buffer->next = *head;
    buffer->value = value;
    *head = buffer;
}

void clearbuffer()
{
    while (getchar() !='\n');
}

int32_t enter()
{
    int32_t status; /* 0 - некоректный ввод 
                       1 - коректный ввод, очистка stdin не требуется
                       2 - коректный ввод, но буфер переполнен, требуется очистка*/
    char c;
    while (true)
    {
        char* s = (char*)malloc(MaxNumberOfdigits * sizeof(char));
        status = 1;
        printf("Enter number, please: ");
        for (int32_t i = 0; i < MaxNumberOfdigits; i++)
        {
            c = getchar();
            if(c == '-')return -1;

            if (c >= '0' && c <= '9')
            {
                status = 2;
                s[i] = c;
            }
            else if (c == '\n')
            {
                status = (s[0] == '\0') ? 0 : 1;
                break;
            }
            else
            {
                status = 0;
                clearbuffer();
                break;
            }
        }
        switch(status)
        {
            case 2:
                clearbuffer();
            case 1:
                return atoi(s);
                break;
            default:
                puts("Try again, please");
                system("pause");
                system("cls");
        }
        free (s);
    }
}

bool cheakForRepeat(Array *head, int32_t number, int32_t size)
{
    while(head != NULL)
    {
        if(head->value == number)return false;
        head = head->next;
    }
    return true;
}

void print(Array *head, int32_t size)
{
    while(head != NULL)
    {
        printf("%d ",head->value);
        head = head->next;
    }
    putchar('\n');
}

int32_t displayingBinaryNumber(int32_t number)
{
    if (number > 1) displayingBinaryNumber(number / 2);
    putchar(number % 2 + '0');
    return number;
}

void displayingBinaryNumberArrayay(Array *head,int32_t size)
{
    while(head != NULL)
    {
        displayingBinaryNumber(head->value);
        head = head->next;
        putchar(' ');
    }
}

int32_t main()
{
    int32_t element;
    int32_t size;

    Array *head= NULL;

    puts("Enter multiplicity. To stop typing enter \'-\'");
    
    while(true)
    {
        element = enter();
        if(element == -1) break;
        if (cheakForRepeat (head, element, size))
            push(&head,element);
        else
        {
            puts("element is already included in the set, try again");
            system("pause");
            system("cls");
        }
    }

    print(head, size);
    displayingBinaryNumberArrayay(head,size);
    putchar('\n');
    system("pause");
    return 0;
}