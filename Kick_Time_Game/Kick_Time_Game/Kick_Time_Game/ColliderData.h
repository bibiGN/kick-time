#ifndef _COLLIDERDATA_H
#define _COLLIDERDATA_H

#include <string>

using namespace std;

class ColliderData
{
private:
	int colliderID;
	int posX;
	int posY;
	int halfSizeX;
	int halfSizeY;

public:
	ColliderData();
	ColliderData(int colliderID, int posX, int posY, int halfSizeX, int halfSizeY);
	~ColliderData(void);
	int getColliderID() const;
	int getPosX() const;
	int getPosY() const;
	int getHalfSizeX() const;
	int getHalfSizeY() const;
};

#define NUMBER_COLLIDERDATA 40

extern const ColliderData colliderDataArray[NUMBER_COLLIDERDATA];

#define COLLIDER_NULL (-1)
#define COLLIDER_SCORPION_STAND_RIGHT 0
#define COLLIDER_SCORPION_MOVE_RIGHT_RIGHT 1
#define COLLIDER_SCORPION_MOVE_LEFT_RIGHT 2
#define COLLIDER_SCORPION_CROUCH_RIGHT 3
#define COLLIDER_SCORPION_STANDUP_RIGHT 4
#define COLLIDER_SCORPION_STEADY_JUMP_UP_RIGHT 5
#define COLLIDER_SCORPION_STEADY_JUMP_DOWN_RIGHT 6
#define COLLIDER_SCORPION_FORWARD_JUMP_RIGHT 7
#define COLLIDER_SCORPION_GUARD_RIGHT 8
#define COLLIDER_SCORPION_LOW_GUARD_RIGHT 9
#define COLLIDER_SCORPION_PUNCH_RIGHT 10
#define COLLIDER_SCORPION_KICK_RIGHT 11
#define COLLIDER_SCORPION_CROUCHED_KICK_RIGHT 12
#define COLLIDER_SCORPION_CROUCHED_PUNCH_RIGHT 13
#define COLLIDER_SCORPION_JUMPED_PUNCH_RIGHT 14
#define COLLIDER_SCORPION_JUMPED_KICK_RIGHT 15
#define COLLIDER_SCORPION_HIT_RIGHT 16
#define COLLIDER_SCORPION_LOW_HIT_RIGHT 17
#define COLLIDER_SCORPION_VICTORY_RIGHT 18
#define COLLIDER_SCORPION_CROUCHED_RIGHT 19
#define COLLIDER_SCORPION_STAND_LEFT 20
#define COLLIDER_SCORPION_MOVE_RIGHT_LEFT 21
#define COLLIDER_SCORPION_MOVE_LEFT_LEFT 22
#define COLLIDER_SCORPION_CROUCH_LEFT 23
#define COLLIDER_SCORPION_STANDUP_LEFT 24
#define COLLIDER_SCORPION_STEADY_JUMP_UP_LEFT 25
#define COLLIDER_SCORPION_STEADY_JUMP_DOWN_LEFT 26
#define COLLIDER_SCORPION_FORWARD_JUMP_LEFT 27
#define COLLIDER_SCORPION_GUARD_LEFT 28
#define COLLIDER_SCORPION_LOW_GUARD_LEFT 29
#define COLLIDER_SCORPION_PUNCH_LEFT 30
#define COLLIDER_SCORPION_KICK_LEFT 31
#define COLLIDER_SCORPION_CROUCHED_KICK_LEFT 32
#define COLLIDER_SCORPION_CROUCHED_PUNCH_LEFT 33
#define COLLIDER_SCORPION_JUMPED_PUNCH_LEFT 34
#define COLLIDER_SCORPION_JUMPED_KICK_LEFT 35
#define COLLIDER_SCORPION_HIT_LEFT 36
#define COLLIDER_SCORPION_LOW_HIT_LEFT 37
#define COLLIDER_SCORPION_VICTORY_LEFT 38
#define COLLIDER_SCORPION_CROUCHED_LEFT 39

#endif _COLLIDERDATA_H
