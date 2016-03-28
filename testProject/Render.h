#pragma once
#include "Systems.h"
#include "Assets.h"

class RenderSystem : public System
{
	// sprite and transform
	bool condition(Handle<Entity> i)
	{
		return i->sprite > -1 && i->transform > -1;
	}

	// the actual draw call
	void update(Handle<Entity> i)
	{
		Mat3 m =
			i->transform->getGlobalTrans()
			* Mat3::translation(i->sprite->offset)
			* Mat3::scale(i->sprite->dimension)
			* Mat3::rotate(i->sprite->angle);

		Asset::instance().drawTexture(i->sprite->assetName, m);
	}
};
