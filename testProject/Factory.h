#pragma once
#include "Entity.h"
#include "GCData.h"
struct Factory
{

	static Handle<Entity> makeBall(Vec2 pos, Vec2 vel, float radius, float mass)
	{
		auto e = Entity::make();
		e->collider = Collider::make();
		e->rigidbody = Rigidbody::make();
		e->transform = Transform::make();

		e->collider->circle.r = radius;
		e->collider->shape = Collider::e_CIRCLE;
		e->rigidbody->mass = mass;
		e->rigidbody->vel = vel;
		e->transform->setPos(pos);
		return e;
	}


	static Handle<Entity> makeWall(Vec2 pos, Vec2 normal)
	{
		auto e = Entity::make();
		e->collider = Collider::make();
		e->transform = Transform::make();

		e->collider->plane.normal = normal;
		e->collider->shape = Collider::e_PLANE;
		e->transform->setPos(pos);

		return e;
	}


	static Handle<Entity> makePlayer(Vec2 pos)
	{
		auto e = Entity::make();
		e->collider = Collider::make();
		e->rigidbody = Rigidbody::make();
		e->transform = Transform::make();
		e->controller = PlayerController::make();
		e->sprite = Sprite::make();

		e->sprite->assetName = "Ship";
		e->sprite->dimension = Vec2{ 72,72 };

		e->collider->shape = Collider::e_AABB;
		e->collider->aabb.halfextents = Vec2{ 36,36 };
		e->transform->setPos(pos);

		return e;
	}


	static Handle<Entity> makeBullet(Vec2 pos, Vec2 dir, float life = 1.6f, float speed = 100.f)
	{
		auto e = Entity::make();
		e->rigidbody = Rigidbody::make();
		e->transform = Transform::make();
		e->lifecycle = LifeCycle::make();

		e->transform->setPos(pos);
		e->rigidbody->vel = dir * speed;
		e->lifecycle->lifespan = life;

		return e;
	}
};