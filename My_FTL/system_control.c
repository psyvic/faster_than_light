/*
** system_control.c for system_control in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Tue Apr 11 11:27:05 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 00:51:55 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "ftl.h"

void	ftl_drive_system_check(t_ship *ship)
{
  my_putstr("\033[33mVeryfying reactor");
  suspense();
  if (ship->ftl_drive->system_state != NULL)
    my_putstr("\033[34mReactor OK BI ATCH...\n");
  else
    my_putstr("\033[31mThe reactor is fucked up...\n");
}

void	navigation_tools_system_check(t_ship *ship)
{
  my_putstr("\033[33mVeryfying navigation tools");
  suspense();
  if (ship->navigation_tools->system_state != NULL)
    my_putstr("\033[34mNavigation tools OK BI ATCH...\n");
  else
    my_putstr("\033[31mThe navigation system is fucked up...\n");
}

void	weapon_system_check(t_ship *ship)
{
  my_putstr("\033[33mVeryfying weapons system");
  suspense();
  if (ship->weapon->system_state != NULL)
    my_putstr("\033[34mWeapons system OK BI ATCH...\n");
  else
    my_putstr("\033[31The weapons system is fucked up...\n");
}

void	system_control(t_ship *ship)
{
  ftl_drive_system_check(ship);
  navigation_tools_system_check(ship);
  weapon_system_check(ship);
}
