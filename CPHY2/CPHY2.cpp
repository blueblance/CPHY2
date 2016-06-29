// CPHY2.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
#include "cphy_decoder.h"

using namespace std;
int main()
{
	cout << "hello world" << '\n';
	cphy_decoder cphy;
	cphy_decoder cphy2;
	cphy.set_wire_state(3);
	cphy.show_wire_state();		
	cphy.ccwp(cphy);
	cout << cphy.get_wire_state(cphy) << '\n';
	cphy.ccwp(cphy);
	cout << cphy.get_wire_state(cphy) << '\n';
	cphy.ccwp(cphy);
	cout << cphy.get_wire_state(cphy) << '\n';
	cphy.ccwp(cphy);
	cout << cphy.get_wire_state(cphy) << '\n';
	cphy.ccwp(cphy);
	cout << cphy.get_wire_state(cphy) << '\n';
	cphy.ccwp(cphy);
	cout << cphy.get_wire_state(cphy) << '\n';
	cphy.ccwp(cphy);
	cout << cphy.get_wire_state(cphy) << '\n';
	cphy.ccwp(cphy);
	cout << cphy.get_wire_state(cphy) << '\n';
	cphy.ccwp(cphy);
	cout << cphy.get_wire_state(cphy) << '\n';
	cphy.ccwp(cphy);
	cout << cphy.get_wire_state(cphy) << '\n';
	cphy.ccwp(cphy);
	cout << cphy.get_wire_state(cphy) << '\n';
	cphy2.set_wire_volt(75, 50, 25);
	cout << "set:cphy2" << '\n';
	cout << cphy.get_wire_state(cphy2) << '\n';
	cphy.show_wire_state();
	cphy2.show_wire_state();
	cphy.get_wire_symbol(cphy, cphy2);
	cout << cphy.get_wire_state(cphy) << '\n';
	cout << cphy.show_symbol() << '\n';
	
	
    return 0;
}

