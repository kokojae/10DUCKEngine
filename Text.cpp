#include "DXUT.h"
#include "Text.h"
#include "10DUCKEngine.h"

Text::Text()
{
}

Text::~Text()
{
}

void Text::Render()
{
	GraphicManager::TextRender(text.c_str(), position, scale);
}

void Text::SetText(std::wstring text, D3DXVECTOR2 scale)
{
	this->text = text;
	this->scale = scale;
}
