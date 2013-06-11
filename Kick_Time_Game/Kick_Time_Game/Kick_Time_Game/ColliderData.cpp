#include "ColliderData.h"

const ColliderData colliderDataArray[NUMBER_COLLIDERDATA] =
{
	ColliderData(COLLIDER_SCORPION_STAND_RIGHT, 38, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_MOVE_RIGHT_RIGHT, 38, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_MOVE_LEFT_RIGHT, 30, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_CROUCH_RIGHT, 26, 55, 22, 50),
	ColliderData(COLLIDER_SCORPION_STANDUP_RIGHT, 26, 55, 22, 50),
	ColliderData(COLLIDER_SCORPION_STEADY_JUMP_UP_RIGHT, 37, 85, 22, 50),
	ColliderData(COLLIDER_SCORPION_STEADY_JUMP_DOWN_RIGHT, 37, 85, 22, 50),
	ColliderData(COLLIDER_SCORPION_FORWARD_JUMP_RIGHT, 30, 100, 22, 30),
	ColliderData(COLLIDER_SCORPION_BACKWARD_JUMP_RIGHT, 30, 100, 22, 30),
	ColliderData(COLLIDER_SCORPION_GUARD_RIGHT, 25, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_GUARD_ON_RIGHT, 25, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_LOW_GUARD_RIGHT, 25, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_LOW_GUARD_ON_RIGHT, 25, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_PUNCH_RIGHT, 26, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_KICK_RIGHT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_CROUCHED_KICK_RIGHT, 28, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_CROUCHED_PUNCH_RIGHT, 33, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_JUMPED_PUNCH_RIGHT, 70, 85, 22, 30),
	ColliderData(COLLIDER_SCORPION_JUMPED_KICK_RIGHT, 30, 85, 22, 30),
	ColliderData(COLLIDER_SCORPION_HIT_RIGHT, 32, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_LOW_HIT_RIGHT, 27, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_VICTORY_RIGHT, 23, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_CROUCHED_RIGHT, 26, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_STAND_LEFT, 33, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_MOVE_RIGHT_LEFT, 35, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_MOVE_LEFT_LEFT, 52, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_CROUCH_LEFT, 42, 55, 22, 50),
	ColliderData(COLLIDER_SCORPION_STANDUP_LEFT, 42, 55, 22, 50),
	ColliderData(COLLIDER_SCORPION_STEADY_JUMP_UP_LEFT, 40, 85, 22, 50),
	ColliderData(COLLIDER_SCORPION_STEADY_JUMP_DOWN_LEFT, 40, 85, 22, 50),
	ColliderData(COLLIDER_SCORPION_FORWARD_JUMP_LEFT, 37, 100, 22, 30),
	ColliderData(COLLIDER_SCORPION_BACKWARD_JUMP_LEFT, 37, 100, 22, 30),
	ColliderData(COLLIDER_SCORPION_GUARD_LEFT, 42, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_GUARD_ON_LEFT, 42, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_LOW_GUARD_LEFT, 44, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_LOW_GUARD_ON_LEFT, 44, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_PUNCH_LEFT, 77, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_KICK_LEFT, 89, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_CROUCHED_KICK_LEFT, 86, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_CROUCHED_PUNCH_LEFT, 68, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_JUMPED_PUNCH_LEFT, 78, 85, 22, 30),
	ColliderData(COLLIDER_SCORPION_JUMPED_KICK_LEFT, 99, 85, 22, 30),
	ColliderData(COLLIDER_SCORPION_HIT_LEFT, 47, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_LOW_HIT_LEFT, 48, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_VICTORY_LEFT, 35, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_CROUCHED_LEFT, 35, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_KICK_PUNCH, 90, 105, 10, 8),
	ColliderData(COLLIDER_SCORPION_KICK_PUNCH_UP, 90, 40, 10, 8),
	ColliderData(COLLIDER_SCORPION_KICK_PUNCH_DOWN, 90, 60, 10, 8),
};

ColliderData::ColliderData()
{
	this->colliderID = 0;
	this->posX = 0;
	this->posY = 0;
	this->halfSizeX = 0;
	this->halfSizeY = 0;
}

ColliderData::ColliderData(int colliderID, int posX, int posY, int halfSizeX, int halfSizeY)
{
	this->colliderID = colliderID;
	this->posX = posX;
	this->posY = posY;
	this->halfSizeX = halfSizeX;
	this->halfSizeY = halfSizeY;
}

ColliderData::~ColliderData(void)
{
}

int ColliderData::getColliderID() const
{
	return this->colliderID;
}

int ColliderData::getPosX() const
{
	return this->posX;
}

int ColliderData::getPosY() const
{
	return this->posY;
}

int ColliderData::getHalfSizeX() const
{
	return this->halfSizeX;
}

int ColliderData::getHalfSizeY() const
{
	return this->halfSizeY;
}
