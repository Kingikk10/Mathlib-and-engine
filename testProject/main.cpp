#include "transform.h"
#include "Collider.h"
#include "sfwdraw.h"
#include "crenderutils.h"
#include "Rigidbody.h"
#include "Vec2.h"
#include "Window.h"
#include "input.h"
#include "Time.h"
#include "collisions.h"
#include <iostream>
#include "Factory.h"
#include "DebugDraw.h"
#include "rigidbodydynamics.h"
#include "LifeTimeSystem.h"
#include "CollisionDetection.h"
#include "DynamicRes.h"
#include "playerflight.h"
#include "Render.h"
#include "Assets.h"



struct mat4
{

	float m[16];
	operator float *() { return m; }


};

mat4 mat3to4(float *m)
{
	return{
		m[0], m[1], 0, m[2],
		m[3], m[4], 0, m[5],
		  0 ,   0 , 1,   0 ,
		m[6], m[7], 0, m[8]};


}

//class lifespan
//{
//private:
//	float lifetime;
//	float lifespan;
//public:
//	void startclock(float lifespan)
//	{
//		lifetime = lifespan;
//		lifetime -= sfw::getDeltaTime();
//	}
//
//	void kill()
//	{
//		if (lifetime < 0)
//		{
//			0;
//			//	Free();
//		}
//	}
//
//
//};

//Collision collisioner;
void main()
{
	auto &window = Window::instance();

	auto &input = Input::instance();
	auto &time = Time::instance();

	window.init();
	input.init();
	time.init();

	Asset::instance().loadTexture("Ship", "../textures/car.jpg");

	Factory::makePlayer({ 0,0 });




	DebugDraw debugDraw;
	RigidbodyDynamics rigidbodies;
	LifetimeSystem lifetimes;
	CollisionDetection collisioner;
	DynamicResolution dynamic;
	PlayerFlightSystem flightsystem;
	RenderSystem render;
	while (window.step())
	{
		
		input.step();
		flightsystem.step();


		rigidbodies.step();
		lifetimes.step();

		collisioner.step();
		dynamic.step();
		render.step();
		debugDraw.step();
		//drawAABB(trans1.getGlobalTrans() * coll1.aabb, (cd.isOverlap ? CYAN : RED));
	//	drawAABB(trans2.getGlobalTrans() * coll2.aabb, (cd.isOverlap ? CYAN : RED));

		
	}

	input.term();
	window.term();
	
	return;
}