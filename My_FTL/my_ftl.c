/*
** my_ftl.c for my_ftl in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Mon Apr 10 10:45:31 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 09:57:30 2017 AIZPURUA Victor Hugo
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "ftl.h"

int     main()
{
  t_matrix *matrix;

  srand (time (NULL));
  my_putstr("\033[H\033[2J");
  spaceship();
  sleep(2);
  matrix = create_matrix();
  sleep(4);
  while (matrix->quit != 1)
    {
      my_putstr("\033[H\033[2J");
      interface(matrix);
      system_command(matrix);
      sleep(3);
    }
  the_end();
  return (0);
}
