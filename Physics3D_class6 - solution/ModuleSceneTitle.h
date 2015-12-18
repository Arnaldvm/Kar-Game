#pragma once
#include "Module.h"
#include "Globals.h"

class ModuleSceneTitle : public Module
{
public:
	ModuleSceneTitle(Application* app, bool start_enabled = true);
	~ModuleSceneTitle();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics;
	unsigned int fx;
	bool fade_out;
};