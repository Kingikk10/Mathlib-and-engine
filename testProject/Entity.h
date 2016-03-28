#pragma once

#include "GCData.h"

#include "Transform.h"
#include "Rigidbody.h"
#include "LifeSpan.h"
#include "Collider.h"
#include "PLayerController.h"
#include "sprite.h"

struct Entity : GCData<Entity>
{
	Handle<Transform> transform;
	Handle<Rigidbody> rigidbody;
	Handle<LifeCycle> lifecycle;
	Handle<Collider > collider;
	Handle<PlayerController> controller;
	Handle<Sprite> sprite;
	void onFree()
	{
		Transform::free(transform.index);
		Rigidbody::free(rigidbody.index);
		LifeCycle::free(lifecycle.index);
		Collider::free(collider.index);
		PlayerController::free(controller.index);
	}
};