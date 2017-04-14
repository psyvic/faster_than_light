/*
** air_shed.c for air_shed in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Mon Apr 10 10:00:18 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 01:33:37 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "ftl.h"

t_matrix                 *create_matrix()
{
  t_matrix               *matrix;
  t_ship                 *ship;

  my_putstr("CREATING GAME PARAMETERS...\n");
  matrix = malloc(sizeof(t_matrix));
  if (matrix == NULL)
    {
      my_putstr("Error creating game parameters\n");
      return (NULL);
    }
  matrix_var(matrix);
  my_putstr("Game mechanics created succesfully!\n");
  ship = create_ship(matrix);
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container_to_ship(ship);
  return (matrix);
}

t_ship                 *create_ship(t_matrix *matrix)
{
  t_ship               *ship;

  my_putstr("Building ship");
  suspense();
  ship = malloc(sizeof(t_ship));
  if (ship == NULL)
    {
      my_putstr("The ship wasnt built due to missing components\n");
      return (NULL);
    }
  matrix->ship = ship;
  ship->hull = 50;
  ship->weapon = NULL;
  ship->ftl_drive = NULL;
  my_putstr("Ship upgrade completed!\n");
  return (ship);
}

int                    add_weapon_to_ship(t_ship *ship)
{
  t_weapon             *weapon;

  my_putstr("Adding weapons");
  suspense();
  weapon = malloc(sizeof(t_weapon));
  if (weapon == NULL)
    {
      my_putstr("Your ship exploded its ass off trying to load weapons!\n");
      return (0);
    }
  ship->weapon = weapon;
  weapon->damage = 10;
  weapon->system_state = my_strdup("online");
  my_putstr("Weapons loaded succesfully!\n");
  return (1);
}

int                    add_ftl_drive_to_ship(t_ship *ship)
{
  t_ftl_drive          *ftl_drive;

  my_putstr("Adding reactor");
  suspense();
  if ((ftl_drive = malloc(sizeof(t_ftl_drive))) == NULL)
    {
      my_putstr("Your ship exploded its ass off trying to add the reactor!\n");
      return (0);
    }
  ship->ftl_drive = ftl_drive;
  ftl_drive->energy = 10;
  ftl_drive->system_state = my_strdup("online");
  my_putstr("Reactor added succesfully!\n");
  return (1);
}

int                    add_navigation_tools_to_ship(t_ship *ship)
{
  t_navigation_tools   *navigation_tools;

  my_putstr("Adding navigation tools");
  suspense();
  navigation_tools = malloc(sizeof(t_navigation_tools));
  if (navigation_tools == NULL)
    {
      my_putstr("Your ship exploded trying to add the navigation tools!\n");
      return (0);
    }
  ship->navigation_tools = navigation_tools;
  navigation_tools->sector = 0;
  navigation_tools->evade = 25;
  navigation_tools->system_state = my_strdup("online");
  my_putstr("Navigation tools added succesfully!\n");
  return (1);
}
