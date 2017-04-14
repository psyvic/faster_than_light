/*
** game_6.c for game_6 in /home/vic/Desktop/piscine/C/My_FTL/aizpur_v/My_FTL
** 
** Made by AIZPURUA Victor Hugo
** Login   <aizpur_v@etna-alternance.net>
** 
** Started on  Fri Apr 14 21:31:17 2017 AIZPURUA Victor Hugo
** Last update Fri Apr 14 22:15:32 2017 AIZPURUA Victor Hugo
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "ftl.h"

void    interface(t_matrix *matrix)
{
  spaceship();
  stats(matrix);
  monsterface(matrix);
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
  my_putstr("SHIP ENERGY: ");
  while (i < hearts)
    {
      my_putstr("\033[32m►");
      i = i + 1;
    }
  my_putstr("\033[0m\n");
}

void    monsterface(t_matrix *matrix)
{
  if (matrix->alien)
    {
      my_putstr("\033[32m");
      my_putstr("     _                      _______                      _");
      my_putstr("  _dMMMb._              .adOOOOOOOOOba.              _,dMMMb_");
      my_putstr(" dP'  ~YMMb            dOOOOOOOOOOOOOOOb            aMMP~ `Yb");
      my_putstr(" V      ~\"Mb          dOOOOOOOOOOOOOOOOOb          dM\"~   V");
      my_putstr("          `Mb.       dOOOOOOOOOOOOOOOOOOOb       ,dM'");
      my_putstr("           `YMb._   |OOOOOOOOOOOOOOOOOOOOO|   _,dMP'");
      my_putstr("      __     `YMMM| OP'~\"YOOOOOOOOOOOP\"~`YO |MMMP'     __");
      my_putstr("    ,dMMMb.     ~~' OO     `YOOOOOP'     OO `~~     ,dMMMb.");
      my_putstr(" _,dP~  `YMba_      OOb      `OOO'      dOO      _aMMP'  ~Yb.");
      my_putstr("<MMP'     `~YMMa_   YOOo   @  OOO  @   oOOP   _adMP~'      `Y");
      my_putstr("             `YMMMM\\`OOOo     OOO     oOOO'/MMMMP'");
      my_putstr("     ,aa.     `~YMMb `OOOb._,dOOOb._,dOOO'dMMP~'       ,aa.");
      my_putstr("   ,dMYYMba._         `OOOOOOOOOOOOOOOOO'          _,adMYYMb.");
      my_putstr("  ,MP'   `YMMba._      OOOOOOOOOOOOOOOOO       _,adMMP'   `YM");
      my_putstr("  MP'        ~YMMMba._ YOOOOPVVVVVYOOOOP  _,adMMMMP~       `Y");
      my_putstr("  YMb           ~YMMMM` OOOI``````IOOOO'/MMMMP~           dMP");
      my_putstr("   `Mb.           `YMMMb`OOOI,,,,,IOOOO'dMMMP'           ,dM'");
      my_putstr("     `'                  `OObNNNNNdOO'                   `'");
      my_putstr("                           `~OOOOO~'   \033[0m\n");
    }
}
