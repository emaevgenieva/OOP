#pragma once
struct vec2{

	float x;
	float y;
	const static float eps;

	vec2();
	vec2(float _x, float _y);
	vec2& operator+= (const vec2& vec);
	vec2& operator*= (float num);
	friend vec2 operator+ (const vec2& a, const vec2& b); // slagame friend, zashtoto ne moje da dostypim private dannite
	friend vec2 operator+ (const vec2& a, const vec2& b);
	friend vec2 operator- (const vec2& _x, const vec2& _y);
	friend vec2 operator* (const vec2& a, float b);
	friend vec2 operator/ (const vec2& _x, float _y);
	friend bool operator!=(const vec2& a, const vec2& b);
	friend bool operator==(const vec2& a, const vec2& b);

};

//vec2 operator+ (const vec2& a, const vec2& b);
//vec2 operator- (const vec2& _x, const vec2& _y);
//vec2 operator* (const vec2& a, float b);
//vec2 operator/ (const vec2& _x, float _y);
//bool operator!=(const vec2& a, const vec2& b);
//bool operator==(const vec2& a, const vec2& b);