#pragma once
#include <iostream>
#include "GameObject.h"

class Text : public GameObject
{
public:
	Text();
	~Text();

	std::wstring text = L"";
	D3DXVECTOR2 scale = { 1,1 };

	void Render();

	void SetText(std::wstring text, D3DXVECTOR2 scale);
};

