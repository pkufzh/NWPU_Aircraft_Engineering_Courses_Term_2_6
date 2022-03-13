#include "map.h"
#include <vector>
#include <cstdlib>
#include <iostream>

bool findFree(const std::vector<position> & vec, int & index)  //find waste memory to reuse
{
	for (int a = 0; a < vec.size(); a++)
	{
		if (vec[a].visible == false)
		{
			index = a;
			return true;
		}
	}
	return false;
}

bool in(int x, int y, const position & pos)
{
	if ( x >= pos.left && x <= pos.right )
		if ( y >= pos.bottom && y <= pos.top )
			return true;
	return false;
}

bool hit(const position & pos1, const position & pos2)
{
    if (in(pos1.left, pos1.bottom, pos2))
		return true;
	if (in(pos1.left, pos1.top, pos2))
		return true;
	if (in(pos1.right, pos1.bottom, pos2))
		return true;
	if (in(pos1.right, pos1.top, pos2))
		return true;
	
	if (in(pos2.left, pos2.bottom, pos1))
		return true;
	if (in(pos2.left, pos2.top, pos1))
		return true;
	if (in(pos2.right, pos2.bottom, pos1))
		return true;
	if (in(pos2.right, pos2.top, pos1))
		return true;

	return false;
}

position::position(int l, int r, int t, int b)
{
	left = l;
	right = r;
	top = t;
	bottom = b;
	visible = true;
}

position::position()
{
	left = right = top = bottom = 0;
	visible = true;
}

void position::setMax(int x, int y)
{
	maxX = x;
	maxY = y;
}

void position::move(direction d, int v)
{
	if (d == Left)
	{
		left -= v;
		right -= v;
	}
	if (d == Right)
	{
		left += v;
		right += v;
	}
	if (d == Forward)
	{
		top += v;
		bottom += v;
	}
	if (d == Back)
	{
		top -= v;
		bottom -= v;
	}

	if (right > maxX)
	{
		right = maxX;
		left = 450;
	}
	/*if (top > maxY)
	{
		top = maxY;
		bottom = 720;
	}*/
	if (left < 0)
	{
		left = 0;
		right = 50;
	}
}

void position::moveex(direction d, int v)
{
	this->move(d, v);

	if (top > maxY)
	{
		top = maxY;
		bottom = 720;
	}
	if (bottom < 0)
	{
		top = 80;
		bottom = 0;
	}
}

bool position::out() const
{
	/*if (top < maxY)
		return false;
	if (right < maxX)
		return false;
	return true£»*/
    if (top == maxY)
		return true;
	if (bottom == 0)
		return true;
	if (left == 0)
		return true;
	if (right ==  maxX)
		return true;
	return false;
}

map::map()
	: aniPlanes(), fires(), mainPlane(225, 275, 80, 0)
{
	addPlane();
	addPlane();
	addPlane();
	score = 0;
	mainPlane.setMax(500, 800);
	overed = false;
}

bool map::isOvered() const
{
	return overed;
}

void map::update(direction d)
{
	for (auto & x : aniPlanes)
		x.move(Back, 5);
	for (auto & x : fires)
		x.move(Forward, 10);
	mainPlane.moveex(d, 6);
	//fire(*this);
}

void map::addPlane()
{
	int x;
	position pos;
	int index;
	bool temp = findFree(this->aniPlanes, index);

    x = rand() % 450;
    pos = position(x, x + 50, 800, 720);
    pos.setMax(500, 800);

	if (!temp)   //if there isnt memory to reuse, new
	    this ->aniPlanes.push_back(pos);

	if (temp)
		this->aniPlanes[index] = pos;
	//for (auto x : aniPlanes)
	//	std::cout << x.getBottom() << x.getTop() << x.getRight() << x.getLeft() << std::endl;

}

void map::check() //check for hit, use for, destory objects, use vector.erase, if fire is out of screen, desdory it
{
	std::vector<int> desFire;
	std::vector<int> desPlane;

	for (int a = 0; a < fires.size(); a++)        //check for hit, save hit-objects index to vector
	{
		if (fires[a].getBottom() > 800)   //if it is out of screen , not visible
			fires[a].visible = false;
		if (!fires[a].visible)       //if not visible, pass.
			continue;
		
		for (int b = 0; b < aniPlanes.size(); b++)
		{
			if (aniPlanes[b].getTop() < 0)
				aniPlanes[b].visible = false;
			if (!aniPlanes[b].visible)
				continue;
			if (hit(fires[a], aniPlanes[b]))
			{
				desFire.push_back(a);
				desPlane.push_back(b);
				score++;
			}
		}
	}

	//check fires for out of sreen, save objects index to vector

	/*for (int x = 0; x < fires.size(); x++)
		if (fires[x].out())
			desFire.push_back(x);*/
	//maybe it will cause a exception...so delete it

	//destory objects
	if (desFire.size() > 0)
	{
		for (int x = 0; x < desFire.size(); x++)
			//fires.erase(fires.begin() + desFire[x], fires.begin() + (desFire[x] + 1));
			fires[desFire[x]].visible = false;
	}

	if (desPlane.size() > 0)
	{
		for (int x = 0; x < desPlane.size(); x++)
		    //aniPlanes.erase(aniPlanes.begin() + desPlane[x], aniPlanes.begin() + (desPlane[x] + 1));
			aniPlanes[desPlane[x]].visible = false;
	}

	//check : main plane hit

	for (auto x : aniPlanes)
	{
		if (!x.visible)
			continue;
		if (hit(x, mainPlane))
			overed = true;
	}
}

void map::fire()
{
	int l = (mainPlane.getLeft() + mainPlane.getRight()) / 2 - 5;     //get x,y
	int r = (mainPlane.getLeft() + mainPlane.getRight()) / 2 + 5;  
	int t = mainPlane.getTop() + 15;
	int b = mainPlane.getTop() + 5;
	int index;                                      //find memory
	bool temp = findFree(this->fires, index);

	position pos = position(l, r, t, b);   //create position
	pos.setMax(500, 800);

	if (!temp)
        fires.push_back(pos);
	if (temp)
		fires[index] = pos;
}