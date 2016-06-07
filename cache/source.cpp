#include "cache.h"
#include <iostream>
#include "voxelinfo.h"
using namespace std;


int main() {
	/*VoxelInfo a, b, c;
	a.morton = 1;
	b.morton = 1;
	c.morton = 2;
	cout << (a == c);
	c = a;
	cout << c.morton << (a == c) << endl << endl;*/


	

	cout << endl << endl << endl;
	voxels<VoxelInfo> asd_("d:", 2, 2, 64);

	VoxelInfo a;
	a.in_out = 0;
	a.inside_boun = 0;
	a.morton = 32;
	asd_.updateOne(a);
	cout << endl << endl;


	/*for (int i = 0;i < 64;i++) {
		cout << *asd_.getCode(i) << ' ' << asd_.voxel.size();
		cout << endl;
	}
	cout << endl << endl << endl;
	for (int i = 0;i < 64;i++) {
		cout << *asd_.getCode(i) << ' ' << asd_.voxel.size();
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 0;i < 64;i++) {
		cout << *asd_.getCode(i) << ' ' << asd_.voxel.size();
		cout << endl;
	}*/
	system("pause");
	return 0;
}