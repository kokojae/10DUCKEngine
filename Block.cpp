#include "DXUT.h"
#include "Block.h"
#include "10DUCKEngine.h"

Block::Block()
{
}

Block::~Block()
{
}

void Block::Init()
{
	texture.path = L"Source/block.png";
	SetTexture(texture.path, { 100,100 });
	SetCollider({ 100,100 });
	texture.color = COLOR(180, 255, 30, 0);
}

void Block::Update()
{
}
