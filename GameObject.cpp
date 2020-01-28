#include "DXUT.h"
#include "GameObject.h"
#include "10DUCKEngine.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Init()
{
}

void GameObject::Update()
{
}

void GameObject::LateUpdate()
{
}

void GameObject::Render()
{
	DrawSelf();
}

void GameObject::DrawSelf()
{
	GraphicManager::TextureRender(texture, position);
}

GameObject* GameObject::PlaceMeeting(D3DXVECTOR2 vector)
{
	collider.enable = false;

	GameObject* inst = ObjectManager::ColliderCheck(collider.size, position + vector - (collider.size / 2));

	collider.enable = true;

	return inst;
}

void GameObject::SetTexture(std::wstring path, D3DXVECTOR2 texture_size)
{
	texture.texture = TextureManager::LoadTexture(path);
	texture.size = texture_size;
	texture.center = texture_size / 2;
}

void GameObject::SetCollider(D3DXVECTOR2 size, D3DXVECTOR2 center)
{
	collider.size = size;
	collider.center = center;

	ObjectManager::collider_list.push_back(this);
}

bool GameObject::operator<(const GameObject& other)
{
	return texture_layer < other.texture_layer;
}
