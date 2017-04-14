/*
** game_4.c for game_4 in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Fri Apr 14 11:50:47 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 00:34:15 2017 AIZPURUA Victor Hugo
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "ftl.h"

void             del_prob(t_ship *ship, t_freight *freight)
{
  if (ship->container->first == freight && ship->container->last != freight)
    {
      freight->next->prev = NULL;
      ship->container->first = freight->next;
    }
  else if (ship->container->last == freight &&
	   ship->container->first != freight)
    {
      freight->prev->next = NULL;
      ship->container->last = freight->prev;
    }
  else if ((ship->container->first == freight) &&
	   (ship->container->last == freight))
    {
      ship->container->first = NULL;
      ship->container->last = NULL;
    }
  else
    {
      freight->next->prev = freight->prev;
      freight->prev->next = freight->next;
    }
}

void           finish(t_matrix *matrix)
{
  my_putstr("Exiting game\n");
  matrix->quit = 1;
}

void           the_end()
{
my_putstr("Thank you for playing!\n");
}

void           spaceship()
{
  my_putstr("\033[31m");
  my_putstr("##########################################################\n");
  my_putstr("#                                                        #\n");
  my_putstr("#                         FTL DRIVE                      #\n");
  my_putstr("#                                                        #\n");
  my_putstr("##########################################################\n");
  my_putstr("\033[33m");
  my_putstr("[By Victor Hugo]        ___\\____\n");
  my_putstr("[ver. 1.0]             0)__/... \\_\n");
  my_putstr("                      00)__)  .___)\n");
  my_putstr("     ___              _0__)\\_/ OOO/`':.\n");
  my_putstr("    0)_^'-._    __..-'`:  \\ | / ::  \\ o`:\n");
  my_putstr("    0)_\\ \\~_..-': \\ \\   :  \\|/   ::  |   \\\n");
  my_putstr("        \\ /      : | |  :    :  ::  /  _./>-\n");
  my_putstr("         (__ ))): /_/____.))_____//.-'`\n");
  my_putstr("          7 7~~'\\\"\"\"           7 7\n");
  my_putstr("          L_L                 / /\n");
  my_putstr("         0) ^'-.__            |_|\n");
  my_putstr("         0)__.-'             0) ^'-.__\n");
  my_putstr("                             0)__.-'\n\033[0m");
}

void           prob_alien(t_matrix *matrix, t_alien *alien)
{
  matrix->alien = alien;
  if (matrix->nb_alien == 0)
    {
      alien->life = 20;
      alien->damage = 10;
      matrix->nb_alien = matrix->nb_alien + 1;
    }
  else
    {
      alien->life = (matrix->temp_life * 1.5);
      alien->damage = (matrix->temp_damage * 1.5);
      matrix->temp_life = alien->life;
      matrix->temp_damage = alien->damage;
    }
  my_putstr("\033[31mALLERT! CODE RED! Hostile life form detected!\n");
  sleep(1);
  my_putstr("All systems disabled! Engaging attack mode!\n");
  sleep(1);
  my_putstr("A meanie alien has appeared!!!!!\n\033[0m");
}
