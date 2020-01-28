#pragma once
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	static enum class Scene
	{
		Main,InGame
	};

	static void LoadScene(Scene scene);
};

