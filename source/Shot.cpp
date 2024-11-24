/*
 * Shot.cpp
 *
 *  Created on: Dec 8, 2022
 *      Author: profe
 */

#include "Shot.h"

Shot::~Shot()
{
	// TODO Auto-generated destructor stub
}

Shot::Shot(GridPosition targetPosition) : targetPosition{targetPosition}
{
}

GridPosition Shot::getTargetPosition() const
{
	return this->targetPosition;
}
