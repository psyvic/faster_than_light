/*
** game_6.c for game_6 in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Fri Apr 14 21:31:17 2017 AIZPURUA Victor Hugo
** Last update Sat Apr 15 00:05:26 2017 AIZPURUA Victor Hugo
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "ftl.h"

void    interface(t_matrix *matrix)
{
  spaceship();
  stats(matrix);
  stats_two(matrix);
  monster_stats(matrix);
  monsterface(matrix);
  sector(matrix);
  help();
}

void    stats(t_matrix *matrix)
{
  int   hearts;
  int   i;

  hearts = (matrix->ship->hull / 2);
  i = 0;
  my_putstr("\nHULL SHIELD: ");
  while (i < hearts)
    {
      my_putstr("\033[31m♥");
      i = i + 1;
    }
  my_putstr("\033[0m\n");
  hearts = matrix->ship->ftl_drive->energy;
  i = 0;
  my_putstr("ENERGY: ");
  while (i < hearts)
    {
      my_putstr("\033[32m►");
      i = i + 1;
    }
  my_putstr("\033[0m");
}

void    stats_two(t_matrix *matrix)
{
  int   hearts;
  int   i;

  hearts = (matrix->ship->weapon->damage / 2);
  i = 0;
  my_putstr("\nATTACK: ");
  while (i < hearts)
    {
      my_putstr("\033[33m█ ");
      i = i + 1;
    }
  my_putstr("\033[0m\n");
  hearts = (matrix->ship->navigation_tools->evade / 2);
  i = 0;
  my_putstr("EVASION: ");
  while (i < hearts)
    {
      my_putstr("\033[34m•");
      i = i + 1;
    }
  my_putstr("\033[0m\n");
}

void    monster_stats(t_matrix *matrix)
{
  int   hearts;
  int   i;

  if (matrix->alien)
    {
      hearts = (matrix->alien->life / 2);
      i = 0;
      my_putstr("\n                                 LIFE: ");
      while (i < hearts)
	{
	  my_putstr("\033[36m♦");
	  i = i + 1;
	}
      my_putstr("\033[0m\n");
      hearts = matrix->ship->ftl_drive->energy;
      i = 0;
      my_putstr("                                 ATTACK: ");
      while (i < hearts)
	{
	  my_putstr("\033[33m◄");
	  i = i + 1;
	}
      my_putstr("\033[0m\n");
    }
}

void    monsterface(t_matrix *matrix)
{
  if (matrix->alien)
    {
      my_putstr("\033[32m");
      my_putstr("   _                      _______                      _\n");
      my_putstr("_dMMMb._              .adOOOOOOOOOba.              _,dMMMb_\n");
      my_putstr("P'  ~YMMb            dOOOOOOOOOOOOOOOb            aMMP~ `Yb\n");
      my_putstr("      ~\"Mb          dOOOOOOOOOOOOOOOOOb          dM\"~   V\n");
      my_putstr("        `Mb.       dOOOOOOOOOOOOOOOOOOOb       ,dM'\n");
      my_putstr("         `YMb._   |OOOOOOOOOOOOOOOOOOOOO|   _,dMP'\n");
      my_putstr("    __     `YMMM| OP'~\"YOOOOOOOOOOOP\"~`YO |MMMP'     __\n");
      my_putstr("  ,dMMMb.     ~~' OO     `YOOOOOP'     OO `~~     ,dMMMb.\n");
      my_putstr(",dP~  `YMba_      OOb      `OOO'      dOO      _aMMP'  ~Yb.\n");
      my_putstr("MP'     `~YMMa_   YOOo   @  OOO  @   oOOP   _adMP~'      `Y\n");
      my_putstr("           `YMMMM\\`OOOo     OOO     oOOO'/MMMMP'\n");
      my_putstr("   ,aa.     `~YMMb `OOOb._,dOOOb._,dOOO'dMMP~'       ,aa.\n");
      my_putstr(" ,dMYYMba._         `OOOOOOOOOOOOOOOOO'          _,adMYYMb.\n");
      my_putstr(",MP'   `YMMba._      OOOOOOOOOOOOOOOOO       _,adMMP'   `YM\n");
      my_putstr("MP'        ~YMMMba._ YOOOOPVVVVVYOOOOP  _,adMMMMP~       `Y\n");
      my_putstr("YMb           ~YMMMM` OOOOI`````IOOOO'/MMMMP~           dMP\n");
      my_putstr(" `Mb.           `YMMMb`OOOI,,,,,IOOOO'dMMMP'           ,dM'\n");
      my_putstr("   `'                  `OObNNNNNdOO'                   `'\n");
      my_putstr("                         `~OOOOO~'   \033[0m\n\n");
    }
}
