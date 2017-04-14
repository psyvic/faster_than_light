/*
** game_3.c for game_3 in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu Apr 13 21:58:01 2017 AIZPURUA Victor Hugo
** Last update Fri Apr 14 14:22:39 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include "ftl.h"
#include <time.h>

void    attack(t_matrix *matrix)
{
  int   random;
  
  if (matrix->alien == NULL)
    my_putstr("Theres no one to attack you silly billy!\n");
  else if (matrix->ship->weapon->system_state == NULL)
    my_putstr("Weapon system damaged! Need reparation before use!\n");
  else
    {
      my_putstr("Attacking the big old meanie! You hit him for ");
      my_put_nbr(matrix->ship->weapon->damage);
      matrix->alien->life = matrix->alien->life - matrix->ship->weapon->damage;
      my_putstr(" points of damage!\n");
      if (matrix->alien->life <= 0)
	delete_alien(matrix);
      else if ((random = random_number()) <= matrix->ship->navigation_tools->evade)
	my_putstr("The meanie tries to attack you but he misses!\n");
      else
	{
	  my_putstr("Now the meanie attacks you for ");
	  my_put_nbr(matrix->alien->damage);
	  matrix->ship->hull = matrix->ship->hull - matrix->alien->damage;
	  my_putstr(" points of damage!\n");
	  system_break(matrix);
	  endgame(matrix);
	}
    }
}

void    system_break(t_matrix *matrix)
{
  int   random;
  
  if ((random = random_number()) <= 100)
    {
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
}

void    delete_alien(t_matrix *matrix)
{
  int   random;
  
  my_putstr("The enemy has been defeated!!! Disengaging attack mode\n");
  my_putstr("Restoring all systems\n");
  matrix->alien = NULL;
  free(matrix->alien);
  if ((random = random_number()) <= 50)
    {
      my_putstr("Due to the harsh combat, you loose 1 point of energy\n");
      matrix->ship->ftl_drive->energy = matrix->ship->ftl_drive->energy - 1;
    }
}

int     random_number_three()
{
  int   random;

  random = (rand()% 3) + 1;
  return (random);
}

void   endgame(t_matrix *matrix)
{
  if (matrix->ship->hull <= 0)
    {
      my_putstr("Your ship was destroyed! You are a shame to the galaxy!\n");
      my_putstr("The aliens devoured the human race! Have fun in HELL!\n");
      exit_game(matrix);
      the_end();
    }
  else if (matrix->ship->navigation_tools->sector == 10)
    {
      my_putstr("You have reached sector 10 safe and sound! You rock!\n");
      my_putstr("You saved mankind! Go have a beer and get laid!\n");
      exit_game(matrix);
      the_end();
    }
}
