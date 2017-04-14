/*
** game_7.c for game_7 in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Fri Apr 14 23:55:38 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 01:34:29 2017 AIZPURUA Victor Hugo
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "ftl.h"

void    sector(t_matrix *matrix)
{
  my_putstr("\033[32m");
  my_putstr("##############################################################\n");
  my_putstr("#                                                            #\n");
  my_putstr("#                       SECTOR N. ");
  my_put_nbr(matrix->ship->navigation_tools->sector);
  my_putstr("                          #\n");
  my_putstr("#                                                            #\n");
  my_putstr("\033[34m");
}

void    hyperspace()
{
  int           i;
  int           s;
  int           max;
  int           t;

  max = t = 0;
  s = 1;
  while (t < 2000)
    {
      t = t + 1;
      i = 0;
      while (i < max)
	i = hyper(i);
      max = max + s;
      if (max >= 50)
	s = -1;
      if (max < 0)
	s = 1;
      my_putstr("\033[33m*");
      i = 0;
      while (i < 80 - max)
	i = space(i);
    }
}

int     hyper(int i)
{
  my_putstr(" ");
  i = i + 1;
  return (i);
}

int     space(int i)
{
  my_putstr("\033[33m   ");
  i = i + 1;
  return (i);
}
