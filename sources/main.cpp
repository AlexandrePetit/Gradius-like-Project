/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:31:36 by alex              #+#    #+#             */
/*   Updated: 2015/01/10 20:18:31 by alex             ###   ########.fr       */
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
	int			c, x, y;
	Map			map;
	PlayerShip	player(2, 11);

	map.setContentType(11, 2, 1);
	map.setContentId(11, 2, 1);

	initscr();
	// nodelay(stdscr, true); 			
	keypad(stdscr, true);
	noecho();		
 	curs_set(0);				
 	start_color();
 	init_pair(1, COLOR_RED, COLOR_BLUE);
	wbkgd(stdscr,COLOR_PAIR(1));
	getmaxyx(stdscr, y, x);

	map.drawMap();

	move(y - 1, x - 25);
	printw("press a key (esc to exit)");

	move(0, 0);
	printw("Sreen's dimension: %dx%d", x, y);

	while ( (c = getch()) != 27 )
	{
		map.drawMap();
		move(y/2, x/2);
		printw(" code key : %d, key is %c", c, c);
		move(y - 1, x - 25);
		printw("press a key (esc to exit)");
		refresh();
		getch();
	}

    endwin();

	return 0;
}