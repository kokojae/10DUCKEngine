#pragma once
#include <iostream>
#include "GameObject.h"

class UIText : public GameObject
{
public:
	UIText();
	~UIText();

	std::wstring text = L"";
	D3DXVECTOR2 scale = { 1,1 };

	void Render();

	void SetText(std::wstring text, D3DXVECTOR2 scale);
};

