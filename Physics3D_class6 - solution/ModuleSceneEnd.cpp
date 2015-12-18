#include "Globals.h"
#include "Application.h"
#include "ModuleSceneEnd.h"

ModuleSceneEnd::ModuleSceneEnd(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	graphics = NULL;
	fx = 0;
}

ModuleSceneEnd::~ModuleSceneEnd()
{}

// Load assets
bool ModuleSceneEnd::Start()
{
	LOG("Loading End assets");
	bool ret = true;

	return ret;
}

// Load assets
bool ModuleSceneEnd::CleanUp()
{
	LOG("Unloading End scene");

	App->texture->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModuleSceneEnd::Update()
{
	// Draw everything --------------------------------------	
	App->renderer->Blit(graphics, 0, 0, NULL);

	return UPDATE_CONTINUE;
}