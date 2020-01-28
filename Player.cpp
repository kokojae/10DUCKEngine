#include "DXUT.h"
#include "Player.h"
#include "10DUCKEngine.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init()
{
	texture.path = L"Source/player.png";
	SetTexture(texture.path, { 100,100 });
	SetCollider({ 80,80 });
}

void Player::Update()
{
	GetKey();
	Hspeed();
	Gravity();
}

void Player::LateUpdate()
{
	CameraMove();
}

void Player::GetKey()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		SceneManager::LoadScene(SceneManager::Scene::InGame);
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (hspeed > -5)
			hspeed -= 0.5f;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (hspeed < 5)
			hspeed += 0.5f;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		if (PlaceMeeting({ 0,10 }))
		{
			SoundManager::PlaySFX(L"Source/Jump.wav");
			vspeed = -15;
		}
	}

	if (GetAsyncKeyState('W'))
		Camera::scale -= Camera::scale * 0.2;
	if (GetAsyncKeyState('S'))
		Camera::scale += Camera::scale * 0.2;
	if (GetAsyncKeyState('D'))
		Camera::rotation += 5;
	if (GetAsyncKeyState('A'))
		Camera::rotation -= 5;
}

void Player::Hspeed()
{
	if (PlaceMeeting({ hspeed,0 }) != nullptr)
	{
		hspeed = 0;
	}
	else
	{
		position.x += hspeed;
	}

	// °¨¼Ó
	if (!GetAsyncKeyState(VK_LEFT))
		if (!GetAsyncKeyState(VK_RIGHT))
			if (hspeed != 0)
				hspeed -= hspeed / 20;
}

void Player::Gravity()
{
	vspeed += 0.5f;

	if (PlaceMeeting({0,vspeed}) != nullptr)
	{
		vspeed = 0;
	}
	else
	{
		position.y += vspeed;
	}
}

void Player::CameraMove()
{
	Camera::position += (position - Camera::position) / 30;
}
