/*
** game_5.c for game_5 in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Fri Apr 14 15:37:55 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 00:56:59 2017 AIZPURUA Victor Hugo
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

void    suspense()
{
  my_putstr(".");
  sleep(1);
  my_putstr(".");
  sleep(1);
  my_putstr(".");
  sleep(1);
  my_putstr("\n");
}

void    bonus_prob(t_ship *ship, t_freight *temp)
{
  while (temp != NULL)
    {
      if (my_strcmp(temp->item, "attackbonus") == 0)
	{
	  ship->weapon->damage = ship->weapon->damage + 5;
	  my_putstr("\033[36m     Attack Bonus (+5)\033[0m");
	}
      else if (my_strcmp(temp->item, "evadebonus\033[0m") == 0)
	{
	  ship->navigation_tools->evade = ship->navigation_tools->evade + 3;
	  my_putstr("\033[34m     Evade Bonus (+3)\033[0m");
	}
      else if (my_strcmp(temp->item, "energy") == 0)
	{
	  ship->ftl_drive->energy = ship->ftl_drive->energy + 1;
	  my_putstr("\033[32m     Energy Bonus (+1)\033[0m");
	}
      else
	my_putstr("\033[31m       Nothing sucker!\033[0m");
      sleep(1);
      del_freight_to_container(ship, temp);
      temp = temp->next;
    }
}

void    matrix_var(t_matrix *matrix)
{
  matrix->ship = NULL;
  matrix->alien = NULL;
  matrix->bonus = 1;
  matrix->quit = 0;
  matrix->temp_life = 20;
  matrix->temp_damage = 10;
  matrix->nb_alien = 0;
}

void    help()
{
  my_putstr("\033[34m");
  my_putstr("##############################################################\n");
  my_putstr("#                                                            #\n");
  my_putstr("#     attack                         jump                    #\n");
  my_putstr("#                    detect                    get_bonus     #\n");
  my_putstr("#     repair_system           control_system                 #\n");
  my_putstr("#                     stat                        finish     #\n");
  my_putstr("#                                                            #\n");
  my_putstr("##############################################################\n");
  my_putstr("\033[0m");
}
