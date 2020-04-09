#pragma once
class IVector2
{
public:

	int x, y;
	
	IVector2(int x, int y);
	IVector2();

	IVector2 operator +(IVector2 const v)
	{
		IVector2 iv2;
		iv2.x = x + v.x;
		iv2.y = y + v.y;
		return iv2;
	}

	void operator +=(IVector2 const v)
	{
		x += v.x;
		y += v.y;
	}

	IVector2 operator *(float const scalar)
	{
		IVector2 iv2;
		iv2.x *= scalar;
		iv2.y *= scalar;
		return iv2;
	}

	void operator *=(float const scalar)
	{
		x *= scalar;
		y *= scalar;
	}

	IVector2 operator /(float const scalar)
	{
		IVector2 iv2;
		iv2.x /= scalar;
		iv2.y /= scalar;
		return iv2;
	}

	void operator /=(float const scalar)
	{
		x /= scalar;
		y /= scalar;
	}

	IVector2 operator -(IVector2 const v)
	{
		IVector2 iv2;
		iv2.x = x - v.x;
		iv2.y = y - v.y;
		return iv2;
	}

	void operator -=(IVector2 const v)
	{
		x -= v.x;
		y -= v.y;
	}

	float Distance(IVector2 v1, IVector2 v2);
};

