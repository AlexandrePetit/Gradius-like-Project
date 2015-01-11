/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnnemyShip.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:37:29 by alex              #+#    #+#             */
/*   Updated: 2015/01/11 17:31:04 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include "../headers/EnnemyShip.class.hpp"

int			EnnemyShip::_nbr = 0;

int			randY( void ) {
	int y = rand() % 24;
	mvprintw(3, 1, "y : %d", y);
	if (y == 0 || y == 1 ) {
		return 2;
	}
	else if ( y == 24 ) {
		return 22;
	}
	else {
		return y;
	}
}

EnnemyShip::EnnemyShip(void) : AShip(), _projectilesIndex(0) {
	if (DebugEntity::getDebug() == true)
		std::cout << "EnnemyShip #" << this->_id << " created at x=" << this->_x << "; y=" << this->_y << "." << std::endl;
	
	this->setY(randY());
	this->setX(80);

	this->setActive(false);

	this->_index = _nbr + 2;
	_nbr++;

	mvprintw(2, 1, "Constructor EnnemyShip x : %d || EnnemyShip y : %d", this->getX(), this->getY());

	return ;
}

EnnemyShip::EnnemyShip(int x, int y) : AShip(2, x, y), _projectilesIndex(0) {
	if (DebugEntity::getDebug() == true)
		std::cout << "EnnemyShip #" << this->_id << " created at x=" << this->_x << "; y=" << this->_y << "." << std::endl;

	return ;
}

EnnemyShip::~EnnemyShip() {
	if (DebugEntity::getDebug() == true)
		std::cout << "EnnemyShip #" << this->_id << " destroyed." << std::endl;

	return ;
}

bool			EnnemyShip::getActive( void ) {
	return this->_active;
}

int				EnnemyShip::getX( void ) {
	return this->_x;
}

int				EnnemyShip::getY( void ) {
	return this->_y;
}

int				EnnemyShip::getIndex( void ) {
	return this->_index;
}

void			EnnemyShip::setActive( bool active ) {
	this->_active = active;
	return ;
}			

void			EnnemyShip::setX( int x ) {
	this->_x = x;
	return ;
}		

void			EnnemyShip::setY( int y ) {
	this->_y = y;
	return ;
}		

void			EnnemyShip::setIndex( int index ) {
	this->_index = index;
	return ;
}	

void EnnemyShip::moveShip(Map & map, int const input) {
	int i = input;
	i = i;
	map = map;
	mvprintw(1, 1, "Ship index : %d, Ship active : %d, Ship x : %d || Ship y : %d", this->getIndex(), this->getActive(), this->getX(), this->getY());
	map.setContentType(this->getY(), this->getX(), 0);
	if (this->getX() == 0)
	{
		this->setX(80);
		this->setY(randY());
	}
	this->setX(this->getX() - 1);
	map.setContentType(this->getY(), this->getX(), this->getIndex());
}

