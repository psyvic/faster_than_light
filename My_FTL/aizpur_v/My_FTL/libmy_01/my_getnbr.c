/*
** my_getbnr.c for my_getnbr in /home/vic/Desktop/piscine/C/C_jour_5/aizpur_v
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Fri Mar 24 16:13:23 2017 AIZPURUA Victor Hugo
** Last update Sat Mar 25 00:54:36 2017 AIZPURUA Victor Hugo
*/

#include <stdio.h>
void	my_putchar(char c);
int	my_getnbr(char *str)
{
  int	a;
  int	i;
  int puissance;
  int boucle_puissance;
  int temp;
  int temp_neg;
  int neg;
  int nombre_chiffres;
  
  a = 0;
  i = 0;
  temp = 0;
  temp_neg = 1;
  neg = 0;
  nombre_chiffres = 0;
  boucle_puissance = 0;
  puissance = 1;
  while ((str[neg] == '-') || (str[neg] == '+'))
    {
      if (str[neg] == '-')
        temp_neg = temp_neg  + 1;
      neg = neg + 1;
    }
  i = neg;
  while ((str[i] >= '0') && (str[i] <= '9'))
    {
      nombre_chiffres = nombre_chiffres + 1;
      i = i + 1;
    }
  i = neg;
  while (boucle_puissance < (nombre_chiffres - 1))
    {
      puissance = puissance * 10;
      boucle_puissance = boucle_puissance + 1;
    }
  boucle_puissance = 0;
  i  = neg;
  while (boucle_puissance < nombre_chiffres)
    {
      a = str[i] - 48;
      temp = temp + (a * puissance);
      puissance = puissance / 10;
      i = i + 1;
      boucle_puissance = boucle_puissance + 1;
    }
  printf("boucle puissance %d\n", boucle_puissance);
  if ((temp_neg % 2) == 0)
    temp = -temp;
  return (temp);
}

