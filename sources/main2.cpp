/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 14:06:58 by hades             #+#    #+#             */
/*   Updated: 2015/01/11 14:51:29 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "../headers/DebugEntity.class.hpp"
#include "../headers/EnnemyShip.class.hpp"
#include "../headers/Map.class.hpp"
#include "../headers/PlayerShip.class.hpp"
#include "../headers/Projectile.class.hpp"

int		main(void)
{
	int			input = 0;

	int			ennemyornot = 6;
	int			index_ennemy;
	int			trois = 3;
	EnnemyShip	*tab[3];

	int			x, y;
	Map			map;
	PlayerShip	player(2, 11);

	map.setContentType(player.getY(), player.getX(), player.getType());

	initscr();
	// nodelay(stdscr, true); 			
	keypad(stdscr, true);
	noecho();		
 	curs_set(0);				
 	// start_color();
 	// init_pair(1, COLOR_RED, COLOR_BLUE);
	// wbkgd(stdscr,COLOR_PAIR(1));
	getmaxyx(stdscr, y, x);

	map.drawMap();

	move(y - 1, x - 25);
	printw("press a key (esc to exit)");
	move(0, 0);
	printw("Sreen's dimension: %dx%d", x, y);

	while ((input = getch()) != 27)
	{
		player.moveShip(map, input);
		while ( trois >= 0) {
			if (tab[trois]) {
				tab[trois].moveShip();
			}
			trois--;
		}
		trois = 3;
		if ( ennemyornot == 0 ) {
			if (index_ennemy < 3) {
				tab[index_ennemy] = new EnnemyShip();
				index_ennemy++;
			}
			ennemyornot = 6;
		}
		ennemyornot--;

		clear();
		map.drawMap();
		refresh();
	}

    endwin();

	return 0;
}


		// mvprintw(y - 2, 1, "Map: ship player pos %dx/%dy", map.getPlayerPosX(), map.getPlayerPosY());
		// mvprintw(y - 1, 1, "Ship player pos %dx/%dy", player.getX(), player.getY());
		// mvprintw(y / 2, x / 2, " code key : %d, key is %c", c, c);
		// mvprintw(y - 1, x - 25, "press a key (esc to exit)");