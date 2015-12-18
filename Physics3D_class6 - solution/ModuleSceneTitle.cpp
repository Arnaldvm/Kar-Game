#include "Globals.h"
#include "Application.h"
#include "ModuleSceneTitle.h"

ModuleSceneTitle::ModuleSceneTitle(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	graphics = NULL;
	fx = 0;
}

ModuleSceneTitle::~ModuleSceneTitle()
{}

// Load assets
bool ModuleSceneTitle::Start()
{
	LOG("Loading End assets");
	bool ret = true;
	graphics = App->texture->Load("Img/Title.png");
	fade_out = false;
	return ret;
}

// Load assets
bool ModuleSceneTitle::CleanUp()
{
	LOG("Unloading End scene");
	App->texture->Unload(graphics);
	return true;
}

// Update: draw background
update_status ModuleSceneTitle::Update()
{
	// Draw everything --------------------------------------	
	App->renderer->Blit(graphics, 0, -15, NULL);
	if (App->input->GetKey(SDL_SCANCODE_RETURN) == KEY_UP && fade_out == false)
	{
		App->audio->PlayFx(fx);
		App->fade->FadeToBlack(this, App->scene_intro, 3.0f);
		fade_out = true;
	}
	return UPDATE_CONTINUE;
}