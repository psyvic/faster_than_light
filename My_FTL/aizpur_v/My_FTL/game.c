/*
** game.c for game in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu Apr 13 14:31:14 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 10:49:42 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "ftl.h"

static const t_demand	g_demand[] = {
  {"attack", &attack},
  {"detect", &detect},
  {"jump", &jump},
  {"get_bonus", &get_bonus_main},
  {"repair_system", &system_repair_main},
  {"control_system", &check_systems},
  {"stat", &check_stats},
  {"finish", &finish},
  {NULL, NULL}
};

void         check_systems(t_matrix *matrix)
{
  system_control(matrix->ship);
}

void    system_repair_main(t_matrix *matrix)
{
  my_putstr("Entering the System Repair Unit(SRU):\n");
  system_repair(matrix->ship);
}

void	     get_bonus_main(t_matrix *matrix)
{
  if (matrix->alien != NULL)
    my_putstr("Get bonus disabled. Start attacking you woos!\n");
  else if (matrix->ship->container->nb_elem == 0)
    my_putstr("There are no elements in your container to make a bonus\n");
  else
    get_bonus(matrix->ship);
}

void         check_stats(t_matrix *matrix)
{
  if (matrix->alien != NULL)
    my_putstr("Stat checks disabled. Start attacking you woos!\n");
  else
    {
  my_putstr ("Checking ship stats:\nHull Proton Shield: ");
  my_put_nbr(matrix->ship->hull);
  my_putstr("\nTime-Space Hyper-Jump Energy: ");
  my_put_nbr(matrix->ship->ftl_drive->energy);
  my_putstr("\nMacro Cromosomic Void Energy Cannons: ");
  my_put_nbr(matrix->ship->weapon->damage);
  my_putstr("\nInsta-Evade Conflict Turbines: ");
  my_put_nbr(matrix->ship->navigation_tools->evade);
  my_putstr("\nMultiverse Navigation UPS System: Sector ");
  my_put_nbr(matrix->ship->navigation_tools->sector);
  my_putstr("\n");
    }
}

void         system_command(t_matrix *matrix)
{
  char       *command;
  int        i;
  int        bool;

  bool = 0;
  while (bool == 0)
    {
      i = 0;
      my_putstr("System_command~> ");
      command = readline();
      if (command == NULL)
	my_putstr("[SYSTEM_FAILURE] Command Reader blocked! \n");
      else if (my_strcmp(command, "exit") == 0)
	bool = 1;
      else
	{
	  while (g_demand[i].ordre != NULL)
	    {
	      if (my_strcmp(command, g_demand[i].ordre) == 0)
		{
		  g_demand[i].f(matrix);
		  bool = 1;
		}
	      i = i + 1;
	    }
	  if (bool == 0)
	    my_putstr("[SYSTEM_FAILURE] Unknown command! \n");
	}
      free(command);
    }
}
