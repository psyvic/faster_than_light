/*
** game_2.c for game_2 in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu Apr 13 18:28:03 2017 AIZPURUA Victor Hugo
** Last update Thu Apr 13 21:52:43 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include "ftl.h"
#include <time.h>

void     jump(t_matrix *matrix)
{
  my_putstr("Initiating Time-Space Warp from Sector ");
  my_put_nbr(matrix->ship->navigation_tools->sector);
  my_putstr(" to Sector ");
  matrix->ship->navigation_tools->sector ++;
  my_put_nbr(matrix->ship->navigation_tools->sector);
  my_putstr("!\nYou have landed safely on Sector ");
  my_put_nbr(matrix->ship->navigation_tools->sector);
  my_putstr("!\n");
}

int        random_number()
{
  int      random;

  srand (time (NULL));
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
  else if ((random > 33) && (random <= 66))
    freight->item = my_strdup("energy");
  else
    freight->item = my_strdup("energy");
  return (freight);
}

void        detect(t_matrix *matrix)
{
  int       i;

  i = 0;
  my_putstr("Locating ship remnants in space...\n10 remnants located!\n");
  my_putstr("Recovering remnats...");
  while (i < 10)
    {
      create_freight(matrix);
      add_freight_to_container(matrix->ship, create_freight(matrix));
      i = i + 1;
    }
  my_putstr("Remnants recovery completed! You have now ");
  my_put_nbr(matrix->ship->container->nb_elem);
  my_putstr(" remmants\n");
}

t_alien     *create_alien(t_matrix *matrix);
{
  t_alien   *alien;

  alien = malloc(sizeof(t_alien));
  matrix->alien = alien;
  alien->life = 10;
  alien->damage = 10;
  my_putstr("A meanie alien has appeared!!!!!");
}
