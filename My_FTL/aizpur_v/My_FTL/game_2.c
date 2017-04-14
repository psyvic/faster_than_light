/*
** game_2.c for game_2 in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu Apr 13 18:28:03 2017 AIZPURUA Victor Hugo
** Last update Fri Apr 14 09:51:18 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include "ftl.h"
#include <time.h>

void     jump(t_matrix *matrix)
{
  int    random;
  
  if (matrix->alien != NULL)
    my_putstr("Time-Space Hyper-Jump disabled. Start attacking you woos!\n");
  else if (matrix->ship->ftl_drive->system_state == NULL)
    my_putstr("Reactor system damaged! Need reparation before jump!\n");
  else
    {
  my_putstr("Initiating Time-Space Hyper-Jump from Sector ");
  my_put_nbr(matrix->ship->navigation_tools->sector);
  my_putstr(" to Sector ");
  matrix->ship->navigation_tools->sector ++;
  my_put_nbr(matrix->ship->navigation_tools->sector);
  my_putstr("!\nYou have landed on Sector ");
  my_put_nbr(matrix->ship->navigation_tools->sector);
  my_putstr("!\n");
  matrix->ship->ftl_drive->energy = matrix->ship->ftl_drive->energy - 1;
  if ((random = random_number()) <= 30)
    create_alien(matrix);
    }
  system_command(matrix);
}

int        random_number()
{
  int      random;

  random = (rand()% 100) + 1;
  return (random);
}


t_freight   *create_freight()
{
  int       random;
  t_freight *freight;

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

void        detect(t_matrix *matrix)
{
  int       i;

  i = 0;
  if (matrix->alien != NULL)
    my_putstr("Detect disabled. Start attacking you woos!\n");
  else if (matrix->ship->navigation_tools->system_state == NULL)
    my_putstr("Navigation system damaged! Need reparation before detect!\n");
  else
    {
      my_putstr("Locating ship remnants in space...\n10 remnants located!\n");
      my_putstr("Recovering remnats...");
      while (i < 10)
	{
	  add_freight_to_container(matrix->ship, create_freight(matrix));
	  i = i + 1;
	}
      my_putstr("Remnants recovery completed! You have now ");
      my_put_nbr(matrix->ship->container->nb_elem);
      my_putstr(" remmants\n");
    }
  system_command(matrix);
}

t_alien     *create_alien(t_matrix *matrix)
{
  t_alien   *alien;

  alien = malloc(sizeof(t_alien));
  if (alien == NULL)
    {
      my_putstr("Error detecting hostile life forms");
      return(NULL);
    }
  matrix->alien = alien;
  matrix->combat = 1;
  alien->life = 20;
  alien->damage = 10;
  my_putstr("ALLERT! CODE RED! Hostile life form detected!\nAll systems");
  my_putstr(" disabled! Engaging attack mode!\n");
  my_putstr("A meanie alien has appeared!!!!!\n");
  return (alien);
}
