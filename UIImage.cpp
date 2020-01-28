#include "DXUT.h"
#include "UIImage.h"
#include "10DUCKEngine.h"

UIImage::UIImage()
{
}

UIImage::~UIImage()
{
}

void UIImage::Init()
{
	texture.path = L"Source/uiimage.png";
	SetTexture(texture.path, { 150,100 });
	texture.camera_on = false;
}

void UIImage::Update()
{
}
