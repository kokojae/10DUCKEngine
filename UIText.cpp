#include "DXUT.h"
#include "UIText.h"
#include "10DUCKEngine.h"

UIText::UIText()
{
}

UIText::~UIText()
{
}

void UIText::Render()
{
	GraphicManager::TextUIRender(text.c_str(), position, scale);
}

void UIText::SetText(std::wstring text, D3DXVECTOR2 scale)
{
	this->text = text;
	this->scale = scale;
}
