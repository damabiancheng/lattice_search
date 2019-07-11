//program search the triangular facets in STL file using lattice grid method

#include "stlread.h"
#include "generateray.h"
#include "intersection.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sys/time.h>
//#pragma once
#define CELL_SIZE 8

vector<CDomain> Divide_domain(const CDomain& d, const int dx, const int dy)
{
	vector<CDomain> sub_domains;
	CPoint pmin, pmax, p1, p2;
	float tx, ty;
	tx = (d.pmax.x - d.pmin.x) / dx;
	ty = (d.pmax.y - d.pmin.y) / dy;
	pmin.SetValue(d.pmin.x, d.pmin.y, 0);
	pmax.SetValue(d.pmin.x + tx, d.pmin.y + ty, 0);
	p1 = pmin;
	p2 = pmax;

	for (int i = 0; i < dy; i++)
	{
		for (int j = 0; j < dx; j++)
		{
			CDomain sub(p1, p2, 0.1);
			sub_domains.push_back(sub);
			p1.x = p1.x + tx;
			p2.x = p2.x + tx;
		}
		p1.x = pmin.x;
		p2.x = pmax.x;
		p1.y = p1.y + ty;
		p2.y = p2.y + ty;
		
	}
	return sub_domains;
}

bool Is_intersect(const CDomain& d, const CTri& t)
{
	return !(((d.pmax.x < t.x1) || (d.pmin.y > t.y2) ||
		     (d.pmin.x > t.x2) || (d.pmax.y < t.y1)));
}

int main(int argc, char* argv[])
{
	CPoint p1, p2;
	CSTLModel stlmodel;
	SRay ray;

	stlmodel.LoadStlFile("./timetest/4970.stl");
   struct timeval start1, end1;
   gettimeofday(&start1, NULL);
	CPoint pmin, pmax;
	pmin.SetValue(0, 0, 0);
	pmax.SetValue(100, 100, 100);
	float size = 0.1;
	int dx = 5, dy = 5;
	CDomain domain(pmin, pmax, size);
	vector<CDomain> sub_domains;
	sub_domains = Divide_domain(domain, dx, dy);
	vector<int> count_tri;

	for (int i = 0; i < stlmodel.arraytri.size(); i++)
	{
		stlmodel.arraytri[i].Boundingbox();
	}

	for (int i = 0; i < dx*dy; i++)
	{
		int count = 0;
		for (int j = 0; j < stlmodel.arraytri.size(); j++)
		{
			if (Is_intersect(sub_domains[i], stlmodel.arraytri[j]))
				count++;
		}
		count_tri.push_back(count);
	}

  gettimeofday(&end1, NULL);
	printf("ray casting time=%f\n", (double)(end1 .tv_usec - start1.tv_usec));

	return 0;
}

