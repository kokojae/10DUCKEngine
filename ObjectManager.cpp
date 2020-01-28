#include "DXUT.h"
#include "ObjectManager.h"
#include "10DUCKEngine.h"

std::list<GameObject*> ObjectManager::object_list = std::list<GameObject*>();
std::list<GameObject*> ObjectManager::collider_list = std::list<GameObject*>();

bool SortObject(const GameObject* a, const GameObject* b)
{
	return a->texture_layer < b->texture_layer;
}

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::sort()
{
	object_list.sort(SortObject);
}

void ObjectManager::Update()
{
	std::list<GameObject*>::iterator it = object_list.begin();

	while (it != object_list.end())
	{
		GameObject* inst = it._Ptr->_Myval;

		if (inst->destroy)
		{
			collider_list.remove(inst);
			object_list.erase(it++);
			delete(inst);
			continue;
		}

		inst->Update();
		it++;
	}
}

void ObjectManager::LateUpdate()
{
	for (GameObject* inst : object_list)
	{
		inst->LateUpdate();
	}
}

void ObjectManager::Render()
{
	for (GameObject* inst : object_list)
	{
		inst->Render();
	}
}

void ObjectManager::Release()
{
	TextureManager::ReleaseTexture();
}

void ObjectManager::Clear()
{
	for (GameObject* inst : object_list)
	{
		inst->destroy = true;
	}
}

GameObject* ObjectManager::ColliderCheck(D3DXVECTOR2 collider, D3DXVECTOR2 position)
{
	for (GameObject* inst : object_list)
	{
		if (inst->collider.enable == false)
			continue;

		if (position.x < inst->position.x + inst->collider.size.x - (inst->collider.size.x / 2))
			if (position.x + collider.x > inst->position.x - (inst->collider.size.x / 2))
				if (position.y < inst->position.y + inst->collider.size.y - (inst->collider.size.y / 2))
					if (position.y + collider.y > inst->position.y - (inst->collider.size.y / 2))
						return inst;
	}
	return nullptr;
}
