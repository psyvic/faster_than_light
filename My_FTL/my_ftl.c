/*
** my_ftl.c for my_ftl in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Mon Apr 10 10:45:31 2017 AIZPURUA Victor Hugo
** Last update Fri Apr 14 14:18:26 2017 AIZPURUA Victor Hugo
*/

#include "ftl.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int     main()
{
  t_ship *ship;
  t_matrix *matrix;

  srand (time (NULL));

  matrix = create_matrix();
  ship = create_ship(matrix);
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container_to_ship(ship);
  create_alien(matrix);
  while ((matrix->ship->hull > 0 && matrix->ship->ftl_drive->energy > 0) ||
	 matrix->ship->navigation_tools->sector < 10 || matrix->quit != 1)
    system_command(matrix);
  the_end();
  return (0);
}
