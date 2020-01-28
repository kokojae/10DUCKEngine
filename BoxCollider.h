#pragma once
class BoxCollider
{
public:
	BoxCollider();
	~BoxCollider();

	bool enable = true;
	D3DXVECTOR2 size;
	D3DXVECTOR2 center;
};

