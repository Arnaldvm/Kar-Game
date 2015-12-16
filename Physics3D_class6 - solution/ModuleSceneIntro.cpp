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

	Cube c35(1, 5, 10);
	c35.SetPos(-107.25f, 2.5f, -4.75f);
	c35.SetRotation(-15, vec3(0, 1, 0));
	circuit.add(c35);
	Cube c36(1, 5, 10);
	c36.SetPos(-103.5f, 2.5f, -13.5f);
	c36.SetRotation(-30, vec3(0, 1, 0));
	circuit.add(c36);
	Cube c37(1, 5, 10);
	c37.SetPos(-97.5f, 2.5f, -21.5f);
	c37.SetRotation(-45, vec3(0, 1, 0));
	circuit.add(c37);
	Cube c38(1, 5, 10);
	c38.SetPos(-90, 2.5f, -27.5f);
	c38.SetRotation(-60, vec3(0, 1, 0));
	circuit.add(c38);
	Cube c39(1, 5, 10);
	c39.SetPos(-50.5f, 2.5f, -4);
	c39.SetRotation(-165, vec3(0, 1, 0));
	circuit.add(c39);
	Cube c310(1, 5, 10);
	c310.SetPos(-54.25f, 2.5f, -13);
	c310.SetRotation(-150, vec3(0, 1, 0));
	circuit.add(c310);
	Cube c311(1, 5, 10);
	c311.SetPos(-60.25f, 2.5f, -20.75f);
	c311.SetRotation(-135, vec3(0, 1, 0));
	circuit.add(c311);
	Cube c312(1, 5, 10);
	c312.SetPos(-68.25f, 2.5f, -26.75f);
	c312.SetRotation(-120, vec3(0, 1, 0));
	circuit.add(c312);
	Cube c313(1, 5, 13.5);
	c313.SetPos(-79, 2.5f, -29.75f);
	c313.SetRotation(-94, vec3(0, 1, 0));
	circuit.add(c313);

	
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

	Cube s312(1, 5, 35);
	s312.SetPos(-62.25f, 5, 98);
	s312.SetRotation(42, vec3(1, 0, 0));
	circuit.add(s312);
	Cube s313(1, 5, 35);
	s313.SetPos(-49.25f, 5, 98);
	s313.SetRotation(42, vec3(1, 0, 0));
	circuit.add(s313);

	Cube s314(1, 5, 10);
	s314.SetPos(-62.25f, 2.5f, 108);
	circuit.add(s314);
	Cube s315(1, 5, 10);
	s315.SetPos(-49.25f, 2.5f, 108);
	circuit.add(s315);


	// Curve 4
	Cube c41(1, 5, 10);
	c41.SetPos(-40.25f, 2.5f, 134);
	c41.SetRotation(-120, vec3(0, 1, 0));
	circuit.add(c41);
	Cube c42(1, 5, 10);
	c42.SetPos(-46.75f, 2.5f, 127.5);
	c42.SetRotation(-150, vec3(0, 1, 0));
	circuit.add(c42);
	Cube c43(1, 5, 10);
	c43.SetPos(-49.25, 2.5f, 118.5);
	circuit.add(c43);
	// ----------
	Cube c44(1, 5, 10);
	c44.SetPos(-34.75f, 2.5f, 154);
	c44.SetRotation(-105, vec3(0, 1, 0));
	circuit.add(c44);
	Cube c45(1, 5, 10);
	c45.SetPos(-43.75f, 2.5f, 150.25);
	c45.SetRotation(-120, vec3(0, 1, 0));
	circuit.add(c45);
	Cube c46(1, 5, 10);
	c46.SetPos(-51.5f, 2.5f, 144.5f);
	c46.SetRotation(-135, vec3(0, 1, 0));
	circuit.add(c46);
	Cube c47(1, 5, 10);
	c47.SetPos(-57.25, 2.5f, 137);
	c47.SetRotation(-150, vec3(0, 1, 0));
	circuit.add(c47);
	Cube c48(1, 5, 10);
	c48.SetPos(-61, 2.5f, 128);
	c48.SetRotation(-165, vec3(0, 1, 0));
	circuit.add(c48);
	Cube c49(1, 5, 10);
	c49.SetPos(-62.25f, 2.5f, 118);
	circuit.add(c49);

	// Straight 4
	Cube s41(1, 5, 49);
	s41.SetPos(-6, 2.5f, 155);
	s41.SetRotation(-90, vec3(0, 1, 0));
	circuit.add(s41);
	Cube s42(1, 5, 55.5);
	s42.SetPos(-8.5f, 2.5f, 136.5f);
	s42.SetRotation(-90, vec3(0, 1, 0));
	circuit.add(s42);

	// Curve 5
	Cube c51(1, 5, 10);
	c51.SetPos(40, 2.5f, 127.25f);
	c51.SetRotation(-30, vec3(0, 1, 0));
	circuit.add(c51);
	Cube c52(1, 5, 10);
	c52.SetPos(33.25f, 2.5f, 134);
	c52.SetRotation(-60, vec3(0, 1, 0));
	circuit.add(c52);
	Cube c53(1, 5, 10);
	c53.SetPos(24.0f, 2.5f, 136.5);
	c53.SetRotation(-90, vec3(0, 1, 0));
	circuit.add(c53);
	//---------
	Cube c54(1, 5, 10);
	c54.SetPos(59, 2.5f, 127.5f);
	c54.SetRotation(-15, vec3(0, 1, 0));
	circuit.add(c54);
	Cube c55(1, 5, 10);
	c55.SetPos(55.25f, 2.5f, 136.5f);
	c55.SetRotation(-30, vec3(0, 1, 0));
	circuit.add(c55);
	Cube c56(1, 5, 10);
	c56.SetPos(49.5, 2.5f, 144.25f);
	c56.SetRotation(-45, vec3(0, 1, 0));
	circuit.add(c56);
	Cube c57(1, 5, 10);
	c57.SetPos(42, 2.5f, 150);
	c57.SetRotation(-60, vec3(0, 1, 0));
	circuit.add(c57);
	Cube c58(1, 5, 10);
	c58.SetPos(33, 2.5f, 153.75);
	c58.SetRotation(-75, vec3(0, 1, 0));
	circuit.add(c58);
	Cube c59(1, 5, 10);
	c59.SetPos(23.75f, 2.5f, 155);
	c59.SetRotation(-90, vec3(0, 1, 0));
	circuit.add(c59);
	
	// Straight 5
	Cube s51(1, 5, 70);
	s51.SetPos(60.25f, 2.5f, 88);
	circuit.add(s51);
	Cube s52(1, 5, 70);
	s52.SetPos(42.5, 2.5f, 88);
	circuit.add(s52);

	Cube s53(16, 1, 35);
	s53.SetPos(51, 2, 55);
	s53.SetRotation(42, vec3(1, 0, 0));
	circuit.add(s53);
	Cube s54(1, 5, 35);
	s54.SetPos(60.25f, 5, 55);
	s54.SetRotation(42, vec3(1, 0, 0));
	circuit.add(s54);
	Cube s55(1, 5, 35);
	s55.SetPos(42.5f, 5, 55);
	s55.SetRotation(42, vec3(1, 0, 0));
	circuit.add(s55);
	//INVISIBLE
	Cube s56(1, 50, 80);
	s56.SetPos(60.25f, 26.5f, 20);
	Cube s57(1, 50, 80);
	s57.SetPos(42.25f, 26.5f, 20);
	App->physics->AddBody(s56, 0.0f);
	App->physics->AddBody(s57, 0.0f);

	Cube s58(1, 5, 100);
	s58.SetPos(60.25f, 2.5f, -60);
	circuit.add(s58);
	Cube s59(1, 5, 100);
	s59.SetPos(42.5, 2.5f, -60);
	circuit.add(s59);



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

