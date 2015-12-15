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
	ground.size.x = ground.size.z = 1000;
	ground.size.y = 1;
	ground.SetPos(0, -1, 0);

	//FL
	Cube fl1(1, 5, 100);
	fl1.SetPos(6, 2.5f, 0);
	circuit.add(fl1);
	Cube fl2(1, 5, 100);
	fl2.SetPos(-6, 2.5f, 0);
	circuit.add(fl2);


	// Curve 1
	Cube c11(1, 5, 10);
	c11.SetPos(-8.5, 2.5f, 54);
	c11.SetRotation(-30, vec3(0, 1, 0));
	circuit.add(c11);
	Cube c12(1,5,10);
	c12.SetPos(-15.25f, 2.5f, 60.50f);
	c12.SetRotation(-60, vec3(0, 1, 0));
	circuit.add(c12);
	Cube c13(1, 5, 10);
	c13.SetPos(-25.0f, 2.5f, 63);
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
	s12.SetPos(-53, 2.5f, 63);
	s12.SetRotation(-90, vec3(0, 1, 0));
	circuit.add(s12);

	// Curve 2
	Cube c21(1, 5, 10);
	c21.SetPos(-79.75f, 2.5f, 60.5f);
	c21.SetRotation(-120, vec3(0, 1, 0));
	circuit.add(c21);
	Cube c22(1, 5, 10);
	c22.SetPos(-86.25, 2.5f, 54);
	c22.SetRotation(-150, vec3(0, 1, 0));
	circuit.add(c22);
	Cube c23(1, 5, 10);
	c23.SetPos(-88.75, 2.5f, 45);
	circuit.add(c23);
	// ----------
	Cube c24(1, 5, 10);
	c24.SetPos(-81, 2.5f, 83);
	c24.SetRotation(-105, vec3(0, 1, 0));
	circuit.add(c24);
	Cube c25(1, 5, 10);
	c25.SetPos(-90, 2.5f, 79.25);
	c25.SetRotation(-120, vec3(0, 1, 0));
	circuit.add(c25);
	Cube c26(1, 5, 10);
	c26.SetPos(-97.5f, 2.5f, 73.5f);
	c26.SetRotation(-135, vec3(0, 1, 0));
	circuit.add(c26);
	Cube c27(1, 5, 10);
	c27.SetPos(-103.5, 2.5f, 66);
	c27.SetRotation(-150, vec3(0, 1, 0));
	circuit.add(c27);
	Cube c28(1, 5, 10);
	c28.SetPos(-107.25, 2.5f, 57);
	c28.SetRotation(-165, vec3(0, 1, 0));
	circuit.add(c28);
	Cube c29(1, 5, 10);
	c29.SetPos(-108.5f, 2.5f, 47);
	circuit.add(c29);

	// Straight 2
	Cube s21(1, 5, 40);
	s21.SetPos(-88.75f, 2.5f, 20);
	circuit.add(s21);
	Cube s22(1, 5, 42.25f);
	s22.SetPos(-108.5, 2.5f, 21);
	circuit.add(s22);

	// Curve 3
	Cube c31(1, 5, 10);
	c31.SetPos(-86.5f, 2.5f, -4);
	c31.SetRotation(-30, vec3(0, 1, 0));
	circuit.add(c31);
	Cube c32(1, 5, 10);
	c32.SetPos(-80, 2.5f, -10.5f);
	c32.SetRotation(-60, vec3(0, 1, 0));
	circuit.add(c32);
	Cube c33(1, 5, 10);
	c33.SetPos(-71.5f, 2.5f, -10.5f);
	c33.SetRotation(-120, vec3(0, 1, 0));
	circuit.add(c33);
	Cube c34(1, 5, 10);
	c34.SetPos(-64.75f, 2.5f, -4);
	c34.SetRotation(-150, vec3(0, 1, 0));
	circuit.add(c34);


	// Straight 3
	Cube s31(1, 5, 50);
	s31.SetPos(-62.25f, 2.5f, 25.25f);
	circuit.add(s31);

	Cube s32(12, 1, 35);
	s32.SetPos(-55.75f, 2, 47.75f);
	s32.SetRotation(-42, vec3(1, 0,0));
	circuit.add(s32);
	Cube s33(12, 1, 25);
	s33.SetPos(-55.75f, 13.5, 73);
	circuit.add(s33);
	Cube s34(12, 1, 35);
	s34.SetPos(-55.75f, 2, 98);
	s34.SetRotation(42, vec3(1, 0, 0));
	circuit.add(s34);

	Cube s35(1, 5, 50);
	s35.SetPos(-49.25f, 2.5f, 25.25f);
	circuit.add(s35);

	Cube s36(1, 5, 35);
	s36.SetPos(-62.25f, 5, 47.75f);
	s36.SetRotation(-42, vec3(1, 0, 0));
	circuit.add(s36);
	Cube s37(1, 5, 35);
	s37.SetPos(-49.25f, 5, 47.75f);
	s37.SetRotation(-42, vec3(1, 0, 0));
	circuit.add(s37);

	Cube s38(1, 5, 25);
	s38.SetPos(-49.25f, 16.5f, 73);
	circuit.add(s38);
	Cube s39(1, 5, 25);
	s39.SetPos(-62.25f, 16.5f, 73);
	circuit.add(s39);
	//INVISIBLE	
	Cube s310(1, 40, 40);
	s310.SetPos(-62.25f, 26.5f, 85);
	Cube s311(1, 40, 40);
	s311.SetPos(-49.25f, 26.5f, 85);
	App->physics->AddBody(s310, 0.0f);
	App->physics->AddBody(s311, 0.0f);




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
	ground.Render();

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

