#pragma once
class cphy_decoder
{
public:
	cphy_decoder() ;
	~cphy_decoder();
	void set_wire_state(int a);
	void show_wire_state();
	//const cphy_decoder & ccw(cphy_decoder &c);
	void ccw(cphy_decoder &c); //symbol 0
	void ccwp(cphy_decoder &c);//symbol 1
	void cw(cphy_decoder &c);//symbol 2
	void cwp(cphy_decoder &c);//symbol 3
	void opol(cphy_decoder &c);//symbol 4
	char* get_wire_state(cphy_decoder &c);
	bool get_wire_state_pol (cphy_decoder &c);
	void wire2state(cphy_decoder &c);
	void set_wire_state(cphy_decoder &c , int symbol);
	void set_wire_volt(int volta , int voltb , int voltc);
	void get_wire_symbol(cphy_decoder &c, cphy_decoder &d);
	char* show_symbol();
	int symbol;

	
private:
	int wire_state;
	bool pol;
	int wire_voltA, wire_voltB, wire_voltC;
	void wire2symbol(cphy_decoder &c , cphy_decoder &d);
	char* error_report;
	
	
};

