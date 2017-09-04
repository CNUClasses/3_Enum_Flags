//============================================================================
// Name        : 3_Enum_Flags.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

// main.cpp
#include "myvar.h"   // define MyClass
//#include "myvar.h"   // Compiler error - myInt already defined


using namespace std;


enum MyOptions {
  OpAutoRedraw    = 0x01,	// 0x01 ==   1 == "00000001"
  OpAntiAlias     = 0x02,	// 0x02 ==   2 == "00000010"
  OpPixelShader   = 0x04,	// 0x04 ==   4 == "00000100"
  OpVertexShader  = 0x08,	// 0x08 ==   8 == "00001000"
  OpFullscreen    = 0x10,	// 0x10 ==  16 == "00010000"
  OpDaylight      = 0x20,	// 0x20 ==  32 == "00100000"
  OpGlow		  = 0x40	// 0x40 ==  64 == "01000000"
  	  	  	  	  	  	    // 0x80 == 128 == "10000000" do not need to use all bits
};

enum MyCarOptions {
  Blue    		= 0x01,
  Red     		= 0x02,
  Only3Wheels   = 0x04,
  Electric  	= 0x08,
  HasToaster    = 0x10,
  IsPretty      = 0x20,
  IsUgly		= 0x40,
  AC	  	  	= 0x80
};
int main() {
	//this car has it all
	unsigned char CarOptions = 0xFF;

	//Caroptions  contains info for a particular car
	//It can only have 1 of 8 features as seen above
	//suppose I want to ensure that it has AC and is Red
	//suppose I dont care about the other features
	//write code to test for this, if it does set the following
	//bool true, otherwise false

	bool HasWhatIWant;

	//your code here
	HasWhatIWant = (CarOptions&AC) && (CarOptions&Red);



	//note this is a hex representation
	//always positive all bits are info, no sign bit
	unsigned char options = 0x00;

	//lets say you want to set antialais(0x02) and fullscreen(0x10)
	options=options|OpAutoRedraw| OpFullscreen;

	//now options = 00010010

	//should succeed
	if (options & OpAutoRedraw)
		std::cout<<"OpAutoRedraw is set";

	//should fail
	if (options & OpAntiAlias)
		std::cout<<"OpAntiAlias is set";
}
