#pragma once
class Object
{
private:

	bool enabled;

protected:

	virtual void Update() = 0;

public:

	Object();

	void UpdateObject();

};

