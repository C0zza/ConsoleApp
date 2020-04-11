#pragma once
class Object
{
private:

	bool enabled;
	bool destroyed;

protected:

	virtual void UpdateWorldObject() = 0;

public:

	Object();

	void UpdateObject();

	void DestroyObject();
	bool GetDestroyed();

};

