#include "vec2.h"
#include<cmath>

const float vec2::eps(0.0001f);

vec2::vec2() : x(0.0f), y(0.0f){}

vec2::vec2(float _x, float _y){

	x = _x;
	y = _y;
}
//vec2::vec2(float _x, float _y) : x(_x), y(_y) {} taka e po-opmitimalno, byrzo i ako imame const ili & trqbwa tuk da gi inizializirame, ako sa vytre se prisvoqvat

vec2& vec2::operator+=(const vec2& vec){

	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

vec2& vec2::operator*=(float num){

	x *= num;
	y *= num;
	return *this;
}

vec2 operator+(const vec2& a, const vec2& b){

	vec2 res(a);
	return res += b;

	//res.x += a.x;
	//res.x += b.x;

	//res.y += a.y;
	//res.y += b.y;

	//return res;
}

vec2 operator-(const vec2& _x, const vec2& _y){

	return vec2(_x.x - _y.x, _x.y - _y.y);
}

vec2 operator*(const vec2& a, float b){

	vec2 res(a);
	return res *= b;

	//return vec2(_x.x * _y, _x.y * _y);
}

vec2 operator/(const vec2& _x, float _y){

	return vec2(_x.x / _y, _x.y / _y);
}

bool operator!=(const vec2& a, const vec2& b){
	
	return (!fabs(a.x == b.x) <= vec2::eps) && !(fabs(a.y == b.y));
}

bool operator==(const vec2& a, const vec2& b)
{
	return !(a != b);
}
