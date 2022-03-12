#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED


#include <vector>

class position;
class map;

bool in(int, int, const position &);
bool hit(const position &, const position &);

enum direction {Left, Right, Forward, Back, None};

class position
{
	friend bool in(int, int, const position &);
	friend bool hit(const position &, const position &);
	friend void fire(map &);
private:
	int left;
	int right;
	int top;
	int bottom;

	int maxX;
	int maxY;
public:
	position(int, int, int, int);
	position();
	void setMax(int, int);
	void move(direction, int);
	void moveex(direction, int);
	bool out() const;
	//void fire(map &) const;
	float getLeft() const {return (float)left;}
	float getRight() const {return (float)right;}
	float getTop() const {return (float)top;}
	float getBottom() const {return (float)bottom;}
	bool visible;
};

class map
{
	friend void display();
private:
	std::vector<position> aniPlanes; //record position
	std::vector<position> fires;
	position mainPlane;
	bool overed;        //is the game over?  if main plane is destoryed , set to true
	int score;          //the number of plane destroyed
public:
	map();     //add some plane ; set mainplane
	void update(direction);   //update positions
	void check();             //check for hit , destory objects
	bool isOvered() const;    //return overed
	void addPlane();          //add new planes
	void fire();              //add new fire
	void move(direction d) { mainPlane.move(d, 10); }   //public move interface
	int getScore() { return score; }
};

#endif