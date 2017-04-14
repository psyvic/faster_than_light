/*
** game_2.c for game_2 in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu Apr 13 18:28:03 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 00:42:21 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "ftl.h"

void            jump(t_matrix *matrix)
{
  int           random;

  if (matrix->alien != NULL)
    my_putstr("Time-Space Hyper-Jump disabled. Start attacking you woos!\n");
  else if (matrix->ship->ftl_drive->system_state == NULL)
    my_putstr("\033[31mReactor system damaged! Need reparation!\033[0m\n");
  else
    {
  my_putstr("\033[34mInitiating Time-Space Hyper-Jump from Sector ");
  my_put_nbr(matrix->ship->navigation_tools->sector);
  my_putstr(" to Sector");
  suspense();
  matrix->ship->navigation_tools->sector ++;
  my_put_nbr(matrix->ship->navigation_tools->sector);
  my_putstr("!\n\033[32mYou have landed on Sector ");
  my_put_nbr(matrix->ship->navigation_tools->sector);
  my_putstr("!\n\033[0m");
  matrix->ship->ftl_drive->energy = matrix->ship->ftl_drive->energy - 1;
  matrix->bonus = 1;
  endgame(matrix);
  if ((random = random_number()) <= 30)
    create_alien(matrix);
    }
}

int             random_number()
{
  int           random;

  random = (rand()% 100) + 1;
  return (random);
}

t_freight       *create_freight()
{
  int           random;
  t_freight	*freight;

  freight = malloc(sizeof(t_freight));
  if ((random = random_number()) <= 70)
      freight->item = my_strdup("scrap");
  else if ((random = random_number()) <= 33)
      freight->item = my_strdup("attackbonus");
  else if ((random > 33) && (random <= 66))
      freight->item = my_strdup("evadebonus");
  else if ((random > 66) && (random <= 99))
      freight->item = my_strdup("energy");
  else
      freight->item = my_strdup("scrap");
  return (freight);
}

void            detect(t_matrix *matrix)
{
  int           i;

  i = 0;
  if (matrix->alien != NULL)
    my_putstr("Detect disabled. Start attacking you woos!\n");
  else if (matrix->ship->navigation_tools->system_state == NULL)
    my_putstr("\033[31mNavigation system damaged! Need reparation\033[0m!\n");
  else if (matrix->bonus == 0)
    my_putstr("There are no more remnants on this sector\n");
  else
    {
      my_putstr("\033[34mLocating ship remnants in space");
      suspense();
      my_putstr("10 remnants located!\nRecovering remnats");
      suspense();
      while (i < 10)
	{
	  add_freight_to_container(matrix->ship, create_freight(matrix));
	  i = i + 1;
	}
      my_putstr("Remnants recovery completed! You have now ");
      my_put_nbr(matrix->ship->container->nb_elem);
      my_putstr(" remmants\n\033[0");
      matrix->bonus = 0;
    }
}

t_alien         *create_alien(t_matrix *matrix)
{
  t_alien       *alien;

  alien = malloc(sizeof(t_alien));
  if (alien == NULL)
    {
      my_putstr("Error detecting hostile life forms\n");
      return (NULL);
    }
  sleep(2);
  prob_alien(matrix, alien);
  return (alien);
}
