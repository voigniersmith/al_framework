#ifndef SCENE_HPP
#define SCENE_HPP

typedef enum {
	SCENE_NULL			= 0,
	SCENE_MENU			= 1,
	SCENE_LOADING		= 2,
	SCENE_TRANSITION	= 3
} SceneType;

class Scene
{
	public:
		SceneType type;

		void init();

};

#endif
