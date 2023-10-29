#include <stdio.h>
#include <stdbool.h>

bool is_vertically_symmetric(char letter)
{
    return (letter == 'I' || letter == 'V' || letter == 'X' || letter == 'M');
}

char get_symmetry(int num)
{
    bool horizontal = true, vertical = true;

    char roman[20]; // Roman numerals will not exceed 20 characters
    int i = 0;

    while (num > 0)
    {
        if (num >= 1000)
        {
            roman[i++] = 'M';
            num -= 1000;
            horizontal = false;
        }
        else if (num >= 900)
        {
            roman[i++] = 'C';
            roman[i++] = 'M';
            num -= 900;
            horizontal = false;
        }
        else if (num >= 500)
        {
            roman[i++] = 'D';
            num -= 500;
        }
        else if (num >= 400)
        {
            roman[i++] = 'C';
            roman[i++] = 'D';
            num -= 400;
        }
        else if (num >= 100)
        {
            roman[i++] = 'C';
            num -= 100;
        }
        else if (num >= 90)
        {
            roman[i++] = 'X';
            roman[i++] = 'C';
            num -= 90;
        }
        else if (num >= 50)
        {
            roman[i++] = 'L';
            num -= 50;
            horizontal = false;
        }
        else if (num >= 40)
        {
            roman[i++] = 'X';
            roman[i++] = 'L';
            num -= 40;
            horizontal = false;
        }
        else if (num >= 10)
        {
            roman[i++] = 'X';
            num -= 10;
        }
        else if (num >= 9)
        {
            roman[i++] = 'I';
            roman[i++] = 'X';
            num -= 9;
        }
        else if (num >= 5)
        {
            roman[i++] = 'V';
            num -= 5;
            horizontal = false;
        }
        else if (num >= 4)
        {
            roman[i++] = 'I';
            roman[i++] = 'V';
            num -= 4;
            horizontal = false;
        }
        else
        {
            roman[i++] = 'I';
            num--;
        }
    }
    roman[i] = 0;

    int l, r; // left and right index

    if (i % 2) // if length is odd
    {
        if (!is_vertically_symmetric(roman[i / 2])) // check middle letter
            vertical = false;
        else
        {
            l = i / 2 - 1;
            r = i / 2 + 1;
        }
    }
    else
    {
        l = i / 2 - 1;
        r = l + 1;
    }

    while (vertical && r < i && l >= 0)
    {
        if (roman[l] != roman[r] || !is_vertically_symmetric(roman[l]))
            vertical = false;

        l--, r++;
    }

    if (horizontal && vertical)
        return '+';
    else if (horizontal)
        return '-';
    else if (vertical)
        return '|';

    return '?';
}

int main()
{
    int t, num;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &num);
        printf("%c\n", get_symmetry(num));
    }

    return 0;
}