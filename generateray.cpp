#include <vector>
#include "generateray.h"

CPoint::CPoint()
{

}

void CPoint::SetValue(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

CPoint::~CPoint()
{

}


CDomain::CDomain()
{

}

CDomain::~CDomain()
{

}

CDomain::CDomain(CPoint _pmin, CPoint _pmax, float _step)
{
	pmin = _pmin;
	pmax = _pmax;
	step = _step;
	ptcnumber[0] = (int) ((pmax.x - pmin.x)/step);
	ptcnumber[1] = (int) ((pmax.y - pmin.y)/step);
	ptcnumber[2] = (int) ((pmax.z - pmin.z)/step);
}


bool CDomain::GenerateRay(float _x, float _y)
{
	r.x = _x;
	r.y = _y;
	return 1;
}
