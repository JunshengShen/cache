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


	voxels<VoxelInfo> asd("d:", 2, 2, 32);


	cout << endl << endl << endl << endl;
	for (int i = 32;i < 64;i++) {
		cout << *asd.getCode(i) << ' ' << asd.voxel.size();
		cout << endl;
	}

	cout << endl << endl << endl;
	voxels<VoxelInfo> asd_("d:", 2, 2, 64);






	system("pause");
	return 0;
}