#include "stdafx.h"
#include "cphy_decoder.h"
#include <iostream>


cphy_decoder::cphy_decoder()
{
	pol = false;
	wire_state = 2;
	wire_voltA = 75;
	wire_voltB = 50;
	wire_voltC = 25;
}


cphy_decoder::~cphy_decoder()
{
}

void cphy_decoder::set_wire_state(int a) {
	wire_state = a;

}

void cphy_decoder::show_wire_state() {
	std::cout << wire_state << '\n';
}



void cphy_decoder::ccw(cphy_decoder & c)
{
	c.wire_state = (c.wire_state - 1) % 3;
	if (c.wire_state == 0) {
		c.wire_state = 3;
	}
}

void cphy_decoder::ccwp(cphy_decoder & c)
{
	c.pol = !c.pol;
	c.wire_state = (c.wire_state - 1) % 3;
	if (c.wire_state == 0) {
		c.wire_state = 3;
	}
}

void cphy_decoder::cw(cphy_decoder & c)
{
	c.wire_state = (c.wire_state + 1) % 3;
	if (c.wire_state == 0) {
		c.wire_state = 3;
	}
}

void cphy_decoder::cwp(cphy_decoder & c)
{
	c.pol = !c.pol;
	c.wire_state = (c.wire_state + 1) % 3;
	if (c.wire_state == 0) {
		c.wire_state = 3;
	}
}

void cphy_decoder::opol(cphy_decoder & c)
{
	c.pol = !c.pol;
}

char* cphy_decoder::get_wire_state(cphy_decoder & c)
{
	if (c.pol) {
		if (c.wire_state == 1)
		{
			return "+y";
		}
		else if (c.wire_state == 2)
		{
			return "+z";
		}
		else if (c.wire_state == 3) 
		{
			return "+x";
		}
		else
		{
			return "error";
		}

	}
	else {
		if (c.wire_state == 1)
		{
			return "-y";
		}
		else if (c.wire_state == 2)
		{
			return "-z";
		}
		else if (c.wire_state == 3)
		{
			return "-x";
		}
		else
		{
			return "error";
		}
	}

	return " ";
}

bool cphy_decoder::get_wire_state_pol(cphy_decoder & c)
{

	return c.pol;
}

void cphy_decoder::wire2state(cphy_decoder & c)
{
	if (wire_voltA == 75 && wire_voltB == 25 && wire_voltC == 50) {
		c.wire_state = 3;
		c.pol = true;
	}
	else if (wire_voltA == 25 && wire_voltB == 75 && wire_voltC == 50) {
		c.wire_state = 3;
		c.pol = false;
	}
	else if (wire_voltA == 50 && wire_voltB == 75 && wire_voltC == 25) {
		c.wire_state = 1;
		c.pol = true;
	}
	else if (wire_voltA == 50 && wire_voltB == 25 && wire_voltC == 75) {
		c.wire_state = 1;
		c.pol = false;
	}
	else if (wire_voltA == 25 && wire_voltB == 50 && wire_voltC == 75) {
		c.wire_state = 2;
		c.pol = true;
	}
	else if (wire_voltA == 75 && wire_voltB == 50 && wire_voltC == 25) {
		c.wire_state = 2;
		c.pol = false;
	}
	else
		error_report = "no this voltage combi";
}

void cphy_decoder::set_wire_volt(int volta, int voltb, int voltc)
{
	wire_voltA = volta;
	wire_voltB = voltb;
	wire_voltC = voltc;

}

void cphy_decoder::get_wire_symbol(cphy_decoder & c, cphy_decoder & d)
{
	int temp;
	if (c.wire_state == d.wire_state && c.pol == d.pol)
		c.error_report = "state no change";
	else if (((d.wire_state == c.wire_state)) && (c.pol != d.pol))
		temp = 4;
	else if (((d.wire_state - c.wire_state) == 1) && (c.pol == d.pol))
		temp = 2;
	else if (((d.wire_state - c.wire_state) == 1) && (c.pol != d.pol))
		temp = 3;
	else if (((c.wire_state - d.wire_state) == 1) && (c.pol == d.pol))
		temp = 0;
	else if (((c.wire_state - d.wire_state) == 1) && (c.pol == d.pol))
		temp = 1;
	else
		c.error_report = "invalid symol";
	c = d;
	c.symbol = temp;
	

}

char * cphy_decoder::show_symbol()
{
	if (symbol == 0)
		return "CCW symbol 0";
	else if (symbol == 1)
		return "CCW pol opp symbol 1";
	else if (symbol == 2)
		return "CW symbol 2";
	else if (symbol == 3)
		return "CW pol opp symbol 2 ";
	else if (symbol == 4)
		return "pol opp";
	else 
		return nullptr;
}


