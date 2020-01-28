#pragma once
#include <iostream>

class TextureInfo
{
public:
	TextureInfo();
	~TextureInfo();

	std::wstring path = L"";
	LPDIRECT3DTEXTURE9 texture = nullptr;
	D3DXVECTOR2 size = { 0,0 };
	int index = 0;
	D3DXVECTOR2 center = { 0,0 };
	D3DXVECTOR2 scale = { 1,1 };
	float rotation = 0;
	D3DXCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255);
	bool camera_on = true;
};

