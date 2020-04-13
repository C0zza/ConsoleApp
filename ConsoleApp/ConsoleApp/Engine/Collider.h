#pragma once
#include <vector>
#include <string>

class IVector2;

class Collider
{
private:

	static std::vector<Collider*> allColliders;
	int colliderID;

	IVector2* position;
	int width;
	int height;

	static bool AABBCollisionCheck(IVector2* v1, IVector2* v2, Collider* c1, Collider* c2);

public:

	Collider(IVector2* position, std::vector<std::string>* sprite);
	~Collider();

	bool CheckCollision();
	bool CheckMovementForCollision(IVector2 movement);
	
	void UpdateDimensions(std::vector<std::string>* sprite);

	IVector2* GetPosition();
};

