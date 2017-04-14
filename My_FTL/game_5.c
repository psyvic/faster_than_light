/*
** game_5.c for game_5 in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Fri Apr 14 15:37:55 2017 AIZPURUA Victor Hugo
** Last update Fri Apr 14 17:49:30 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "ftl.h"

void    random_break(t_matrix *matrix)
{
  int   random;

  if ((random = random_number_three()) == 1)
    {
      my_putstr("Critical error! The weapon system has been damaged!\n");
      free (matrix->ship->weapon->system_state);
      matrix->ship->weapon->system_state = NULL;
    }
  else if (random == 2)
    {
      my_putstr("Critical error! The navigation tools system");
      my_putstr(" has been damaged!\n");
      free (matrix->ship->navigation_tools->system_state);
      matrix->ship->navigation_tools->system_state = NULL;
    }
  else
    {
      my_putstr("Critical error! The reactor system has been damaged!\n");
      free (matrix->ship->ftl_drive->system_state);
      matrix->ship->ftl_drive->system_state = NULL;
    }
}
