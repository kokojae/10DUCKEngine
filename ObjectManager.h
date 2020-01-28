#pragma once
#include <list>
#include "GameObject.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	static std::list<GameObject*> object_list;
	static std::list<GameObject*> collider_list;

	template <typename T>
	static T* Instantiate(D3DXVECTOR2 position = { 0,0 });

	static void sort();

	static void Update();
	static void LateUpdate();
	static void Render();
	static void Release();
	static void Clear();

	static GameObject* ColliderCheck(D3DXVECTOR2 collider, D3DXVECTOR2 position);
};

template<typename T>
inline T* ObjectManager::Instantiate(D3DXVECTOR2 position)
{
	T* inst = new T;

	object_list.push_back(inst);
	inst->Init();
	inst->position = position;

	sort();

	return inst;
}
