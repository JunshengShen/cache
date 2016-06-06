#pragma once
#include <iostream>
using namespace std;
class VoxelInfo {
public:
	long long morton;
	bool in_out = false;//true is in     false is out
	bool inside_boun = true;//true is boundary    false is inside
							//both false is unkonw
	bool operator==(const VoxelInfo & o);
	void operator=(const VoxelInfo & o);
	bool operator>(const VoxelInfo &o);
	bool operator<(const VoxelInfo &o);
	bool operator!=(const VoxelInfo &o);
	bool operator!=(const int & o);
	void operator=(const int & o);
	bool operator<(const unsigned long long &o);
};
ostream& operator<<(ostream & os, const VoxelInfo & o);