#include <vector>
using namespace std;
#pragma once


class CPoint
{
public:
	float x,y,z;
public:
	CPoint();
	void SetValue(float _x, float _y, float _z);
	~CPoint();
};

struct SRay
{
	float x, y;              //start point of ray

};
class CDomain
{
public:
	CPoint pmin,pmax;
	float step;
	int ptcnumber[3];
	SRay r;
public:
	CDomain();
	CDomain(CPoint _pmin, CPoint _pmax, float _step);
	~CDomain();
	bool GenerateRay(float _x, float _y);
};

