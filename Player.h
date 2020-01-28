#pragma once
#include "GameObject.h"
class CSound;

class Player : public GameObject
{
public:
	Player();
	~Player();

	float vspeed = 0;
	float hspeed = 0;

	void Init();
	void Update();
	void LateUpdate();

	void GetKey();
	void Hspeed();
	void Gravity();
	void CameraMove();
};

