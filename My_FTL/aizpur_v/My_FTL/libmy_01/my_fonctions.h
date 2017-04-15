/*
** my_fonctions.h for my_fonctions in /home/vic/Desktop/piscine/C/libmy_01
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Fri Mar 31 18:20:12 2017 AIZPURUA Victor Hugo
** Last update Fri Mar 31 18:29:44 2017 AIZPURUA Victor Hugo
*/

#include <unistd.h>

void    my_putchar(char c)
{
  write(1, &c, 1);
}

void    my_putstr(char *str)
{

  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}

char *my_strcpy(char *dest, char *src)
{
  int i;

  i = 0;
  while(src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

int  my_strcmp(char *s1, char *s2)
{
  while ((*s1 != '\0') || (*s2 != '\0'))
    {
      if (*s1 > *s2)
	{
	  return (1);
	}
      else if (*s1 < *s2)
	{
	  return (-1);
	}
      else if ((*s1 == *s2) && (*s1 == '\0') && (*s2 == '\0'))
	{
	  return (0);
	}
      s1 = s1 + 1;
      s2 = s2 + 1;
    }
  return (*s1 - *s2);
}

char    *my_strncat(char *dest, char *src, int nb)
{
  int   j;
  int   i;

  i = 0;
  j = 0;
  while (dest[i])
    i = i + 1;
  while (src[j] && j < nb)
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = '\0';
  return (dest);
}

int  my_strncmp(char *s1, char *s2, int n)
{
  int i;

  i = 0;
  while (i <= n)
    {
      if (*s1 > *s2)
	return (1);
      else if (*s1 < *s2)
	return (-1);
      else if ((*s1 == *s2) && (*s1 == '\0') && (*s2 == '\0'))
	return (0);
      s1 = s1 + 1;
      s2 = s2 + 1;
      i = i + 1;
    }
  return (*s1 - *s2);
}

char     *my_strstr(char *str, char *to_find)
{
  int    i;
  int    j;
  int    start;

  i = 0;
  j = 0;
  start = 0;
  while(str[i] && to_find[j])
    {
      if(str[i] == to_find[j])
	{
	  if(j == 0)
	    start = i;
	  j = j + 1;
	}
      else
	j = 0;
      i = i + 1;
    }
  if(to_find[j] == '\0')
    return (&str[start]);
  else
    return (0);
}

void    my_swap(int *a, int *b)
{
  int   temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

char    my_isneg(int n)
{
  if (n  < 0)
    {
      return 0;
    }
  else
    {
      return 1;
    }
}

int     my_nb_len(int n)
{
  int   num_chiffres;

  num_chiffres = 0;
  if (n < 0)
    n = -n;
  if (n > 0)
    {
      while (n != 0)
	{
	  n = n/10;
	  num_chiffres = num_chiffres + 1;
	}
    }
  else
    num_chiffres = 1;
  return (num_chiffres);
}

void    my_put_nbr(int n)
{
  int   puissance;
  int   index;
  int   temp;

  puissance = index = 1;
  temp = 0;
  if (n < 0)
    {
      my_putchar('-');
      n = n * (-1);
    }
  if ( n == -2147483648)
    my_putstr("2147483648");
  while (index < my_nb_len(n))
    {
      puissance = puissance * 10;
      index = index + 1;
    }
  while (index > 0)
    {
      temp = (n / puissance) % 10;
      my_putchar('0' + temp);
      index = index - 1;
      puissance = puissance / 10;
    }
}

int     my_getnbr(char *str)
{
  int   i;
  int   temp;
  int   temp_neg;

  i = 0;
  temp = 0;
  temp_neg = 1;
  while ((str[i] == '-') || (str[i] == '+'))
    {
      if (str[i] == '-')
	temp_neg = temp_neg * -1;
      i = i + 1;
    }
  while ((str[i] >= '0') && (str[i] <= '9'))
    {
      temp = (temp * 10) + (str[i] - 48);
      i = i + 1;
    }
  return (temp * temp_neg);
}
