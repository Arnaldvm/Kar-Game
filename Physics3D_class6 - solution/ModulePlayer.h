#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 3000.0f
#define TURN_DEGREES 17.0f * DEGTORAD
#define BRAKE_POWER 1500.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

public:

	PhysVehicle3D* vehicle;
	float turn;
	float acceleration;
	float brake;
	uint fx_breaks;
	uint final_lap_fx;
	uint win_fx;
	uint horn_fx;
	void Respawn();
	uint lap = 1;
	uint lap_time;
	uint time_to_beat;
	uint current_lap = 0;
	Timer timer;
	bool check = false;
	bool done = true;
};