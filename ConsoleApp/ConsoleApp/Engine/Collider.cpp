#include "Collider.h"
#include "Math/IVector2.h"

std::vector<Collider*> Collider::allColliders;

Collider::Collider(IVector2* position, std::vector<std::string>* sprite)
{
	this->position = position;

	UpdateDimensions(sprite);

	colliderID = allColliders.size();
	allColliders.push_back(this);
}

Collider::~Collider()
{
	allColliders.erase(allColliders.begin() + colliderID);

	for (int i = colliderID + 1; i < allColliders.size(); i++)
	{
		allColliders[i]->colliderID--;
	}
}

bool Collider::CheckCollision()
{
	int numColliders = allColliders.size();

	for (int i = 0; i < numColliders; i++)
	{
		if (allColliders[i] != this)
		{
			if (AABBCollisionCheck(position, allColliders[i]->GetPosition(), this, allColliders[i]))
			{
				return true;
			}
		}
	}

	return false;
}

bool Collider::CheckMovementForCollision(IVector2 movement)
{
	int numColliders = allColliders.size();

	for (int i = 0; i < numColliders; i++)
	{
		if (allColliders[i] != this)
		{
			if (AABBCollisionCheck(new IVector2(*position + movement), allColliders[i]->GetPosition(), this, allColliders[i]))
			{
				return true;
			}
		}
	}

	return false;
}

void Collider::UpdateDimensions(std::vector<std::string>* sprite)
{
	width = 0;

	for (int i = 0; i < sprite->size(); i++)
	{
		if (sprite[i].size() > width)
		{
			width = sprite[i].size();
		}
	}

	height = sprite->size();
}

IVector2* Collider::GetPosition()
{
	return position;
}

bool Collider::AABBCollisionCheck(IVector2* v1, IVector2* v2, Collider* c1, Collider* c2)
{
	if (v1->x <= v2->x + c2->width - 1 &&
		v1->x + c1->width - 1 >= v2->x &&
		v1->y <= v2->y + c2->height - 1 &&
		v1->y + c1->height - 1 >= v2->y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
