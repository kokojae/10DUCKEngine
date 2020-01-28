#pragma once
#include <iostream>
#include "TextureInfo.h"
#include "BoxCollider.h"
class ObjectManager;

class GameObject
{
public:
	GameObject();
	~GameObject();

	TextureInfo texture;
	D3DXVECTOR2 position = { 0,0 };
	BoxCollider collider;
	int texture_layer = 0;
	bool destroy = false;

	virtual void Init();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	void DrawSelf();

	template <typename T>
	T* Instantiate(D3DXVECTOR2 position);

	GameObject* PlaceMeeting(D3DXVECTOR2 vector);

	void SetTexture(std::wstring path, D3DXVECTOR2 texture_size);
	void SetCollider(D3DXVECTOR2 size, D3DXVECTOR2 center = { 0,0 });

	bool operator < (const GameObject& other);
};

template<typename T>
inline T* GameObject::Instantiate(D3DXVECTOR2 position)
{
	return ObjectManager::Instantiate<T>(position);
}
