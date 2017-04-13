/*
** game.c for game in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Thu Apr 13 14:31:14 2017 AIZPURUA Victor Hugo
** Last update Thu Apr 13 17:29:37 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include "ftl.h"

static const t_demand g_demand[] = {
  /*  {"attack", &},
  {"detect", &},
  {"jump", &},
  {"get_bonus", &},
  {"repair_system", &},*/
  {"control_system", &check_systems},
  {"stat", &check_stats},
  {NULL, NULL}
};

void    check_systems(t_matrix *matrix)
{
  my_putstr ("Checking ship systems status:\n Reactor FTL Drive system: ");
  my_putstr(matrix->ship->weapon->system_state);
  my_putstr ("\n Weapons system: ");
  my_putstr(matrix->ship->ftl_drive->system_state);
  my_putstr ("\n Navigation tools system: ");
  my_putstr(matrix->ship->navigation_tools->system_state);
  my_putstr("\n");
}
void    check_stats(t_matrix *matrix)
{
  my_putstr ("Checking ship stats:\nHull Proton Shield: ");
  my_put_nbr(matrix->ship->hull);
  my_putstr("\nTime-Space Warp-Energy: ");
  my_put_nbr(matrix->ship->ftl_drive->energy);
  my_putstr("\nMacro Cromosomic Void Energy Cannons: ");
  my_put_nbr(matrix->ship->weapon->damage);
  my_putstr("\nInsta-Evade Conflict Turbines: ");
  my_put_nbr(matrix->ship->navigation_tools->evade);
  my_putstr("\nMultiverse Navigation UPS System: Sector ");
  my_put_nbr(matrix->ship->navigation_tools->sector);
  my_putstr("\n");
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
