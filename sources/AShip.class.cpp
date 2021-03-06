/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AShip.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:55:45 by alex              #+#    #+#             */
/*   Updated: 2015/01/10 20:37:14 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../headers/AShip.class.hpp"

AShip::AShip(void) : AMobileEntity() {
	if (DebugEntity::getDebug() == true)
		std::cout << "AShip::AMobileEntity()." << std::endl;

	return ;
}

AShip::AShip(int type, int x, int y) : AMobileEntity(type, x,y) {
	if (DebugEntity::getDebug() == true)
		std::cout << "AShip::AMobileEntity(" << x << ", " << y << ")." << std::endl;

	return ;
}


AShip::~AShip(void) {
	if (DebugEntity::getDebug() == true)
		std::cout << "~AShip()." << std::endl;

	return;
}