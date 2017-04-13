/*
** system_repair.c for system_repair in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Tue Apr 11 12:27:12 2017 AIZPURUA Victor Hugo
** Last update Thu Apr 13 13:23:53 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include "ftl.h"

void         ftl_drive_system_repair(t_ship *ship)
{
  my_putstr("Reparing reactor...\n");
  free(ship->ftl_drive->system_state);
  if ((ship->ftl_drive->system_state = my_strdup("online")))
    my_putstr("The reactor has been repaired!\n");
  else
    my_putstr("Reactor reparations failed!\n");
  
}

void         navigation_tools_system_repair(t_ship *ship)
{
  my_putstr("Reparing navigation tools...\n");
  free(ship->navigation_tools->system_state);
  if ((ship->navigation_tools->system_state = my_strdup("online")))
    my_putstr("The navigation tools have been repaired!\n");
  else
    my_putstr("Navigation tools reparations failed!\n");
}

void         weapon_system_repair(t_ship *ship)
{
  my_putstr("Reparing weapons system...\n");
  free(ship->weapon->system_state);
  if ((ship->weapon->system_state = my_strdup("online")))
    my_putstr("The weapons system has been repaired!\n");
  else
    my_putstr("Weapons system reparations failed!\n");
}

static const t_repair_command g_repair_command[] = {
  {"ftl_drive", &ftl_drive_system_repair},
  {"navigation_tools", &navigation_tools_system_repair},
  {"weapon", &weapon_system_repair},
  {NULL, NULL}
};

void         system_repair(t_ship *ship)
{
  char       *command;
  int        i;
  int        bool;

  bool = 0;
  while (bool == 0)
    {
      i = 0;
      my_putstr("Repair_system~> ");
      command = readline();
      if (command == NULL)
	my_putstr("[SYSTEM_FAILURE] Command Reader blocked! \n");
      else if (my_strcmp(command, "exit") == 0)
	bool = 1;
      else
	{
	  while (g_repair_command[i].ordre != NULL)
	    {
	      if (my_strcmp(command, g_repair_command[i].ordre) == 0)
		{
		  g_repair_command[i].f(ship);
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

char         *readline(void)
{
  ssize_t    ret;
  char       *buff;

  if ((buff = malloc((50 + 1) * sizeof(char))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  free(buff);
  return (NULL);
}
