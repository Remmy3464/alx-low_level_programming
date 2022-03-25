#include "main.h"
/**
* _strlen - returns the lenght of a string
* @s: pointer to s
*
* Return: 0 on success
*
*/
int _strlen(char *s)
{
int count = 0;

if (s != '\0')
{
while (*(s + count) != '\0')
count++;
}
return (count);
}
/**
* rev_string - reverses a string
* @s: pointer to string
*
* Return: none
*
*/
void rev_string(char *s)
{
int i, count;
char swap;

if (*s != '\0')
{
count = 0;
while (*(s + count) != '\0')
{
count++;
}
i = 0;
count = count - 1;
while (i <= count)
{
swap = *(s + i);     /* swap = first */
*(s + i) = *(s + count); /* first = last */
*(s + count) = swap; /* last = swap (first) */
i++;
count--;
}
}
}
/**
* _carry - set r[j] and return carry
* @l1: length of n1
* @l2: length of n2
* @n1: string n1
* @n2: string n2
* @r: buffer for new string
* @j: index for buffer
* @carry: carry
*
* Return: carry
*/
int _carry(int l1, int l2, char *n1, char *n2, char *r, int j, int carry)
{
int sum, d1, d2;

sum = 0;
if (l1 >= 0)
d1 = n1[l1] - '0';
else
d1 = 0;
if (l2 >= 0)
d2 = n2[l2] - '0';
else
d2 = 0;
sum = d1 + d2 + carry;
if (sum >= 10)
{
r[j] = sum % 10 + '0';
carry = 1;
}
else
{
r[j] = sum + '0';
carry = 0;
}
return (carry);
}

/**
* infinite_add - adds two numbers
* @n1: string with number 1
* @n2: string with number 2
* @r: buffer for new string of sum of n1 and n2
* @size_r: size of a buffer
*
* Return: pointer to buffer
*/
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
int l1, l2, j;
int carry;
l1 = _strlen(n1);
l2 = _strlen(n2);
if (l1 > size_r - 1 || l2 > size_r - 1)
return (0);
carry = 0;
j = 0;
l1--;
l2--;
while (l1 >= 0 || l2 >= 0)
{
carry = _carry(l1, l2, n1, n2, r, j, carry);
l1--;
l2--;
j++;
}
if (carry == 1)
{
r[j] = carry + '0';
r[j + 1] = '\0';
if (_strlen(r) + 1 > size_r) /* _strlen(r) + '\0' */
return (0);
}
else
r[j] = '\0';
rev_string(r);
return (r);
}
