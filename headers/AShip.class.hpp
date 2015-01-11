/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AShip.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:46:02 by alex              #+#    #+#             */
/*   Updated: 2015/01/11 15:27:29 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_CLASS_HPP
# define SHIP_CLASS_HPP

# include "AMobileEntity.class.hpp"
# include "Projectile.class.hpp"

class AShip : public AMobileEntity {
	public:
		AShip();
		AShip(int type, int x, int y);
		~AShip();

};

#endif