#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));


	//s.size = vec3(100, 0.5f, 100);
	//s.SetPos(0, 0.5f, 20);
	//c.size = vec3(5, 1, 3);
	//c.SetPos(0, 3, 20);

	//FL
	Cube fl1(1, 5, 100);
	fl1.SetPos(6, 2.5f, 0);
	circuit.add(fl1);
	Cube fl2(1, 5, 100);
	fl2.SetPos(-6, 2.5f, 0);
	circuit.add(fl2);


	// Curve 1
	Cube c11(1, 5, 10);
	c11.SetPos(-8.5, 2.5f, 55);
	c11.SetRotation(-30, vec3(0, 1, 0));
	circuit.add(c11);
	Cube c12(1,5,10);
	c12.SetPos(-15.25f, 2.5f, 62.25f);
	c12.SetRotation(-60, vec3(0, 1, 0));
	circuit.add(c12);
	Cube c13(1, 5, 10);
	c13.SetPos(-25.0f, 2.5f, 65);
	c13.SetRotation(-90, vec3(0, 1, 0));
	circuit.add(c13);
	//---------
	Cube c14(1, 5, 10);
	c14.SetPos(5, 2.5f, 55);
	c14.SetRotation(-15, vec3(0, 1, 0));
	circuit.add(c14);
	Cube c15(1, 5, 10);
	c15.SetPos(1.25f, 2.5f, 64.5f);
	c15.SetRotation(-30, vec3(0, 1, 0));
	circuit.add(c15);
	Cube c16(1, 5, 10);
	c16.SetPos(-4.75f, 2.5f, 72.75f);
	c16.SetRotation(-45, vec3(0, 1, 0));
	circuit.add(c16);
	Cube c17(1, 5, 10);
	c17.SetPos(-12.5, 2.5f, 79);
	c17.SetRotation(-60, vec3(0, 1, 0));
	circuit.add(c17);
	Cube c18(1, 5, 10);
	c18.SetPos(-21.5f, 2.5f, 83);
	c18.SetRotation(-75, vec3(0, 1, 0));
	circuit.add(c18);
	Cube c19(1, 5, 10);
	c19.SetPos(-31.25f, 2.5f, 84.25f);
	c19.SetRotation(-90, vec3(0, 1, 0));
	circuit.add(c19);


	// Straight 1
	Cube s11(1, 5, 40);
	s11.SetPos(-56.25f, 2.5f, 84.25);
	s11.SetRotation(-90, vec3(0, 1, 0));
	circuit.add(s11);
	Cube s12(1, 5, 45.5);
	s12.SetPos(-53, 2.5f, 65);
	s12.SetRotation(-90, vec3(0, 1, 0));
	circuit.add(s12);


	// Curve 2

	// Straight 2

	// Curve 3

	// Straight 3

	// Curve 4

	// Straight 4

	// Curve 5

	// Straight 5

	// Curve 6

	// Straight 6

	// Curve 7

	// Straight 7

	// Curve 8

	// Curve 9

	p2List_item<Cube>* item = circuit.getFirst();
	while (item != NULL) {
		App->physics->AddBody(item->data, 0.0f);
		item = item->next;
	}


	/*sensor = App->physics->AddBody(, 0.0f);
	sensor->SetAsSensor(false);
	sensor->collision_listeners.add(this);
	*/
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	//sensor->GetTransform(&s.transform);
	//s.Render();
	//c.Render();
	p2List_item<Cube>* item = circuit.getFirst();
	while (item != NULL) {
		item->data.Render();
		item = item->next;
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Hit!");
}

